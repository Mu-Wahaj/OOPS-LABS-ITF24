#include <string> 
#include <iostream> 
using namespace std; 
class Vehicle { 
private: 
    string model; 
    int fuelCapacity; 
protected: 
    // Function to check if vehicle is fuel efficient 
    // Return true if fuel capacity > 50 liters 
    bool isFuelEfficient(int capacity); 
     
public: 
    // Constructor with default values 
    Vehicle(string m = "Unknown", int fc = 0); 
    void displayVehicle(); 
    int getFuelCapacity(); 
}; 