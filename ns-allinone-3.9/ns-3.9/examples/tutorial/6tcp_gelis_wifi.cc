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

int 
main (int argc, char *argv[])
{
    string folderName = "tcpExamples/TTPToClient/";
    
	ofstream out;
	out.open("tcpExamples/TTPToClient/srcWifi/10_1_3_1.txt");
	out.close();
	ofstream out2;
	out2.open("tcpExamples/TTPToClient/destWifi/10_1_3_2.txt");
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
		//LogComponentEnable("GlobalRouteManager", LOG_LEVEL_ALL);
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
	
	
	
	double totalTime = 1000.0;
	
	
	
	
	uint16_t port = 5000;
	Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
	PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
	ApplicationContainer hubApp = packetSinkHelper.Install (wifiApNode.Get(0));
	//benim eklemem
	packetSinkHelper.setAddr(hubApp.Get(0), apInterfaces.GetAddress(0));
	packetSinkHelper.setPath(hubApp.Get(0), folderName + "destWifi/");
	
	hubApp.Start (Seconds (1.0));
	hubApp.Stop (Seconds (totalTime));
		
	OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
	onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
	onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
	
	ifstream input;
	input.open("tcpExamples/TTPToClient/destMesh/10_1_3_21.txt");
	double computationDelay = 0.0123;
	string line;
	while(getline(input, line))
	{
		vector<string> vec = split(line, '$');    
        string orgClient = vec[0];
        string orgAp = vec[1];
        string orgGw = vec[2];
        string orgOp = vec[3];
        string tmpPacketId = vec[4];
        string time = vec[5];
        string netProtocol = vec[6];
        
		double arrangedTime = atof(time.c_str());
		ApplicationContainer spokeApps;
		AddressValue remoteAddress (InetSocketAddress (apInterfaces.GetAddress(0), port));
		onOffHelper.SetAttribute ("Remote", remoteAddress);
		onOffHelper.SetAttribute ("PacketSize", UintegerValue(512));
		onOffHelper.SetAttribute ("MaxBytes", UintegerValue(512));
		onOffHelper.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
		
		spokeApps.Add (onOffHelper.Install (wifiStaNode.Get(0)));	
		//benim eklemem
		onOffHelper.setPacketId(spokeApps.Get(0), atoi(tmpPacketId.c_str()));
		onOffHelper.setAddr(spokeApps.Get(0), staInterfaces.GetAddress(0));
		onOffHelper.setPath(spokeApps.Get(0), folderName + "srcWifi/");
		
		arrangedTime += computationDelay;
		
		spokeApps.Start (Seconds (arrangedTime));
		spokeApps.Stop (Seconds (totalTime));		
	}
	input.close();
	Ipv4GlobalRoutingHelper::PopulateRoutingTables ();
	
	Simulator::Stop (Seconds (totalTime));
		
	//csma.EnablePcap ("dene", csmaDevices.Get (1), true);
	
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
