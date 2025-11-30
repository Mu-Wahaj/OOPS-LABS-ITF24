#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Include our simple packet class
#include "SimplePacket.h"

class SimpleNetwork {
private:
    SimplePacket* packets;  // Array to store packets
    int count;
    int capacity;
    double lossRate;

public:
    // Constructor
    SimpleNetwork(int cap = 10, double loss = 0.3) 
        : count(0), capacity(cap), lossRate(loss) {
        packets = new SimplePacket[capacity];
        srand(time(0));  // Initialize random once
    }
    
    // Destructor
    ~SimpleNetwork() {
        delete[] packets;
    }
    
    // Send a packet - returns true if successful
    bool sendPacket(const SimplePacket& packet) {
        // Simulate packet loss
        if ((double)rand() / RAND_MAX < lossRate) {
            cout << "❌ Packet " << packet.getID() << " LOST!" << endl;
            return false;
        }
        
        // Store the packet if not lost
        if (count < capacity) {
            packets[count] = packet;
            count++;
            cout << "✅ Packet " << packet.getID() << " DELIVERED!" << endl;
            return true;
        }
        
        cout << "📦 Buffer FULL! Packet " << packet.getID() << " dropped!" << endl;
        return false;
    }
    
    // Print all stored packets
    void printPackets() const {
        cout << "\n=== STORED PACKETS ===" << endl;
        for (int i = 0; i < count; i++) {
            cout << i+1 << ". ";
            packets[i].print();
        }
        if (count == 0) {
            cout << "No packets stored (all lost or none sent)" << endl;
        }
    }
};

int main() {
    cout << "=== SUPER SIMPLE NETWORK SIMULATION ===" << endl;
    
    // Create network with 30% packet loss
    SimpleNetwork network(5, 0.3);
    
    // Create some simple packets
    SimplePacket packet1(1, "Hello", 1, 2);
    SimplePacket packet2(2, "How are you?", 1, 2);
    SimplePacket packet3(3, "Lunch time!", 1, 2);
    SimplePacket packet4(4, "Meeting at 3", 1, 2);
    SimplePacket packet5(5, "Goodbye!", 1, 2);
    
    // Send packets
    cout << "\n=== SENDING PACKETS ===" << endl;
    network.sendPacket(packet1);
    network.sendPacket(packet2);
    network.sendPacket(packet3);
    network.sendPacket(packet4);
    network.sendPacket(packet5);
    
    // Show what made it through
    network.printPackets();
    
    return 0;
}