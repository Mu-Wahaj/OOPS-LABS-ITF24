#include "Appliance.h" 
using namespace std; 
 
class WashingMachine : public Appliance { 
public: 
    // Derived class specific function - starts washing cycle 
    void startWash(); 
     
    // Should be able to call base class functions 
    void operateWashingMachine(); 
}; 
 
// Global function  
void operateAppliance(Appliance &a); 