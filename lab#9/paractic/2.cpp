#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0)
    {
        real = r;
        imag = i;
    }

    // Getters
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Setters
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    // ------------ MEMBER OPERATORS ----------------

    // Complex + Complex
    Complex operator+(const Complex& rhs) const
    {
        Complex temp;
        temp.setReal(this->real + rhs.real);
        temp.setImag(this->imag + rhs.imag);
        return temp;
    }

    // Complex + double  (c1 + 5)
    Complex operator+(double value) const
    {
        Complex temp;
        temp.setReal(this->real + value);   // correct logic
        temp.setImag(this->imag);
        return temp;
    }

    // Complex - Complex
    Complex operator-(const Complex& rhs) const
    {
        Complex temp;
        temp.setReal(this->real - rhs.real);
        temp.setImag(this->imag - rhs.imag);
        return temp;
    }

    // Complex - double (c1 - 5)
    Complex operator-(double value) const
    {
        Complex temp;
        temp.setReal(this->real - value);
        temp.setImag(this->imag);
        return temp;
    }

    void display() const
    {
        cout << real << " + i" << imag << endl;
    }
};

// ------------ NON-MEMBER OPERATORS (NO FRIEND) ------------

// double + Complex   (5 + c1)
Complex operator+(double lhs, const Complex& rhs)
{
    Complex temp;
    temp.setReal(lhs + rhs.getReal());
    temp.setImag(rhs.getImag());
    return temp;
}

// double - Complex   (5 - c1)
Complex operator-(double lhs, const Complex& rhs)
{
    Complex temp;
    temp.setReal(lhs - rhs.getReal());
    temp.setImag(0 - rhs.getImag());
    return temp;
}


// ----------------- TEST MAIN -----------------
int main()
{
    Complex c1(3, 4);
    Complex c2(2, 1);

    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();

    Complex a = c1 + c2;
    Complex b = c1 + 5;
    Complex c = 5 + c1;

    Complex d = c1 - c2;
    Complex e = c1 - 5;
    Complex f = 5 - c1;

    cout << "\nResults:\n";
    cout << "c1 + c2 = "; a.display();
    cout << "c1 + 5  = "; b.display();
    cout << "5 + c1  = "; c.display();
    cout << "c1 - c2 = "; d.display();
    cout << "c1 - 5  = "; e.display();
    cout << "5 - c1  = "; f.display();

    return 0;
}
