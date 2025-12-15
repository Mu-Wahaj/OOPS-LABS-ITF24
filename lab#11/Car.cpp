#include "Car.h"

Car::Car(string model, int fuelCapacity, string type) 
    : Vehicle(model, fuelCapacity), carType(type) {}

void Car::showCarDetails() {
    cout << " Car Details " << endl;
    displayVehicle();
    cout << "Car Type: " << carType << endl;
    
    if (isFuelEfficient(getFuelCapacity())) {
        cout << "Fuel Efficiency:  Fuel Efficient " << endl;
    } else {
        cout << "Fuel Efficiency: Not Fuel Efficient" << endl;
    }
}