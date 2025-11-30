#include "Packet.h"
#include <cstring>
#include <iostream>
using namespace std;
Packet::Packet(int id, const char* payload, int sourceID, int destinationID)
    : id(id), sourceID(sourceID), destinationID(destinationID) {
    // Allocate memory for payload and copy content
    this->payload = new char[strlen(payload) + 1];
    strcpy(this->payload, payload);
}

// Deep copy constructor
Packet::Packet(const Packet& other) 
    : id(other.id), sourceID(other.sourceID), destinationID(other.destinationID) {
    payload = new char[strlen(other.payload) + 1];
    strcpy(payload, other.payload);
}

// Destructor
Packet::~Packet() {
    delete[] payload;
}

int Packet::getID() const {
    return id;
}

int Packet::getSource() const {
    return sourceID;
}

int Packet::getDestination() const {
    return destinationID;
}

const char* Packet::getPayload() const {
    return payload;
}

void Packet::printInfo() const {
    cout << "Packet " << id << " (" << payload << ") from Node " 
         << sourceID << " to Node " << destinationID;
}