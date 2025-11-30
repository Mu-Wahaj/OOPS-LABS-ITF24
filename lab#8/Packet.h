
#ifndef PACKET_H
#define PACKET_H
class Packet
{
private:
    int id;
    char *payload; //// dynamically allocated payload text
    int sourceID;
    int destinationID;

public:
    Packet(int id = 0, const char *p = "", int sourceID = 0, int destinationID = 0);

  
    Packet(const Packet &other);

    //     // Destructor: releases allocated payload memory
    ~Packet();
    void setID();
    void setSource();
    void setName(const char *);
    void setDestination();
    int getID() const;
    int getSource() const;
    int getDestination() const;
    const char *getPayload() const;

    //     // Prints packet information (ID, source, destination, payload)
    void printInfo() const;
};
#endif