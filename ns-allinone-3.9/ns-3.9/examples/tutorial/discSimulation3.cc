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
#import "ns3/discCommon.h"

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
    
    string folderName = g_folderName;
    int totalOtherEntities = g_totalUserCount + g_totalApCount;
    int totalCsmaUserCount = g_totalGwCount + g_totalOpCount + g_totalTTPCount;
    
    for (int i = totalOtherEntities + 1; i <= totalOtherEntities + totalCsmaUserCount ; i++) 
    {                
        int ip1 = i / 256;
        int ip2 = i % 256;
        
        ofstream out;
        string _out = folderName + "3srcCsma/10_1_"+itoa(ip1, 10)+"_" + itoa(ip2, 10) + ".txt";        
        out.open(_out.c_str());
        out.close();
        ofstream out2;
        string _out2 = folderName + "3destCsma/10_1_"+itoa(ip1, 10)+"_" + itoa(ip2, 10) + ".txt";
        out2.open(_out2.c_str());
        out2.close();
    }
    
    NodeContainer dummyNodes;
  NodeContainer csmaNodes;
    NodeContainer nodes;
  csmaNodes.Create (totalCsmaUserCount);
    dummyNodes.Create (totalOtherEntities);
    nodes.Add(dummyNodes);
    nodes.Add(csmaNodes);

  CsmaHelper csma;
  csma.SetChannelAttribute ("DataRate", StringValue ("100Mbps"));
  csma.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (1)));

  NetDeviceContainer csmaDevices;
  csmaDevices = csma.Install (nodes);


  InternetStackHelper stack;
  stack.Install (nodes);

  Ipv4AddressHelper address;

  address.SetBase ("10.1.0.0", "255.255.0.0");
  Ipv4InterfaceContainer csmaInterfaces;
  csmaInterfaces = address.Assign (csmaDevices);
	
	//Install Applications
	
	double totalTime = g_totalSimulationTime;
	
    
    for(int i = totalOtherEntities + 1; i <= totalOtherEntities + g_totalGwCount; i++)
    {
        int ip1 = i / 256;
        int ip2 = i % 256;
        
        string line;
        ifstream input;
        string _input = folderName + "2destMesh/10_1_"+itoa(ip1, 10)+"_"+ itoa(ip2, 10) +".txt";
        input.open(_input.c_str());
        
        
        OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
        onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
        onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));	
        
        
        uint16_t port = 5000;
        
        int serverIndex = totalOtherEntities + totalCsmaUserCount - 1;
        int clientIndex = i-1;
        
        Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
        PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
        
        ApplicationContainer serverApps = packetSinkHelper.Install (nodes.Get(serverIndex));
        packetSinkHelper.setAddr(serverApps.Get(0), csmaInterfaces.GetAddress(serverIndex));
        packetSinkHelper.setPath(serverApps.Get(0), folderName + "3destCsma/");
        serverApps.Start (Seconds (1.0));
        serverApps.Stop (Seconds (totalTime));
        
        while(getline(input, line))
        {
            if(line.length() > 10){

                vector<string> vec = split(line, '$');    
                string orgClient = vec[0];
                string orgAp = vec[1];
                string orgGw = vec[2];
                string orgOp = vec[3];
                string tmpPacketId = vec[4];
                string time = vec[5];
                string netProtocol = vec[6];

                double arrangedTime = atof(time.c_str());    
                ostringstream oss;
                oss<<csmaInterfaces.GetAddress(clientIndex);
                orgGw = oss.str();
                
                AddressValue remoteAddress (InetSocketAddress (csmaInterfaces.GetAddress(serverIndex), port));		
                onOffHelper.SetAttribute ("Remote", remoteAddress);
                onOffHelper.SetAttribute ("PacketSize", UintegerValue(g_packetToServerSize));
                onOffHelper.SetAttribute ("MaxBytes", UintegerValue(g_packetToServerSize));

                ApplicationContainer clientApps;
                clientApps.Add (onOffHelper.Install (nodes.Get(clientIndex)));				
                onOffHelper.setAddr(clientApps.Get(0), csmaInterfaces.GetAddress(clientIndex));
                onOffHelper.setPacketId(clientApps.Get(0), atoi(tmpPacketId.c_str()));
                onOffHelper.setPath(clientApps.Get(0), folderName + "3srcCsma/");
                onOffHelper.setNetworkProtocol(clientApps.Get(0), netProtocol);
                
                onOffHelper.SetOrgClient(clientApps.Get(0), orgClient);
                onOffHelper.SetOrgAp(clientApps.Get(0), orgAp);
                onOffHelper.SetOrgGw(clientApps.Get(0), orgGw);
                onOffHelper.SetOrgOp(clientApps.Get(0), orgOp);
                
                clientApps.Start(Seconds (arrangedTime));
                clientApps.Stop(Seconds (totalTime));	
            }
        }
        
        input.close();
	}
	
	//END Install Applications

  Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

  Simulator::Stop (Seconds (totalTime));

  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
