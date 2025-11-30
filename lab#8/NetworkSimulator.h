#include "NetworkNode.h"

class NetworkSimulator {
private:
NetworkNode* nodes;//   // dynamic array of nodes
int nodeCount;
int capacity;

public:
NetworkSimulator(int cap = 10);
~NetworkSimulator();

//    // Adds a node to the simulator (deep copy into array)
void addNode(const NetworkNode& n);

//   // Retrieves node by ID (returns pointer)
NetworkNode* getNode(int id);

//    // Sends a packet across multiple hops using a route array
void sendPacketThroughRoute(const Packet& p, int* route, int length);

//    // Prints all nodes, interfaces, and stored packets
void printNetwork() const;
};