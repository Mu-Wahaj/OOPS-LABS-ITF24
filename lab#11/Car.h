#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>
using namespace std;

class Car : public Vehicle {
private:
    string carType; 

public:
    
    Car(string model, int fuelCapacity, string type);

    
    void showCarDetails();
};

#endif