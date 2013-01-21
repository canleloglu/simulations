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
#include "ns3/address-utils.h"
#include "ns3/nstime.h"
#include "ns3/inet-socket-address.h"
#include "ns3/socket.h"
#include "ns3/udp-socket.h"
#include "ns3/simulator.h"
#include "ns3/socket-factory.h"
#include "ns3/packet.h"
#include "ns3/uinteger.h"
#include <fstream>
#include <string>
#include <iostream>
#include "udp-echo-server.h"
#include "ns3/cipher.h"
#include "ns3/SHA-256.h"
#include <stdio.h>


namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("UdpEchoServerApplication");
NS_OBJECT_ENSURE_REGISTERED (UdpEchoServer);

TypeId
UdpEchoServer::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::UdpEchoServer")
    .SetParent<Application> ()
    .AddConstructor<UdpEchoServer> ()
    .AddAttribute ("Port", "Port on which we listen for incoming packets.",
                   UintegerValue (9),
                   MakeUintegerAccessor (&UdpEchoServer::m_port),
                   MakeUintegerChecker<uint16_t> ())
    ;
  return tid;
}

UdpEchoServer::UdpEchoServer ()
{
  NS_LOG_FUNCTION_NOARGS ();
	m_key = "";
	hashCount = new int[10];
	for(int i = 0; i<10; i++)
	{
		hashCount[i] = 1;
	}
}

UdpEchoServer::~UdpEchoServer()
{
  NS_LOG_FUNCTION_NOARGS ();
  m_socket = 0;
}

void
UdpEchoServer::DoDispose (void)
{
  NS_LOG_FUNCTION_NOARGS ();
  Application::DoDispose ();
}
	
	void
	UdpEchoServer::SetKey(std::string k)
	{
		m_key = k;
	}
	
	std::string
	UdpEchoServer::GetKey()
	{
		return m_key;
	}
	

void 
UdpEchoServer::StartApplication (void)
{
  NS_LOG_FUNCTION_NOARGS ();

  if (m_socket == 0)
    {
      TypeId tid = TypeId::LookupByName ("ns3::UdpSocketFactory");
      m_socket = Socket::CreateSocket (GetNode(), tid);
      InetSocketAddress local = InetSocketAddress (Ipv4Address::GetAny (), m_port);
      m_socket->Bind (local);
      if (addressUtils::IsMulticast (m_local))
        {
          Ptr<UdpSocket> udpSocket = DynamicCast<UdpSocket> (m_socket);
          if (udpSocket)
            {
              // equivalent to setsockopt (MCAST_JOIN_GROUP)
              udpSocket->MulticastJoinGroup (0, m_local);
            }
          else
            {
              NS_FATAL_ERROR ("Error: joining multicast on a non-UDP socket");
            }
        }
    }
  m_socket->SetRecvCallback(MakeCallback(&UdpEchoServer::HandleRead, this));
}

void 
UdpEchoServer::StopApplication ()
{
  NS_LOG_FUNCTION_NOARGS ();

  if (m_socket != 0) 
    {
      m_socket->Close ();
      m_socket->SetRecvCallback(MakeNullCallback<void, Ptr<Socket> > ());
    }
}
	
Ptr<Packet>
UdpEchoServer::GetReceivedPacket(void)
{
	return m_packet->Copy();
}
	
std::string my_itoa(int value, int base)
{
	std::string buf = "";
	int i = 30;
		
	buf = "";
		
	for(; value && i ; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;
	return buf;
		
}

std::string
	server_GetKey(std::string addr, std::string& n_key)
{
	CSHA256 sha;
	ifstream clientText;
	std::string clientTextUrl = "output_server/" + addr + ".txt";
	clientText.open(clientTextUrl.c_str());
	std::string line = "";
	int count = 0;
	getline(clientText,line);
	std::cout<<"Server seed: "<< line  <<std::endl;
	std::string seed = line;
	getline(clientText, line);
	std::string currentKey = line;
	
	std::string temp = seed;
	for(int i = 1; i<=100; i++)
	{
		temp = sha.CalculateHash(temp.c_str());
		temp = temp.substr(0,32);
		if(temp == currentKey)
		{
			count = i;
			break;
		}
		n_key = temp;
	}
	
	

	clientText.close();
	if(count >= 97)
	{
	ofstream out;
	std::string outTextUrl = "output_server/" + addr + ".txt";
	out.open(outTextUrl.c_str());
	out<<seed<<std::endl;
	out<<n_key;
	out.close();
	}
	return currentKey;
}

void 
UdpEchoServer::sendBack(Ptr<Socket> soc, Address from, Ptr<Packet> packet)
{
	//soc -> SendTo(packet, 0, from);
	std::ostringstream str;
	str << Simulator::Now().GetSeconds();
	std::cout<<"Fonksiyona girme zamani: "<<str.str()<<"\n\n";
}
	
void 
UdpEchoServer::HandleRead (Ptr<Socket> socket)
{
  std::ofstream output;
  Ptr<Packet> packet;
  Address from;
  while (packet = socket->RecvFrom (from))
    {
		/*if(m_key == "")
		{
			if (InetSocketAddress::IsMatchingType (from))
			{
				InetSocketAddress address = InetSocketAddress::ConvertFrom (from);

				NS_LOG_INFO ("Received " << packet->GetSize() << " bytes from " << 
							 address.GetIpv4()<<" at "<<Simulator::Now ().GetSeconds()<<" Packet ID: "<<packet->GetUid());
				packet->RemoveAllPacketTags ();
				packet->RemoveAllByteTags ();
				NS_LOG_LOGIC ("Echoing packet");
				socket->SendTo (packet, 0, from);
			}
		}
		else
		{*/

			if (InetSocketAddress::IsMatchingType (from))
			{
				InetSocketAddress address = InetSocketAddress::ConvertFrom (from);
				Ipv4Address remote = address.GetIpv4();
				std::string addr = my_itoa(remote.Get(),10);
				std::string n_key;
				std::string key = server_GetKey(addr, n_key);
				std::cout<<"Server currentkey: " << key  <<std::endl;
				std::cout<<"New key is: "<<n_key<<std::endl;
				cipher ciph;
				ciph.init(key);
				uint8_t* buf = new uint8_t[2000];
				packet->CopyData(buf, 2000);
				std::string ciphertext = reinterpret_cast<const char*> (buf);
				std::string plaintext = ciph.decrypt(ciphertext);
				
				
				std::cout<<"Server decrypted the message: "<<plaintext<<std::endl;
				
				
				
				NS_LOG_INFO ("Server received " << packet->GetSize() << " bytes from " << 
							 address.GetIpv4()<<" at "<<Simulator::Now ().GetSeconds()<<" Packet ID: "<<packet->GetUid());
				packet->RemoveAllPacketTags ();
				packet->RemoveAllByteTags ();
				
				NS_LOG_LOGIC ("Echoing packet");
				//socket->SendTo (packet, 0, from);
				
				void (UdpEchoServer::*fp)(Ptr<Socket>, Address, Ptr<Packet>) = &UdpEchoServer::sendBack;
				Simulator::Schedule(Seconds(2.0), fp, this, socket, from, packet);
				//sendBack(socket, from, packet);
				

			}
		//}
    }
}

} // Namespace ns3
