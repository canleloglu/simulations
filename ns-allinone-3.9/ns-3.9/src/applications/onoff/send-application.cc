/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
//
// Copyright (c) 2006 Georgia Tech Research Corporation
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation;
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// Author: George F. Riley<riley@ece.gatech.edu>
//

// ns3 - On/Off Data Source Application class
// George F. Riley, Georgia Tech, Spring 2007
// Adapted from ApplicationSend in GTNetS.

#include "ns3/log.h"
#include "ns3/address.h"
#include "ns3/node.h"
#include "ns3/nstime.h"
#include "ns3/data-rate.h"
#include "ns3/random-variable.h"
#include "ns3/socket.h"
#include "ns3/simulator.h"
#include "ns3/socket-factory.h"
#include "ns3/packet.h"
#include "ns3/uinteger.h"
#include "ns3/trace-source-accessor.h"
#include "send-application.h"
#include "ns3/udp-socket-factory.h"
#include "ns3/inet-socket-address.h"
#include "ns3/cipher.h"
#include "ns3/Sha-256.h"

#include <fstream>

NS_LOG_COMPONENT_DEFINE ("SendApplication");

using namespace std;

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (SendApplication);
	
string replaceSend( string source, const string find, string replace );

TypeId
SendApplication::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::SendApplication")
    .SetParent<Application> ()
    .AddConstructor<SendApplication> ()
    .AddAttribute ("DataRate", "The data rate in on state.",
                   DataRateValue (DataRate ("500kb/s")),
                   MakeDataRateAccessor (&SendApplication::m_cbrRate),
                   MakeDataRateChecker ())
    .AddAttribute ("PacketSize", "The size of packets sent in on state",
                   UintegerValue (512),
                   MakeUintegerAccessor (&SendApplication::m_pktSize),
                   MakeUintegerChecker<uint32_t> (1))
    .AddAttribute ("Remote", "The address of the destination",
                   AddressValue (),
                   MakeAddressAccessor (&SendApplication::m_peer),
                   MakeAddressChecker ())
    .AddAttribute ("OnTime", "A RandomVariable used to pick the duration of the 'On' state.",
                   RandomVariableValue (ConstantVariable (1.0)),
                   MakeRandomVariableAccessor (&SendApplication::m_onTime),
                   MakeRandomVariableChecker ())
    .AddAttribute ("OffTime", "A RandomVariable used to pick the duration of the 'Off' state.",
                   RandomVariableValue (ConstantVariable (1.0)),
                   MakeRandomVariableAccessor (&SendApplication::m_offTime),
                   MakeRandomVariableChecker ())
    .AddAttribute ("MaxBytes", 
                   "The total number of bytes to send. Once these bytes are sent, "
                   "no packet is sent again, even in on state. The value zero means "
                   "that there is no limit.",
                   UintegerValue (0),
                   MakeUintegerAccessor (&SendApplication::m_maxBytes),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("Protocol", "The type of protocol to use.",
                   TypeIdValue (UdpSocketFactory::GetTypeId ()),
                   MakeTypeIdAccessor (&SendApplication::m_tid),
                   MakeTypeIdChecker ())
    .AddTraceSource ("Tx", "A new packet is created and is sent",
                     MakeTraceSourceAccessor (&SendApplication::m_txTrace))
    ;
  return tid;
}



SendApplication::SendApplication ()
{
  NS_LOG_FUNCTION_NOARGS ();
  m_socket = 0;
  m_connected = false;
  m_residualBits = 0;
  m_lastStartTime = Seconds (0);
  m_totBytes = 0;
}

SendApplication::~SendApplication()
{
  NS_LOG_FUNCTION_NOARGS ();
}

void 
SendApplication::SetMaxBytes(uint32_t maxBytes)
{
  NS_LOG_FUNCTION (this << maxBytes);
  m_maxBytes = maxBytes;
}


void
SendApplication::DoDispose (void)
{
  NS_LOG_FUNCTION_NOARGS ();

  m_socket = 0;
  // chain up
  Application::DoDispose ();
}

// Application Methods
void SendApplication::StartApplication() // Called at time specified by Start
{
  NS_LOG_FUNCTION_NOARGS ();

  // Create the socket if not already
  if (!m_socket)
    {
      m_socket = Socket::CreateSocket (GetNode(), m_tid);
      m_socket->Bind ();
      m_socket->Connect (m_peer);
      m_socket->SetAllowBroadcast (true);
      m_socket->ShutdownRecv ();
    }
  // Insure no pending event
  CancelEvents ();
  // If we are not yet connected, there is nothing to do here
  // The ConnectionComplete upcall will start timers at that time
  //if (!m_connected) return;
  ScheduleStartEvent();
}

void SendApplication::StopApplication() // Called at time specified by Stop
{
  NS_LOG_FUNCTION_NOARGS ();

  CancelEvents ();
  if(m_socket != 0)
    {
      m_socket->Close ();
    }
  else
    {
      NS_LOG_WARN("SendApplication found null socket to close in StopApplication");
    }
}

void SendApplication::CancelEvents ()
{
  NS_LOG_FUNCTION_NOARGS ();

  if (m_sendEvent.IsRunning ())
    { // Cancel the pending send packet event
      // Calculate residual bits since last packet sent
      Time delta(Simulator::Now() - m_lastStartTime);
      Scalar bits = delta * Scalar (m_cbrRate.GetBitRate ()) / Seconds (1.0);
      m_residualBits += (uint32_t)bits.GetDouble ();
    }
  Simulator::Cancel(m_sendEvent);
  Simulator::Cancel(m_startStopEvent);
}

// Event handlers
void SendApplication::StartSending()
{
  NS_LOG_FUNCTION_NOARGS ();
  m_lastStartTime = Simulator::Now();
  ScheduleNextTx();  // Schedule the send packet event
  ScheduleStopEvent();
}

void SendApplication::StopSending()
{
  NS_LOG_FUNCTION_NOARGS ();
  CancelEvents();

  ScheduleStartEvent();
}
	
	void SendApplication::setPacketId (uint64_t val)
	{
		packetId = val;
	}

// Private helpers
	////
	////
	////
	////
	////
	////eger burada next timei packet interval gibi bir seye esitlersem
	////udp-echodaki packet intervalin aynisini yakalamis olurum
void SendApplication::ScheduleNextTx()
{
  NS_LOG_FUNCTION_NOARGS ();

  if (m_maxBytes == 0 || m_totBytes < m_maxBytes)
    {
      uint32_t bits = m_pktSize * 8 - m_residualBits;
      NS_LOG_LOGIC ("bits = " << bits);
      Time nextTime(Seconds (bits / 
        static_cast<double>(m_cbrRate.GetBitRate()))); // Time till next packet

      NS_LOG_LOGIC ("nextTime = " << nextTime);
      m_sendEvent = Simulator::Schedule(nextTime, 
                                        &SendApplication::SendPacket, this);
    }
  else
    { // All done, cancel any pending events
      StopApplication();
    }
}

void SendApplication::ScheduleStartEvent()
{  // Schedules the event to start sending data (switch to the "On" state)
  NS_LOG_FUNCTION_NOARGS ();

  Time offInterval = Seconds(m_offTime.GetValue());
  NS_LOG_LOGIC ("start at " << offInterval);
  m_startStopEvent = Simulator::Schedule(offInterval, &SendApplication::StartSending, this);
}

void SendApplication::ScheduleStopEvent()
{  // Schedules the event to stop sending data (switch to "Off" state)
  NS_LOG_FUNCTION_NOARGS ();

  Time onInterval = Seconds(m_onTime.GetValue());
  NS_LOG_LOGIC ("stop at " << onInterval);
  m_startStopEvent = Simulator::Schedule(onInterval, &SendApplication::StopSending, this);
}

	
	void SendApplication::setDirection(std::string s)
	{
		direction = s;
	}

	void SendApplication::setNetType(std::string s)
	{
		netType = s;
	}
	
void SendApplication::SendPacket()
{
  NS_LOG_FUNCTION_NOARGS ();
  //NS_LOG_LOGIC ("sending packet at " << Simulator::Now());
  NS_ASSERT (m_sendEvent.IsExpired ());
  Ptr<Packet> packet = Create<Packet> (m_pktSize);
	
	InetSocketAddress peerAddress = InetSocketAddress::ConvertFrom (m_peer);
	
	packet->SetUid(packetId);
	
  NS_LOG_UNCOND ("Sending "<<m_pktSize<<" bytes to "<< peerAddress.GetIpv4() <<" at " 
	<< Simulator::Now().GetSeconds()<< " Packet ID: "<<packet->GetUid());		
	
	
  m_txTrace (packet);
  m_socket->Send (packet);
  m_totBytes += m_pktSize;
  m_lastStartTime = Simulator::Now();
  m_residualBits = 0;
  ScheduleNextTx();
}

void SendApplication::ConnectionSucceeded(Ptr<Socket>)
{
  NS_LOG_FUNCTION_NOARGS ();

  m_connected = true;
  ScheduleStartEvent();
}
  
void SendApplication::ConnectionFailed(Ptr<Socket>)
{
  NS_LOG_FUNCTION_NOARGS ();
  cout << "SendApplication, Connection Failed" << endl;
}
	
void SendApplication::setAddr(Ipv4Address addr)
{
	m_address = addr;
}
	
string replaceSend( string source, const string find, string replace ) 
{	
	size_t j;
	for ( ; (j = source.find( find )) != string::npos ; ) {
		source.replace( j, find.length(), replace );
	}
	return source;
}

} // Namespace ns3
