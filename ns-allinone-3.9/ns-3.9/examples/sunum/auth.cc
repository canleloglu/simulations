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

using namespace std;

int 
main (int argc, char *argv[])
{
	
	bool verbose = true;
	double totalTime = 10;
	double serverDelay = 0.005;
	double clientDelay = 0.01;
	int nSta = 1;
	
  CommandLine cmd;
  //cmd.AddValue ("nWifi", "Number of wifi STA devices", nWifi);
  cmd.AddValue ("verbose", "Tell echo applications to log if true", verbose);
  cmd.AddValue("serverDelay", "Add computation delay to the server", serverDelay);
  cmd.AddValue("clientDelay", "Add computation delay to the client", clientDelay);
  cmd.AddValue("nSta", "Number of wifi stations" , nSta);

  cmd.Parse (argc,argv);

  if (verbose)
    {
      LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
      LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
	  //LogComponentEnable("NqapWifiMac", LOG_LEVEL_INFO);
    }

  NodeContainer wifiStaNodes;
  wifiStaNodes.Create (nSta);
  NodeContainer wifiApNodes;
  wifiApNodes.Create(1);

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
  apDevices = wifi.Install (phy, mac, wifiApNodes);

  MobilityHelper mobility;

  mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
    "MinX", DoubleValue (0.0),
    "MinY", DoubleValue (0.0),
    "DeltaX", DoubleValue (30.0),
    "DeltaY", DoubleValue (30.0),
    "GridWidth", UintegerValue (3),
    "LayoutType", StringValue ("RowFirst"));

  mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  mobility.Install (wifiApNodes);
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
	
	
	
	
	/*serverApps.Add(echoServer.Install(wifiStaNodes.Get(0)));
	echoServer.setDelay(serverApps.Get(0), Seconds(serverDelay));
	echoServer.setIpv4Addr(serverApps.Get(0), staInterfaces.GetAddress(0));
	UdpEchoClientHelper echoClient (staInterfaces.GetAddress (0), 9);
	echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
	echoClient.SetAttribute ("Interval", TimeValue (Seconds (.1)));
	echoClient.SetAttribute ("PacketSize", UintegerValue (1024));
	clientApps.Add(echoClient.Install(wifiApNodes.Get(0)));
	echoClient.SetAddr(clientApps.Get(0), apInterfaces.GetAddress(0));
	echoClient.setPacketId(clientApps.Get(0), 1);
	echoClient.setDelay(clientApps.Get(0), Seconds(clientDelay));*/
	UdpEchoServerHelper echoServer (9);
	ApplicationContainer serverApps;
	ApplicationContainer clientApps;
	for(int i = 0; i< nSta; i++)
	{
		
		
		serverApps.Add(echoServer.Install(wifiStaNodes.Get(i)));
		echoServer.setDelay(serverApps.Get(i), Seconds(serverDelay));
		echoServer.setIpv4Addr(serverApps.Get(i), staInterfaces.GetAddress(i));
		UdpEchoClientHelper echoClient (staInterfaces.GetAddress (i), 9);
		echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
		echoClient.SetAttribute ("Interval", TimeValue (Seconds (.1)));
		echoClient.SetAttribute ("PacketSize", UintegerValue (512));
		clientApps.Add(echoClient.Install(wifiApNodes.Get(0)));
		echoClient.SetAddr(clientApps.Get(i), apInterfaces.GetAddress(0));
		echoClient.setPacketId(clientApps.Get(i), i+1);
		echoClient.setDelay(clientApps.Get(i), Seconds(clientDelay));
		
	}
	
	serverApps.Start (Seconds (0.0));
	serverApps.Stop (Seconds (totalTime));
	clientApps.Start (Seconds (1.0));
	clientApps.Stop (Seconds (totalTime));
	
	
  Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

  Simulator::Stop (Seconds (totalTime));

  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
