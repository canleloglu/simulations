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
#include "ns3/compCommon.h"

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

int closestApIndex(Ptr<Node> n, NodeContainer aps, Ptr<Node> otherThanThisNode)
{
    if (aps.GetN() == 1) {
        return g_totalUserCount + g_totalApCount;
    }
    Vector nodePos = n->GetObject<MobilityModel>()->GetPosition();
    double minDist = 9999999;
    int index = -1;
    for (int i = 0; i < aps.GetN(); i++) {        
        Vector apPos = aps.Get(i)->GetObject<MobilityModel>()->GetPosition();
        Vector currentApPos = otherThanThisNode->GetObject<MobilityModel>()->GetPosition();
        if(!(apPos.x == currentApPos.x && apPos.y == currentApPos.y && apPos.z == currentApPos.z))
        {
            double xDif = nodePos.x - apPos.x;
            double yDif = nodePos.y - apPos.y;
            double realDist = sqrt(pow(xDif, 2) + pow(yDif, 2));
            if (realDist < minDist && realDist <= 100) {
                minDist = realDist;
                index = i;
            }
        }
    }
    return index;
}

int 
main (int argc, char *argv[])
{    
    srand(time(NULL));
    uint32_t totalUserCount = g_totalUserCount;
    uint32_t totalAccessPointCount = g_totalApCount;
    string folderName = g_folderName;
    double totalTime = g_totalSimulationTime;
    double activeAgainDelay = 20;
    double lastStateChangeSecond = 0;
    
    for (int i = 1; i <= totalUserCount; i++) {
        ofstream out;
        int ip1 = i / 256;
        int ip2 = i % 256;
        string _out = folderName + "1srcWifi/10_1_" + itoa(ip1, 10) + "_" + itoa(ip2, 10) + ".txt";
        out.open(_out.c_str());
        out.close();
    }
    for (int i = totalUserCount + 1; i <= totalUserCount + totalAccessPointCount; i++) {
        ofstream out;
        int ip1 = i / 256;
        int ip2 = i % 256;
        string _out = folderName + "1destWifi/10_1_" + itoa(ip1, 10) + "_" + itoa(ip2,10) + ".txt";
        out.open(_out.c_str());
        out.close();
    }           
    
	NodeContainer wifiStaNodes;
	wifiStaNodes.Create (totalUserCount);
    for (int i = 0; i < totalUserCount; i++) {
        int luck = i % 3;
        string role = "";
        if (luck == 0) {
            role = "nonworker";
        }else if (luck == 1) {
            role = "student";
        }else if (luck == 2) {
            role = "worker";
        }else role = "hayirsiz";
        wifiStaNodes.Get(i)->nodeRole = role;
    }
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
    
    InternetStackHelper stack;
	stack.Install (wifiApNodes);
	stack.Install (wifiStaNodes);
	
	Ipv4AddressHelper address;
	
	address.SetBase ("10.1.0.0", "255.255.0.0");
	Ipv4InterfaceContainer staInterfaces;
	staInterfaces = address.Assign (staDevice);
	Ipv4InterfaceContainer apInterfaces;
	apInterfaces = address.Assign (apDevice);
	
	MobilityHelper mobility;	
    
    mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
								   "MinX", DoubleValue (0.0),
								   "MinY", DoubleValue (0.0),
								   "DeltaX", DoubleValue (200.0),
								   "DeltaY", DoubleValue (200.0),
								   "GridWidth", UintegerValue (g_gridWidth),
								   "LayoutType", StringValue ("RowFirst"));
	
    mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
    
	mobility.Install (wifiApNodes);
    
    for(int i = 0; i < g_totalApCount; i++)
    {
        Vector apPosition = wifiApNodes.Get(i)->GetObject<MobilityModel>()->GetPosition();
        for(int j = i * g_userPerAp; j < i * g_userPerAp + g_userPerAp; j++)
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
            ostringstream oss;
            oss<<apInterfaces.GetAddress(i);
            wifiStaNodes.Get(j)->servingApAddress = oss.str();
        }
    }
	
    uint16_t port = 5000;	
    uint64_t packetID = 1;
    
    for (int apNum = 0; apNum < totalAccessPointCount; apNum++)
    {        
        for(int staNum = apNum * g_userPerAp; staNum < apNum * g_userPerAp + g_userPerAp; staNum++)
        {
            lastStateChangeSecond = 0;
            bool active = false;
            double tempsec = g_simulationStartTime;
            
            while(tempsec <= totalTime)
            {                
                int serverIndex = indexOfNode(wifiStaNodes.Get(staNum)->servingApAddress, wifiApNodes, apInterfaces);
                
                Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
                PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
                
                ApplicationContainer hubApp = packetSinkHelper.Install (wifiApNodes.Get(serverIndex));
                packetSinkHelper.setAddr(hubApp.Get(0), apInterfaces.GetAddress(serverIndex));
                packetSinkHelper.setPath(hubApp.Get(0), folderName + "1destWifi/");
                
                hubApp.Start (Seconds (1.0));
                hubApp.Stop (Seconds (totalTime));
                
                OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
                onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
                onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
                
                ApplicationContainer spokeApps;
                AddressValue remoteAddress (InetSocketAddress (apInterfaces.GetAddress(serverIndex), port));

                onOffHelper.SetAttribute ("Remote", remoteAddress);
                onOffHelper.SetAttribute ("PacketSize", UintegerValue(512));
                onOffHelper.SetAttribute ("MaxBytes", UintegerValue(512));
                onOffHelper.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));                            
                
                int r = rand() % 100;  
                double extraDelay = 0;
                
                int timeIndex = ceil(tempsec * 2 / totalTime);//islem sonucu yukari kaldirilmali
                int becomeActiveProb = 0;
                int stayActiveProb = 0;
                
                if (wifiStaNodes.Get(staNum)->nodeRole == "nonworker") {
                    becomeActiveProb = becomeActiveProbNonWorker[timeIndex];
                    stayActiveProb = stayActiveProbNonWorker[timeIndex];
                }else if (wifiStaNodes.Get(staNum)->nodeRole == "student") {
                    becomeActiveProb = becomeActiveProbStudent[timeIndex];
                    stayActiveProb = stayActiveProbStudent[timeIndex];
                }else if (wifiStaNodes.Get(staNum)->nodeRole == "worker") {
                    becomeActiveProb = becomeActiveProbWorker[timeIndex];
                    stayActiveProb = stayActiveProbWorker[timeIndex];                    
                }
                
                if (active) 
                {
                    spokeApps.Add (onOffHelper.Install (wifiStaNodes.Get(staNum)));
                    onOffHelper.setPacketId(spokeApps.Get(0), packetID);
                    onOffHelper.setAddr(spokeApps.Get(0), staInterfaces.GetAddress(staNum));
                    onOffHelper.setPath(spokeApps.Get(0), folderName + "1srcWifi/");
                    
                    ostringstream oss;
                    oss<<staInterfaces.GetAddress(staNum)<<"$n/a$n/a$n/a";
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
                            if(r < 90)//stationary olasiligina 90 dedim simdilik
                            {
                                onOffHelper.setNetworkProtocol(spokeApps.Get(0), "PacketTransfer");
                                spokeApps.Start (Seconds (tempsec + extraDelay));
                                spokeApps.Stop (Seconds (totalTime));
                            }
                            else
                            {
                                int newApIndex = closestApIndex(wifiStaNodes.Get(staNum), wifiApNodes, wifiApNodes.Get(serverIndex));
                                int oldApIndex = serverIndex;
                                int clientIndex = staNum;
                                
                                if (true/*newApIndex == -1*/) {
                                    onOffHelper.setNetworkProtocol(spokeApps.Get(0), "PacketTransfer");
                                    spokeApps.Start (Seconds (tempsec + extraDelay));
                                    spokeApps.Stop (Seconds (totalTime));
                                }else{                                
                                    onOffHelper.setNetworkProtocol(spokeApps.Get(0), "SeamlessMobility");
                                    spokeApps.Start (Seconds (tempsec + extraDelay));
                                    spokeApps.Stop (Seconds (totalTime));
                                    
                                    for (int j = 1; j < 6; j++) {
                                        if(j % 2 == 1)
                                        {
                                            int portSeamless = 9000;
                                            Address hubLocalAddressSeamless (InetSocketAddress (Ipv4Address::GetAny (), portSeamless));
                                            PacketSinkHelper packetSinkHelperSeamless ("ns3::TcpSocketFactory", hubLocalAddressSeamless);
                                            
                                            ApplicationContainer hubAppSeamless = packetSinkHelperSeamless.Install (wifiStaNodes.Get(clientIndex));
                                            packetSinkHelperSeamless.setAddr(hubAppSeamless.Get(0), staInterfaces.GetAddress(clientIndex));
                                            
                                            hubAppSeamless.Start (Seconds (tempsec / 10));
                                            hubAppSeamless.Stop (Seconds (totalTime));
                                            
                                            OnOffHelper onOffHelperSeamless ("ns3::TcpSocketFactory", Address ());
                                            onOffHelperSeamless.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
                                            onOffHelperSeamless.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
                                            
                                            ApplicationContainer spokeAppsSeamless;
                                            AddressValue remoteAddressSeamless (InetSocketAddress (staInterfaces.GetAddress(clientIndex), portSeamless));
                                            
                                            onOffHelperSeamless.SetAttribute ("Remote", remoteAddressSeamless);
                                            onOffHelperSeamless.SetAttribute ("PacketSize", UintegerValue(512));
                                            onOffHelperSeamless.SetAttribute ("MaxBytes", UintegerValue(512));
                                            onOffHelperSeamless.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
                                            
                                            spokeAppsSeamless.Add (onOffHelperSeamless.Install (wifiApNodes.Get(oldApIndex)));
                                            onOffHelperSeamless.setPacketId(spokeAppsSeamless.Get(0), packetID);
                                            onOffHelperSeamless.setAddr(spokeAppsSeamless.Get(0), apInterfaces.GetAddress(oldApIndex));
                                            onOffHelper.setNetworkProtocol(spokeAppsSeamless.Get(0), "SeamlessMobility");
                                            
                                            spokeAppsSeamless.Start (Seconds (tempsec + extraDelay + j * 0.2));
                                            spokeAppsSeamless.Stop (Seconds (totalTime));
                                        }else{
                                            int portSeamless = 10000;
                                            Address hubLocalAddressSeamless (InetSocketAddress (Ipv4Address::GetAny (), portSeamless));
                                            PacketSinkHelper packetSinkHelperSeamless ("ns3::TcpSocketFactory", hubLocalAddressSeamless);
                                            
                                            ApplicationContainer hubAppSeamless = packetSinkHelperSeamless.Install (wifiApNodes.Get(newApIndex));
                                            packetSinkHelperSeamless.setAddr(hubAppSeamless.Get(0), apInterfaces.GetAddress(newApIndex));
                                            
                                            hubAppSeamless.Start (Seconds (tempsec / 10));
                                            hubAppSeamless.Stop (Seconds (totalTime));
                                            
                                            OnOffHelper onOffHelperSeamless ("ns3::TcpSocketFactory", Address ());
                                            onOffHelperSeamless.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
                                            onOffHelperSeamless.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
                                            
                                            ApplicationContainer spokeAppsSeamless;
                                            AddressValue remoteAddressSeamless (InetSocketAddress (apInterfaces.GetAddress(newApIndex), portSeamless));
                                            
                                            onOffHelperSeamless.SetAttribute ("Remote", remoteAddressSeamless);
                                            onOffHelperSeamless.SetAttribute ("PacketSize", UintegerValue(512));
                                            onOffHelperSeamless.SetAttribute ("MaxBytes", UintegerValue(512));
                                            onOffHelperSeamless.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
                                            
                                            spokeAppsSeamless.Add (onOffHelperSeamless.Install (wifiStaNodes.Get(clientIndex)));
                                            onOffHelperSeamless.setPacketId(spokeAppsSeamless.Get(0), packetID);
                                            onOffHelperSeamless.setAddr(spokeAppsSeamless.Get(0), apInterfaces.GetAddress(oldApIndex));
                                            onOffHelper.setNetworkProtocol(spokeAppsSeamless.Get(0), "SeamlessMobility");
                                            
                                            spokeAppsSeamless.Start (Seconds (tempsec + extraDelay + j * 0.2));
                                            spokeAppsSeamless.Stop (Seconds (totalTime));
                                        }
                                    }
                                    
                                    ostringstream o;
                                    o<<apInterfaces.GetAddress(newApIndex);
                                    wifiStaNodes.Get(staNum)->servingApAddress = o.str();
                                }
                            }
                        }
                        
                        
                    }else{
                        if (tempsec - lastStateChangeSecond >= activeAgainDelay) {
                            onOffHelper.setNetworkProtocol(spokeApps.Get(0), "Disconnection");
                            lastStateChangeSecond = tempsec;
                            extraDelay = 1.5;
                            spokeApps.Start (Seconds (tempsec + extraDelay));
                            spokeApps.Stop (Seconds (totalTime));
                            active = false;
                        }else{
                            onOffHelper.setNetworkProtocol(spokeApps.Get(0), "PacketTransfer");
                            spokeApps.Start (Seconds (tempsec + extraDelay));
                            spokeApps.Stop (Seconds (totalTime));                        
                        }
                    }
                    packetID++;
                }
                else{
                    if (r <= becomeActiveProb && (tempsec - lastStateChangeSecond >= activeAgainDelay || lastStateChangeSecond == 0)) 
                    {
                        spokeApps.Add (onOffHelper.Install (wifiStaNodes.Get(staNum)));
                        onOffHelper.setPacketId(spokeApps.Get(0), packetID);
                        onOffHelper.setAddr(spokeApps.Get(0), staInterfaces.GetAddress(staNum));
                        onOffHelper.setPath(spokeApps.Get(0), folderName + "1srcWifi/");
                        
                        ostringstream oss;
                        oss<<staInterfaces.GetAddress(staNum)<<"$n/a$n/a$n/a";
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
                        active = true;
                        packetID++;
                    }
                }         
                tempsec += g_packetInterval + extraDelay;
                
                wifiStaNodes.Get(0)->servingApAddress = "10.1.0.14";
                Vector3D vec(0, 250, 0);
                wifiStaNodes.Get(0)->GetObject<MobilityModel>()->SetPosition(vec);
            } 
        }
        
    }
    
    
	Ipv4GlobalRoutingHelper::PopulateRoutingTables ();	
	Simulator::Stop (Seconds (totalTime));	
	Simulator::Run ();
	Simulator::Destroy ();
	return 0;
}
