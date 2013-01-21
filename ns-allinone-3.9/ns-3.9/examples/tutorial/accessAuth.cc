/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
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

#include "ns3/core-module.h"
#include "ns3/simulator-module.h"
#include "ns3/node-module.h"
#include "ns3/helper-module.h"
#include "ns3/wifi-module.h"
#include "ns3/mobility-module.h"
#include "ns3/accessCommon.h"
#include <fstream>


// Default Network Topology
//
//   Wifi 10.1.3.0
//                 AP   
//  *    *    *    *
//  |    |    |    |    10.1.1.0
// n5   n6   n7   n0 -------------- n1   n2   n3   n4
//                   point-to-point  |    |    |    |
//                                   ================
//                                     LAN 10.1.2.0

using namespace ns3;
using namespace std;

NS_LOG_COMPONENT_DEFINE ("ThirdScriptExample");

vector<string> split(const string& strValue, char separator);
void sendTcpPacket(Ptr<Node> srcNode, Ipv4Address srcAddress, Ptr<Node> destNode, Ipv4Address destAddress, uint64_t packetID, double time, int port, string sinkPath = "", string pingPath = "", string strProtocol = "");

void sendTcpPacket(Ptr<Node> srcNode, Ipv4Address srcAddress, Ptr<Node> destNode, Ipv4Address destAddress, uint64_t packetID, double time, int port, string sinkPath, string pingPath, string strProtocol)
{
    Address hubLocalAddress2 (InetSocketAddress (Ipv4Address::GetAny (), port));
    PacketSinkHelper packetSinkHelper2 ("ns3::TcpSocketFactory", hubLocalAddress2);    
    
    OnOffHelper onOffHelper2 ("ns3::TcpSocketFactory", Address ());
    onOffHelper2.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
    onOffHelper2.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
    
    onOffHelper2.SetAttribute ("PacketSize", UintegerValue(g_packetSize));
    onOffHelper2.SetAttribute ("MaxBytes", UintegerValue(g_packetSize));
    onOffHelper2.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
    
    ApplicationContainer hubApp2 = packetSinkHelper2.Install (destNode);
    packetSinkHelper2.setAddr(hubApp2.Get(0), destAddress);
    if(sinkPath != "") packetSinkHelper2.setPath(hubApp2.Get(0), g_folderName + sinkPath);
    
    hubApp2.Start (Seconds (time - 2));
    hubApp2.Stop (Seconds (time + 2));
    
    ApplicationContainer spokeApps2;
    AddressValue remoteAddress2 (InetSocketAddress (destAddress, port));
    onOffHelper2.SetAttribute ("Remote", remoteAddress2);    
    
    spokeApps2.Add (onOffHelper2.Install (srcNode));
    if(packetID != 0) onOffHelper2.setPacketId(spokeApps2.Get(0), packetID);
    onOffHelper2.setAddr(spokeApps2.Get(0), srcAddress);
    if(pingPath != "") onOffHelper2.setPath(spokeApps2.Get(0), g_folderName + pingPath);
    if(strProtocol != "") onOffHelper2.setNetworkProtocol(spokeApps2.Get(0), strProtocol);
    
    ostringstream oss;
    oss<<srcAddress<<"$n/a$n/a$n/a";
    vector<string> vect = split(oss.str(), '$');    
    onOffHelper2.SetOrgClient(spokeApps2.Get(0), vect[0]);
    onOffHelper2.SetOrgAp(spokeApps2.Get(0), vect[1]);
    onOffHelper2.SetOrgGw(spokeApps2.Get(0), vect[2]);
    onOffHelper2.SetOrgOp(spokeApps2.Get(0), vect[3]);
    
    spokeApps2.Start(Seconds(time));
    spokeApps2.Stop(Seconds(g_totalSimulationTime));
}

int 
main (int argc, char *argv[])
{
	string folderName = "tcpExamples/accessSimulation/";
    double totalTime = 1440;
	ofstream out;
	out.open("tcpExamples/wifiSimulation/srcWifi/10_1_3_1.txt");
	out.close();
	ofstream out2;
	out2.open("tcpExamples/wifiSimulation/destWifi/10_1_3_2.txt");
	out2.close();
	
	bool verbose = true;
	uint32_t nCsma = 3;
	uint32_t nWifi = 3;
	
	CommandLine cmd;
	cmd.AddValue ("nCsma", "Number of \"extra\" CSMA nodes/devices", nCsma);
	cmd.AddValue ("nWifi", "Number of wifi STA devices", nWifi);
	cmd.AddValue ("verbose", "Tell echo applications to log if true", verbose);
	
	cmd.Parse (argc,argv);
	
	if (verbose)
    {
		LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
		LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
    }
	
	NodeContainer wifiStaNode;
	wifiStaNode.Create (1);
	NodeContainer wifiApNode;
	wifiApNode.Create (1);
	
	YansWifiChannelHelper channel = YansWifiChannelHelper::Default ();
	YansWifiPhyHelper phy = YansWifiPhyHelper::Default ();
	phy.SetChannel (channel.Create ());
	
	WifiHelper wifi = WifiHelper::Default ();
	wifi.SetRemoteStationManager ("ns3::AarfWifiManager");
	
	NqosWifiMacHelper mac = NqosWifiMacHelper::Default ();
	
	Ssid ssid = Ssid ("ns-3-ssid");
	mac.SetType ("ns3::NqstaWifiMac", 
				 "Ssid", SsidValue (ssid),
				 "ActiveProbing", BooleanValue (false));
	
	NetDeviceContainer staDevice;
	staDevice = wifi.Install (phy, mac, wifiStaNode);
	
	mac.SetType ("ns3::NqapWifiMac", 
				 "Ssid", SsidValue (ssid));
	
	NetDeviceContainer apDevice;
	apDevice = wifi.Install (phy, mac, wifiApNode);
	
	MobilityHelper mobility;
	
	mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
								   "MinX", DoubleValue (0.0),
								   "MinY", DoubleValue (0.0),
								   "DeltaX", DoubleValue (50.0),
								   "DeltaY", DoubleValue (0.0),
								   "GridWidth", UintegerValue (3),
								   "LayoutType", StringValue ("RowFirst"));
	
	mobility.SetMobilityModel ("ns3::RandomWalk2dMobilityModel",
							   "Bounds", RectangleValue (Rectangle (-50, 50, -50, 50)));
	mobility.Install (wifiStaNode);
	
	mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	mobility.Install (wifiApNode);
	
	
	InternetStackHelper stack;
	stack.Install (wifiApNode);
	stack.Install (wifiStaNode);
	
	Ipv4AddressHelper address;
	
	address.SetBase ("10.1.3.0", "255.255.255.0");
	Ipv4InterfaceContainer staInterfaces;
	staInterfaces = address.Assign (staDevice);
	Ipv4InterfaceContainer apInterfaces;
	apInterfaces = address.Assign (apDevice);
	
	double tmpTime = 2.0184;
	for(int i = 1; tmpTime <= 1440; i++)
	{		
//        double delaytime = 0.01;
        //void sendTcpPacket(Ptr<Node> srcNode, Ipv4Address srcAddress, Ptr<Node> destNode, Ipv4Address destAddress, uint64_t packetID, double time, int port, string sinkPath, string pingPath, string strProtocol)
//        sendTcpPacket(wifiStaNode.Get(0), staInterfaces.GetAddress(0),wifiApNode.Get(0),apInterfaces.GetAddress(0),i,tmpTime,port,"",folderName+"1srcWifi/","AccessAuth");
//        sendTcpPacket(wifiStaNode.Get(0), staInterfaces.GetAddress(0),wifiApNode.Get(0),apInterfaces.GetAddress(0),i,tmpTime + delaytime,port);
//        sendTcpPacket(wifiStaNode.Get(0), staInterfaces.GetAddress(0),wifiApNode.Get(0),apInterfaces.GetAddress(0),i,tmpTime + delaytime*2,port);
//        sendTcpPacket(wifiStaNode.Get(0), staInterfaces.GetAddress(0),wifiApNode.Get(0),apInterfaces.GetAddress(0),i,tmpTime + delaytime*3,port);
//        sendTcpPacket(wifiStaNode.Get(0), staInterfaces.GetAddress(0),wifiApNode.Get(0),apInterfaces.GetAddress(0),i,tmpTime + delaytime*4,port);
//        sendTcpPacket(wifiStaNode.Get(0), staInterfaces.GetAddress(0),wifiApNode.Get(0),apInterfaces.GetAddress(0),i,tmpTime + delaytime*5,port,"",folderName + "1destWifi/","AccessAuth");

            uint16_t port = 5000;
            Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
            PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
            ApplicationContainer hubApp = packetSinkHelper.Install (wifiApNode.Get(0));
            //benim eklemem
            packetSinkHelper.setAddr(hubApp.Get(0), apInterfaces.GetAddress(0));
//            packetSinkHelper.setPath(hubApp.Get(0), folderName + "1destWifi/");
            
            hubApp.Start (Seconds (1.0));
            hubApp.Stop (Seconds (totalTime));
            
            OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
            onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
            onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
            
            ApplicationContainer spokeApps;
            AddressValue remoteAddress (InetSocketAddress (apInterfaces.GetAddress(0), port));
            onOffHelper.SetAttribute ("Remote", remoteAddress);
            onOffHelper.SetAttribute ("PacketSize", UintegerValue(512));
            onOffHelper.SetAttribute ("MaxBytes", UintegerValue(512));
            onOffHelper.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
            spokeApps.Add (onOffHelper.Install (wifiStaNode.Get(0)));	
            //benim eklemem
            onOffHelper.setPacketId(spokeApps.Get(0), i);
            onOffHelper.setAddr(spokeApps.Get(0), staInterfaces.GetAddress(0));
            onOffHelper.setPath(spokeApps.Get(0), folderName + "1srcWifi/");
            
            spokeApps.Start (Seconds (tmpTime));            
            spokeApps.Stop (Seconds (totalTime));
            
            
            
            Address hubLocalAddress2 (InetSocketAddress (Ipv4Address::GetAny (), port+1000));
            PacketSinkHelper packetSinkHelper2 ("ns3::TcpSocketFactory", hubLocalAddress2);
            ApplicationContainer hubApp2 = packetSinkHelper2.Install (wifiStaNode.Get(0));
            //benim eklemem
            packetSinkHelper2.setAddr(hubApp2.Get(0), staInterfaces.GetAddress(0));
            packetSinkHelper2.setPath(hubApp2.Get(0), folderName + "1destWifi/");
            
            hubApp2.Start (Seconds (1.0));
            hubApp2.Stop (Seconds (totalTime));
            
            OnOffHelper onOffHelper2 ("ns3::TcpSocketFactory", Address ());
            onOffHelper2.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
            onOffHelper2.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
            
            ApplicationContainer spokeApps2;
            AddressValue remoteAddress2 (InetSocketAddress (staInterfaces.GetAddress(0), port+1000));
            onOffHelper2.SetAttribute ("Remote", remoteAddress2);
            onOffHelper2.SetAttribute ("PacketSize", UintegerValue(512));
            onOffHelper2.SetAttribute ("MaxBytes", UintegerValue(512));
            onOffHelper2.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
            spokeApps2.Add (onOffHelper2.Install (wifiApNode.Get(0)));	
            //benim eklemem
            onOffHelper2.setPacketId(spokeApps2.Get(0), i);
            onOffHelper2.setAddr(spokeApps2.Get(0), apInterfaces.GetAddress(0));
//            onOffHelper2.setPath(spokeApps2.Get(0), folderName + "1srcWifi/");
            
            spokeApps2.Start (Seconds (tmpTime + 0.05));            
            spokeApps2.Stop (Seconds (totalTime));
            
            tmpTime += 1;
	}
	Ipv4GlobalRoutingHelper::PopulateRoutingTables ();
	
	Simulator::Stop (Seconds (totalTime));
    
	//csma.EnablePcap ("dene", csmaDevices.Get (1), true);
	
	Simulator::Run ();
	Simulator::Destroy ();
	return 0;
}
