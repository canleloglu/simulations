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
#ifndef SEND_HELPER_H
#define SEND_HELPER_H

#include <stdint.h>
#include <string>
#include "ns3/object-factory.h"
#include "ns3/address.h"
#include "ns3/attribute.h"
#include "ns3/net-device.h"
#include "node-container.h"
#include "application-container.h"
#include "ns3/ipv4-address.h"

namespace ns3 {

/**
 * \brief A helper to make it easier to instantiate an ns3::SendApplication 
 * on a set of nodes.
 */
class SendHelper
{
public:
	
	SendHelper (std::string protocol, Address address);
	void setAddr(Ptr<Application> app, Ipv4Address addr);
	
  /**
   * Create an SendHelper to make it easier to work with SendApplications
   *
   * \param protocol the name of the protocol to use to send traffic
   *        by the applications. This string identifies the socket
   *        factory type used to create sockets for the applications.
   *        A typical value would be ns3::UdpSocketFactory.
   * \param address the address of the remote node to send traffic
   *        to.
   */
  

  /**
   * Helper function used to set the underlying application attributes.
   *
   * \param name the name of the application attribute to set
   * \param value the value of the application attribute to set
   */
  void SetAttribute (std::string name, const AttributeValue &value);

  /**
   * Install an ns3::SendApplication on each node of the input container
   * configured with all the attributes set with SetAttribute.
   *
   * \param c NodeContainer of the set of nodes on which an SendApplication 
   * will be installed.
   * \returns Container of Ptr to the applications installed.
   */
  ApplicationContainer Install (NodeContainer c) const;

  /**
   * Install an ns3::SendApplication on the node configured with all the 
   * attributes set with SetAttribute.
   *
   * \param node The node on which an SendApplication will be installed.
   * \returns Container of Ptr to the applications installed.
   */
  ApplicationContainer Install (Ptr<Node> node) const;

  /**
   * Install an ns3::SendApplication on the node configured with all the 
   * attributes set with SetAttribute.
   *
   * \param nodeName The node on which an SendApplication will be installed.
   * \returns Container of Ptr to the applications installed.
   */
  ApplicationContainer Install (std::string nodeName) const;
	
	
	void setPacketId(Ptr<Application> app, uint64_t val);
	void setDirection(Ptr<Application> app, std::string s);
	void setNetType(Ptr<Application> app, std::string s);

private:
  /**
   * \internal
   * Install an ns3::SendApplication on the node configured with all the 
   * attributes set with SetAttribute.
   *
   * \param node The node on which an SendApplication will be installed.
   * \returns Ptr to the application installed.
   */
  Ptr<Application> InstallPriv (Ptr<Node> node) const;
  std::string m_protocol;
  Address m_remote;
  ObjectFactory m_factory;
};

} // namespace ns3

#endif /* ON_OFF_HELPER_H */

