/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2008,2009 IITP RAS
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
 * Author: Kirill Andreev <andreev@iitp.ru>
 *
 *
 * By default this script creates m_xSize * m_ySize square grid topology with
 * IEEE802.11s stack installed at each node with peering management
 * and HWMP protocol.
 * The side of the square cell is defined by m_step parameter.
 * When topology is created, UDP ping is installed to opposite corners
 * by diagonals. packet size of the UDP ping and interval between two
 * successive packets is configurable.
 * 
 *  m_xSize * step
 *  |<--------->|
 *   step
 *  |<--->|
 *  * --- * --- * <---Ping sink  _
 *  | \   |   / |                ^
 *  |   \ | /   |                |
 *  * --- * --- * m_ySize * step |
 *  |   / | \   |                |
 *  | /   |   \ |                |
 *  * --- * --- *                _
 *  ^ Ping source
 *
 *  See also MeshTest::Configure to read more about configurable
 *  parameters.
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
#include "ns3/random-variable.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <math.h>
#include "ns3/unitLast.h"

using namespace ns3;
using namespace std;

NS_LOG_COMPONENT_DEFINE ("TestMeshScript");
class MeshTest
{
public:
    /// Init test
    MeshTest ();
    /// Configure test from command line arguments
    void Configure (int argc, char ** argv);
    /// Run test
    int Run ();
private:
    int       m_xSize;
    int       m_ySize;
    double    m_step;
    double    m_randomStart;
    double    m_totalTime;
    double    m_packetInterval;
    uint16_t  m_packetSize;
    uint32_t  m_nIfaces;
    bool      m_chan;
    bool      m_pcap;
    std::string m_stack;
    std::string m_root;
    /// List of network nodes
    NodeContainer nodes;
    /// List of all mesh point devices
    NetDeviceContainer meshDevices;
    //Addresses of interfaces:
    Ipv4InterfaceContainer interfaces;
    // MeshHelper. Report is not static methods
    MeshHelper mesh;
private:
    /// Create nodes and setup their mobility
    void CreateNodes ();
    /// Install internet m_stack on nodes
    void InstallInternetStack ();
    /// Install applications
    void InstallApplication ();
    /// Print mesh devices diagnostics
    void Report (int a);  
    
    int closestGwIndex(Ptr<Node> n);
};
MeshTest::MeshTest () :
m_xSize (3),
m_ySize (3),
m_step (g_mStep),
m_randomStart (1),
m_totalTime (g_totalSimulationTime),
m_packetInterval (1),
m_packetSize (g_packetSize),
m_nIfaces (1),
m_chan (true),
m_pcap (false),
m_stack ("ns3::Dot11sStack"),
m_root ("ff:ff:ff:ff:ff:ff")
{
}

int totalRouterNumber = g_totalApCount;

void
MeshTest::Configure (int argc, char *argv[])
{
	CommandLine cmd;
	cmd.AddValue ("x-size", "Number of nodes in a row grid. [6]", m_xSize);
	cmd.AddValue ("y-size", "Number of rows in a grid. [6]", m_ySize);
	cmd.AddValue ("step",   "Size of edge in our grid, meters. [100 m]", m_step);
	/*
	 * As soon as starting node means that it sends a beacon,
	 * simultaneous start is not good.
	 */
	cmd.AddValue ("start",  "Maximum random start delay, seconds. [0.1 s]", m_randomStart);
	cmd.AddValue ("time",  "Simulation time, seconds [100 s]", m_totalTime);
	cmd.AddValue ("packet-interval",  "Interval between packets in UDP ping, seconds [0.001 s]", m_packetInterval);
	cmd.AddValue ("packet-size",  "Size of packets in UDP ping", m_packetSize);
	cmd.AddValue ("interfaces", "Number of radio interfaces used by each mesh point. [1]", m_nIfaces);
	cmd.AddValue ("channels",   "Use different frequency channels for different interfaces. [0]", m_chan);
	cmd.AddValue ("pcap",   "Enable PCAP traces on interfaces. [0]", m_pcap);
	cmd.AddValue ("stack",  "Type of protocol stack. ns3::Dot11sStack by default", m_stack);
	cmd.AddValue ("root", "Mac address of root mesh point in HWMP", m_root);
	
	cmd.Parse (argc, argv);
}
void
MeshTest::CreateNodes ()
{ 
    nodes.Create(3);

	// Configure YansWifiChannel
	YansWifiPhyHelper wifiPhy = YansWifiPhyHelper::Default ();
	YansWifiChannelHelper wifiChannel = YansWifiChannelHelper::Default ();
	wifiPhy.SetChannel (wifiChannel.Create ());

	mesh = MeshHelper::Default ();
	mesh.SetStackInstaller (m_stack, "Root", Mac48AddressValue (Mac48Address (m_root.c_str ())));
	if (m_chan)
    {
		mesh.SetSpreadInterfaceChannels (MeshHelper::SPREAD_CHANNELS);
    }
	else
    {
		mesh.SetSpreadInterfaceChannels (MeshHelper::ZERO_CHANNEL);
    }
	mesh.SetMacType ("RandomStart", TimeValue (Seconds(m_randomStart)));
	// Set number of interfaces - default is single-interface mesh point
	mesh.SetNumberOfInterfaces (m_nIfaces);
	// Install protocols and return container if MeshPointDevices
	meshDevices = mesh.Install (wifiPhy, nodes);
	// Setup mobility - static grid topology
	MobilityHelper mobility;
	mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
								   "MinX", DoubleValue (0.0),
								   "MinY", DoubleValue (0.0),
								   "DeltaX", DoubleValue (100),
								   "DeltaY", DoubleValue (g_mStep),
								   "GridWidth", UintegerValue (g_gridWidth),
								   "LayoutType", StringValue ("RowFirst"));
	mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");	
	mobility.Install(nodes);
}
void
MeshTest::InstallInternetStack ()
{
	InternetStackHelper internetStack;
	internetStack.Install (nodes);
	Ipv4AddressHelper address;
	address.SetBase ("10.1.3.0", "255.255.255.0");    
    interfaces.Add(address.Assign (meshDevices));
}

void
MeshTest::InstallApplication ()
{    
    string folderName = g_folderName; 
    ofstream out, out2, out3, out4;
    string _out = folderName + "2destMesh/10_1_3_1.txt";
    out.open(_out.c_str());
    out.close();
    string _out2 = folderName + "2destMesh/10_1_3_3.txt";
    out2.open(_out2.c_str());
    out2.close();
    string _out3 = folderName + "2srcMesh/10_1_3_1.txt";
    out3.open(_out3.c_str());
    out3.close();
    string _out4 = folderName + "2srcMesh/10_1_3_3.txt";
    out4.open(_out4.c_str());
    out4.close();
    
    OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
    onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
    onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));	
    
    uint16_t port = 5000;
    Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
    PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
    ApplicationContainer serverApps;
    serverApps.Add(packetSinkHelper.Install (nodes.Get(2)));
    packetSinkHelper.setAddr(serverApps.Get(0), interfaces.GetAddress(2));
    packetSinkHelper.setPath(serverApps.Get(0), folderName + "2destMesh/");
    serverApps.Start (Seconds (1.0));
    serverApps.Stop (Seconds (m_totalTime));
    
    ifstream input;
    string _input = folderName + "1destWifi/10_1_3_2.txt";
    input.open(_input.c_str());
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
        AddressValue remoteAddress (InetSocketAddress (interfaces.GetAddress(2), port));
        onOffHelper.SetAttribute ("Remote", remoteAddress);
        onOffHelper.SetAttribute ("PacketSize", UintegerValue(g_packetSize));
        onOffHelper.SetAttribute ("MaxBytes", UintegerValue(g_packetSize));           
        
        ApplicationContainer clientApps;
        clientApps.Add (onOffHelper.Install (nodes.Get(0)));
        onOffHelper.setPacketId(clientApps.Get(0), atoi(tmpPacketId.c_str()));
        onOffHelper.setAddr(clientApps.Get(0), interfaces.GetAddress(0));
        onOffHelper.setPath(clientApps.Get(0), folderName + "2srcMesh/");
        onOffHelper.setNetworkProtocol(clientApps.Get(0), netProtocol);

        clientApps.Start (Seconds (arrangedTime));
        clientApps.Stop (Seconds (m_totalTime));
    }
    input.close();
}
int
MeshTest::Run ()
{
	CreateNodes ();
	InstallInternetStack ();
	InstallApplication ();
	Simulator::Stop (Seconds (m_totalTime));
	Simulator::Run ();
	Simulator::Destroy ();
	return 0;
}

int
main (int argc, char *argv[])
{
	LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
	LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
	MeshTest t; 
	t.Configure (argc, argv);
	return t.Run();
}

