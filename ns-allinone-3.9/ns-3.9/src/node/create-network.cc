/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 */
#include <iostream>
#include <errno.h>
#include "ns3/log.h"
#include "ns3/wifi-mac.h"
#include "ns3/string.h"
#include "ns3/internet-stack-helper.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/object.h"
#include "ns3/ipv4.h"
#include "ns3/ipv4-address-helper.h"
#include "ns3/mobility-helper.h"
#include "ns3/names.h"


#include "create-network.h"



NS_LOG_COMPONENT_DEFINE ("create-network");

namespace ns3
{
	
	CreateNetwork::CreateNetwork ()
	{
		NS_LOG_FUNCTION_NOARGS ();
		NetworkConfig m_networkDataStruct;
		m_networkData = m_networkDataStruct.m_networkData;
		NS_LOG_INFO ("CreateNetwork() constructor");
		m_nNodes = 0;
	}
	
	CreateNetwork::~CreateNetwork ()
	{
		NS_LOG_FUNCTION_NOARGS ();
	}
	
	TypeId
	CreateNetwork::GetTypeId (void)
	{
		static TypeId  tid = TypeId ("ns3::CreateNetwork");
		return tid;
	}
	
	void
	CreateNetwork::SetPhy (void)
	{
		for (uint32_t i = 0; i < m_vectorChannelData.size (); i++)
		{
			YansWifiPhyHelper phy = YansWifiPhyHelper::Default ();
			YansWifiChannelHelper channel = YansWifiChannelHelper::Default ();
			phy.SetChannel (channel.Create ());
			m_vectorWifiPhy.push_back (phy);
		}
	}
	
	void
	CreateNetwork::SetAddresser (void)
	{
		std::ostringstream network;
		for (uint32_t i = 0; i < m_vectorChannelData.size (); i++)
		{
			Ipv4AddressHelper addressHelper;
			network.str ("");
			network << "10.1." << i + 1 << ".0";
			std::string net = network.str ();
			NS_LOG_DEBUG ("Network: " << network.str ());
			addressHelper.SetBase (net.c_str (), "255.255.255.0");
			m_vectorAddresser.push_back (addressHelper);
		}
	}
	
	NqosWifiMacHelper
	CreateNetwork::SetNqosMac (NetworkConfig::DeviceData deviceData)
	{
		NqosWifiMacHelper mac = NqosWifiMacHelper::Default ();
		
		//ssid name
		std::ostringstream oss;
		oss.str ("");
		oss << "ssid-" << deviceData.chId;
		Ssid ssid = Ssid (oss.str ());
		
		switch (deviceData.macType)
		{
			case NetworkConfig::AP :
				mac.SetType ("ns3::NqapWifiMac",
							 "Ssid", SsidValue (ssid),
							 "BeaconGeneration", BooleanValue (true),
							 "BeaconInterval", TimeValue (Seconds (10)));
				NS_LOG_DEBUG ("  Access Point");
				break;
			case NetworkConfig::STA :
				mac.SetType ("ns3::NqstaWifiMac",
							 "Ssid", SsidValue (ssid),
							 "ActiveProbing", BooleanValue (false));
				NS_LOG_DEBUG ("  Station");
				break;
			case NetworkConfig::ADHOC :
				mac.SetType ("ns3::AdhocWifiMac");
				NS_LOG_DEBUG ("  Ad-Hoc");
				break;
			default:
				NS_LOG_ERROR ("  No correct MAC type selected");
				exit (-1);
		}
		return mac;
	}
	
	QosWifiMacHelper
	CreateNetwork::SetQosMac (NetworkConfig::DeviceData deviceData)
	{
		QosWifiMacHelper mac = QosWifiMacHelper::Default ();
		
		//ssid name
		std::ostringstream oss;
		oss.str ("");
		oss << "ssid-" << deviceData.chId;
		Ssid ssid = Ssid (oss.str ());
		
		switch (deviceData.macType)
		{
			case NetworkConfig::QAP :
				mac.SetType ("ns3::QapWifiMac", "Ssid", SsidValue (ssid),
							 "BeaconGeneration", BooleanValue (true),
							 "BeaconInterval", TimeValue (Seconds (2.5)));
				break;
			case NetworkConfig::QSTA :
				mac.SetType ("ns3::QstaWifiMac",
							 "Ssid", SsidValue (ssid),
							 "ActiveProbing", BooleanValue (false));
				NS_LOG_DEBUG ("  QoS Station");
				break;
			case NetworkConfig::QADHOC :
				mac.SetType ("ns3::QadhocWifiMac");
				NS_LOG_DEBUG ("  QoS Ad-Hoc");
				break;
			default:
				NS_LOG_ERROR ("  No correct MAC type selected");
				exit (-1);
		}
		return mac;
	}
	
	void
	CreateNetwork::SetAddress (NetDevice &device, Ipv4Address address)
	{
		NS_LOG_FUNCTION_NOARGS ();
		
		Ptr<Node> node = device.GetNode ();
		NS_ASSERT_MSG (node, "Ipv4AddressHelper::Allocate(): Bad node");
		
		Ptr<Ipv4> ipv4 = node->GetObject<Ipv4 > ();
		NS_ASSERT_MSG (ipv4, "Ipv4AddressHelper::Allocate(): Bad ipv4");
		
		int32_t interface = ipv4->GetInterfaceForDevice (&device);
		if (interface == -1)
		{
			interface = ipv4->AddInterface (&device);
		}
		NS_ASSERT_MSG (interface >= 0, "Ipv4AddressHelper::Allocate(): "
					   "Interface index not found");
		
		Ipv4InterfaceAddress ipv4Addr = Ipv4InterfaceAddress (address, "255.255.255.0");
		NS_LOG_DEBUG ("Ipv4Addr: " << ipv4Addr);
		//NS_LOG_DEBUG ("Ipv4Addr: " << ipv4->Address);
		ipv4->AddAddress (interface, ipv4Addr);
		ipv4->SetMetric (interface, 1);
		ipv4->SetUp (interface);
	}
	
	void
	CreateNetwork::SetAllNodes (void)
	{
		NetDeviceContainer devices;
		for (uint32_t i = 0; i < m_nNodes; i++)
		{
			/*
			 * Node installation
			 */
			NS_LOG_INFO ("Node installation " << i << " of " << m_nNodes);
			NetworkConfig::NodeData nodeData = m_vectorNodeData[i];
			Names::Add (nodeData.name, m_nodes.Get (i));
			
			NS_LOG_INFO ("  Device Installation");
			for (uint32_t j = 0; j < nodeData.vectorDeviceData.size (); j++)
			{
				/*
				 * Device installation
				 */
				NS_LOG_INFO ("  Device " << j);
				NetworkConfig::DeviceData deviceData = nodeData.vectorDeviceData[j];
				NetDeviceContainer device = DeviceInstallation (deviceData, m_nodes.Get (i));
				devices.Add (device);
				//Names::Add (deviceData.name, device.Get (0)); Doesn't work but It's not important: for improvements
				
			}
		}
		//Turn on global static routing
		Ipv4GlobalRoutingHelper::PopulateRoutingTables ();
		
	}
	
	NetDeviceContainer
	CreateNetwork::DeviceInstallation (NetworkConfig::DeviceData deviceData, Ptr<Node> node)
	{
		NS_LOG_DEBUG ("Ch ID: " << deviceData.chId << " MAC type: " << deviceData.macType);
		
		uint16_t index = deviceData.chId - 1;
		
		WifiHelper wifi = WifiHelper::Default ();
		
		YansWifiPhyHelper phy;
		phy = m_vectorWifiPhy.at (index);
		
		Ipv4AddressHelper address;
		address = m_vectorAddresser.at (index);
		
		
		std::string mode = m_vectorChannelData.at (index).mode;
		wifi.SetRemoteStationManager ("ns3::ConstantRateWifiManager",
									  "DataMode", StringValue (mode));
		
		//  WifiMacHelper mac = SetMac (deviceData.macType);
		// WifiMacHelper is an abstract class with virtual methods.
		// Must think on templates, base classes...
		
		NetDeviceContainer device;
		
		if (deviceData.macType <= NetworkConfig::ADHOC)
		{
			NqosWifiMacHelper mac = SetNqosMac (deviceData);
			device = wifi.Install (phy, mac, node);
		}
		else
		{
			QosWifiMacHelper mac = SetQosMac (deviceData);
			device = wifi.Install (phy, mac, node);
		}
		
		if (deviceData.address.IsEqual (""))
		{
			address.Assign (device);
		}
		else
		{
			SetAddress (*device.Get (0), Ipv4Address (deviceData.address));
		}
		
		
		m_vectorAddresser.at (index) = address; ///< Need to update the object!?, const reference vs reference
		
		return device;
	}
	
	NodeContainer
	CreateNetwork::Create (NetworkConfig::NetworkData networkData)
	{
		// Reading network information data
		m_networkData = networkData;
		m_vectorNodeData = m_networkData.vectorNodeData;
		m_vectorChannelData = m_networkData.vectorChannelData;
		
		NS_LOG_INFO ("Create nodes.");
		m_nNodes = m_vectorNodeData.size (); //number of nodes
		m_nodes.Create (m_nNodes);
		
		
		// Install network stacks on the nodes
		InternetStackHelper internet;
		internet.Install (m_nodes);
		
		NS_LOG_INFO ("Create channels.");
		SetPhy ();
		//class WimaxPhy : public Object
		//  It doesn't derive from yans
		
		SetAddresser ();
		
		//Node Configuration 
		SetAllNodes ();
		
		/*
		 * Mobility
		 */
		NS_LOG_INFO ("Mobility");
		MobilityHelper mobility;
		mobility.InstallAll ();
		
		/*
		 * Traces: pcap
		 */
		NS_LOG_INFO ("Enabling pcap traces");
		m_vectorWifiPhy.at (0).EnablePcapAll ("cusco"); //We only need a YansWifiPhyHelper
		
		return m_nodes; // return all nodes
	}
	
} // namespace ns3
