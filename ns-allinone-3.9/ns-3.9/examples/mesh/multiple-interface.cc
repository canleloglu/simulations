/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2010 IITP RAS
 *
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
 *
 * Authors: Pavel Boyko <boyko@iitp.ru>
 */

/*
 * This is a simplest example of multi-interface and multi-channel 802.11s mesh network 
 * 
 * Every mesh station has 2 interfaces configured on two different channels: 
 * 
 * channel:   i   j
 *            |   |
 * station:  [ STA ]  
 * 
 * Chain topology is created:
 * 
 *   1   2                   2   3                  3   1
 *   |   |                   |   |                  |   |
 *  [STA 1]   <-- 120 m --> [STA 2]  <-- 120 m --> [STA 3]
 *  10.0.0.1                10.0.0.2               10.0.0.3
 *  
 *  Then STA1 ping STA3
 *  
 *  Parameters tuning and assertions are omitted for clarity.
 */

#include "ns3/core-module.h"
#include "ns3/simulator-module.h"
#include "ns3/node-module.h"
#include "ns3/helper-module.h"
#include "ns3/global-routing-module.h"
#include "ns3/wifi-module.h"
#include "ns3/mesh-module.h"
#include "ns3/mobility-module.h"
#include "ns3/mesh-helper.h"
#include <iostream>

using namespace ns3;

int main (int argc, char **argv)
{
  LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

  // Create nodes & devices
  NodeContainer nodes;
  nodes.Create (10);
  YansWifiPhyHelper wifiPhy = YansWifiPhyHelper::Default ();
  YansWifiChannelHelper wifiChannel = YansWifiChannelHelper::Default ();
  wifiPhy.SetChannel (wifiChannel.Create ());
  MeshHelper mesh = MeshHelper::Default ();     
  mesh.SetStackInstaller ("ns3::Dot11sStack");  // use 802.11s mesh stack
  mesh.SetNumberOfInterfaces (2);               // use 2-interface stations
  NetDeviceContainer meshDevices = mesh.Install (wifiPhy, nodes);
  
  // Manually setup channel numbers for every mesh STA/interface
  //uint32_t channel[10 /*node id*/][2 /*interface id*/] = {{1, 0}, {0, 3}, {1, 2}, {1, 0}, {3, 0}, {2, 0}, {2, 4}, {1, 4}, {3, 1}, {4, 0}};
  uint32_t channel[10 /*node id*/][2 /*interface id*/] = {{1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {1, 0}};
	for (uint32_t i = 0; i < 10; ++i)
    {
      // access i-th mesh point, production code should add NS_ASSERT (mp != 0);
      Ptr<MeshPointDevice> mp = DynamicCast<MeshPointDevice> (meshDevices.Get (i));  
      // get list of MP interfaces, production code should add NS_ASSERT (ifaces.size() == 2)
      std::vector< Ptr<NetDevice> > ifaces = mp->GetInterfaces ();
      for (uint32_t j = 0; j < 2; ++j)
        {
          // access j-th interface, it's worth to add assertion again
          Ptr<WifiNetDevice> iface = DynamicCast<WifiNetDevice> (ifaces [j]);
          // finally set channel number
          iface->GetPhy()->SetChannelNumber(channel[i][j]);
        }
    }
  
  
  // Place nodes
  
  MobilityHelper mobility;
  Ptr<ListPositionAllocator> positionAlloc = CreateObject<ListPositionAllocator> ();
  positionAlloc->Add (Vector (0.0, 200.0, 0.0));
  positionAlloc->Add (Vector (50.0, 150.0, 0.0));
  positionAlloc->Add (Vector (50.0, 100.0, 0.0));
  positionAlloc->Add (Vector (0.0, 25.0, 0.0));
  positionAlloc->Add (Vector (125.0, 200.0, 0.0));
  positionAlloc->Add (Vector (75.0, 100.0, 0.0));
  positionAlloc->Add (Vector (100.0, 0.0, 0.0));
  positionAlloc->Add (Vector (150.0, 150.0, 0.0));
  positionAlloc->Add (Vector (160.0, 175.0, 0.0));
  positionAlloc->Add (Vector (160.0, 0.0, 0.0));
  mobility.SetPositionAllocator (positionAlloc);
  mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  mobility.Install (nodes);
  
  // Install Internet stack and ping
  InternetStackHelper internetStack;
  internetStack.Install (nodes);
  Ipv4AddressHelper address;
  address.SetBase ("10.0.0.0", "255.255.255.0");
  
  address.Assign (meshDevices);
  
	/*V4PingHelper ping (Ipv4Address ("10.0.0.4")); // ping target 
  ping.SetAttribute ("Verbose", BooleanValue (true));
   
  
  ApplicationContainer p = ping.Install (nodes.Get (1));
  p.Start (Seconds (0));
  p.Stop (totalTime - Seconds(0.001));*/
	

	UdpEchoServerHelper echoServer (9);
	ApplicationContainer serverApps = echoServer.Install (nodes.Get(0));
	serverApps.Start (Seconds (1.0));
	serverApps.Stop (Seconds (10));
	UdpEchoClientHelper echoClient (nodes.Get(0)->GetObject<Ipv4> ()->GetAddress(1, 0).GetLocal (), 9);
	echoClient.SetAttribute ("MaxPackets", UintegerValue (10));
	echoClient.SetAttribute ("Interval", TimeValue (Seconds (9)));
	echoClient.SetAttribute ("PacketSize", UintegerValue (1040));
	ApplicationContainer clientApps = echoClient.Install (nodes.Get(9));
	clientApps.Start (Seconds (2.0));
	clientApps.Stop (Seconds (10));
	
	
	//wifiPhy.EnablePcapAll("lan");
  // Go!
	Time totalTime = Seconds(5);
  Simulator::Stop (totalTime);
  Simulator::Run ();
  Simulator::Destroy (); 
}