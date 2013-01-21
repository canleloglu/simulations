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
#include "ns3/discCommon.h"

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

uint32_t indexOfNode(string ipAddr, NodeContainer container, Ipv4InterfaceContainer interface);

int 
main (int argc, char *argv[])
{
    srand(time(NULL));
    uint32_t totalUserCount = g_totalUserCount;
    uint32_t totalAccessPointCount = g_totalApCount;
    string folderName = g_folderName;
    double totalTime = g_totalSimulationTime;
    
    for (int i = 1; i <= totalUserCount; i++) {
        ofstream out;
        int ip1 = i / 256;
        int ip2 = i % 256;
        string _out = folderName + "6destWifi/10_1_"+itoa(ip1, 10)+"_" + itoa(ip2, 10) + ".txt";
        out.open(_out.c_str());
        out.close();
    }
    for (int i = totalUserCount + 1; i <= totalUserCount + totalAccessPointCount; i++) {
        ofstream out;
        int ip1 = i / 256;
        int ip2 = i % 256;
        string _out = folderName + "6srcWifi/10_1_"+itoa(ip1, 10)+"_" + itoa(ip2,10) + ".txt";
        out.open(_out.c_str());
        out.close();
    }                    	
	
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
								   "DeltaX", DoubleValue (150.0),
								   "DeltaY", DoubleValue (150.0),
								   "GridWidth", UintegerValue (g_gridWidth),
								   "LayoutType", StringValue ("RowFirst"));
	
    mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
    
	mobility.Install (wifiApNodes);
    
    for(int i = 0; i < g_totalApCount; i++)
    {
        Vector apPosition = wifiApNodes.Get(i)->GetObject<MobilityModel>()->GetPosition();
        for(int j = i*g_userPerAp; j < i * g_userPerAp + g_userPerAp; j++)
        {
            mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
                                           "MinX", DoubleValue (apPosition.x),
                                           "MinY", DoubleValue (apPosition.y + g_userYDistance),
                                           "DeltaX", DoubleValue (1.0),
                                           "DeltaY", DoubleValue (1.0),
                                           "GridWidth", UintegerValue (g_gridWidth),
                                           "LayoutType", StringValue ("RowFirst"));
            
            mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
            
            mobility.Install (wifiStaNodes.Get(j));	
        }
    }
	
	InternetStackHelper stack;
	stack.Install (wifiApNodes);
	stack.Install (wifiStaNodes);
	
	Ipv4AddressHelper address;
	
	address.SetBase ("10.1.0.0", "255.255.0.0");
	Ipv4InterfaceContainer staInterfaces;
	staInterfaces = address.Assign (staDevice);
	Ipv4InterfaceContainer apInterfaces;
	apInterfaces = address.Assign (apDevice);
	
    
    
	//asil mesele
    
    for(int i = totalUserCount + 1; i <= totalUserCount + totalAccessPointCount; i++)
    {
        
        int ip1 = i / 256;
        int ip2 = i % 256;
        
        string line;
        ifstream in;
        string _in = folderName + "5destMesh/10_1_"+itoa(ip1, 10)+"_"+ itoa(ip2, 10) +".txt";
        in.open(_in.c_str());
        
        OnOffHelper onOff ("ns3::TcpSocketFactory", Address ());
        onOff.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
        onOff.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));	
        
        uint16_t prt = 7000;
        Address hubAddress (InetSocketAddress (Ipv4Address::GetAny (), prt));
        PacketSinkHelper sHelper ("ns3::TcpSocketFactory", hubAddress);
        
        while (getline(in, line)) {
            
            vector<string> vec = split(line, '$');    
            string orgClient = vec[0];
            string orgAp = vec[1];
            string orgGw = vec[2];
            string orgOp = vec[3];
            string tmpPacketId = vec[4];
            string time = vec[5];
            string netProtocol = vec[6];
            
            double arrangedTime = atof(time.c_str());
            
            ApplicationContainer sApps;
            sApps.Add(sHelper.Install (wifiStaNodes.Get(0)));
            sHelper.setAddr(sApps.Get(0), staInterfaces.GetAddress(0));
            sHelper.setPath(sApps.Get(0), folderName + "6destWifi/");
            
            sApps.Start (Seconds (1.0));
            sApps.Stop (Seconds (totalTime));
            
            AddressValue remAddress (InetSocketAddress (staInterfaces.GetAddress(0), prt));		
            onOff.SetAttribute ("Remote", remAddress);
            onOff.SetAttribute ("PacketSize", UintegerValue(g_packetToClientSize));
            onOff.SetAttribute ("MaxBytes", UintegerValue(g_packetToClientSize));
            
            ApplicationContainer cApps;
            cApps.Add (onOff.Install (wifiApNodes.Get(0)));
            onOff.setAddr(cApps.Get(0), apInterfaces.GetAddress(0));
            onOff.setPacketId(cApps.Get(0), atoi(tmpPacketId.c_str()));
            onOff.setPath(cApps.Get(0), folderName + "6srcWifi/");
            onOff.setNetworkProtocol(cApps.Get(0), netProtocol);
            
            onOff.SetOrgClient(cApps.Get(0), orgClient);
            onOff.SetOrgAp(cApps.Get(0), orgAp);
            onOff.SetOrgGw(cApps.Get(0), orgGw);
            onOff.SetOrgOp(cApps.Get(0), orgOp);
            
            cApps.Start(Seconds (arrangedTime + g_rsaVerificationAPDelay));
            cApps.Stop(Seconds (totalTime));
        }
        
        in.close();
    }
    
	Ipv4GlobalRoutingHelper::PopulateRoutingTables ();	
	Simulator::Stop (Seconds (totalTime));	
	Simulator::Run ();
	Simulator::Destroy ();
	return 0;
}

uint32_t indexOfNode(string ipAddr, NodeContainer container, Ipv4InterfaceContainer interface)
{
    Ipv4Address addr;
    addr.Set(ipAddr.c_str());
    for (uint32_t i = 0; i < container.GetN(); i++) {
        if (interface.GetAddress(i) == addr) {
            return i;
        }
    }
    return -1;
}
