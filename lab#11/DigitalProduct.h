#ifndef DIGITALPRODUCT_H
#define DIGITALPRODUCT_H

#include "Product.h"
#include <cstring>
using namespace std;

class DigitalProduct : public Product {
private:
    char* fileFormat; 

public:
    // Constructor
    DigitalProduct(const char* n, float p, const char* format);
    
    // Copy constructor
    DigitalProduct(const DigitalProduct& dp);
    
    // Assignment operator
    DigitalProduct& operator=(const DigitalProduct& dp);
    
    // Destructor
    ~DigitalProduct();
    
    // Display function - override
   // void display() const;
    
    // Getter for file format
    const char* getFormat() const;
};

#endif