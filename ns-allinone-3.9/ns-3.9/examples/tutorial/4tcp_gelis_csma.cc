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
	out.open("tcpExamples/TTPToClient/srcCsma/10_1_3_1.txt");
	out.close();
	ofstream out2;
	out2.open("tcpExamples/TTPToClient/destCsma/10_1_3_3.txt");
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


	double computationDelay = 0.0188;
	
  NodeContainer csmaNodes;
  csmaNodes.Create (3);

  CsmaHelper csma;
  csma.SetChannelAttribute ("DataRate", StringValue ("100Mbps"));
  csma.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (1)));

  NetDeviceContainer csmaDevices;
  csmaDevices = csma.Install (csmaNodes);


  InternetStackHelper stack;
  stack.Install (csmaNodes);

  Ipv4AddressHelper address;

  address.SetBase ("10.1.3.0", "255.255.255.0");
  Ipv4InterfaceContainer csmaInterfaces;
  csmaInterfaces = address.Assign (csmaDevices);
	
	//Install Applications
	
	double totalTime = 1000.0;
	
	string line;
	ifstream input;
	input.open("tcpExamples/clientToTTP/destCsma/10_1_3_3.txt");
	
	
	OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
	onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
	onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));	
	
	
	uint16_t port = 5000;
	Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
	PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
	
	ApplicationContainer serverApps = packetSinkHelper.Install (csmaNodes.Get(2));
	packetSinkHelper.setAddr(serverApps.Get(0), csmaInterfaces.GetAddress(2));
	packetSinkHelper.setPath(serverApps.Get(0), folderName + "destCsma/");
	serverApps.Start (Seconds (1.0));
	serverApps.Stop (Seconds (totalTime));
	
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
		AddressValue remoteAddress (InetSocketAddress (csmaInterfaces.GetAddress(2), port));		
		onOffHelper.SetAttribute ("Remote", remoteAddress);
		onOffHelper.SetAttribute ("PacketSize", UintegerValue(512));
		onOffHelper.SetAttribute ("MaxBytes", UintegerValue(512));
		ApplicationContainer clientApps;
		clientApps.Add (onOffHelper.Install (csmaNodes.Get(0)));
		onOffHelper.setAddr(clientApps.Get(0), csmaInterfaces.GetAddress(0));
		onOffHelper.setPacketId(clientApps.Get(0), atoi(tmpPacketId.c_str()));
		onOffHelper.setPath(clientApps.Get(0), folderName + "srcCsma/");
		
		arrangedTime += computationDelay;
		
		clientApps.Start(Seconds (arrangedTime));
		clientApps.Stop(Seconds (totalTime));
		
	}
	
	input.close();
	
	
	//END Install Applications

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
