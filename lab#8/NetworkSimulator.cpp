#include "NetworkSimulator.h"
#include <iostream>
using namespace std;
NetworkSimulator::NetworkSimulator(int cap)
    : nodeCount(0), capacity(cap)
{
    nodes = new NetworkNode[capacity];
}

NetworkSimulator::~NetworkSimulator()
{
    delete[] nodes;
}

void NetworkSimulator::addNode(const NetworkNode &n)
{
    if (nodeCount >= capacity)
    {
        // Expand node array
        int newCapacity = capacity * 2;
        NetworkNode *newNodes = new NetworkNode[newCapacity];

        for (int i = 0; i < nodeCount; i++)
        {
            newNodes[i] = nodes[i];
        }

        delete[] nodes;
        nodes = newNodes;
        capacity = newCapacity;
    }

    nodes[nodeCount] = n; // Uses NetworkNode copy constructor
    nodeCount++;
}

NetworkNode *NetworkSimulator::getNode(int id)
{
    for (int i = 0; i < nodeCount; i++)
    {
        if (nodes[i].getID() == id)
        {
            return &nodes[i];
        }
    }
    return nullptr;
}

void NetworkSimulator::sendPacketThroughRoute(const Packet &p, int *route, int length)
{
    cout << "Starting transmission of ";
    p.printInfo();
    cout << "." << endl;

    for (int i = 0; i < length - 1; i++)
    {
        int currentNodeID = route[i];
        NetworkNode *currentNode = getNode(currentNodeID);

        if (!currentNode)
        {
            cout << "Node " << currentNodeID << " not found in network!" << endl;
            return;
        }

        if (!currentNode->forwardPacket(p))
        {
            cout << "Transmission aborted";
            if (i > 0)
            {
                cout << " at hop " << i + 1;
            }
            cout << "." << endl;
            return;
        }
    }

    // Packet reached final node - store it there
    int finalNodeID = route[length - 1];
    NetworkNode *finalNode = getNode(finalNodeID);
    if (finalNode)
    {
        // Find any interface to store the packet
        NetworkInterface *iface = finalNode->getInterfaceByID(finalNodeID * 10); // Simple heuristic
        if (iface)
        {
            iface->receivePacket(p);
        }
    }

    cout << "Packet delivered to final node " << finalNodeID << "." << endl;
}

void NetworkSimulator::printNetwork() const
{
    cout << "Final Network Status:" << endl;
    for (int i = 0; i < nodeCount; i++)
    {
        nodes[i].printNode();
    }
}