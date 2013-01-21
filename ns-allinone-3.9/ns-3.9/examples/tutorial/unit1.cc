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
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "ns3/unitLast.h"

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

NS_LOG_COMPONENT_DEFINE ("BaseSimulation");

int 
main (int argc, char *argv[])
{
    string folderName = g_folderName;
    ofstream out, out2, out3, out4;
    string _out = folderName + "1destWifi/10_1_3_1.txt";
    out.open(_out.c_str());
    out.close();
    string _out2 = folderName + "1destWifi/10_1_3_2.txt";
    out2.open(_out2.c_str());
    out2.close();
    string _out3 = folderName + "1srcWifi/10_1_3_1.txt";
    out3.open(_out3.c_str());
    out3.close();
    string _out4 = folderName + "1srcWifi/10_1_3_2.txt";
    out4.open(_out4.c_str());
    out4.close();
    
	NodeContainer wifiStaNodes;
    wifiStaNodes.Create (1);
    NodeContainer wifiApNode;
	wifiApNode.Create(1);
    
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
    
    NetDeviceContainer staDevices;
    staDevices = wifi.Install (phy, mac, wifiStaNodes);
    
    mac.SetType ("ns3::NqapWifiMac", 
                 "Ssid", SsidValue (ssid));
    
    NetDeviceContainer apDevices;
    apDevices = wifi.Install (phy, mac, wifiApNode);
    
    MobilityHelper mobility;
    
    mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
                                   "MinX", DoubleValue (0.0),
                                   "MinY", DoubleValue (0.0),
                                   "DeltaX", DoubleValue (100.0),
                                   "DeltaY", DoubleValue (0.0),
                                   "GridWidth", UintegerValue (3),
                                   "LayoutType", StringValue ("RowFirst"));
    
    mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
    mobility.Install (wifiStaNodes);
    mobility.Install (wifiApNode);
    
    InternetStackHelper stack;
    stack.Install (wifiStaNodes);
    stack.Install (wifiApNode);
    
    Ipv4AddressHelper address;
    
    address.SetBase ("10.1.3.0", "255.255.255.0");
    Ipv4InterfaceContainer staInterfaces;
    staInterfaces = address.Assign (staDevices);
    Ipv4InterfaceContainer apInterfaces;
    apInterfaces = address.Assign (apDevices);
    	
    uint64_t packetID = 1;
    uint16_t port = packetID + 9000;
    
    
    Ptr<Node> staNode = wifiStaNodes.Get(0);
    Ipv4Address staAddress = staInterfaces.GetAddress(0);
    Ptr<Node> apNode = wifiApNode.Get(0);
    
    Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
    PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
    
    ApplicationContainer hubApp = packetSinkHelper.Install (apNode);
    packetSinkHelper.setAddr(hubApp.Get(0), apInterfaces.GetAddress(0));
    packetSinkHelper.setPath(hubApp.Get(0), folderName + "1destWifi/");
    
    hubApp.Start (Seconds (1.0));
    hubApp.Stop (Seconds (g_totalSimulationTime));    
    
    for (int i = g_simulationStartTime; i < g_totalSimulationTime; i += g_packetInterval, packetID++) {
        OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
        onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
        onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
        
        ApplicationContainer spokeApps;
        AddressValue remoteAddress (InetSocketAddress (apInterfaces.GetAddress(0), port));
        
        onOffHelper.SetAttribute ("Remote", remoteAddress);
        onOffHelper.SetAttribute ("PacketSize", UintegerValue(512));
        onOffHelper.SetAttribute ("MaxBytes", UintegerValue(512));
        onOffHelper.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
        
        spokeApps.Add (onOffHelper.Install (staNode));
        onOffHelper.setPacketId(spokeApps.Get(0), packetID);
        onOffHelper.setAddr(spokeApps.Get(0), staAddress);
        onOffHelper.setPath(spokeApps.Get(0), folderName + "1srcWifi/");
        
        ostringstream oss;
        oss<<staInterfaces.GetAddress(0)<<"$n/a$n/a$n/a";
        vector<string> vect = split(oss.str(), '$');            
        
        onOffHelper.SetOrgClient(spokeApps.Get(0), vect[0]);
        onOffHelper.SetOrgAp(spokeApps.Get(0), vect[1]);
        onOffHelper.SetOrgGw(spokeApps.Get(0), vect[2]);
        onOffHelper.SetOrgOp(spokeApps.Get(0), vect[3]);
        
        onOffHelper.setNetworkProtocol(spokeApps.Get(0), "End-To-End");
        spokeApps.Start (Seconds (i));
        spokeApps.Stop (Seconds (g_totalSimulationTime));
    }
    
	Ipv4GlobalRoutingHelper::PopulateRoutingTables ();	
	Simulator::Stop (Seconds (g_totalSimulationTime));	
	Simulator::Run ();
	Simulator::Destroy ();
	return 0;
}