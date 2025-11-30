#include "NetworkNode.h"
#include <iostream>
using namespace std;

NetworkNode::NetworkNode(int id, int maxInterfaces, int maxRoutes)
    : nodeID(id), interfaceCount(0), interfaceCapacity(maxInterfaces), routeCount(0) {
    interfaces = new NetworkInterface[interfaceCapacity];
    routingDest = new int[maxRoutes];
    routingIface = new int[maxRoutes];
}

// Copy constructor
NetworkNode::NetworkNode(const NetworkNode& other)
    : nodeID(other.nodeID), interfaceCount(other.interfaceCount),
      interfaceCapacity(other.interfaceCapacity), routeCount(other.routeCount) {
    
    interfaces = new NetworkInterface[interfaceCapacity];
    for (int i = 0; i < interfaceCount; i++) {
        interfaces[i] = other.interfaces[i];
    }
    
    routingDest = new int[interfaceCapacity];
    routingIface = new int[interfaceCapacity];
    for (int i = 0; i < routeCount; i++) {
        routingDest[i] = other.routingDest[i];
        routingIface[i] = other.routingIface[i];
    }
}

NetworkNode::~NetworkNode() {
    delete[] interfaces;
    delete[] routingDest;
    delete[] routingIface;
}

void NetworkNode::addInterface(const NetworkInterface& ni) {
    if (interfaceCount >= interfaceCapacity) {
        // Expand interface array
        int newCapacity = interfaceCapacity * 2;
        NetworkInterface* newInterfaces = new NetworkInterface[newCapacity];
        
        for (int i = 0; i < interfaceCount; i++) {
            newInterfaces[i] = interfaces[i];
        }
        
        delete[] interfaces;
        interfaces = newInterfaces;
        interfaceCapacity = newCapacity;
    }
    
    interfaces[interfaceCount] = ni; // Uses NetworkInterface copy constructor
    interfaceCount++;
}

void NetworkNode::addRoute(int destinationNode, int interfaceID) {
    routingDest[routeCount] = destinationNode;
    routingIface[routeCount] = interfaceID;
    routeCount++;
}

bool NetworkNode::forwardPacket(const Packet& p) {
    int destination = p.getDestination();
    int interfaceID = -1;
    
    // Find route for this destination
    for (int i = 0; i < routeCount; i++) {
        if (routingDest[i] == destination) {
            interfaceID = routingIface[i];
            break;
        }
    }
    
    if (interfaceID == -1) {
        cout << "No route found for destination Node " << destination << endl;
        return false;
    }
    
    // Find the interface
    NetworkInterface* iface = getInterfaceByID(interfaceID);
    if (!iface) {
        cout << "Interface " << interfaceID << " not found on Node " << nodeID << endl;
        return false;
    }
    
    cout << "Node " << nodeID << " forwarding to Node " << destination 
         << " using Interface " << interfaceID << "." << endl;
    
    // Try to send packet
    if (iface->sendPacket(p)) {
        cout << "Packet sent successfully." << endl;
        // If successful, receive a copy
        iface->receivePacket(p);
        return true;
    } else {
        cout << "Packet lost at Interface " << interfaceID << "." << endl;
        return false;
    }
}

NetworkInterface* NetworkNode::getInterfaceByID(int id) {
    for (int i = 0; i < interfaceCount; i++) {
        if (interfaces[i].getID() == id) {
            return &interfaces[i];
        }
    }
    return nullptr;
}

int NetworkNode::getID() const {
    return nodeID;
}

void NetworkNode::printNode() const {
    cout << "Node " << nodeID << ":" << endl;
    cout << "  Interfaces:" << endl;
    for (int i = 0; i < interfaceCount; i++) {
        interfaces[i].printStatus();
    }
    cout << "  Routing Table:" << endl;
    for (int i = 0; i < routeCount; i++) {
        cout << "    Destination " << routingDest[i] << " -> Interface " << routingIface[i] << endl;
    }
}