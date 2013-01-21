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
#include "ns3/sha-256.h"
#include "ns3/cipher.h"
#include "ns3/randgen.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("TestMeshScript");
std::string mobilityText = "";
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
	int staNumber;
	int* hashCount;
    std::string m_stack;
    std::string m_root;
    /// List of network nodes
    NodeContainer nodes;
	NodeContainer staNodes;
	NodeContainer apNodes;
    /// List of all mesh point devices
    NetDeviceContainer meshDevices;
    //Addresses of interfaces:
    Ipv4InterfaceContainer interfaces;
	InternetStackHelper internetStack;
    // MeshHelper. Report is not static methods
    MeshHelper mesh;
private:
	std::string client_GetKey(int nodeCount, int count);
	void PreDeployment();
    /// Create nodes and setup their mobility
    void CreateNodes ();
    /// Install internet m_stack on nodes
    void InstallInternetStack ();
    /// Install applications
    void InstallApplication ();
    /// Print mesh devices diagnostics
    void Report ();  
};
MeshTest::MeshTest () :
m_xSize (4),
m_ySize (4),
m_step (50.0),
m_randomStart (0.1),
m_totalTime (10.0),
m_packetInterval (9.0),
m_packetSize (1024),
m_nIfaces (1),
m_chan (false),
m_pcap (false),
staNumber(10),
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

void CourseChange (std::string context, Ptr<const MobilityModel> model)
{
	Vector position = model->GetPosition ();
	//NS_LOG_UNCOND(context << " x = " << position.x << ", y = "
	//			  << position.y);
	ostringstream oss;
	oss<<context << " x = " << position.x << ", y = "
	<< position.y<<std::endl;
	mobilityText += oss.str();
	
}
void
MeshTest::CreateNodes ()
{ 
	/*
	 * Create m_ySize*m_xSize stations to form a grid topology
	 */
	staNodes.Create(10);
	apNodes.Create(m_ySize*m_xSize - 10);
	//nodes.Create (m_ySize*m_xSize);
	
	nodes.Add(staNodes);
	nodes.Add(apNodes);
	
	
	// Configure YansWifiChannel
	YansWifiPhyHelper wifiPhy = YansWifiPhyHelper::Default ();
	
	wifiPhy.SetPcapDataLinkType(YansWifiPhyHelper::DLT_IEEE802_11);
	
	
	YansWifiChannelHelper wifiChannel = YansWifiChannelHelper::Default ();
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
	/*
	Ssid ssid = Ssid ("ns-3-ssid");
	mesh.SetMacType ("ns3::NqstaWifiMac", 
				 "Ssid", SsidValue (ssid),
				 "ActiveProbing", BooleanValue (false));
	 */
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
	
	mobility.SetMobilityModel ("ns3::RandomWalk2dMobilityModel",
							   "Bounds", RectangleValue (Rectangle (-250, 250, -250, 250)));
	mobility.Install (staNodes);
	
	mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	mobility.Install (apNodes);
	
	std::ostringstream oss;
	oss << "/NodeList/" << staNodes.Get (7)->GetId() <<
	"/$ns3::MobilityModel/CourseChange";
	Config::Connect (oss.str(), MakeCallback(&CourseChange));
	
	if (m_pcap)
		wifiPhy.EnablePcapAll (std::string ("mp-"));
}
void
MeshTest::InstallInternetStack ()
{
	internetStack.Install (nodes);
	Ipv4AddressHelper address;
	address.SetBase ("10.1.1.0", "255.255.255.0");
	interfaces = address.Assign (meshDevices);
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
MeshTest::PreDeployment()
{
	//Predeployment
	hashCount = new int[staNumber];
	for(int i = 0; i<staNumber; i++)
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
std::string
MeshTest::client_GetKey(int nodeCount, int count)
{
	Ipv4Address Addr = interfaces.GetAddress(nodeCount);	
	std::string s_Addr = itoa(Addr.Get(),10);
	ifstream clientText;
	std::string clientTextUrl = "output_client/"+s_Addr+".txt";
	clientText.open(clientTextUrl.c_str());
	std::string line = "";
	for(int i = 0; i < count; i++)
	{
		getline(clientText, line);
	}
	clientText.close();
	return line;
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
	
	UdpEchoClientHelper echoClient2 (interfaces.GetAddress (m_xSize*m_ySize-1), 9);
	echoClient2.SetAttribute ("MaxPackets", UintegerValue (1));
	echoClient2.SetAttribute ("Interval", TimeValue (Seconds (m_packetInterval)));
	echoClient2.SetAttribute ("PacketSize", UintegerValue (m_packetSize));
	
	
	ApplicationContainer clientApps = echoClient.Install (nodes.Get (0));
	clientApps.Add(echoClient.Install(nodes.Get(1)));
	
	ApplicationContainer clientApps2 = echoClient2.Install (nodes.Get (0));
	clientApps2.Add(echoClient2.Install(nodes.Get(1)));
	
	cipher c;
	c.init(client_GetKey(0,echoClient.GetCount(clientApps.Get(0))));
	
	std::string plaintext = "Rekey";
	std::string ciphertext = c.encrypt(plaintext);
	c.init(client_GetKey(1,echoClient.GetCount(clientApps.Get(1))));
	std::string ciphertext2 = c.encrypt(plaintext);
	

	
	
	echoClient.SetFill(clientApps.Get(0), ciphertext, 14);
	echoClient.SetAddr(clientApps.Get(0), itoa(interfaces.GetAddress(0).Get(),10));
	echoClient.SetFill(clientApps.Get(1), ciphertext2, 14);
	echoClient.SetAddr(clientApps.Get(1), itoa(interfaces.GetAddress(1).Get(),10));
	
	
	echoClient.SetFill(clientApps2.Get(0), ciphertext, 14);
	echoClient.SetAddr(clientApps2.Get(0), itoa(interfaces.GetAddress(0).Get(),10));
	echoClient.SetFill(clientApps2.Get(1), ciphertext2, 14);
	echoClient.SetAddr(clientApps2.Get(1), itoa(interfaces.GetAddress(1).Get(),10));
	
	
	
	std::cout<<"Client Key1 is "<<client_GetKey(0,100)<<"\n";
	std::cout<<"Client Key2 is "<<client_GetKey(1,100)<<"\n";
	
	
	printf("\n\n\n");
	
	

	serverApps.Start (Seconds (1.0));
	serverApps.Stop (Seconds (m_totalTime));
	clientApps.Start (Seconds (2.0));
	clientApps.Stop (Seconds (5));
	
	clientApps2.Start (Seconds (6.0));
	clientApps2.Stop (Seconds (10));
}

int
MeshTest::Run ()
{
	CreateNodes ();
	InstallInternetStack ();
	PreDeployment();
	InstallApplication ();
	Simulator::Stop (Seconds (m_totalTime));
	Simulator::Run ();
	Simulator::Destroy ();
	ofstream output;
	std::string outputText = "output_mobility/mobility.txt";
	output.open(outputText.c_str());
	output<<mobilityText;
	output.close();
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
