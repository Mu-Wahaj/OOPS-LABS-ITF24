#ifndef SIMPLEPACKET_H
#define SIMPLEPACKET_H
#include <iostream>
#include <string>
using namespace std;

class SimplePacket {
private:
    int id;
    string message;  // Using string instead of char* - NO MEMORY MANAGEMENT!
    int source;
    int destination;

public:
    // Simple constructor
    SimplePacket(int id = 0, string msg = "", int src = 0, int dest = 0);
    
    // Print function
    void print() const;
    
    // Getters
    int getID() const;
    string getMessage() const;
    int getSource() const;
    int getDestination() const;
};

#endif
