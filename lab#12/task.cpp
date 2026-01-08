#include <iostream>
using namespace std;

class Appliance
{
public:
    virtual void turnOn() = 0;

    virtual void turnOff()
    {
        cout << "Appliance is turning off" << endl;
    }

    virtual ~Appliance()
    {
        cout << "Appliance destroyed" << endl;
    }
};

class WashingMachine : public Appliance
{
public:
    void turnOn() override
    {
        cout << "WashingMachine is starting wash cycle" << endl;
    }
    void turnOff()
    {
        cout << "new " << endl;
    }

    ~WashingMachine() override
    {
        cout << "WashingMachine destroyed" << endl;
    }
};

class Microwave : public Appliance
{
public:
    void turnOn() override
    {
        cout << "Microwave is heating food" << endl;
    }

    ~Microwave() override
    {
        cout << "Microwave destroyed" << endl;
    }
};

int main()
{

    cout << " Creating Appliances " << endl;

    Appliance *appliances[4];

    appliances[0] = new WashingMachine();
    appliances[1] = new Microwave();
    appliances[2] = new WashingMachine();
    appliances[3] = new Microwave();

    cout << "Operating Appliances " << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "Appliance " << i + 1 << ":" << endl;
        appliances[i]->turnOn();
        appliances[i]->turnOff();
    }

    cout << " Cleaning Up " << endl;

    for (int i = 0; i < 4; i++)
    {
        delete appliances[i];
        cout << endl;
    }

    return 0;
}
