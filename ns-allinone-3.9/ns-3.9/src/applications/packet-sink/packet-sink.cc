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
 *
 * Author:  Tom Henderson (tomhend@u.washington.edu)
 */
#include "ns3/address.h"
#include "ns3/address-utils.h"
#include "ns3/log.h"
#include "ns3/inet-socket-address.h"
#include "ns3/node.h"
#include "ns3/socket.h"
#include "ns3/udp-socket.h"
#include "ns3/simulator.h"
#include "ns3/socket-factory.h"
#include "ns3/packet.h"
#include "ns3/trace-source-accessor.h"
#include "ns3/udp-socket-factory.h"
#include "packet-sink.h"
#include "ns3/cipher.h"
#include "ns3/Sha-256.h"

#include <fstream>

using namespace std;

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("PacketSink");
NS_OBJECT_ENSURE_REGISTERED (PacketSink);
	
string replaceSink( string source, const string find, string replace ); 

TypeId 
PacketSink::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::PacketSink")
    .SetParent<Application> ()
    .AddConstructor<PacketSink> ()
    .AddAttribute ("Local", "The Address on which to Bind the rx socket.",
                   AddressValue (),
                   MakeAddressAccessor (&PacketSink::m_local),
                   MakeAddressChecker ())
    .AddAttribute ("Protocol", "The type id of the protocol to use for the rx socket.",
                   TypeIdValue (UdpSocketFactory::GetTypeId ()),
                   MakeTypeIdAccessor (&PacketSink::m_tid),
                   MakeTypeIdChecker ())
    .AddTraceSource ("Rx", "A packet has been received",
                     MakeTraceSourceAccessor (&PacketSink::m_rxTrace))
    ;
  return tid;
}

PacketSink::PacketSink ()
{
  NS_LOG_FUNCTION (this);
  m_socket = 0;
  m_totalRx = 0;
}

PacketSink::~PacketSink()
{
  NS_LOG_FUNCTION (this);
}

uint32_t PacketSink::GetTotalRx() const
{
  return m_totalRx;
}
  
void PacketSink::DoDispose (void)
{
  NS_LOG_FUNCTION (this);
  m_socket = 0;
  m_socketList.clear ();

  // chain up
  Application::DoDispose ();
}


// Application Methods
void PacketSink::StartApplication()    // Called at time specified by Start
{
  NS_LOG_FUNCTION (this);
  // Create the socket if not already
  if (!m_socket)
    {
      m_socket = Socket::CreateSocket (GetNode(), m_tid);
      m_socket->Bind (m_local);
      m_socket->Listen ();
      m_socket->ShutdownSend ();
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

  m_socket->SetRecvCallback (MakeCallback(&PacketSink::HandleRead, this));
  m_socket->SetAcceptCallback (
            MakeNullCallback<bool, Ptr<Socket>, const Address &> (),
            MakeCallback(&PacketSink::HandleAccept, this));
  m_socket->SetCloseCallbacks (
            MakeCallback(&PacketSink::HandlePeerClose, this),
            MakeCallback(&PacketSink::HandlePeerError, this));
}

void PacketSink::StopApplication()     // Called at time specified by Stop
{
  NS_LOG_FUNCTION (this);
  while(!m_socketList.empty()) //these are accepted sockets, close them
  {
    Ptr<Socket> acceptedSocket = m_socketList.front();
    m_socketList.pop_front();
    acceptedSocket->Close();
  }
  if (m_socket) 
    {
      m_socket->Close ();
      m_socket->SetRecvCallback (MakeNullCallback<void, Ptr<Socket> > ());
    }
}

void PacketSink::HandleRead (Ptr<Socket> socket)
{
  NS_LOG_FUNCTION (this << socket);
  Ptr<Packet> packet;
  Address from;
  while (packet = socket->RecvFrom (from))
    {
      if (packet->GetSize() == 0)
        { //EOF
	  break;
        }
      if (InetSocketAddress::IsMatchingType (from))
        {
          InetSocketAddress address = InetSocketAddress::ConvertFrom (from);
          m_totalRx += packet->GetSize();
          /*NS_LOG_UNCOND ("Received " << packet->GetSize() << " bytes from " << 
                       address.GetIpv4() << " [" << address << "]" 
                       << " total Rx " << m_totalRx);*/
			
			NS_LOG_UNCOND("Received " << packet->GetSize() << " bytes from " << 
			address.GetIpv4()<<" at "<<Simulator::Now().GetSeconds() <<" Packet ID: "<<packet->GetUid()<<" (<-"<< packet->GetProtocol()<<")");
			
            if(path.size() >= 5){
                fstream input; ostringstream oss; oss<<m_address;
                
                string orgClient = packet->GetOrgClient();
                string orgAp = packet->GetOrgAp();
                string orgGw = packet->GetOrgGw();
                string orgOp = packet->GetOrgOp();
                
                string in = oss.str();
                in = path + replaceSink(in, ".", "_") + ".txt";

                input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
                input << orgClient << "$" << orgAp << "$" << orgGw << "$" << orgOp << "$" << packet->GetUid()
                << "$" << Simulator::Now().GetSeconds() << "$" << packet->GetProtocol() <<endl;
                input.close();
            }
			
            /*
			//GIDIS burasi tcpwifi icin
			if(direction == "gidis" && netType == "wifi")
			{
				fstream input; ostringstream oss; oss<<m_address;
				string in = oss.str();
				in = "tcpExamples/clientToTTP/destWifi/" + replaceSink(in, ".", "_") + ".txt";
				input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
				input << m_address << "$" << address.GetIpv4() << "$" << packet->GetUid()
				<< "$" << Simulator::Now().GetSeconds() << endl;
				input.close();
			}
			
			//GIDIS burasi tcpMesh icin
			if(direction == "gidis" && netType == "mesh")
			{
				fstream input; ostringstream oss; oss<<m_address;
				string in = oss.str();
				in = "tcpExamples/clientToTTP/destMesh/" + replaceSink(in, ".", "_") + ".txt";
				input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
				input << m_address << "$" << address.GetIpv4() << "$" << packet->GetUid()
				<< "$" << Simulator::Now().GetSeconds() << endl;
				input.close();
			}
			
			//GIDIS burasi tcpcsma icin
			if(direction == "gidis" && netType == "csma")
			{
				fstream input; ostringstream oss; oss<<m_address;
				string in = oss.str();
				in = "tcpExamples/clientToTTP/destCsma/" + replaceSink(in, ".", "_") + ".txt";
				input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
				input << m_address << "$" << address.GetIpv4() << "$" << packet->GetUid()
				<< "$" << Simulator::Now().GetSeconds() << endl;
				input.close();
			}
			
			
			
			
			
			
			//GELIS burasi tcpcsma icin
			
			if(direction == "gelis" && netType == "csma")
			{
				fstream input; ostringstream oss; oss<<m_address;
				string in = oss.str();
				in = "tcpExamples/TTPToClient/destCsma/" + replaceSink(in, ".", "_") + ".txt";
				input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
				input << m_address << "$" << address.GetIpv4() << "$" << packet->GetUid()
				<< "$" << Simulator::Now().GetSeconds() << endl;
				input.close();
			}
			
			//GELIS burasi tcpMesh icin
			if(direction == "gelis" && netType == "mesh")
			{
				fstream input; ostringstream oss; oss<<m_address;
				string in = oss.str();
				in = "tcpExamples/TTPToClient/destMesh/" + replaceSink(in, ".", "_") + ".txt";
				input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
				input << m_address << "$" << address.GetIpv4() << "$" << packet->GetUid()
				<< "$" << Simulator::Now().GetSeconds() << endl;
				input.close();
			}
			
			//GELIS burasi tcpWifi icin
			if(direction == "gelis" && netType == "wifi")
			{
				fstream input; ostringstream oss; oss<<m_address;
				string in = oss.str();
				in = "tcpExamples/TTPToClient/destWifi/" + replaceSink(in, ".", "_") + ".txt";
				input.open(in.c_str(), fstream::in | fstream::out | fstream::app);
				input << m_address << "$" << address.GetIpv4() << "$" << packet->GetUid()
				<< "$" << Simulator::Now().GetSeconds() << endl;
				input.close();
			}
             */
             
        }    
      m_rxTrace (packet, from);
    }
}

void PacketSink::HandlePeerClose (Ptr<Socket> socket)
{
  NS_LOG_INFO("PktSink, peerClose");
}
 
void PacketSink::HandlePeerError (Ptr<Socket> socket)
{
  NS_LOG_INFO("PktSink, peerError");
}
 

void PacketSink::HandleAccept (Ptr<Socket> s, const Address& from)
{
  NS_LOG_FUNCTION (this << s << from);
  s->SetRecvCallback (MakeCallback(&PacketSink::HandleRead, this));
  m_socketList.push_back (s);
}
	
void PacketSink::setAddr(Ipv4Address addr)
{
	m_address = addr;
}
	
void PacketSink::setDirection(std::string s)
{
	direction = s;
}	

void PacketSink::setNetType(std::string s)
{
	netType = s;
}
    
void PacketSink::setPath(string s)
{
    path = s;
}
    
    void PacketSink::setUserRole(string s)
    {
        userRole = s;
    }
    
    void PacketSink::setClientID(int i)
    {
        clientID = i;
    }
	
string replaceSink( string source, const string find, string replace ) 
{	
	size_t j;
	for ( ; (j = source.find( find )) != string::npos ; ) {
		source.replace( j, find.length(), replace );
	}
	return source;
}

} // Namespace ns3
