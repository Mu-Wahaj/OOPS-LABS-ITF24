#include "NetworkInterface.h"

class NetworkNode {
private:
int nodeID;
NetworkInterface* interfaces;// dynamic array of interfaces
 int interfaceCount;
int interfaceCapacity;

int* routingDest; // routing table: destination nodes
int* routingIface;// for each destination, interface to use
int routeCount;
    int routeCapacity;  // ✅ ADD THIS!


public:
NetworkNode(int id = 0, int maxInterfaces = 5, int maxRoutes = 10);
NetworkNode(const NetworkNode& other);
~NetworkNode();

//    // Deep copies an interface into the node (expand array if needed)
void addInterface(const NetworkInterface& ni);
//    // Adds a routing rule: destination node → interface ID
void addRoute(int destinationNode, int interfaceID);
// // Attempts to forward packet using appropriate interface; returns false on loss
bool forwardPacket(const Packet& p);
//    // Returns pointer to interface with matching ID
NetworkInterface* getInterfaceByID(int id);
int getID() const;
// Prints node information, interfaces, and routing table
void printNode() const;
};