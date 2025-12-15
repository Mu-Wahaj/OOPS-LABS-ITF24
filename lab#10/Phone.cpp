#include <iostream>
using namespace std;
#include <string>
#include "Phone.h"
MobilePhone::MobilePhone() : manufacturer("Unknown"), model("Unknown"), poweredOn(false) {}
MobilePhone::MobilePhone(const string &manufacturer, const string &model)
    : manufacturer(manufacturer), model(model), poweredOn(false) {}
MobilePhone::~MobilePhone() {}

void MobilePhone::turnOn()
{
    poweredOn = true;
}
void MobilePhone::turnOff()
{
    poweredOn = false;
}
bool MobilePhone::isPoweredOn() const
{
    return poweredOn;
}
string MobilePhone::getManufacturer() const
{
    return manufacturer;
}
string MobilePhone::getModel() const
{
    return model;
}
void MobilePhone::setManufacturer(const string &manufacturer)
{
    this->manufacturer = manufacturer;
}
void MobilePhone::setModel(const string &model)
{
    this->model = model;
}
void MobilePhone::showInfo() const
{
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Powered On: " <<poweredOn << endl;
    cout << "Model: " << model << endl;
}
