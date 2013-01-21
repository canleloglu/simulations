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

#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>

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
	NodeContainer routers;
	NodeContainer gateway;
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
m_xSize (4),
m_ySize (5),
m_step (100.0),
m_randomStart (1),
m_totalTime (10.0),
m_packetInterval (1),
m_packetSize (512),
m_nIfaces (1),
m_chan (true),
m_pcap (false),
m_stack ("ns3::Dot11sStack"),
m_root ("ff:ff:ff:ff:ff:ff")
{
}

vector<string> split(const string& strValue, char separator);
string replaceMesh( string source, const string find, string replace );


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
	/*
	 * Create m_ySize*m_xSize stations to form a grid topology
	 */
	routers.Create(m_ySize * m_xSize);
	gateway.Create(1);
	//nodes.Create (m_ySize*m_xSize);
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
								   "GridWidth", UintegerValue (m_xSize),
								   "LayoutType", StringValue ("RowFirst"));
	mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	//mobility.Install (nodes);
	
	mobility.Install(routers);	
	
	
	Ptr<MobilityModel> mob = routers.Get(m_xSize*m_ySize-1)->GetObject<MobilityModel>(); 
	Vector pos = mob->GetPosition ();
	uint32_t x = pos.x;
	uint32_t y = pos.y;
	Vector3D vec(x, y, 90);
	ListPositionAllocator list;
	list.Add(vec);
	mobility.SetPositionAllocator(&list);
	mobility.Install(gateway);
	
	if (m_pcap)
		wifiPhy.EnablePcapAll (std::string ("mp-"));
}
void
MeshTest::InstallInternetStack ()
{
	InternetStackHelper internetStack;
	internetStack.Install (nodes);
	Ipv4AddressHelper address;
	address.SetBase ("10.1.3.0", "255.255.255.0");
	interfaces = address.Assign (meshDevices);
}

void
MeshTest::InstallApplication ()
{
	uint32_t nAp = m_xSize * m_ySize;
	
	string line;
	
	
	OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
	onOffHelper.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
	onOffHelper.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));	
	
	
	uint16_t port = 5000;
	Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
	PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
	ApplicationContainer serverApps;
	serverApps.Add(packetSinkHelper.Install (nodes.Get(nAp)));
	packetSinkHelper.setAddr(serverApps.Get(0), interfaces.GetAddress(nAp));


	
	ostringstream oss;
	//oss << "tcpExamples/destWifi/" <<interfaces.GetAddress(1);
	oss << "tcpExamples/TTPToClient/destCsma/10_1_3_3";
	string in = replaceMesh(oss.str(),".","_");
	in = in + ".txt";
	ifstream input;
	input.open(in.c_str());
	while(getline(input, line))
	{
		vector<string> vec = split(line, '$');
		string time = vec[vec.size()-1];
		double arrangedTime = atof(time.c_str());
		AddressValue remoteAddress (InetSocketAddress (interfaces.GetAddress(nAp), port));
		onOffHelper.SetAttribute ("Remote", remoteAddress);
		onOffHelper.SetAttribute ("PacketSize", UintegerValue(512));
		onOffHelper.SetAttribute ("MaxBytes", UintegerValue(512));
		ApplicationContainer clientApps;
		clientApps.Add (onOffHelper.Install (nodes.Get(1)));
		onOffHelper.setAddr(clientApps.Get(0), interfaces.GetAddress(1));
		clientApps.Start (Seconds (arrangedTime));
		clientApps.Stop (Seconds (10.0));
	}
	

	serverApps.Start (Seconds (0.0));
	serverApps.Stop (Seconds (10.0));
	
}
int
MeshTest::Run ()
{
	CreateNodes ();
	InstallInternetStack ();
	InstallApplication ();
	//void (MeshTest::*fp)(int) = &MeshTest::Report; 
	//Simulator::Schedule(Seconds(5.0), fp, this, 5);
	//Simulator::Schedule (Seconds(m_totalTime), & MeshTest::Report, this);
	Simulator::Stop (Seconds (m_totalTime));
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
string replaceMesh( string source, const string find, string replace ) {
	
	size_t j;
	for ( ; (j = source.find( find )) != string::npos ; ) {
		source.replace( j, find.length(), replace );
	}
	return source;
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