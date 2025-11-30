#include "Packet.h"

class NetworkInterface {
private:
 int interfaceID;
 double lossProbability;

 Packet* receivedPackets;//  // dynamically growing array of stored packets
int capacity;//           // current capacity of array
 int count;//                 // number of stored packets

public:
 NetworkInterface(int id = 0, double lossProb = 0.1, int cap = 10);
 NetworkInterface(const NetworkInterface& ni);
~NetworkInterface();

//    // Simulates sending a packet; returns false if packet is lost
bool sendPacket(const Packet& p);

//    // Stores a deep copy of the packet; expands array if needed
void receivePacket(const Packet& p);

//    // Prints interface details and all stored packets
void printStatus() const;

int getID() const;
};