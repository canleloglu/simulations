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
#include "ns3/cipher.h"
#include "ns3/Sha-256.h"
#include "ns3/randgen.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace ns3;

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
	//std::string m_stack2;
    std::string m_root;
    /// List of network nodes
    NodeContainer nodes;
    /// List of all mesh point devices
    NetDeviceContainer meshDevices;

    //Addresses of interfaces:
    Ipv4InterfaceContainer interfaces;
	InternetStackHelper internetStack;
    // MeshHelper. Report is not static methods
    MeshHelper mesh;
	
	uint32_t nWifi;
	NodeContainer wifiStaNodes, wifiApNode;
	NetDeviceContainer apDevices, staDevices;
	Ipv4InterfaceContainer apInterfaces, staInterfaces;	
	
	
private:
    /// Create nodes and setup their mobility
    void CreateNodes ();
    /// Install internet m_stack on nodes
    void InstallInternetStack ();
    /// Install applications
    void InstallApplication ();
    /// Print mesh devices diagnostics
    void Report ();  
	
	std::string client_GetKey(int nodeCount, int count);
	void PreDeployment();
};
MeshTest::MeshTest () :
m_xSize (4),
m_ySize (4),
m_step (100.0),
m_randomStart (0.1),
m_totalTime (10.0),
m_packetInterval (1.),
m_packetSize (1024),
m_nIfaces (1),
m_chan (false),
m_pcap (false),//normalde false idi bu
m_stack ("ns3::Dot11sStack"),
m_root ("ff:ff:ff:ff:ff:ff")
{
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
	
	nWifi = 1;
	wifiStaNodes.Create (nWifi);
	wifiApNode.Create(1);
	
	YansWifiChannelHelper channel = YansWifiChannelHelper::Default ();
	YansWifiPhyHelper phy = YansWifiPhyHelper::Default ();
	phy.SetChannel (channel.Create ());
	
	WifiHelper wifi = WifiHelper::Default ();
	wifi.SetRemoteStationManager ("ns3::AarfWifiManager");
	
	NqosWifiMacHelper mac = NqosWifiMacHelper::Default ();
	
	Ssid ssid = Ssid ("ns-3-ssid");
	mac.SetType ("ns3::NqstaWifiMac", 
				 "Ssid", SsidValue (ssid),
				 "ActiveProbing", BooleanValue (false));
	
	staDevices = wifi.Install (phy, mac, wifiStaNodes);
	
	mac.SetType ("ns3::NqapWifiMac", 
				 "Ssid", SsidValue (ssid));
	
	apDevices = wifi.Install (phy, mac, wifiApNode);
	
	MobilityHelper mobility2;
	
	mobility2.SetPositionAllocator ("ns3::GridPositionAllocator",
								   "MinX", DoubleValue (0.0),
								   "MinY", DoubleValue (0.0),
								   "DeltaX", DoubleValue (5.0),
								   "DeltaY", DoubleValue (10.0),
								   "GridWidth", UintegerValue (3),
								   "LayoutType", StringValue ("RowFirst"));
	
	mobility2.SetMobilityModel ("ns3::RandomWalk2dMobilityModel",
							   "Bounds", RectangleValue (Rectangle (-50, 50, -50, 50)));
	mobility2.Install (wifiStaNodes);
	
	mobility2.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	mobility2.Install (wifiApNode);
	
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	 * Create m_ySize*m_xSize stations to form a grid topology
	 */
	nodes.Create (m_ySize*m_xSize-1);
	nodes.Add(wifiApNode.Get(0));
	
	// Configure YansWifiChannel
	YansWifiPhyHelper wifiPhy = YansWifiPhyHelper::Default ();
	
	YansWifiChannelHelper wifiChannel = YansWifiChannelHelper::Default ();
	
	wifiChannel.SetPropagationDelay ("ns3::ConstantSpeedPropagationDelayModel");
	
	wifiPhy.SetChannel (wifiChannel.Create ());
	/*
	 * Create mesh helper and set stack installer to it
	 * Stack installer creates all needed protocols and install them to
	 * mesh point device
	 */
	mesh = MeshHelper::Default ();
	if (!Mac48Address (m_root.c_str ()).IsBroadcast ())
    {
		mesh.SetStackInstaller (m_stack, "Root", Mac48AddressValue (Mac48Address (m_root.c_str ())));
    }
	else
    {
		//If root is not set, we do not use "Root" attribute, because it
		//is specified only for 11s
		mesh.SetStackInstaller (m_stack);
    }
	if (m_chan)
    {
		mesh.SetSpreadInterfaceChannels (MeshHelper::SPREAD_CHANNELS);
    }
	else
    {
		mesh.SetSpreadInterfaceChannels (MeshHelper::ZERO_CHANNEL);
    }
	mesh.SetMacType ("RandomStart", TimeValue (Seconds(m_randomStart)));
	mesh.SetMacType ("BeaconGeneration", BooleanValue(true));
	
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
	mobility.Install(nodes);
	
	if (m_pcap)
		wifiPhy.EnablePcapAll (std::string ("mp-"));
}
void
MeshTest::InstallInternetStack ()
{
	internetStack.Install (nodes);
	Ipv4AddressHelper address;
	address.SetBase ("10.0.0.0", "255.0.0.0");
	interfaces = address.Assign (meshDevices);
	
	internetStack.Install(wifiStaNodes);
	address.SetBase ("10.1.3.0", "255.255.255.0");
	staInterfaces = address.Assign (staDevices);

	apInterfaces = address.Assign (apDevices);
	
}

std::string itoa(int value, int base)
{
	std::string buf = "";
	int i = 30;
	
	buf = "";
	
	for(; value && i ; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;
	return buf;
}

void
MeshTest::InstallApplication ()
{
	
	UdpEchoServerHelper echoServer (9);
	ApplicationContainer serverApps = echoServer.Install (nodes.Get (m_xSize*m_ySize-1));
	
	UdpEchoClientHelper echoClient (interfaces.GetAddress (m_xSize*m_ySize-1), 9);
	echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
	echoClient.SetAttribute ("Interval", TimeValue (Seconds (m_packetInterval)));
	echoClient.SetAttribute ("PacketSize", UintegerValue (m_packetSize));
	ApplicationContainer clientApps = echoClient.Install (nodes.Get (0));
	
	serverApps.Start (Seconds (0.0));
	serverApps.Stop (Seconds (m_totalTime));
	clientApps.Start (Seconds (1.0));
	clientApps.Stop (Seconds (m_totalTime));
	

	
	
	
	UdpEchoServerHelper wifiechoServer (9);
	
	ApplicationContainer wifiserverApps = wifiechoServer.Install (wifiApNode.Get(0));
	wifiserverApps.Start (Seconds (5.0));
	wifiserverApps.Stop (Seconds (10.0));
	
	UdpEchoClientHelper wifiechoClient (apInterfaces.GetAddress (0), 9);
	//UdpEchoClientHelper echoClient (interfaces.GetAddress (m_ySize*m_xSize-1), 9);
	wifiechoClient.SetAttribute ("MaxPackets", UintegerValue (1));
	wifiechoClient.SetAttribute ("Interval", TimeValue (Seconds (1.)));
	wifiechoClient.SetAttribute ("PacketSize", UintegerValue (1024));
	
	ApplicationContainer wificlientApps = wifiechoClient.Install (wifiStaNodes.Get (0));
	wificlientApps.Start (Seconds (6.0));
	wificlientApps.Stop (Seconds (10.0));
	
}

int
MeshTest::Run ()
{
	CreateNodes ();
	InstallInternetStack ();
	//PreDeployment();
	InstallApplication ();
	Simulator::Schedule (Seconds(m_totalTime), & MeshTest::Report, this);
	Simulator::Stop (Seconds (m_totalTime));
	Simulator::Run ();
	Simulator::Destroy ();
	return 0;
}

void
MeshTest::PreDeployment()
{
	//Predeployment
	int *hashCount = new int[1];
	for(int i = 0; i<1; i++)
	{
		Ipv4Address remoteAddr = interfaces.GetAddress(i);//appSource->GetObject<Ipv4> ()->GetAddress(1, 0).GetLocal ();
		RandGen rand;
		int random = rand.RandInt(0,999999999);
		std::string valToHash = itoa(random,10);
		CSHA256 sha;
		std::string hashVal = sha.CalculateHash(valToHash.c_str());
		hashVal = hashVal.substr(0,32);
		hashCount[i] = 100;
		ofstream clientText;
		std::string clientTextUrl = "output_client/" + itoa(remoteAddr.Get(),10) + ".txt";
		clientText.open(clientTextUrl.c_str());
		std::string tempHashVal = hashVal;
		std::string forserver;
		for(int j = 0; j<100;j++)
		{
			forserver = tempHashVal;
			clientText << tempHashVal << "\n";
			tempHashVal = sha.CalculateHash(tempHashVal.c_str());
			tempHashVal = tempHashVal.substr(0,32);
		}
		clientText.close();
		
		std::string textUrl = "output_server/" + itoa(remoteAddr.Get(),10) + ".txt";
		ofstream serverText;
		serverText.open(textUrl.c_str());
		
		//std::cout<<"The seed value for "<<i<<"th node is "<<hashVal<<"\n";
		serverText<<hashVal<<std::endl;
		serverText<<forserver;
		
		serverText.close();

	}
	//End of PreDeployment
}

void
MeshTest::Report ()
{
	 /*unsigned n (0);
	 for (NetDeviceContainer::Iterator i = meshDevices.Begin (); i != meshDevices.End (); ++i, ++n)
	 {
	 std::ostringstream os;
	 os << "mp-report-" << n << ".xml";
	 std::cerr << "Printing mesh point device #" << n << " diagnostics to " << os.str () << "\n";
	 std::ofstream of;
	 of.open (os.str().c_str());
	 if (! of.is_open ())
	 {
	 std::cerr << "Error: Can't open file " << os.str() << "\n";
	 return;
	 }
	 mesh.Report (*i, of);
	 of.close ();
	 }*/
}
int
main (int argc, char *argv[])
{
	LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
	LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
	//LogComponentEnable("MeshPointDevice", LOG_LEVEL_DEBUG);
  MeshTest t; 
  t.Configure (argc, argv);
  return t.Run();
}
