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
#include "ns3/common.h"

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

vector<string> split(const string& strValue, char separator);
uint32_t indexOfNode(string ipAddr, NodeContainer container, Ipv4InterfaceContainer interface);

std::string itoa(int value, int base);

int 
main (int argc, char *argv[])
{
    srand(time(NULL));
    uint32_t totalUserCount = _g_totalUserCount;
    uint32_t totalAccessPointCount = _g_totalApCount;
    string folderName = _g_folderName;
    double totalTime = _g_totalSimulationTime;
    
    for (int i = 1; i <= totalUserCount; i++) {
        ofstream out;
        string _out = folderName + "6destWifi/10_1_3_" + itoa(i, 10) + ".txt";
        out.open(_out.c_str());
        out.close();
    }
    for (int i = 1; i <= totalAccessPointCount; i++) {
        ofstream out;
        string _out = folderName + "6srcWifi/10_1_3_" + itoa(i+totalUserCount,10) + ".txt";
        out.open(_out.c_str());
        out.close();
    }                    	
	
	NodeContainer wifiStaNode;
	wifiStaNode.Create (totalUserCount);
	NodeContainer wifiApNode;
	wifiApNode.Create (totalAccessPointCount);
    
    wifiStaNode.Get(0)->nodeRole = "nonWorker";
    
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
								   "DeltaX", DoubleValue (150.0),
								   "DeltaY", DoubleValue (150.0),
								   "GridWidth", UintegerValue (3),
								   "LayoutType", StringValue ("RowFirst"));
	
    mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
    
	mobility.Install (wifiStaNode);		
    
    mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
								   "MinX", DoubleValue (50.0),
								   "MinY", DoubleValue (0.0),
								   "DeltaX", DoubleValue (150.0),
								   "DeltaY", DoubleValue (150.0),
								   "GridWidth", UintegerValue (3),
								   "LayoutType", StringValue ("RowFirst"));
	
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
	
    
    
	//asil mesele
    
    for(int i = totalUserCount; i < totalUserCount + totalAccessPointCount; i++)
    {
        string line;
        ifstream in;
        string _in = folderName + "5destMesh/10_1_3_"+ itoa(i, 10) +".txt";
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
            
            uint32_t clientIndex = indexOfNode(orgClient, wifiStaNode, staInterfaces);
            uint32_t apIndex = indexOfNode(orgAp, wifiApNode, apInterfaces);
            
            ApplicationContainer sApps;
            sApps.Add(sHelper.Install (wifiStaNode.Get(clientIndex)));
            sHelper.setAddr(sApps.Get(0), staInterfaces.GetAddress(clientIndex));
            sHelper.setPath(sApps.Get(0), folderName + "6destWifi/");
            
            sApps.Start (Seconds (1.0));
            sApps.Stop (Seconds (totalTime));
            
            AddressValue remAddress (InetSocketAddress (staInterfaces.GetAddress(clientIndex), prt));		
            onOff.SetAttribute ("Remote", remAddress);
            onOff.SetAttribute ("PacketSize", UintegerValue(512));
            onOff.SetAttribute ("MaxBytes", UintegerValue(512));
            
            ApplicationContainer cApps;
            cApps.Add (onOff.Install (wifiApNode.Get(apIndex)));
            onOff.setAddr(cApps.Get(0), apInterfaces.GetAddress(apIndex));
            onOff.setPacketId(cApps.Get(0), atoi(tmpPacketId.c_str()));
            onOff.setPath(cApps.Get(0), folderName + "6srcWifi/");
            onOff.setNetworkProtocol(cApps.Get(0), netProtocol);
            
            onOff.SetOrgClient(cApps.Get(0), orgClient);
            onOff.SetOrgAp(cApps.Get(0), orgAp);
            onOff.SetOrgGw(cApps.Get(0), orgGw);
            onOff.SetOrgOp(cApps.Get(0), orgOp);
            
            cApps.Start(Seconds (arrangedTime));
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


vector<string> split(const string& strValue, char separator)
{
    vector<string> vecstrResult;
    int startpos=0;
    int endpos=0;
	
    endpos = strValue.find_first_of(separator, startpos);
    while (endpos != -1)
    {       
        vecstrResult.push_back(strValue.substr(startpos, endpos-startpos)); // add to vector
        startpos = endpos+1; //jump past sep
        endpos = strValue.find_first_of(separator, startpos); // find next
        if(endpos==-1)
        {
            //lastone, so no 2nd param required to go to end of string
            vecstrResult.push_back(strValue.substr(startpos));
        }
    }
	
    return vecstrResult;
}

std::string itoa(int value, int base)
{
	std::string buf = "";
	int i = 30;
    
	buf = "";
    
	for(; value && i ; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;
	return buf;
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
