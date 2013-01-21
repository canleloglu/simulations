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
#import "ns3/common.h"

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
std::string itoa(int value, int base);

int 
main (int argc, char *argv[])
{
    
    string folderName = _g_folderName;
    int totalOtherEntities = _g_totalUserCount + _g_totalApCount;
    int totalCsmaUserCount = _g_totalGwCount + _g_totalOpCount + _g_totalTTPCount;
    
    for (int i = totalOtherEntities + 1; i <= totalOtherEntities + 3 ; i++) {
        ofstream out;
        string _out = folderName + "4srcCsma/10_1_3_" + itoa(i, 10) + ".txt";
        out.open(_out.c_str());
        out.close();
        ofstream out2;
        string _out2 = folderName + "4destCsma/10_1_3_" + itoa(i, 10) + ".txt";
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

  address.SetBase ("10.1.3.0", "255.255.255.0");
  Ipv4InterfaceContainer csmaInterfaces;
  csmaInterfaces = address.Assign (csmaDevices);
	
	//Install Applications
	
	double totalTime = _g_totalSimulationTime;
	
	string line;
	ifstream input;
    string _input = folderName + "3destCsma/10_1_3_23.txt";
	input.open(_input.c_str());
	
	
	OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
	onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
	onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));	
	
	
	uint16_t port = 5000;
    
    int serverIndex = totalOtherEntities;
    int clientIndex = totalOtherEntities + totalCsmaUserCount - 1;
    
	Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
	PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
	
	ApplicationContainer serverApps = packetSinkHelper.Install (nodes.Get(serverIndex));
	packetSinkHelper.setAddr(serverApps.Get(0), csmaInterfaces.GetAddress(serverIndex));
	packetSinkHelper.setPath(serverApps.Get(0), folderName + "4destCsma/");
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
            
            AddressValue remoteAddress (InetSocketAddress (csmaInterfaces.GetAddress(serverIndex), port));		
            onOffHelper.SetAttribute ("Remote", remoteAddress);
            onOffHelper.SetAttribute ("PacketSize", UintegerValue(512));
            onOffHelper.SetAttribute ("MaxBytes", UintegerValue(512));

            ApplicationContainer clientApps;
            clientApps.Add (onOffHelper.Install (nodes.Get(clientIndex)));				
            onOffHelper.setAddr(clientApps.Get(0), csmaInterfaces.GetAddress(clientIndex));
            onOffHelper.setPacketId(clientApps.Get(0), atoi(tmpPacketId.c_str()));
            onOffHelper.setPath(clientApps.Get(0), folderName + "4srcCsma/");
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

std::string itoa(int value, int base)
{
	std::string buf = "";
	int i = 30;
    
	buf = "";
    
	for(; value && i ; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;
	return buf;
}
