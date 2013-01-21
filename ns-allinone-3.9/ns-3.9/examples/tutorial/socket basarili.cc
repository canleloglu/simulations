#include <iostream>

#include "ns3/core-module.h"
#include "ns3/helper-module.h"
#include "ns3/node-module.h"
#include "ns3/simulator-module.h"

using namespace ns3;

static void
GenerateTraffic (Ptr<Socket> socket, uint32_t size)
{
	std::cout << "at=" << Simulator::Now ().GetSeconds () << "s, tx bytes=" << size << std::endl;
	socket->Send (Create<Packet> (size));
	if (size > 0)
    {
		Simulator::Schedule (Seconds (0.5), &GenerateTraffic, socket, size - 50);
    }
	else
    {
		socket->Close ();
    }
}

static void
SocketPrinter (Ptr<Socket> socket)
{
	Ptr<Packet> packet;
	while (packet = socket->Recv ())
    { 
		std::cout << "at=" << Simulator::Now ().GetSeconds () << "s, rx bytes=" << packet->GetSize () << std::endl;
    }
}

static void
PrintTraffic (Ptr<Socket> socket)
{
	socket->SetRecvCallback (MakeCallback (&SocketPrinter));
}
 

void
RunSimulation (void)
{
	NodeContainer c;
	c.Create (2);
	
	
	PointToPointHelper pointToPoint;
	pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
	pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));
	
	NetDeviceContainer p2pDevices;
	p2pDevices = pointToPoint.Install (c);
	
	InternetStackHelper internet;
	internet.Install (c);
	
	Ipv4AddressHelper address;
	address.SetBase ("10.1.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces;
	p2pInterfaces = address.Assign (p2pDevices);
	
	
	
	
	
	TypeId tid = TypeId::LookupByName ("ns3::UdpSocketFactory");
	Ptr<Socket> sink = Socket::CreateSocket (c.Get (0), tid);
	InetSocketAddress local = InetSocketAddress (p2pInterfaces.GetAddress(0), 80);
	sink->Bind (local);
	
	Ptr<Socket> source = Socket::CreateSocket (c.Get (0), tid);
	InetSocketAddress remote = InetSocketAddress (p2pInterfaces.GetAddress(1), 80);
	source->Connect (remote);
	
	GenerateTraffic (source, 500);
	PrintTraffic (sink);
	
	pointToPoint.EnablePcapAll("dene");
	
	Simulator::Run ();
	
	Simulator::Destroy ();
}

int main (int argc, char *argv[])
{
	RunSimulation ();
	
	return 0;
}