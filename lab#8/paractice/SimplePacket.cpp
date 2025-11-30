#include "SimplePacket.h"

// Constructor - SUPER SIMPLE!
SimplePacket::SimplePacket(int id, string msg, int src, int dest)
    : id(id), message(msg), source(src), destination(dest) {
    // No dynamic memory! String handles everything automatically!
}

void SimplePacket::print() const {
    cout << "Packet " << id << ": '" << message 
         << "' from " << source << " to " << destination << endl;
}

int SimplePacket::getID() const { return id; }
string SimplePacket::getMessage() const { return message; }
int SimplePacket::getSource() const { return source; }
int SimplePacket::getDestination() const { return destination; }