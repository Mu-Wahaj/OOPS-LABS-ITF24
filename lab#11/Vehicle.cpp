#include "Vehicle.h"

Vehicle::Vehicle(string m, int fc) : model(m), fuelCapacity(fc) {}

bool Vehicle::isFuelEfficient(int capacity) {
    return capacity > 50;  
}

void Vehicle::displayVehicle() {
    cout << "Model: " << model << endl;
    cout << "Fuel Capacity: " << fuelCapacity << " liters" << endl;
}

int Vehicle::getFuelCapacity() {
    return fuelCapacity;
}