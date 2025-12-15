#include <iostream> 
#include <cstring> 
using namespace std; 
 
class Product { 
private: 
    char* name; 
    float price; 
     
public: 
    Product(const char* n = "Unknown", float p = 0.0); 
    Product(const Product& p); 
    Product& operator=(const Product& p); 
     
    // Destructor - frees dynamically allocated memory 
    ~Product(); 
     
    // Display function - shows product name and price 
    void display() const; 
    const char* getName() const; 
    float getPrice() const; 
    void setName(const char* n); 
    void setPrice(float p); 
}; 