#include "DigitalProduct.h"

DigitalProduct::DigitalProduct(const char* n, float p, const char* format) 
    : Product(n, p) {
    fileFormat = new char[strlen(format) + 1];
    strcpy(fileFormat, format);
}

DigitalProduct::DigitalProduct(const DigitalProduct& dp) 
    : Product(dp) {  
    fileFormat = new char[strlen(dp.fileFormat) + 1];
    strcpy(fileFormat, dp.fileFormat);
    cout << "DigitalProduct copy constructor called" << endl;
}

DigitalProduct& DigitalProduct::operator=(const DigitalProduct& dp) {
    
        Product::operator=(dp);
        
        delete[] fileFormat;
        fileFormat = new char[strlen(dp.fileFormat) + 1];
        strcpy(fileFormat, dp.fileFormat);
        cout << "DigitalProduct assignment operator called" << endl;
    
    return *this;
}

DigitalProduct::~DigitalProduct() {
    delete[] fileFormat;
}



const char* DigitalProduct::getFormat() const {
    return fileFormat;
}