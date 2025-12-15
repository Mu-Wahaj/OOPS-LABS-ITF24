#include <iostream>
#include "Car.h"
#include "WashingMachine.h"
#include "DigitalProduct.h"
#include "DigitalProduct.cpp"
#include "WashingMachine.cpp"
#include "Car.cpp"
#include "Vehicle.cpp"
#include "Appliance.cpp"
#include "Shape.h"
#include "Car.h"
// #include "Product.cpp"


using namespace std;

int main()
{
    cout << "Task 1" << endl;

    Car sedan("Toyota Camry", 60, "Sedan");
    Car hatchback("Honda Civic", 45, "Hatchback");
    Car suv("Ford Explorer", 70, "SUV");

    sedan.showCarDetails();
    hatchback.showCarDetails();
    suv.showCarDetails();

    Vehicle vehicle("Generic Model", 40);
    vehicle.displayVehicle();
    cout << " Task 2" << endl;

    Appliance genericAppliance;
    WashingMachine washingMachine;

    washingMachine.operateWashingMachine();

    genericAppliance.turnOn();

    Appliance *appliancePtr = &washingMachine;
    appliancePtr->turnOn();
    operateAppliance(genericAppliance);
    operateAppliance(washingMachine);

    cout << "Task 3" << endl;

    DigitalProduct ebook("C++ Programming", 29.99, "PDF");
    DigitalProduct musicAlbum("Greatest Hits", 9.99, "MP3");

    ebook.display();
    musicAlbum.display();

    DigitalProduct ebookCopy = ebook;
    ebookCopy.display();

    DigitalProduct anotherEbook("Temp", 0.0, "TXT");
    anotherEbook = ebook;
    anotherEbook.display();

    Product product("Physical Book", 49.99);
    product.display();
    cout << endl;

    Product *productPtr = &ebook;
    cout << "Base pointer to derived object: ";
    productPtr->display();
    cout << endl;



    // TASK 4

    // shape s;
    // Circle c;
    // cout<<"calling drw on object ";
    // s.draw();
    // c.draw();

    // shape*ptr=&c;
    // cout<<"calling draw ising shape*";
    // ptr->draw();
    // return 0;
}
