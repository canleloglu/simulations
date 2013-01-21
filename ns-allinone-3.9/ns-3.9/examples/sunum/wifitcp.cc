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

int 
main (int argc, char *argv[])
{
	
	bool verbose = true;

	uint32_t nAp = 20;
	uint32_t columnNumber = 5;
	uint32_t nWifi = nAp * columnNumber;
	//double totalTime = 10;
	
  CommandLine cmd;
  cmd.AddValue ("nWifi", "Number of wifi STA devices", nWifi);
  cmd.AddValue ("verbose", "Tell echo applications to log if true", verbose);

  cmd.Parse (argc,argv);

  if (verbose)
    {
      //LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
      //LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
	  //LogComponentEnable("NqapWifiMac", LOG_LEVEL_INFO);
    }

  NodeContainer wifiStaNodes;
  wifiStaNodes.Create (nWifi);
  NodeContainer wifiApNodes;
  wifiApNodes.Create(nAp);

  YansWifiChannelHelper channel = YansWifiChannelHelper::Default ();
  YansWifiPhyHelper phy = YansWifiPhyHelper::Default ();
  phy.SetChannel (channel.Create ());

  WifiHelper wifi = WifiHelper::Default ();
  wifi.SetRemoteStationManager ("ns3::AarfWifiManager");

  NqosWifiMacHelper mac = NqosWifiMacHelper::Default ();
  
  Ssid ssid = Ssid ("ns-3-ssid");
  mac.SetType("ns3::NqstaWifiMac", "Ssid", SsidValue(ssid), "ActiveProbing", BooleanValue(false)); 

  NetDeviceContainer staDevices;
  staDevices = wifi.Install (phy, mac, wifiStaNodes);

  mac.SetType("ns3::NqapWifiMac", "Ssid", SsidValue(ssid)); 

  NetDeviceContainer apDevices;
	//NetDeviceContainer apDevices2;
  apDevices = wifi.Install (phy, mac, wifiApNodes);
	//apDevices2 = wifi.Install (phy, mac, wifiApNode2.Get(0));

  MobilityHelper mobility;

  mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
    "MinX", DoubleValue (0.0),
    "MinY", DoubleValue (0.0),
    "DeltaX", DoubleValue (200.0),
    "DeltaY", DoubleValue (200.0),
    "GridWidth", UintegerValue (4),
    "LayoutType", StringValue ("RowFirst"));

  mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  mobility.Install (wifiApNodes);
	
	
	
	ListPositionAllocator list;	
	
	for(uint32_t i = 0; i < nAp; i++)
	{
		Ptr<MobilityModel> mob = wifiApNodes.Get(i)->GetObject<MobilityModel>(); 
		Vector pos = mob->GetPosition ();

		for(uint32_t j = 0; j < columnNumber; j++)
		{

			uint32_t x = pos.x;
			uint32_t y = pos.y;
			Vector3D apPos(x + j, y, 70.0);
			list.Add(apPos);
			
		}
	}
	
	mobility.SetPositionAllocator(&list); 
	mobility.Install(wifiStaNodes);
	

	
  InternetStackHelper stack;
  stack.Install (wifiApNodes);
  stack.Install (wifiStaNodes);

  Ipv4AddressHelper address;

  address.SetBase ("10.1.3.0", "255.255.255.0");
  
  Ipv4InterfaceContainer apInterfaces;
  Ipv4InterfaceContainer staInterfaces;
  apInterfaces = address.Assign (apDevices);
  staInterfaces = address.Assign (staDevices);
	
	
	OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
	onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
	onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));	
	
	
	uint16_t port = 5000;
	Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
	PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
	ApplicationContainer serverApps;
	ApplicationContainer clientApps;
	for(uint32_t i = 0; i < nAp; i++)
	{
		serverApps.Add(packetSinkHelper.Install (wifiApNodes.Get(i)));
		packetSinkHelper.setAddr(serverApps.Get(i), apInterfaces.GetAddress(i));
		for(uint32_t j = 0; j < columnNumber; j++)
		{
			AddressValue remoteAddress (InetSocketAddress (apInterfaces.GetAddress(i), port));
			onOffHelper.SetAttribute ("Remote", remoteAddress);
			onOffHelper.SetAttribute ("PacketSize", UintegerValue(512));
			onOffHelper.SetAttribute ("MaxBytes", UintegerValue(512));
			uint32_t index = i * columnNumber + j;
			clientApps.Add (onOffHelper.Install (wifiStaNodes.Get(index)));
			uint32_t count = clientApps.GetN();
			onOffHelper.setAddr(clientApps.Get(index), staInterfaces.GetAddress(index));
		}
	}
	
	clientApps.Start (Seconds (3.0));
	clientApps.Stop (Seconds (10.0));
	serverApps.Start (Seconds (1.0));
	serverApps.Stop (Seconds (10.0));
	
	
  Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

  Simulator::Stop (Seconds (10.0));

  //phy.EnablePcap ("thirdSTA", staDevices.Get (0));
	/*Ptr<MobilityModel> mob = wifiStationNodes.Get(0)->GetObject<MobilityModel>(); 
	Vector pos = mob->GetPosition ();*/

  Simulator::Run ();
  Simulator::Destroy ();
	
  return 0;
}
