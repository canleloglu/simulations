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
//#include "ns3/multCommon.h"

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

static void
SetVelocity (Ptr<Node> node, Vector vel)
{
    /*
    Ptr<ConstantVelocityMobilityModel> mobility =
    node->GetObject<ConstantVelocityMobilityModel> ();
    mobility->SetVelocity (vel);
    */
    node->GetObject<MobilityModel>()->SetPosition(Vector(150,0,0));
}

void
log(Ptr<Node> n){
    Vector nodePos = n->GetObject<MobilityModel>()->GetPosition();
    cout<<nodePos.x <<" "<<nodePos.y<<" "<<nodePos.z<<endl;
}

int 
main (int argc, char *argv[])
{    
    srand(time(NULL));
    uint32_t totalUserCount = 1;
    uint32_t totalAccessPointCount = 2;
    
    double totalTime = 100;
    
	NodeContainer wifiStaNodes;
	wifiStaNodes.Create (totalUserCount);

	NodeContainer wifiApNodes;
	wifiApNodes.Create (totalAccessPointCount);
    
	YansWifiChannelHelper channel = YansWifiChannelHelper::Default ();
	YansWifiPhyHelper phy = YansWifiPhyHelper::Default ();
	phy.SetChannel (channel.Create ());
	
	WifiHelper wifi = WifiHelper::Default ();
	wifi.SetRemoteStationManager ("ns3::AarfWifiManager");
	
	NqosWifiMacHelper mac = NqosWifiMacHelper::Default ();
	
	Ssid ssid = Ssid ("ns-3-ssid");
	mac.SetType ("ns3::NqstaWifiMac", 
				 "Ssid", SsidValue (ssid),
                 "MaxMissedBeacons", UintegerValue(1),
                 "AssocRequestTimeout", TimeValue (Seconds(0.0001)),
				 "ActiveProbing", BooleanValue (false));
	
	NetDeviceContainer staDevice;
	staDevice = wifi.Install (phy, mac, wifiStaNodes);
	
	mac.SetType ("ns3::NqapWifiMac", 
				 "Ssid", SsidValue (ssid));
	
	NetDeviceContainer apDevice;
	apDevice = wifi.Install (phy, mac, wifiApNodes);
	
	MobilityHelper mobility;	
    
    mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
								   "MinX", DoubleValue (0.0),
								   "MinY", DoubleValue (0.0),
								   "DeltaX", DoubleValue (200.0),
								   "DeltaY", DoubleValue (200.0),
								   "GridWidth", UintegerValue (3),
								   "LayoutType", StringValue ("RowFirst"));
	
    mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
    
	mobility.Install (wifiApNodes);
    
    
    /*mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
                                   "MinX", DoubleValue (0),
                                   "MinY", DoubleValue (0),
                                   "DeltaX", DoubleValue (100.0),
                                   "DeltaY", DoubleValue (100.0),
                                   "GridWidth", UintegerValue (3),
                                   "LayoutType", StringValue ("RowFirst"));
    */
    //mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
    Ptr<ListPositionAllocator> positionAlloc_Adhoc = CreateObject<ListPositionAllocator>();
    positionAlloc_Adhoc->Add(Vector(0.0,0.0,0.0));
    
    mobility.SetMobilityModel ("ns3::ConstantVelocityMobilityModel");
    mobility.SetPositionAllocator(positionAlloc_Adhoc);
    mobility.Install (wifiStaNodes);
	
	InternetStackHelper stack;
	stack.Install (wifiApNodes);
	stack.Install (wifiStaNodes);
	
	Ipv4AddressHelper address;
	
	address.SetBase ("10.1.0.0", "255.255.0.0");
	Ipv4InterfaceContainer staInterfaces;
	staInterfaces = address.Assign (staDevice);
	Ipv4InterfaceContainer apInterfaces;
	apInterfaces = address.Assign (apDevice);
	
    uint16_t port = 5000;	
    uint64_t packetID = 1;
    
    for(int i = 1; i < 10; i++)
    {
        Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
        PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
        
        OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
        onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
        onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));

        onOffHelper.SetAttribute ("PacketSize", UintegerValue(512));
        onOffHelper.SetAttribute ("MaxBytes", UintegerValue(512));
        onOffHelper.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
        
        
        //1
        /*ApplicationContainer hubApp = packetSinkHelper.Install (wifiApNodes.Get(0));
        packetSinkHelper.setAddr(hubApp.Get(0), apInterfaces.GetAddress(0));

        hubApp.Start (Seconds (1.0));
        hubApp.Stop (Seconds (totalTime));

        

        ApplicationContainer spokeApps;
        AddressValue remoteAddress (InetSocketAddress (apInterfaces.GetAddress(0), port));
        onOffHelper.SetAttribute ("Remote", remoteAddress);
                                   

        spokeApps.Add (onOffHelper.Install (wifiStaNodes.Get(0)));
        onOffHelper.setPacketId(spokeApps.Get(0), packetID);
        onOffHelper.setAddr(spokeApps.Get(0), staInterfaces.GetAddress(0));

        spokeApps.Start(Seconds(i + 2));
        spokeApps.Stop(Seconds(totalTime));

        packetID++;
        */
        
        
        
        
        
        //2
        /*int port2 = 6000;
        Address hubLocalAddress2 (InetSocketAddress (Ipv4Address::GetAny (), port2));
        PacketSinkHelper packetSinkHelper2 ("ns3::TcpSocketFactory", hubLocalAddress2);
        
        OnOffHelper onOffHelper2 ("ns3::TcpSocketFactory", Address ());
        onOffHelper2.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
        onOffHelper2.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
        
        onOffHelper2.SetAttribute ("PacketSize", UintegerValue(512));
        onOffHelper2.SetAttribute ("MaxBytes", UintegerValue(512));
        onOffHelper2.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
        
        ApplicationContainer hubApp2 = packetSinkHelper2.Install (wifiStaNodes.Get(0));
        packetSinkHelper2.setAddr(hubApp2.Get(0), staInterfaces.GetAddress(0));
        
        hubApp2.Start (Seconds (1.0));
        hubApp2.Stop (Seconds (totalTime));
        
        ApplicationContainer spokeApps2;
        AddressValue remoteAddress2 (InetSocketAddress (staInterfaces.GetAddress(0), port2));
        onOffHelper2.SetAttribute ("Remote", remoteAddress2);
        
        
        spokeApps2.Add (onOffHelper2.Install (wifiApNodes.Get(0)));
        onOffHelper2.setPacketId(spokeApps2.Get(0), packetID);
        onOffHelper2.setAddr(spokeApps2.Get(0), apInterfaces.GetAddress(0));
        
        spokeApps2.Start(Seconds(i + 3));
        spokeApps2.Stop(Seconds(totalTime));
        
        packetID++;
        */
        
        if(i <= 5){
            int port3 = 6000;
            Address hubLocalAddress3 (InetSocketAddress (Ipv4Address::GetAny (), port3));
            PacketSinkHelper packetSinkHelper3 ("ns3::TcpSocketFactory", hubLocalAddress3);
            
            OnOffHelper onOffHelper3 ("ns3::TcpSocketFactory", Address ());
            onOffHelper3.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
            onOffHelper3.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
            
            onOffHelper3.SetAttribute ("PacketSize", UintegerValue(513));
            onOffHelper3.SetAttribute ("MaxBytes", UintegerValue(513));
            onOffHelper3.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
            
            ApplicationContainer hubApp3 = packetSinkHelper3.Install (wifiApNodes.Get(0));
            packetSinkHelper3.setAddr(hubApp3.Get(0), apInterfaces.GetAddress(0));
            
            hubApp3.Start (Seconds (1.0));
            hubApp3.Stop (Seconds (totalTime));
            
            ApplicationContainer spokeApps3;
            AddressValue remoteAddress3 (InetSocketAddress (apInterfaces.GetAddress(0), port3));
            onOffHelper3.SetAttribute ("Remote", remoteAddress3);
            
            spokeApps3.Add (onOffHelper3.Install (wifiStaNodes.Get(0)));
            onOffHelper3.setPacketId(spokeApps3.Get(0), packetID);
            onOffHelper3.setAddr(spokeApps3.Get(0), staInterfaces.GetAddress(0));
            
            spokeApps3.Start(Seconds(i));
            spokeApps3.Stop(Seconds(totalTime));
            
            packetID++;
            
            int port2 = 6000;
            Address hubLocalAddress2 (InetSocketAddress (Ipv4Address::GetAny (), port2));
            PacketSinkHelper packetSinkHelper2 ("ns3::TcpSocketFactory", hubLocalAddress2);
            
            OnOffHelper onOffHelper2 ("ns3::TcpSocketFactory", Address ());
            onOffHelper2.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
            onOffHelper2.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
            
            onOffHelper2.SetAttribute ("PacketSize", UintegerValue(512));
            onOffHelper2.SetAttribute ("MaxBytes", UintegerValue(512));
            onOffHelper2.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
            
            ApplicationContainer hubApp2 = packetSinkHelper2.Install (wifiStaNodes.Get(0));
            packetSinkHelper2.setAddr(hubApp2.Get(0), staInterfaces.GetAddress(0));
            
            hubApp2.Start (Seconds (1.0));
            hubApp2.Stop (Seconds (totalTime));
            
            ApplicationContainer spokeApps2;
            AddressValue remoteAddress2 (InetSocketAddress (staInterfaces.GetAddress(0), port2));
            onOffHelper2.SetAttribute ("Remote", remoteAddress2);
                        
            spokeApps2.Add (onOffHelper2.Install (wifiApNodes.Get(0)));
            onOffHelper2.setPacketId(spokeApps2.Get(0), packetID);
            onOffHelper2.setAddr(spokeApps2.Get(0), apInterfaces.GetAddress(0));
            
            spokeApps2.Start(Seconds(i + 0.1));
            spokeApps2.Stop(Seconds(totalTime));
            
            packetID++;            
        }
        else{
            //3
            int port3 = 7000;
            Address hubLocalAddress3 (InetSocketAddress (Ipv4Address::GetAny (), port3));
            PacketSinkHelper packetSinkHelper3 ("ns3::TcpSocketFactory", hubLocalAddress3);
            
            OnOffHelper onOffHelper3 ("ns3::TcpSocketFactory", Address ());
            onOffHelper3.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
            onOffHelper3.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
            
            onOffHelper3.SetAttribute ("PacketSize", UintegerValue(513));
            onOffHelper3.SetAttribute ("MaxBytes", UintegerValue(513));
            onOffHelper3.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
            
            ApplicationContainer hubApp3 = packetSinkHelper3.Install (wifiApNodes.Get(1));
            packetSinkHelper3.setAddr(hubApp3.Get(0), apInterfaces.GetAddress(1));
            
            hubApp3.Start (Seconds (1.0));
            hubApp3.Stop (Seconds (totalTime));
            
            ApplicationContainer spokeApps3;
            AddressValue remoteAddress3 (InetSocketAddress (apInterfaces.GetAddress(1), port3));
            onOffHelper3.SetAttribute ("Remote", remoteAddress3);
                    
            spokeApps3.Add (onOffHelper3.Install (wifiStaNodes.Get(0)));
            onOffHelper3.setPacketId(spokeApps3.Get(0), packetID);
            onOffHelper3.setAddr(spokeApps3.Get(0), staInterfaces.GetAddress(0));
            
            spokeApps3.Start(Seconds(i));
            spokeApps3.Stop(Seconds(totalTime));
            
            packetID++;
            
            int port2 = 6000;
            Address hubLocalAddress2 (InetSocketAddress (Ipv4Address::GetAny (), port2));
            PacketSinkHelper packetSinkHelper2 ("ns3::TcpSocketFactory", hubLocalAddress2);
            
            OnOffHelper onOffHelper2 ("ns3::TcpSocketFactory", Address ());
            onOffHelper2.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
            onOffHelper2.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
            
            onOffHelper2.SetAttribute ("PacketSize", UintegerValue(512));
            onOffHelper2.SetAttribute ("MaxBytes", UintegerValue(512));
            onOffHelper2.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
            
            ApplicationContainer hubApp2 = packetSinkHelper2.Install (wifiStaNodes.Get(0));
            packetSinkHelper2.setAddr(hubApp2.Get(0), staInterfaces.GetAddress(0));
            
            hubApp2.Start (Seconds (1.0));
            hubApp2.Stop (Seconds (totalTime));
            
            ApplicationContainer spokeApps2;
            AddressValue remoteAddress2 (InetSocketAddress (staInterfaces.GetAddress(0), port2));
            onOffHelper2.SetAttribute ("Remote", remoteAddress2);
            
            
            spokeApps2.Add (onOffHelper2.Install (wifiApNodes.Get(1)));
            onOffHelper2.setPacketId(spokeApps2.Get(0), packetID);
            onOffHelper2.setAddr(spokeApps2.Get(0), apInterfaces.GetAddress(1));
            
            spokeApps2.Start(Seconds(i + 0.1));
            spokeApps2.Stop(Seconds(totalTime));
            
            packetID++;
        }
        
        
        //void (*fp)(Ptr<Node>) = &log;
        //Simulator::Schedule(Seconds(i), fp, wifiStaNodes.Get(0));
    }   
    Simulator::Schedule (Seconds (5.9), &SetVelocity, wifiStaNodes.Get(0),Vector(40.0,0.0,0.0));
    
	Ipv4GlobalRoutingHelper::PopulateRoutingTables ();	
	Simulator::Stop (Seconds (totalTime));	
	Simulator::Run ();
	Simulator::Destroy ();
	return 0;
}
