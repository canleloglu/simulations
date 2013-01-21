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

std::string itoa(int value, int base);

int 
main (int argc, char *argv[])
{    
    srand(time(NULL));
    uint32_t totalUserCount = _g_totalUserCount;
    uint32_t totalAccessPointCount = _g_totalApCount;
    string folderName = _g_folderName;
    bool trafficOn = true;
    double totalTime = _g_totalSimulationTime;
    int becomeActiveProb = 60;
    int stayActiveProb = 98;
    double activeAgainDelay = 20;
    double lastStateChangeSecond = 0;
    bool active[totalUserCount];
    
    for (int i = 0; i < totalUserCount; i++) {
        active[i] = false;
    }
    
    for (int i = 1; i <= totalUserCount; i++) {
        ofstream out;
        string _out = folderName + "1srcWifi/10_1_3_" + itoa(i, 10) + ".txt";
        out.open(_out.c_str());
        out.close();
    }
    for (int i = 1; i <= totalAccessPointCount; i++) {
        ofstream out;
        string _out = folderName + "1destWifi/10_1_3_" + itoa(i+totalUserCount,10) + ".txt";
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
	
	uint16_t port = 5000;	
    
    for (int trafficTurn = 0; trafficTurn < totalUserCount; trafficTurn++) 
    {        
        lastStateChangeSecond = 0;
        double tempsec = 50;
        
        Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
        PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
        ApplicationContainer hubApp = packetSinkHelper.Install (wifiApNode.Get(trafficTurn));
        packetSinkHelper.setAddr(hubApp.Get(0), apInterfaces.GetAddress(trafficTurn));
        packetSinkHelper.setPath(hubApp.Get(0), folderName + "1destWifi/");
        
        hubApp.Start (Seconds (1.0));
        hubApp.Stop (Seconds (totalTime));
            
        OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
        onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
        onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
                
        if(trafficOn)
        {                        
            
            for(int i = trafficTurn * 2 * totalTime + 1; tempsec <= totalTime; i++)
            {                
                ApplicationContainer spokeApps;
                AddressValue remoteAddress (InetSocketAddress (apInterfaces.GetAddress(trafficTurn), port));
                /*string ad = "10.1.3.20";
                Ipv4Address addr;
                addr.Set(ad.c_str());
                AddressValue remAddress (InetSocketAddress (addr, port));*/
                onOffHelper.SetAttribute ("Remote", remoteAddress);
                onOffHelper.SetAttribute ("PacketSize", UintegerValue(512));
                onOffHelper.SetAttribute ("MaxBytes", UintegerValue(512));
                onOffHelper.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));                            
                
                int r = rand() % 100;  
                double extraDelay = 0;
                
                if (active[trafficTurn]) 
                {
                    spokeApps.Add (onOffHelper.Install (wifiStaNode.Get(trafficTurn)));
                    onOffHelper.setPacketId(spokeApps.Get(0), i);
                    onOffHelper.setAddr(spokeApps.Get(0), staInterfaces.GetAddress(trafficTurn));
                    onOffHelper.setPath(spokeApps.Get(0), folderName + "1srcWifi/");
                    
                    ostringstream oss;
                    oss<<staInterfaces.GetAddress(trafficTurn)<<"$n/a$n/a$n/a";
                    vector<string> vect = split(oss.str(), '$');            

                    onOffHelper.SetOrgClient(spokeApps.Get(0), vect[0]);
                    onOffHelper.SetOrgAp(spokeApps.Get(0), vect[1]);
                    onOffHelper.SetOrgGw(spokeApps.Get(0), vect[2]);
                    onOffHelper.SetOrgOp(spokeApps.Get(0), vect[3]);
                    
                    if (r <= stayActiveProb) {
                        if ((int)tempsec % 50 == 0) {
                            onOffHelper.setNetworkProtocol(spokeApps.Get(0), "ChangeAlias");
                            extraDelay = 1.5;
                            spokeApps.Start (Seconds (tempsec + extraDelay));
                            spokeApps.Stop (Seconds (totalTime));                        
                        }else{
                            onOffHelper.setNetworkProtocol(spokeApps.Get(0), "PacketTransfer");
                            spokeApps.Start (Seconds (tempsec + extraDelay));
                            spokeApps.Stop (Seconds (totalTime));                        
                        }
                        
                    }else{
                        if (tempsec - lastStateChangeSecond >= activeAgainDelay) {
                            onOffHelper.setNetworkProtocol(spokeApps.Get(0), "Disconnection");
                            lastStateChangeSecond = tempsec;
                            extraDelay = 1.5;
                            spokeApps.Start (Seconds (tempsec + extraDelay));
                            spokeApps.Stop (Seconds (totalTime));
                            active[trafficTurn] = false;
                        }else{
                            onOffHelper.setNetworkProtocol(spokeApps.Get(0), "PacketTransfer");
                            spokeApps.Start (Seconds (tempsec + extraDelay));
                            spokeApps.Stop (Seconds (totalTime));                        
                        }
                    }
                }else{
                    if (r <= becomeActiveProb && (tempsec - lastStateChangeSecond >= activeAgainDelay || lastStateChangeSecond == 0)) 
                    {
                        spokeApps.Add (onOffHelper.Install (wifiStaNode.Get(trafficTurn)));
                        onOffHelper.setPacketId(spokeApps.Get(0), i);
                        onOffHelper.setAddr(spokeApps.Get(0), staInterfaces.GetAddress(trafficTurn));
                        onOffHelper.setPath(spokeApps.Get(0), folderName + "1srcWifi/");
                        
                        ostringstream oss;
                        oss<<staInterfaces.GetAddress(trafficTurn)<<"$n/a$n/a$n/a";
                        vector<string> vect = split(oss.str(), '$');            
                        
                        onOffHelper.SetOrgClient(spokeApps.Get(0), vect[0]);
                        onOffHelper.SetOrgAp(spokeApps.Get(0), vect[1]);
                        onOffHelper.SetOrgGw(spokeApps.Get(0), vect[2]);
                        onOffHelper.SetOrgOp(spokeApps.Get(0), vect[3]);
                        
                        if (lastStateChangeSecond == 0) {
                            onOffHelper.setNetworkProtocol(spokeApps.Get(0), "InitialAuth");
                        }else{
                            onOffHelper.setNetworkProtocol(spokeApps.Get(0), "Reuse");
                        }                    
                        lastStateChangeSecond = tempsec;
                        extraDelay = 1.5;
                        spokeApps.Start (Seconds (tempsec + extraDelay));
                        spokeApps.Stop (Seconds (totalTime));                        
                        active[trafficTurn] = true;
                    }
                }         
                tempsec += 0.5 + extraDelay;
            }     
        }
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
