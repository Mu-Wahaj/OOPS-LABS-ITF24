
#include <iostream>
using namespace std;
#include "Complex.h"
Complex::Complex(double r , double i )
{
    real = r;
    imag = i;
}
Complex Complex::operator+(const Complex &rhs)
{
    real = this->real + rhs.real;
    imag = this->imag + rhs.imag;
    return *this;
}

Complex &Complex::operator-(const Complex &rhs)
{
    real = this->real - rhs.real;
    imag = this->imag - rhs.imag;
    return *this;
}
Complex Complex::operator+(double r) const
{
    return Complex(real + r, imag);
}



Complex &Complex::operator+=(const Complex &rhs)
{
    real += rhs.real;
    imag += rhs.imag;
    return *this;
}

void Complex::display() const
{
    cout << real << " + i" << imag << endl;
}
double Complex::getReal() const
{
    return real;
}
double Complex::getImag() const
{
    return imag;
}

bool Complex::operator==(const Complex &rhs) const
{
    return (this->real == rhs.real) && (this->imag == rhs.imag);
}
bool Complex::operator!=(const Complex &rhs) const
{
    return (this->real != rhs.real) && (this->imag != rhs.imag);
}

Complex operator+(double lhs, const Complex &rhs)
{
    Complex temp;
    temp.real = lhs + rhs.getReal();
    temp.imag = rhs.getImag();
    return temp;
}