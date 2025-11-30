#include <iostream>
#include "NetworkSimulator.h"

using namespace std;

int main() {
    cout << "=== Network Packet Transmission System ===" << endl << endl;
    
    // Create network simulator
    NetworkSimulator simulator;
    
    // Create nodes with interfaces
    NetworkNode node1(1);
    NetworkNode node2(2);
    NetworkNode node3(3);
    NetworkNode node4(4);
    NetworkNode node7(7);
    NetworkNode node9(9);
    
    // Add interfaces to nodes (with different loss probabilities)
    NetworkInterface iface10(10, 0.1);  // 10% loss probability
    NetworkInterface iface11(11, 0.2);  // 20% loss probability
    NetworkInterface iface20(20, 0.1);
    NetworkInterface iface22(22, 0.8);  // 80% loss probability for test case 3
    NetworkInterface iface30(30, 0.1);
    NetworkInterface iface40(40, 0.1);
    NetworkInterface iface70(70, 0.1);
    NetworkInterface iface90(90, 0.1);
    
    node1.addInterface(iface10);
    node1.addInterface(iface11);
    node2.addInterface(iface20);
    node3.addInterface(iface30);
    node4.addInterface(iface40);
    node7.addInterface(iface70);
    node9.addInterface(iface90);
    
    // Set up routing tables
    node1.addRoute(2, 10);
    node1.addRoute(4, 11);
    node2.addRoute(3, 20);
    node4.addRoute(7, 22);
    node7.addRoute(9, 70);
    
    // Add nodes to simulator
    simulator.addNode(node1);
    simulator.addNode(node2);
    simulator.addNode(node3);
    simulator.addNode(node4);
    simulator.addNode(node7);
    simulator.addNode(node9);
    
    // Test Case 1: Successful transmission
    cout << "=== Test Case 1: Successful Transmission ===" << endl;
    Packet packet1(50, "HelloWorld", 1, 3);
    int route1[] = {1, 2, 3};
    simulator.sendPacketThroughRoute(packet1, route1, 3);
    cout << endl;
    
    // Test Case 2: Packet loss at first hop
    cout << "=== Test Case 2: Packet Loss at First Hop ===" << endl;
    Packet packet2(77, "DataX", 1, 2);
    int route2[] = {1, 2};
    simulator.sendPacketThroughRoute(packet2, route2, 2);
    cout << endl;
    
    // Test Case 3: Packet lost at middle hop
    cout << "=== Test Case 3: Packet Lost at Middle Hop ===" << endl;
    Packet packet3(200, "EmergencySignal", 1, 9);
    int route3[] = {1, 4, 7, 9};
    simulator.sendPacketThroughRoute(packet3, route3, 4);
    cout << endl;
    
    // Print final network status
    cout << "=== Final Network Status ===" << endl;
    simulator.printNetwork();
    
    return 0;
}