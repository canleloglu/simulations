/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright 2007 University of Washington
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include "ns3/log.h"
#include "ns3/ipv4-address.h"
#include "ns3/nstime.h"
#include "ns3/inet-socket-address.h"
#include "ns3/socket.h"
#include "ns3/simulator.h"
#include "ns3/socket-factory.h"
#include "ns3/packet.h"
#include "ns3/uinteger.h"
#include "ns3/trace-source-accessor.h"
#include "udp-echo-client.h"
#include "ns3/randgen.h"
#include <stdio.h>
#include "ns3/Hash.h"
#include "ns3/SHA-256.h"
#include "ns3/cipher.h"
#include <fstream>
namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("UdpEchoClientApplication");
NS_OBJECT_ENSURE_REGISTERED (UdpEchoClient);
	
TypeId
UdpEchoClient::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::UdpEchoClient")
    .SetParent<Application> ()
    .AddConstructor<UdpEchoClient> ()
    .AddAttribute ("MaxPackets", 
                   "The maximum number of packets the application will send",
                   UintegerValue (100),
                   MakeUintegerAccessor (&UdpEchoClient::m_count),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("Interval", 
                   "The time to wait between packets",
                   TimeValue (Seconds (1.0)),
                   MakeTimeAccessor (&UdpEchoClient::m_interval),
                   MakeTimeChecker ())
    .AddAttribute ("RemoteAddress", 
                   "The destination Ipv4Address of the outbound packets",
                   Ipv4AddressValue (),
                   MakeIpv4AddressAccessor (&UdpEchoClient::m_peerAddress),
                   MakeIpv4AddressChecker ())
    .AddAttribute ("RemotePort", 
                   "The destination port of the outbound packets",
                   UintegerValue (0),
                   MakeUintegerAccessor (&UdpEchoClient::m_peerPort),
                   MakeUintegerChecker<uint16_t> ())
    .AddAttribute ("PacketSize", "Size of echo data in outbound packets",
                   UintegerValue (100),
                   MakeUintegerAccessor (&UdpEchoClient::SetDataSize,
                                         &UdpEchoClient::GetDataSize),
                   MakeUintegerChecker<uint32_t> ())
    .AddTraceSource ("Tx", "A new packet is created and is sent",
                     MakeTraceSourceAccessor (&UdpEchoClient::m_txTrace))
    ;
  return tid;
}

UdpEchoClient::UdpEchoClient ()
{
  NS_LOG_FUNCTION_NOARGS ();
  m_sent = 0;
  m_socket = 0;
  m_sendEvent = EventId ();
  m_data = 0;
  m_dataSize = 0;
  m_nonce = 0;
	m_hashCount = 100;
	m_key = "";
}
	UdpEchoClient::UdpEchoClient (std::string param)
	{
		NS_LOG_FUNCTION_NOARGS ();
		m_sent = 0;
		m_socket = 0;
		m_sendEvent = EventId ();
		m_data = 0;
		m_dataSize = 0;
		m_nonce = 0;

		m_key = "";
		m_addr = param;
		
	}
UdpEchoClient::~UdpEchoClient()
{
  NS_LOG_FUNCTION_NOARGS ();
  m_socket = 0;

  delete [] m_data;
  m_data = 0;
  m_dataSize = 0;
}
	
	void
	UdpEchoClient::SetKey(std::string k)
	{
		m_key = k;
	}
	
	void
	UdpEchoClient::SetAddr(std::string addr)
	{
		m_addr = addr;
	}
	
	std::string
	UdpEchoClient::GetKey()
	{
		return m_key;
	}

void 
UdpEchoClient::SetRemote (Ipv4Address ip, uint16_t port)
{
  m_peerAddress = ip;
  m_peerPort = port;
}

void
UdpEchoClient::DoDispose (void)
{
  NS_LOG_FUNCTION_NOARGS ();
  Application::DoDispose ();
}

void 
UdpEchoClient::StartApplication (void)
{
  NS_LOG_FUNCTION_NOARGS ();

  if (m_socket == 0)
    {
      TypeId tid = TypeId::LookupByName ("ns3::UdpSocketFactory");
      m_socket = Socket::CreateSocket (GetNode(), tid);
      m_socket->Bind ();
      m_socket->Connect (InetSocketAddress (m_peerAddress, m_peerPort));
    }

  m_socket->SetRecvCallback(MakeCallback(&UdpEchoClient::HandleRead, this));

  ScheduleTransmit (Seconds(1));
}

void 
UdpEchoClient::StopApplication ()
{
  NS_LOG_FUNCTION_NOARGS ();
  if (m_socket != 0) 
    {
      m_socket->Close ();
      m_socket->SetRecvCallback(MakeNullCallback<void, Ptr<Socket> > ());
      m_socket = 0;
    }

  Simulator::Cancel(m_sendEvent);
}

void 
UdpEchoClient::SetDataSize (uint32_t dataSize)
{
  NS_LOG_FUNCTION (dataSize);

  //
  // If the client is setting the echo packet data size this way, we infer
  // that she doesn't care about the contents of the packet at all, so 
  // neither will we.
  //
  delete [] m_data;
  m_data = 0;
  m_dataSize = 0;
  m_size = dataSize;
}

uint32_t 
UdpEchoClient::GetDataSize (void) const
{
  NS_LOG_FUNCTION_NOARGS ();
  return m_size;
}
	
	

void 
UdpEchoClient::SetFill (std::string fill)
{
	
  NS_LOG_FUNCTION (fill);

  uint32_t dataSize = fill.size () + 1;

  if (dataSize != m_dataSize)
    {
      delete [] m_data;
      m_data = new uint8_t [dataSize];
      m_dataSize = dataSize;
    }

  memcpy (m_data, fill.c_str (), dataSize);

  //
  // Overwrite packet size attribute.
  //
  m_size = dataSize;
}
	
std::string itoa(int value, int base)
{
	std::string buf = "";
	int i = 30;
		
	buf = "";
		
	for(; value && i ; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;
	return buf;
}
	
//Nonce ekledigim SetFill
void 
UdpEchoClient::SetFill (std::string fill, int nonce)
{
	m_nonce = nonce;
	std::string nonce_str = itoa(nonce,10);
	NS_LOG_FUNCTION (fill);
	
	uint32_t dataSize = fill.size () + 1;
		
	if (dataSize != m_dataSize)
	{
		delete [] m_data;
		m_data = new uint8_t [dataSize];
		m_dataSize = dataSize;
	}
		
	memcpy (m_data, fill.c_str (), dataSize);
		
		//
		// Overwrite packet size attribute.
		//
	m_size = dataSize;
}

void 
UdpEchoClient::SetFill (uint8_t fill, uint32_t dataSize)
{
  if (dataSize != m_dataSize)
    {
      delete [] m_data;
      m_data = new uint8_t [dataSize];
      m_dataSize = dataSize;
    }

  memset (m_data, fill, dataSize);

  //
  // Overwrite packet size attribute.
  //
  m_size = dataSize;
}

void 
UdpEchoClient::SetFill (uint8_t *fill, uint32_t fillSize, uint32_t dataSize)
{
  if (dataSize != m_dataSize)
    {
      delete [] m_data;
      m_data = new uint8_t [dataSize];
      m_dataSize = dataSize;
    }

  if (fillSize >= dataSize)
    {
      memcpy (m_data, fill, dataSize);
      return;
    }

  //
  // Do all but the final fill.
  //
  uint32_t filled = 0;
  while (filled + fillSize < dataSize)
    {
      memcpy (&m_data[filled], fill, fillSize);
      filled += fillSize;
    }

  //
  // Last fill may be partial
  //
  memcpy(&m_data[filled], fill, dataSize - filled);

  //
  // Overwrite packet size attribute.
  //
  m_size = dataSize;
}

void 
UdpEchoClient::ScheduleTransmit (Time dt)
{
  NS_LOG_FUNCTION_NOARGS ();
  m_sendEvent = Simulator::Schedule(dt, &UdpEchoClient::Send, this);
}

void 
UdpEchoClient::Send (void)
{
	
  NS_LOG_FUNCTION_NOARGS ();

  NS_ASSERT (m_sendEvent.IsExpired ());

  Ptr<Packet> p;
  if (m_dataSize)
    {
      //
      // If m_dataSize is non-zero, we have a data buffer of the same size that we
      // are expected to copy and send.  This state of affairs is created if one of
      // the Fill functions is called.  In this case, m_size must have been set
      // to agree with m_dataSize
      //
      NS_ASSERT_MSG (m_dataSize == m_size, "UdpEchoClient::Send(): m_size and m_dataSize inconsistent");
      NS_ASSERT_MSG (m_data, "UdpEchoClient::Send(): m_dataSize but no m_data");
      p = Create<Packet> (m_data, m_dataSize);
    }
  else
    {
      //
      // If m_dataSize is zero, the client has indicated that she doesn't care 
      // about the data itself either by specifying the data size by setting
      // the corresponding atribute or by not calling a SetFill function.  In 
      // this case, we don't worry about it either.  But we do allow m_size
      // to have a value different from the (zero) m_dataSize.
      //
      p = Create<Packet> (m_size);
    }
  // call to the trace sinks before the packet is actually sent,
  // so that tags added to the packet can be sent as well
  m_txTrace (p);
  m_socket->Send (p);

  ++m_sent;

  NS_LOG_INFO ("Sent " << m_size << " bytes to " << m_peerAddress<<" at "<<Simulator::Now ().GetSeconds()<<" Packet ID is: "<<p->GetUid());

  if (m_sent < m_count)
    {
      ScheduleTransmit (m_interval);
    }
}
	
	
	
	
	int
	UdpEchoClient::GetCount()
	{
		return m_hashCount;
	}

void
UdpEchoClient::HandleRead (Ptr<Socket> socket)
{
	
	if(m_key == "")
	{

		NS_LOG_FUNCTION (this << socket);
		Ptr<Packet> packet;
		Address from;
		while (packet = socket->RecvFrom (from))
		{
			if (InetSocketAddress::IsMatchingType (from))
			{
				InetSocketAddress address = InetSocketAddress::ConvertFrom (from);
				NS_LOG_INFO ("Client received " << packet->GetSize() << " bytes from " <<
				  address.GetIpv4()<<" at "<<Simulator::Now ().GetSeconds()<<" Packet ID is: "<<packet->GetUid());
				printf("\n\n\n");
				m_hashCount--;
			}
			
        }
    }
	else {
		
		cipher ciph;
		
		NS_LOG_FUNCTION (this << socket);
		Ptr<Packet> packet;
		Address from;
		
		while (packet = socket->RecvFrom (from))
		{
			ciph.init(m_key);
			uint8_t* buf = new uint8_t[64];
			packet->CopyData(buf,64);
			if (InetSocketAddress::IsMatchingType (from))
			{
				std::string received_str = reinterpret_cast<const char*> (buf);
				std::string decrypted_str = ciph.decrypt(received_str);
				
				std::cout << "Client received: "<<received_str<<std::endl;
				
				int index = decrypted_str.size();
				std::string nonce_comp = decrypted_str.substr(index-9);
				std::string payload = decrypted_str.substr(0,index-9); 
				
				std::cout<<"Nonce: "<<nonce_comp<<std::endl;
				std::cout<<"New key is: "<<payload<<std::endl;
				m_hashCount--;
				m_key = payload;
				
				InetSocketAddress address = InetSocketAddress::ConvertFrom (from);
				NS_LOG_INFO ("Received " << packet->GetSize() << " bytes from " <<
				  address.GetIpv4()<<" at "<<Simulator::Now ().GetSeconds()<<" Packet ID is: "<<packet->GetUid());
				
			}
			
        }
	}

}

} // Namespace ns3