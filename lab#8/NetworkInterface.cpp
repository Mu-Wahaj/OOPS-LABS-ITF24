#include "NetworkInterface.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
NetworkInterface::NetworkInterface(int id, double lossProb, int cap)
    : interfaceID(id), lossProbability(lossProb), capacity(cap), count(0)
{
    receivedPackets = new Packet[capacity];
}

// Copy constructor
NetworkInterface::NetworkInterface(const NetworkInterface &ni)
    : interfaceID(ni.interfaceID), lossProbability(ni.lossProbability),
      capacity(ni.capacity), count(ni.count)
{
    receivedPackets = new Packet[capacity];
    for (int i = 0; i < count; i++)
    {
        receivedPackets[i] = ni.receivedPackets[i]; // Uses Packet's copy constructor
    }
}

NetworkInterface::~NetworkInterface()
{
    delete[] receivedPackets;
}

bool NetworkInterface::sendPacket(const Packet &p)
{
    // Initialize random seed if not already done
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(0));
        seeded = true;
    }

    double randomValue = (double)rand() / RAND_MAX;
    if (randomValue < lossProbability)
    {
        return false; // Packet lost
    }
    return true; // Packet sent successfully
}

void NetworkInterface::receivePacket(const Packet &p)
{
    // Expand array if needed
    if (count >= capacity)
    {
        int newCapacity = capacity * 2;
        Packet *newArray = new Packet[newCapacity];

        for (int i = 0; i < count; i++)
        {
            newArray[i] = receivedPackets[i]; // Deep copy
        }

        delete[] receivedPackets;
        receivedPackets = newArray;
        capacity = newCapacity;
    }

    // Store deep copy of packet
    receivedPackets[count] = p; // Uses Packet's copy constructor
    count++;
}

void NetworkInterface::printStatus() const
{
    cout << "Interface " << interfaceID << " stored packets: " << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "  ";
        receivedPackets[i].printInfo();
        cout << endl;
    }
}

int NetworkInterface::getID() const
{
    return interfaceID;
}