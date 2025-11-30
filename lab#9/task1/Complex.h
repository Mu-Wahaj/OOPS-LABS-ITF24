#pragma once 
#include <iostream>
using namespace std;

class Complex
{
private:
double real, imag;
public:
// ========== CONSTRUCTORS ==========
Complex(double r = 0.0, double i = 0.0);
// ========== MEMBER OPERATOR OVERLOADING ==========
Complex operator+(const Complex& rhs); // Complex + Complex
Complex& operator-(const Complex& rhs); // Assignment operator
Complex& operator+(double rhs); // Complex + double
Complex& operator+=(const Complex& rhs); // Compound assignment
Complex& operator=(const Complex& rhs); // Assignment operator
// ========== MEMBER FUNCTIONS ==========
void display() const;
double getReal() const; // Getters for non-friend functions
double getImag() const;
// ========== FRIEND FUNCTION DECLARATIONS ==========
friend Complex operator+(double lhs, const Complex& rhs); // double + Complex
bool operator==(const Complex& rhs) const; // Equality comparison
bool operator!=(const Complex& rhs) const; // Inequalit comparison
};
// ========== NON-MEMBER FUNCTION DECLARATIONS ==========
Complex operator+(double lhs, const Complex& rhs); // Friend function implementation