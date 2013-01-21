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
#include "ns3/mobCommon.h"

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
    
    uint32_t indexOfNode(string ipAddr);
    
private:
	bool	  m_randomTraffic;
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
	NodeContainer routers;
	NodeContainer gateway;
    NodeContainer dummyNodes;
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
};
MeshTest::MeshTest () :
m_xSize (3),
m_randomTraffic (false),
m_ySize (3),
m_step (g_mStep),
m_randomStart (1),
m_totalTime (g_totalSimulationTime),
m_packetInterval (1),
m_packetSize (512),
m_nIfaces (1),
m_chan (true),
m_pcap (false),
m_stack ("ns3::Dot11sStack"),
m_root ("ff:ff:ff:ff:ff:ff")
{
}

int totalRouterNumber = g_totalApCount;

uint32_t 
MeshTest::indexOfNode(string ipAddr)
{
    Ipv4Address addr;
    addr.Set(ipAddr.c_str());
    for (uint32_t i = 0; i < nodes.GetN(); i++) {
        if (interfaces.GetAddress(i) == addr) {
            return i;
        }
    }
    return -1;
}


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
	NS_LOG_DEBUG ("Grid:" << m_xSize << "*" << m_ySize);
	NS_LOG_DEBUG ("Simulation time: " << m_totalTime << " s");
}
void
MeshTest::CreateNodes ()
{ 
    dummyNodes.Create(g_totalUserCount);
	routers.Create(totalRouterNumber);
	gateway.Create(g_totalGwCount);
    
    nodes.Add(dummyNodes);
	nodes.Add(routers);
	nodes.Add(gateway);
	// Configure YansWifiChannel
	YansWifiPhyHelper wifiPhy = YansWifiPhyHelper::Default ();
	YansWifiChannelHelper wifiChannel = YansWifiChannelHelper::Default ();
	wifiPhy.SetChannel (wifiChannel.Create ());
	/*
	 * Create mesh helper and set stack installer to it
	 * Stack installer creates all needed protocols and install them to
	 * mesh point device
	 */
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
								   "DeltaX", DoubleValue (m_step),
								   "DeltaY", DoubleValue (m_step),
								   "GridWidth", UintegerValue (g_gridWidth),
								   "LayoutType", StringValue ("RowFirst"));
	mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	
	mobility.Install(routers);	
    
    mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
								   "MinX", DoubleValue (g_mStep),
								   "MinY", DoubleValue (g_mStep),
								   "DeltaX", DoubleValue (m_step),
								   "DeltaY", DoubleValue (m_step),
								   "GridWidth", UintegerValue (g_gridWidth-2),
								   "LayoutType", StringValue ("RowFirst"));
	mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");

    mobility.Install(gateway);
    
    ListPositionAllocator list;
    for(int i = 0; i < gateway.GetN(); i++)
    {
        Ptr<MobilityModel> mob = gateway.Get(i)->GetObject<MobilityModel>(); 
        Vector pos = mob->GetPosition ();
        uint32_t x = pos.x;
        uint32_t y = pos.y;
        Vector3D vec(x, y, g_gatewayHeight);        
        list.Add(vec);
    }
	mobility.SetPositionAllocator(&list);
	mobility.Install(gateway);
    
    //put dummy nodes far away
    mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
								   "MinX", DoubleValue (5000.0),
								   "MinY", DoubleValue (5000.0),
								   "DeltaX", DoubleValue (m_step),
								   "DeltaY", DoubleValue (m_step),
								   "GridWidth", UintegerValue (m_xSize-1),
								   "LayoutType", StringValue ("RowFirst"));
	mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
    
    mobility.Install(dummyNodes);
}
void
MeshTest::InstallInternetStack ()
{
	InternetStackHelper internetStack;
	internetStack.Install (nodes);
	Ipv4AddressHelper address;
	address.SetBase ("10.1.0.0", "255.255.0.0");    
    interfaces.Add(address.Assign (meshDevices));
}

void
MeshTest::InstallApplication ()
{
    
    string folderName = g_folderName;   
    
    //initialize the system
    /*
    double initTime = 1;
    for(int i = g_totalUserCount - 1; i < g_totalUserCount + g_totalApCount + g_totalGwCount; i++)
    {
        for (int j = g_totalUserCount - 1; j < g_totalUserCount + g_totalApCount + g_totalGwCount; j++) {            
            OnOffHelper onOff ("ns3::TcpSocketFactory", Address ());
            onOff.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
            onOff.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));	
            
            uint16_t prt = 6000;
            Address hubAddress (InetSocketAddress (Ipv4Address::GetAny (), prt));
            PacketSinkHelper sinkHelper ("ns3::TcpSocketFactory", hubAddress);
            ApplicationContainer sApps = sinkHelper.Install (nodes.Get(i));
            sinkHelper.setAddr(sApps.Get(0), interfaces.GetAddress(i));
            
            sApps.Start (Seconds (0.0));
            sApps.Stop (Seconds (g_totalSimulationTime));
            
            AddressValue remAddress (InetSocketAddress (interfaces.GetAddress(i), prt));		
            onOff.SetAttribute ("Remote", remAddress);
            onOff.SetAttribute ("PacketSize", UintegerValue(1));
            onOff.SetAttribute ("MaxBytes", UintegerValue(1));
            ApplicationContainer cApps;
            cApps.Add (onOff.Install (nodes.Get(j)));
            onOff.setAddr(cApps.Get(0), interfaces.GetAddress(j));
            onOff.setPacketId(cApps.Get(0), 9999);
            cApps.Start(Seconds (initTime));
            cApps.Stop(Seconds (g_totalSimulationTime));
        }
        initTime++;
    }
     */
    for (int i = g_totalUserCount + 1; i <=  g_totalUserCount + g_totalApCount + g_totalGwCount; i++) {
        ofstream out;
        int ip1 = i / 256;
        int ip2 = i % 256;
        string _out = folderName + "5destMesh/10_1_"+itoa(ip1, 10)+"_" + itoa(ip2,10) + ".txt";
        out.open(_out.c_str());
        out.close();
        
        ofstream out2;
        string _out2 = folderName + "5srcMesh/10_1_"+itoa(ip1, 10)+"_" + itoa(ip2, 10) + ".txt";
        out2.open(_out2.c_str());
        out2.close();
    }  
	
    
    for(int i = g_totalUserCount + g_totalApCount + 1; i <= g_totalUserCount + g_totalApCount + g_totalGwCount; i++)
    {
        string line;
        ifstream in;
        
        int ip1 = i / 256;
        int ip2 = i % 256;
        
        string _in = folderName + "4destCsma/10_1_"+itoa(ip1, 10)+"_"+ itoa(ip2, 10) +".txt";
        in.open(_in.c_str());
        
        OnOffHelper onOff2 ("ns3::TcpSocketFactory", Address ());
        onOff2.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
        onOff2.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));	
        
        uint16_t prt2 = 7000;
        Address hubAddress2 (InetSocketAddress (Ipv4Address::GetAny (), prt2));
        PacketSinkHelper sHelper2 ("ns3::TcpSocketFactory", hubAddress2);
        

        while (getline(in, line)) {
            
            vector<string> vec = split(line, '$');    
            string orgClient = vec[0];
            string orgAp = vec[1];
            string orgGw = vec[2];
            string orgOp = vec[3];
            string tmpPacketId = vec[4];
            string time = vec[5];
            string netProtocol = vec[6];
            
            double arrangedTime = atof(time.c_str());
            
            uint32_t gwIndex = indexOfNode(orgGw);
            uint32_t apIndex = indexOfNode(orgAp);
            
            ApplicationContainer sApps2;
            sApps2.Add(sHelper2.Install (nodes.Get(apIndex)));
            sHelper2.setAddr(sApps2.Get(0), interfaces.GetAddress(apIndex));
            sHelper2.setPath(sApps2.Get(0), folderName + "5destMesh/");
            
            sApps2.Start (Seconds (1.0));
            sApps2.Stop (Seconds (m_totalTime));
            
            AddressValue remAddress2 (InetSocketAddress (interfaces.GetAddress(apIndex), prt2));		
            onOff2.SetAttribute ("Remote", remAddress2);
            onOff2.SetAttribute ("PacketSize", UintegerValue(512));
            onOff2.SetAttribute ("MaxBytes", UintegerValue(512));
            
            ApplicationContainer cApps2;
            cApps2.Add (onOff2.Install (nodes.Get(gwIndex)));
            onOff2.setAddr(cApps2.Get(0), interfaces.GetAddress(gwIndex));
            onOff2.setPacketId(cApps2.Get(0), atoi(tmpPacketId.c_str()));
            onOff2.setPath(cApps2.Get(0), folderName + "5srcMesh/");
            onOff2.setNetworkProtocol(cApps2.Get(0), netProtocol);
            
            onOff2.SetOrgClient(cApps2.Get(0), orgClient);
            onOff2.SetOrgAp(cApps2.Get(0), orgAp);
            onOff2.SetOrgGw(cApps2.Get(0), orgGw);
            onOff2.SetOrgOp(cApps2.Get(0), orgOp);
            
            cApps2.Start(Seconds (arrangedTime));
            cApps2.Stop(Seconds (m_totalTime));
        }
        
        in.close();
	}
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