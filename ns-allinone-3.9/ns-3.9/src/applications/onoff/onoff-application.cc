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
// Adapted from ApplicationOnOff in GTNetS.

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
#include "onoff-application.h"
#include "ns3/udp-socket-factory.h"
#include "ns3/inet-socket-address.h"
#include "ns3/cipher.h"
#include "ns3/Sha-256.h"

#include <fstream>

NS_LOG_COMPONENT_DEFINE ("OnOffApplication");

using namespace std;

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (OnOffApplication);
	
string replaceOnOff( string source, const string find, string replace );

TypeId
OnOffApplication::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::OnOffApplication")
    .SetParent<Application> ()
    .AddConstructor<OnOffApplication> ()
    .AddAttribute ("DataRate", "The data rate in on state.",
                   DataRateValue (DataRate ("500kb/s")),
                   MakeDataRateAccessor (&OnOffApplication::m_cbrRate),
                   MakeDataRateChecker ())
    .AddAttribute ("PacketSize", "The size of packets sent in on state",
                   UintegerValue (512),
                   MakeUintegerAccessor (&OnOffApplication::m_pktSize),
                   MakeUintegerChecker<uint32_t> (1))
    .AddAttribute ("Remote", "The address of the destination",
                   AddressValue (),
                   MakeAddressAccessor (&OnOffApplication::m_peer),
                   MakeAddressChecker ())
    .AddAttribute ("OnTime", "A RandomVariable used to pick the duration of the 'On' state.",
                   RandomVariableValue (ConstantVariable (1.0)),
                   MakeRandomVariableAccessor (&OnOffApplication::m_onTime),
                   MakeRandomVariableChecker ())
    .AddAttribute ("OffTime", "A RandomVariable used to pick the duration of the 'Off' state.",
                   RandomVariableValue (ConstantVariable (1.0)),
                   MakeRandomVariableAccessor (&OnOffApplication::m_offTime),
                   MakeRandomVariableChecker ())
    .AddAttribute ("MaxBytes", 
                   "The total number of bytes to send. Once these bytes are sent, "
                   "no packet is sent again, even in on state. The value zero means "
                   "that there is no limit.",
                   UintegerValue (0),
                   MakeUintegerAccessor (&OnOffApplication::m_maxBytes),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("Protocol", "The type of protocol to use.",
                   TypeIdValue (UdpSocketFactory::GetTypeId ()),
                   MakeTypeIdAccessor (&OnOffApplication::m_tid),
                   MakeTypeIdChecker ())
    .AddTraceSource ("Tx", "A new packet is created and is sent",
                     MakeTraceSourceAccessor (&OnOffApplication::m_txTrace))
    ;
  return tid;
}



OnOffApplication::OnOffApplication ()
{
  NS_LOG_FUNCTION_NOARGS ();
  m_socket = 0;
  m_connected = false;
  m_residualBits = 0;
  m_lastStartTime = Seconds (0);
  m_totBytes = 0;
}

OnOffApplication::~OnOffApplication()
{
  NS_LOG_FUNCTION_NOARGS ();
}

void 
OnOffApplication::SetMaxBytes(uint32_t maxBytes)
{
  NS_LOG_FUNCTION (this << maxBytes);
  m_maxBytes = maxBytes;
}


void
OnOffApplication::DoDispose (void)
{
  NS_LOG_FUNCTION_NOARGS ();

  m_socket = 0;
  // chain up
  Application::DoDispose ();
}

// Application Methods
void OnOffApplication::StartApplication() // Called at time specified by Start
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

void OnOffApplication::StopApplication() // Called at time specified by Stop
{
  NS_LOG_FUNCTION_NOARGS ();

  CancelEvents ();
  if(m_socket != 0)
    {
      m_socket->Close ();
    }
  else
    {
      NS_LOG_WARN("OnOffApplication found null socket to close in StopApplication");
    }
}

void OnOffApplication::CancelEvents ()
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
void OnOffApplication::StartSending()
{
  NS_LOG_FUNCTION_NOARGS ();
  m_lastStartTime = Simulator::Now();
  ScheduleNextTx();  // Schedule the send packet event
  ScheduleStopEvent();
}

void OnOffApplication::StopSending()
{
  NS_LOG_FUNCTION_NOARGS ();
  CancelEvents();

  ScheduleStartEvent();
}
	
	void OnOffApplication::setPacketId (uint64_t val)
	{
		packetId = val;
	}
    
    std::string OnOffApplication::GetOrgClient(){
        return orgClient;
    }
    
    std::string OnOffApplication::GetOrgAp(){
        return orgAp;
    }
    
    std::string OnOffApplication::GetOrgGw(){
        return orgGw;
    }
    
    std::string OnOffApplication::GetOrgOp(){
        return orgOp;
    }
    
    void OnOffApplication::SetOrgClient(std::string s){
        orgClient = s;
    }
    
    void OnOffApplication::SetOrgAp(std::string s){
        orgAp = s;
    }
    
    void OnOffApplication::SetOrgGw(std::string s){
        orgGw = s;
    }
    
    void OnOffApplication::SetOrgOp(std::string s){
        orgOp = s;
    }
     
// Private helpers
	////
	////
	////
	////
	////
	////eger burada next timei packet interval gibi bir seye esitlersem
	////udp-echodaki packet intervalin aynisini yakalamis olurum
void OnOffApplication::ScheduleNextTx()
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
                                        &OnOffApplication::SendPacket, this);
    }
  else
    { // All done, cancel any pending events
      StopApplication();
    }
}

void OnOffApplication::ScheduleStartEvent()
{  // Schedules the event to start sending data (switch to the "On" state)
  NS_LOG_FUNCTION_NOARGS ();

  Time offInterval = Seconds(m_offTime.GetValue());
  NS_LOG_LOGIC ("start at " << offInterval);
  m_startStopEvent = Simulator::Schedule(offInterval, &OnOffApplication::StartSending, this);
}

void OnOffApplication::ScheduleStopEvent()
{  // Schedules the event to stop sending data (switch to "Off" state)
  NS_LOG_FUNCTION_NOARGS ();

  Time onInterval = Seconds(m_onTime.GetValue());
  NS_LOG_LOGIC ("stop at " << onInterval);
  m_startStopEvent = Simulator::Schedule(onInterval, &OnOffApplication::StopSending, this);
}

	
	void OnOffApplication::setDirection(std::string s)
	{
		direction = s;
	}

	void OnOffApplication::setNetType(std::string s)
	{
		netType = s;
	}
    
    void OnOffApplication::setPath(std::string s)
    {
        path = s;
    }
    
    std::string OnOffApplication::getNetworkProtocol(void){
        return networkProtocol;
    }
    
    void OnOffApplication::setNetworkProtocol(std::string val){
        networkProtocol = val;
    }
    
    void OnOffApplication::setUserRole(string val){
        userRole = val;
    }
    
    void OnOffApplication::setClientID(int i){
        clientID = i;
    }
    
    
	
void OnOffApplication::SendPacket()
{
  NS_LOG_FUNCTION_NOARGS ();
  //NS_LOG_LOGIC ("sending packet at " << Simulator::Now());
  NS_ASSERT (m_sendEvent.IsExpired ());
  Ptr<Packet> packet = Create<Packet> (m_pktSize);
	
	InetSocketAddress peerAddress = InetSocketAddress::ConvertFrom (m_peer);
	
	packet->SetUid(packetId);
    packet->SetProtocol(networkProtocol);
    packet->SetOrgClient(orgClient);
    packet->SetOrgAp(orgAp);
    packet->SetOrgGw(orgGw);
    packet->SetOrgOp(orgOp);
    
  NS_LOG_UNCOND ("Sending "<<m_pktSize<<" bytes to "<< peerAddress.GetIpv4()
	<<" from "<< m_address << " at " << Simulator::Now().GetSeconds()<< " Packet ID: "<<packet->GetUid());		
    
    if(path.size() >= 5){
        fstream input;
        ostringstream oss; oss<<m_address; string in = oss.str();
        in = path + replaceOnOff(in, ".", "_") + ".txt";
        input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
        input << orgClient << "$" << orgAp << "$" << orgGw << "$" << orgOp << "$" << packet->GetUid()
        <<"$" << Simulator::Now().GetSeconds() << "$" << packet->GetProtocol() << "$" << userRole << "$" << clientID <<endl;
        input.close();
    }

    
	/*
	//GIDIS burasi tcp wifi src example icin
	if(direction == "gidis" && netType == "wifi")
	{
		fstream input;
		ostringstream oss; oss<<m_address; string in = oss.str();
		in = "tcpExamples/clientToTTP/srcWifi/" + replaceOnOff(in, ".", "_") + ".txt";
		input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
		input << m_address << "$" << packet->GetUid()
		<<"$" << Simulator::Now().GetSeconds() << endl;
		input.close();
	}
	
	//GIDIS burasi tcp mesh src example icin
	if(direction == "gidis" && netType == "mesh")
	{
		fstream input;
		ostringstream oss; oss<<m_address; string in = oss.str();
		in = "tcpExamples/clientToTTP/srcMesh/" + replaceOnOff(in, ".", "_") + ".txt";
		input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
		input << m_address << "$" << packet->GetUid()
		<<"$" << Simulator::Now().GetSeconds() << endl;
		input.close();
	}
	
	//GIDIS burasi tcpCsma icin
	if(direction == "gidis" && netType == "csma")
	{
		fstream input;
		ostringstream oss; oss<<m_address; string in = oss.str();
		in = "tcpExamples/clientToTTP/srcCsma/" + replaceOnOff(in, ".", "_") + ".txt";
		input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
		input << m_address << "$" << packet->GetUid()
		<<"$" << Simulator::Now().GetSeconds() << endl;
		input.close();
	}
	
	
	
	//GELIS burasi tcpCsma icin
	if(direction == "gelis" && netType == "csma")
	{
		fstream input;
		ostringstream oss; oss<<m_address; string in = oss.str();
		in = "tcpExamples/TTPToClient/srcCsma/" + replaceOnOff(in, ".", "_") + ".txt";
		input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
		input << m_address << "$" << packet->GetUid()
		<<"$" << Simulator::Now().GetSeconds() << endl;
		input.close();
	}
	
	//GELIS burasi tcpMesh icin
	if(direction == "gelis" && netType == "mesh")
	{
		fstream input;
		ostringstream oss; oss<<m_address; string in = oss.str();
		in = "tcpExamples/TTPToClient/srcMesh/" + replaceOnOff(in, ".", "_") + ".txt";
		input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
		input << m_address << "$" << packet->GetUid()
		<<"$" << Simulator::Now().GetSeconds() << endl;
		input.close();
	}
	
	//GELIS burasi tcpWifi icin
	if(direction == "gelis" && netType == "wifi")
	{
		fstream input;
		ostringstream oss; oss<<m_address; string in = oss.str();
		in = "tcpExamples/TTPToClient/srcWifi/" + replaceOnOff(in, ".", "_") + ".txt";
		input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
		input << m_address << "$" << packet->GetUid()
		<<"$" << Simulator::Now().GetSeconds() << endl;
		input.close();
	}
	*/
    
    
    
	//burasi wifitcp icin
	/*fstream input;
	ostringstream oss;
	oss<<m_address;
	string in = oss.str();
	in = "z_sta/" + replaceOnOff(in, ".", "_") + ".txt";
	input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
	input << m_address << "$" << peerAddress.GetIpv4() << "$" << packet->GetUid()
	<<"$" << Simulator::Now().GetSeconds() << endl;
	input.close();*/		
	//burasi meshtcp icin
	/*fstream input;
	ostringstream oss;
	oss<<m_address;
	string in = oss.str();
	in = "z_mesh/" + replaceOnOff(in, ".", "_") + "sta.txt";
	input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
	input << m_address << "$" << peerAddress.GetIpv4() << "$" << packet->GetUid()
	<<"$" << Simulator::Now().GetSeconds() << endl;
	input.close();*/
	//burasi csmatcp icin
	/*fstream input;
	input.open("z_csma/client.txt", fstream::in | fstream::out | fstream::app);
	input << m_address << "$" << peerAddress.GetIpv4() << "$" << packet->GetUid()
	<<"$" << Simulator::Now().GetSeconds() << endl;
	input.close();*/
	
	
  m_txTrace (packet);
  m_socket->Send (packet);
  m_totBytes += m_pktSize;
  m_lastStartTime = Simulator::Now();
  m_residualBits = 0;
  ScheduleNextTx();
}

void OnOffApplication::ConnectionSucceeded(Ptr<Socket>)
{
  NS_LOG_FUNCTION_NOARGS ();

  m_connected = true;
  ScheduleStartEvent();
}
  
void OnOffApplication::ConnectionFailed(Ptr<Socket>)
{
  NS_LOG_FUNCTION_NOARGS ();
  cout << "OnOffApplication, Connection Failed" << endl;
}
	
void OnOffApplication::setAddr(Ipv4Address addr)
{
	m_address = addr;
}
	
string replaceOnOff( string source, const string find, string replace ) 
{	
	size_t j;
	for ( ; (j = source.find( find )) != string::npos ; ) {
		source.replace( j, find.length(), replace );
	}
	return source;
}

} // Namespace ns3
