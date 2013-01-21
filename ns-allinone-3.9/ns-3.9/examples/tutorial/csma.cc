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


  NodeContainer csmaNodes;
  csmaNodes.Create (2);

  CsmaHelper csma;
  csma.SetChannelAttribute ("DataRate", StringValue ("100Mbps"));
  csma.SetChannelAttribute ("Delay", TimeValue (NanoSeconds (6560)));

  NetDeviceContainer csmaDevices;
  csmaDevices = csma.Install (csmaNodes);


  InternetStackHelper stack;
  stack.Install (csmaNodes);

  Ipv4AddressHelper address;

  address.SetBase ("10.1.3.20", "255.255.255.252");
  Ipv4InterfaceContainer csmaInterfaces;
  csmaInterfaces = address.Assign (csmaDevices);
	
	
	
	
	//Install Applications
	
	double totalTime = 50.0;
	
	/*UdpEchoServerHelper echoServer (9);
	ApplicationContainer serverApps = echoServer.Install (csmaNodes.Get(1));
	serverApps.Start (Seconds (1.0));
	serverApps.Stop (Seconds (totalTime));
	
	UdpEchoClientHelper echoClient (csmaInterfaces.GetAddress (1), 9);
	echoClient.SetAttribute ("MaxPackets", UintegerValue (10000));
	echoClient.SetAttribute ("Interval", TimeValue (Seconds (0.05)));
	echoClient.SetAttribute ("PacketSize", UintegerValue (1024));
	
	ApplicationContainer clientApps = echoClient.Install (csmaNodes.Get (0));
	clientApps.Start (Seconds (2));
	clientApps.Stop (Seconds (totalTime));*/
	
	
	/*string line;
	ifstream input;
	input.open("a_mesh/gateway.txt");
	
	UdpEchoServerHelper echoServer (9);
	ApplicationContainer serverApps = echoServer.Install (csmaNodes.Get(1));
	serverApps.Start (Seconds (1.0));
	serverApps.Stop (Seconds (totalTime));
	
	while(getline(input, line))
	{
		vector<string> vec = split(line, '$');
		string time = vec[vec.size()-1];
		double arrangedTime = atof(time.c_str());
		
	  UdpEchoClientHelper echoClient (csmaInterfaces.GetAddress (1), 9);
	  echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
	  echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.)));
	  echoClient.SetAttribute ("PacketSize", UintegerValue (1024));

	  ApplicationContainer clientApps = echoClient.Install (csmaNodes.Get (0));
	  clientApps.Start (Seconds (arrangedTime-1));
	  clientApps.Stop (Seconds (totalTime));
	}
	
	input.close();*/
	
	ofstream out1, out2;
	out1.open("z_chart/csmaClient.txt"); out2.open("z_chart/csmaServer.txt");
	out1.close(); out2.close();
	
	string line;
	ifstream input;
	input.open("z_chart/meshServer.txt");
	UdpEchoServerHelper echoServer (9);
	ApplicationContainer serverApps = echoServer.Install (csmaNodes.Get(1));
	serverApps.Start (Seconds (1.0));
	serverApps.Stop (Seconds (totalTime));
	while(getline(input, line))
	{
		vector<string> vec = split(line, '$');
		string time = vec[vec.size()-1];
		double arrangedTime = atof(time.c_str());
		uint64_t packetId = atof(vec[vec.size()-2].c_str());
		UdpEchoClientHelper echoClient (csmaInterfaces.GetAddress (1), 9);
		echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
		echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.)));
		echoClient.SetAttribute ("PacketSize", UintegerValue (1024));		
		ApplicationContainer clientApps = echoClient.Install (csmaNodes.Get (0));
		echoClient.setPacketId(clientApps.Get(0), packetId);
		clientApps.Start (Seconds (arrangedTime-1));
		clientApps.Stop (Seconds (totalTime));
	}
	
	input.close();
	
	//END Install Applications

  Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

  Simulator::Stop (Seconds (totalTime));


  //csma.EnablePcap ("thirdcsma", csmaDevices.Get (0), true);


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
