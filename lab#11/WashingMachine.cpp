#include "WashingMachine.h"

void WashingMachine::startWash()
{
    cout << "Washing cycle started" << endl;
}

void WashingMachine::operateWashingMachine()
{
    cout << " Operating Washing Machine" << endl;
    turnOn();
    startWash();
    cout << "Washing completed!" << endl;
}