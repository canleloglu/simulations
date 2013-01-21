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
#include "ns3/seamlessCommon.h"

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
void sendTcpPacket(Ptr<Node> srcNode, Ipv4Address srcAddress, Ptr<Node> destNode, Ipv4Address destAddress, uint64_t packetID, double time, int port, string path = "", string strProtocol = "");
static void setNodePosition (Ptr<Node> node, Vector vel);
int indexOfNodeInContainer(Ptr<Node> n, NodeContainer nc);

struct structMobility
{
    int stationNumber;
    int mobilityTarget;
    double mobilityStartTime;
    int mobilityOrgSpeed;
    int mobilityCurrentSpeed;
};

void sendTcpPacket(Ptr<Node> srcNode, Ipv4Address srcAddress, Ptr<Node> destNode, Ipv4Address destAddress, uint64_t packetID, double time, int port, string path, string strProtocol)
{
    Vector n1 = srcNode->GetObject<MobilityModel>()->GetPosition();
    Vector n2 = destNode->GetObject<MobilityModel>()->GetPosition();
    double xDif = n1.x - n2.x;
    double yDif = n1.y - n2.y;
    double realDist = sqrt(pow(xDif, 2) + pow(yDif, 2));
    
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
    if(path != "") packetSinkHelper2.setPath(hubApp2.Get(0), g_folderName + path);
    
    hubApp2.Start (Seconds (0));
    hubApp2.Stop (Seconds (g_totalSimulationTime));
    
    ApplicationContainer spokeApps2;
    AddressValue remoteAddress2 (InetSocketAddress (destAddress, port));
    onOffHelper2.SetAttribute ("Remote", remoteAddress2);    
    
    spokeApps2.Add (onOffHelper2.Install (srcNode));
    if(packetID != 0) onOffHelper2.setPacketId(spokeApps2.Get(0), packetID);
    onOffHelper2.setAddr(spokeApps2.Get(0), srcAddress);
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

static void setNodePosition (Ptr<Node> node, Vector vel)
{
    node->GetObject<MobilityModel>()->SetPosition(vel);
    //NS_LOG_UNCOND();
}

int indexOfNodeInContainer(Ptr<Node> n, NodeContainer nc){
    for (int i = 0; i < nc.GetN(); i++){
        if (n == nc.Get(i)) {
            return i;
        }
    }
    return -1;
}

int 
main (int argc, char *argv[])
{
    srand(time(NULL));
    uint32_t totalUserCount = g_totalUserCount;
    uint32_t totalAccessPointCount = g_totalApCount;
    string folderName = g_folderName;
    
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
                 "MaxMissedBeacons", UintegerValue(2),
                 "AssocRequestTimeout", TimeValue (Seconds(0.001)),
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
                                           "DeltaX", DoubleValue (0.0),
                                           "DeltaY", DoubleValue (0.0),
                                           "GridWidth", UintegerValue (g_gridWidth),
                                           "LayoutType", StringValue ("RowFirst"));
            
            mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
            mobility.Install (wifiStaNodes.Get(j));	
            wifiStaNodes.Get(j)->servingApAddress = apInterfaces.GetAddress(i);
            wifiStaNodes.Get(j)->servingApNode = wifiApNodes.Get(i);
            wifiStaNodes.Get(j)->servingOperator = wifiApNodes.Get(i)->servingOperator;
        }
    }
    
    uint64_t packetID = 1;
    uint16_t port = 9000;
    float tempsec = g_simulationStartTime;
    int staNum = 0;
    int apIndex = 0;
    
    while(tempsec <= g_totalSimulationTime)
    {                
        Ptr<Node> staNode = wifiStaNodes.Get(staNum);
        Ipv4Address staAddress = staInterfaces.GetAddress(staNum);
        Ptr<Node> apNode = staNode->servingApNode;
        Ipv4Address apAddress = staNode->servingApAddress;
        
        Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
        PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
        
        ApplicationContainer hubApp = packetSinkHelper.Install (apNode/*wifiApNodes.Get(apNum)*/);
        packetSinkHelper.setAddr(hubApp.Get(0), apAddress /*apInterfaces.GetAddress(apNum)*/);
        packetSinkHelper.setPath(hubApp.Get(0), folderName + "1destWifi/");
        
        OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
        onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
        onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
        
        ApplicationContainer spokeApps;
        AddressValue remoteAddress (InetSocketAddress (apAddress/*apInterfaces.GetAddress(apNum)*/, port));
        
        onOffHelper.SetAttribute ("Remote", remoteAddress);
        onOffHelper.SetAttribute ("PacketSize", UintegerValue(512));
        onOffHelper.SetAttribute ("MaxBytes", UintegerValue(512));
        onOffHelper.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));                            

        spokeApps.Add (onOffHelper.Install (staNode));
        onOffHelper.setPacketId(spokeApps.Get(0), packetID);
        onOffHelper.setAddr(spokeApps.Get(0), staAddress);
        onOffHelper.setPath(spokeApps.Get(0), folderName + "1srcWifi/");
        
        ostringstream oss;
        oss<<staInterfaces.GetAddress(staNum)<<"$n/a$n/a$n/a";
        vector<string> vect = split(oss.str(), '$');            
        
        onOffHelper.SetOrgClient(spokeApps.Get(0), vect[0]);
        onOffHelper.SetOrgAp(spokeApps.Get(0), vect[1]);
        onOffHelper.SetOrgGw(spokeApps.Get(0), vect[2]);
        onOffHelper.SetOrgOp(spokeApps.Get(0), vect[3]);
        
        packetSinkHelper.setPath(hubApp.Get(0), "");
        onOffHelper.setNetworkProtocol(spokeApps.Get(0), "SeamlessMobility");
        spokeApps.Start (Seconds (tempsec));
        spokeApps.Stop (Seconds (g_totalSimulationTime));
        
        sendTcpPacket(apNode, apAddress, staNode, staAddress, packetID, tempsec + g_seamlessMobilityPeriod, 500);
        
        wifiStaNodes.Get(staNum)->servingApAddress = apInterfaces.GetAddress(apIndex);
        wifiStaNodes.Get(staNum)->servingApNode = wifiApNodes.Get(apIndex);
        
        Vector newApPos = wifiApNodes.Get(apIndex)->GetObject<MobilityModel>()->GetPosition();
        newApPos.y += g_userYDistance;
        Simulator::Schedule (Seconds (tempsec + 2 * g_seamlessMobilityPeriod), &setNodePosition, wifiStaNodes.Get(staNum), newApPos);                            
        
        Ptr<Node> newApNode = staNode->servingApNode;
        Ipv4Address newApAddress = staNode->servingApAddress;
        double currentTime = tempsec + 3*g_seamlessMobilityPeriod;                                
        
        sendTcpPacket(staNode, staAddress, newApNode, newApAddress, packetID, currentTime + g_seamlessMobilityDelay, 1000);
        sendTcpPacket(newApNode, newApAddress, staNode, staAddress, packetID, currentTime + g_seamlessMobilityDelay + g_seamlessMobilityPeriod, 2000);
        sendTcpPacket(staNode, staAddress, newApNode, newApAddress, packetID, currentTime + g_seamlessMobilityDelay + 2 * g_seamlessMobilityPeriod, 3000, "1destWifi/", "SeamlessMobility");
        sendTcpPacket(newApNode, newApAddress, staNode, staAddress, packetID, currentTime + g_seamlessMobilityDelay + g_seamlessMobilityPeriod + 3 * g_seamlessMobilityPeriod, 4000);
        
        packetID++;
        tempsec += g_packetInterval;
        hubApp.Start (Seconds (1.0));
        hubApp.Stop (Seconds (g_totalSimulationTime));
        
    }
    
    
	Ipv4GlobalRoutingHelper::PopulateRoutingTables ();	
	Simulator::Stop (Seconds (g_totalSimulationTime));	
	Simulator::Run ();
	Simulator::Destroy ();
	return 0;
}
