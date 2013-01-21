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

using namespace std;
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
	soc -> SendTo(packet, 0, from);
}
	
	
	
	void UdpEchoServer::setIpv4Addr(Ipv4Address ad)
	{
		m_address = ad;
	}
	
	
	
string replace( string source, const string find, string replace ) {
	
	size_t j;
	for ( ; (j = source.find( find )) != string::npos ; ) {
		source.replace( j, find.length(), replace );
	}
	return source;
}
	
void UdpEchoServer::setDelay(Time t)
{
	delay = t;
}
	
	struct sad {
		string ad;
		int count;
	};
	
	vector<sad> vec;
	
	int findVecIndex(vector<sad> v, string ad)
	{		
		for (int i = 0; i < v.size(); i++) {
			//cout << "gelen adress: " << ad << " vectordeki adres: " << v[i].ad << endl;
			if (v[i].ad == ad) {
				return i;
			}
		}
		return -1;
	}
	
uint32_t *temp = 0;
	
void 
UdpEchoServer::HandleRead (Ptr<Socket> socket)
{
  std::ofstream output;
  Ptr<Packet> packet;
  Address from;
  while (packet = socket->RecvFrom (from))
    {

		if (InetSocketAddress::IsMatchingType (from))
		{
			InetSocketAddress address = InetSocketAddress::ConvertFrom (from);
			Ipv4Address remote = address.GetIpv4();
			
			uint8_t* buf = new uint8_t[1024];
			packet->CopyData(buf, 1024);		
			
			ostringstream oss;
			oss<<m_address;
			string mAdress = oss.str();
			
			/*fstream input;
			input.open ("csmaFinalNode.txt", fstream::in | fstream::out | fstream::app);
			
			ostringstream oss;
			oss <<m_local<<"$"<<address.GetIpv4()<<"$"<<m_local<<"$"
				<<packet<<"$"<<Simulator::Now().GetSeconds();
			input<<oss.str()<<endl;
			input.close();*/		
			
			NS_LOG_INFO ("Server received " << packet->GetSize() << " bytes from " << 
						 address.GetIpv4()<<" at "<<Simulator::Now ().GetSeconds()<<" Packet ID: "<<packet->GetUid());
			packet->RemoveAllPacketTags ();
			packet->RemoveAllByteTags ();
			
			//burada server txt hazirliyoruz
			//burasi third2 icin
			/*
			fstream input;
			ostringstream o;
			o<<m_address;
			string in = replace(o.str(), ".", "_");
			in += "ap.txt";
			in = "a_ap/" + in;
			input.open (in.c_str(), fstream::in | fstream::out | fstream::app);
			
			ostringstream oss;
			oss <<m_address<<"$"<<address.GetIpv4()<<"$"<<m_address<<"$"
			<<packet<<"$"<<Simulator::Now().GetSeconds();
			input<<oss.str()<<endl;
			input.close();
			*/
			 
			 
			//burasi mesh3 icin
			/*fstream input;
			input.open ("a_mesh/gateway.txt", fstream::in | fstream::out | fstream::app);
			
			ostringstream oss;
			oss <<m_address<<"$"<<address.GetIpv4()<<"$"<<m_address<<"$"
			<<packet<<"$"<<Simulator::Now().GetSeconds();
			input<<oss.str()<<endl;
			input.close();*/
			
			
			
			//burasi csma icin
			/*fstream input;
			input.open ("a_csma/server.txt", fstream::in | fstream::out | fstream::app);
			
			ostringstream oss;
			oss <<m_address<<"$"<<address.GetIpv4()<<"$"<<m_address<<"$"
			<<packet<<"$"<<Simulator::Now().GetSeconds();
			input<<oss.str()<<endl;
			input.close();*/
			
			
			
			//burasi meshtcp icin
			/*fstream input;
			input.open ("z_mesh/gateway.txt", fstream::in | fstream::out | fstream::app);
			
			ostringstream oss;
			oss <<m_address<<"$"<<address.GetIpv4()<<"$"<<m_address<<"$"
			<<packet<<"$"<<Simulator::Now().GetSeconds();
			input<<oss.str()<<endl;
			input.close();*/
			
			
			//burasi chartlar icin olan
			/*fstream input;
			input.open ("z_mesh/forchartServer.txt", fstream::in | fstream::out | fstream::app);
			input<<m_address<<"$"<<address.GetIpv4()<<"$"<<packet->GetUid()
				<<"$"<<Simulator::Now().GetSeconds()<<endl;
			input.close();*/
			
			//for wifi charts
			/*fstream input;
			input.open ("z_chart/wifiServer.txt", fstream::in | fstream::out | fstream::app);
			input<<m_address<<"$"<<address.GetIpv4()<<"$"<<packet->GetUid()
			<<"$"<<Simulator::Now().GetSeconds()<<endl;
			input.close();*/
				
			//for mesh charts
			/*fstream input;
			input.open ("z_chart/meshServer.txt", fstream::in | fstream::out | fstream::app);
			input<<m_address<<"$"<<address.GetIpv4()<<"$"<<packet->GetUid()
			<<"$"<<Simulator::Now().GetSeconds()<<endl;
			input.close();*/
			
			//for csma charts
			/*fstream input;
			input.open ("z_chart/csmaServer.txt", fstream::in | fstream::out | fstream::app);
			input<<m_address<<"$"<<address.GetIpv4()<<"$"<<packet->GetUid()
			<<"$"<<Simulator::Now().GetSeconds()<<endl;
			input.close();*/
			
			
			//NS_LOG_LOGIC ("Echoing packet");
			//socket->SendTo (packet, 0, from);
			
			//to add delay IMPORTANT
			int tempNum = findVecIndex(vec, mAdress);
			if (tempNum == -1) {
				//cout << "0 oldu: " << fromAddress << endl;
				void (UdpEchoServer::*fp)(Ptr<Socket>, Address, Ptr<Packet>) = &UdpEchoServer::sendBack;
				Simulator::Schedule(delay, fp, this, socket, from, packet);
				sad temps;
				temps.ad = mAdress;
				temps.count = 1;
				vec.push_back(temps);
			}
			else{
				//cout << "1 oldu: " << vec[tempNum].count << endl;
				if(vec[tempNum].count < 1)
				{
					void (UdpEchoServer::*fp)(Ptr<Socket>, Address, Ptr<Packet>) = &UdpEchoServer::sendBack;
					Simulator::Schedule(delay, fp, this, socket, from, packet);
					sad temps;
					temps.ad = mAdress;
					temps.count = vec[tempNum].count + 1;
					vec[tempNum] = temps;
				}
			}
			
			//socket -> SendTo(packet, 0, from);
		}
		
    }
}
	


} // Namespace ns3
