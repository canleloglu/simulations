/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2008 INRIA
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
 * Author: Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 */
#include "udp-echo-helper.h"
#include "ns3/udp-echo-server.h"
#include "ns3/udp-echo-client.h"
#include "ns3/uinteger.h"
#include "ns3/names.h"

namespace ns3 {

UdpEchoServerHelper::UdpEchoServerHelper (uint16_t port)
{
  m_factory.SetTypeId (UdpEchoServer::GetTypeId ());
  SetAttribute ("Port", UintegerValue(port));
}

void 
UdpEchoServerHelper::SetAttribute (
  std::string name, 
  const AttributeValue &value)
{
  m_factory.Set (name, value);
}

ApplicationContainer
UdpEchoServerHelper::Install (Ptr<Node> node) const
{
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
UdpEchoServerHelper::Install (std::string nodeName) const
{
  Ptr<Node> node = Names::Find<Node> (nodeName);
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
UdpEchoServerHelper::Install (NodeContainer c) const
{
  ApplicationContainer apps;
  for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
    {
      apps.Add (InstallPriv (*i));
    }

  return apps;
}

Ptr<Application>
UdpEchoServerHelper::InstallPriv (Ptr<Node> node) const
{
  Ptr<Application> app = m_factory.Create<UdpEchoServer> ();
  node->AddApplication (app);
  
  return app;
}
	
	void
	UdpEchoServerHelper::SetKey(Ptr<Application> app, std::string k)
	{
		app->GetObject<UdpEchoServer>()->SetKey(k);
	}
	
	void 
	UdpEchoServerHelper::setIpv4Addr(Ptr<Application> app, Ipv4Address ad)
	{
		app->GetObject<UdpEchoServer>()->setIpv4Addr(ad);
	}
	
	
	std::string
	UdpEchoServerHelper::GetKey(Ptr<Application> app)
	{
		return app->GetObject<UdpEchoServer>()->GetKey();
	}
	
	void UdpEchoServerHelper::setDelay(Ptr<Application> app, Time t)
	{
		app->GetObject<UdpEchoServer>()->setDelay(t);
	}

UdpEchoClientHelper::UdpEchoClientHelper (Ipv4Address address, uint16_t port)
{
  m_factory.SetTypeId (UdpEchoClient::GetTypeId ());
  SetAttribute ("RemoteAddress", Ipv4AddressValue (address));
  SetAttribute ("RemotePort", UintegerValue (port));
}

	
void 
UdpEchoClientHelper::SetAttribute (
  std::string name, 
  const AttributeValue &value)
{
  m_factory.Set (name, value);
}

void
UdpEchoClientHelper::SetFill (Ptr<Application> app, std::string fill)
{
  app->GetObject<UdpEchoClient>()->SetFill (fill);
}
	
	void
	UdpEchoClientHelper::SetFill (Ptr<Application> app, std::string fill, int nonce)
	{
		app->GetObject<UdpEchoClient>()->SetFill (fill, nonce);
	}
	
	void
	UdpEchoClientHelper::SetKey(Ptr<Application> app, std::string k)
	{
		app->GetObject<UdpEchoClient>()->SetKey(k);
	}
	int
	UdpEchoClientHelper::GetCount(Ptr<Application> app)
	{
		return app->GetObject<UdpEchoClient>()->GetCount();
	}
	
	std::string
	UdpEchoClientHelper::GetKey(Ptr<Application> app)
	{
		return app->GetObject<UdpEchoClient>()->GetKey();
	}
	void
	UdpEchoClientHelper::SetAddr(Ptr<Application> app, Ipv4Address addr)
	{
		return app->GetObject<UdpEchoClient>()->SetAddr(addr);
	}
	void 
	UdpEchoClientHelper::setPacketId(Ptr<Application> app, uint64_t val)
	{
		app->GetObject<UdpEchoClient>()->setPacketId(val);
	}
	void UdpEchoClientHelper::setDelay(Ptr<Application> app, Time t)
	{
		app->GetObject<UdpEchoClient>()->setDelay(t);
	}

void
UdpEchoClientHelper::SetFill (Ptr<Application> app, uint8_t fill, uint32_t dataLength)
{
  app->GetObject<UdpEchoClient>()->SetFill (fill, dataLength);
}

void
UdpEchoClientHelper::SetFill (Ptr<Application> app, uint8_t *fill, uint32_t fillLength, uint32_t dataLength)
{
  app->GetObject<UdpEchoClient>()->SetFill (fill, fillLength, dataLength);
}

ApplicationContainer
UdpEchoClientHelper::Install (Ptr<Node> node) const
{
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
UdpEchoClientHelper::Install (std::string nodeName) const
{
  Ptr<Node> node = Names::Find<Node> (nodeName);
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer
UdpEchoClientHelper::Install (NodeContainer c) const
{
  ApplicationContainer apps;
  for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
    {
      apps.Add (InstallPriv (*i));
    }

  return apps;
}

Ptr<Application>
UdpEchoClientHelper::InstallPriv (Ptr<Node> node) const
{
	Ptr<Application> app = m_factory.Create<UdpEchoClient> ();
  node->AddApplication (app);
  
  return app;
}

} // namespace ns3
