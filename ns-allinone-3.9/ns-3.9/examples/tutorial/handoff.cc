#include "ns3/core-module.h" 
#include "ns3/simulator-module.h" 
#include "ns3/node-module.h" 
#include "ns3/helper-module.h" 
#include "ns3/wifi-module.h" 
#include "ns3/mobility-module.h" 

// Handoff Network Topology 
// 
//    ʘ (Mobile_Station)⇛⇛⇛⇛⇛⇛⇛⇛⇛⇛⇛⇛⇛⇛  (向这个方向移动) (WIFI 10.1.3.0) 
//                   
//                                                                                                              Point-2-Point(10.1.1.0) 
//    *               *               *               * ============= ⊛  Static_Node (10.1.2.0) 
//    |               |                           |                               | 
//   AP              AP                           AP                      AP 
//   

using namespace ns3; 

NS_LOG_COMPONENT_DEFINE("Hand-Off"); 

int main(int argc, char *argv[]) 
{ 
    bool verbose = true; 
    uint32_t numAPs = 3; 
    
    CommandLine cmd; 
    cmd.AddValue("numAPs", "The number of APs", numAPs); 
    cmd.AddValue("verbose", "Tell Application to log if true", verbose); 
    cmd.Parse(argc, argv); 
    
    if (verbose) { 
        LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO); 
        LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO); 
    } 
    
    NodeContainer wifiStationNodes; //生成一个Station节点 
    wifiStationNodes.Create(1); 
    
    NodeContainer wifiAPNodes;              //生成numAPs数量的AP节点 
    wifiAPNodes.Create(numAPs); 
    
    NodeContainer p2pNodes;                 //AP和固定的Static_Node-用作p2p链接 
    p2pNodes.Create(2); 
    
    PointToPointHelper p2pHelper;   //生成p2p的链接helper 
    p2pHelper.SetDeviceAttribute("DataRate", StringValue("5Mbps")); 
    p2pHelper.SetChannelAttribute("Delay", StringValue("2ms")); 
    
    NetDeviceContainer p2pDevices; 
    p2pDevices = p2pHelper.Install(p2pNodes); 
    
    //NetDeviceContainer staticDevice; 
    //staticDevice = p2pHelper.Install(Static_Node); 
    
    wifiAPNodes.Add(p2pNodes.Get(0));               //将p2pNodes的0号作为一个AP 
    
    NodeContainer Static_Node;                              //将p2pNodes的1号作为固定的节点 
    Static_Node.Add(p2pNodes.Get(1)); 
    //Static_Node.Create(1); 
    
    YansWifiChannelHelper channel = YansWifiChannelHelper::Default();       //设置好物理层 
    YansWifiPhyHelper phy = YansWifiPhyHelper::Default(); 
    phy.SetChannel(channel.Create()); 
    
    WifiHelper wifi = WifiHelper::Default(); 
    wifi.SetRemoteStationManager("ns3::AarfWifiManager"); 
    
    NqosWifiMacHelper mac = NqosWifiMacHelper::Default ();  //设置好Mac层 
    
    Ssid ssid = Ssid("Hand-Off-ns3"); 
    mac.SetType("ns3::NqstaWifiMac", "Ssid", SsidValue(ssid), "ActiveProbing", BooleanValue(false)); 
    //mac.SetType("ns3::NqosWifiMac", "Ssid", SsidValue(ssid), "ActiveProbing", BooleanValue(true)); 
    
    NetDeviceContainer stationDevices; 
    stationDevices = wifi.Install(phy, mac, wifiStationNodes); 
    
    mac.SetType("ns3::NqapWifiMac", "Ssid", SsidValue(ssid)); 
    
    NetDeviceContainer apDevices; 
    apDevices = wifi.Install(phy, mac, wifiAPNodes); 
    
    //下面是设置AP和station的位置 
    Vector3D AP1_Position(0.0, 50.0, 0.0); 
    Vector3D AP2_Position(50.0, 50.0, 0.0); 
    Vector3D AP3_Position(100.0, 50.0, 0.0); 
    Vector3D AP4_Position(150.0, 50.0, 0.0); 
    
    ListPositionAllocator myListPositionAllocator; 
    myListPositionAllocator.Add(AP1_Position); 
    myListPositionAllocator.Add(AP2_Position); 
    myListPositionAllocator.Add(AP3_Position); 
    myListPositionAllocator.Add(AP4_Position); 
    
    MobilityHelper mobility; 
    
    mobility.SetPositionAllocator(&myListPositionAllocator); 
    
    /* 
     先设置一下固定的位置 
     */ 
    
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");      //将AP的位置固定,先设置为固定位置模型 
    mobility.Install(wifiAPNodes); 
    
    ObjectVectorValue stationObjectVectorValue; 
    ConstantVelocityHelper stationVelocity; 
 
    ns3::Vector stationSpeed(10.0, 0.0, 0.0); 
    mobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel", 
                              "Velocity", 
                              Vector3DValue(stationSpeed));
    mobility.Install(wifiStationNodes); 
    //上面是设置AP和station的位置 
    
    InternetStackHelper stack; 
    stack.Install(wifiStationNodes); 
    stack.Install(wifiAPNodes); 
    stack.Install(Static_Node); 
    
    Ipv4AddressHelper address;                                               
    address.SetBase("10.1.1.0", "255.255.255.0");       //将Point-2-Point部分的IP设置为 10.1.1.0 
    Ipv4InterfaceContainer p2pInterfaces; 
    p2pInterfaces = address.Assign(p2pDevices); 
    
    //address.SetBase("10.1.2.0", "255.255.255.0");     //将固定节点的IP设置为 10.1.2.0 
    //Ipv4InterfaceContainer staticNodeInterfaces; 
    //staticNodeInterfaces = address.Assign();              //设备? 
    
    address.SetBase("10.1.3.0", "255.255.255.0");       //将WIFI部分的IP设置为 10.1.3.0 
    address.Assign(stationDevices); 
    address.Assign(apDevices); 
    
    UdpEchoServerHelper echoServer(9); 
    ApplicationContainer servApps = echoServer.Install(Static_Node); 
    servApps.Start(Seconds(1.0)); 
    servApps.Stop(Seconds(17.0)); 
    
    UdpEchoClientHelper echoClient(p2pInterfaces.GetAddress(0 , 1), 9); 
    
    ApplicationContainer clientApps = echoClient.Install(wifiStationNodes); 
    clientApps.Start(Seconds(2.0)); 
    clientApps.Stop(Seconds(17.0)); 
    
    Ipv4GlobalRoutingHelper::PopulateRoutingTables(); 
    Simulator::Stop(Seconds(17.0)); 
    
    //phy.EnablePcap("AP", apDevices.Get(numAPs)); 
    //mac.EnablePcapALL("MAC", stationDevices); 
    //AsciiTraceHelper ascii; 
    //phy.EnableAsciiAll(ascii.CreateFileStream("phy.tr")); 
    //mac.EnableAsciiAll(ascii.CreateFilesStream("mac.tr")); 
    
    Simulator::Run(); 
    Simulator::Destroy(); 
    return 0; 
    
} 