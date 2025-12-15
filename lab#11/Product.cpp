#include "Product.h"

Product::Product(const char* n, float p) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    price = p;
}

Product::Product(const Product& p) {
    name = new char[strlen(p.name) + 1];
    strcpy(name, p.name);
    price = p.price;
    cout << "Product copy constructor called" << endl;
}

Product& Product::operator=(const Product& p) {
    if (this != &p) {
        delete[] name;
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
        price = p.price;
        cout << "Product assignment operator called" << endl;
    }
    return *this;
}

Product::~Product() {
    delete[] name;
}

void Product::display() const {
    cout << "Product: " << name << ", Price: $" << price;
}

const char* Product::getName() const {
    return name;
}

float Product::getPrice() const {
    return price;
}

void Product::setName(const char* n) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

void Product::setPrice(float p) {
    price = p;
}