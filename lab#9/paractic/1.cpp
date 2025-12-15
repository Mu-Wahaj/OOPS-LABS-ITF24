// oop_tasks.cpp
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

/*
  1) String class
    - Manages a dynamic char* (deep copy)
    - Copy ctor, destructor, operator= (self-assignment guarded)
    - operator+ for concatenation (returns new String)
    - operator== for equality
    - c_str() or display helper
*/
class String {
private:
    char* str;
    size_t size;
public:
    // default / from C-string
    String(const char* s = nullptr) : str(nullptr), size(0) {

            str = new char[strlen(s) + 1];
            strcpy(str, s);
        
    }

    // copy constructor (deep copy)
    String(const String& other) : str(nullptr), size(0) {
        if (other.str) {
            size = other.size;
            str = new char[size + 1];
            strcpy(str, other.str);
        }
    }

    // destructor
    ~String() {
        delete[] str;
    }

    // assignment operator (deep copy + self-check)
    String& operator=(const String& rhs) {
        if (this != &rhs) {
            // free existing
            delete[] str;
            str = nullptr;
            size = 0;
            // copy from rhs
            if (rhs.str) {
                size = rhs.size;
                str = new char[size + 1];
                strcpy(str, rhs.str);
            }
        }
        return *this;
    }

    // concatenation - return a new String
    friend String operator+(const String& a, const String& b) {
        if (!a.str && !b.str) return String();
        if (!a.str) return b;
        if (!b.str) return a;
        size_t newSize = a.size + b.size;
        char* buf = new char[newSize + 1];
        strcpy(buf, a.str);
        strcat(buf, b.str);
        String result(buf);
        delete[] buf;
        return result;
    }

    // equality
    friend bool operator==(const String& a, const String& b) {
        if (a.str == nullptr && b.str == nullptr) return true;
        if (a.str == nullptr || b.str == nullptr) return false;
        return strcmp(a.str, b.str) == 0;
    }

    const char* c_str() const { return str ? str : ""; }

    void display() const {
        cout << "\"" << c_str() << "\" (size=" << size << ")\n";
    }
};


/*
  2) Point class
    - Simple 2D point with + and +=
    - Real-life example: Adding two position vectors
*/
class Point {
public:
    double x, y;
    Point(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

    // member + : returns a new point (non-mutating)
    Point operator+(const Point& rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }

    // member += : modifies lhs and returns reference for chaining
    Point& operator+=(const Point& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    void display() const {
        cout << "Point(" << x << ", " << y << ")";
    }
};


/*
  3) Complex class
    - real, imag
    - member +=, -=
    - relational operators based on magnitude (abs)
    - non-member + and - (as requested)
*/
class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // member add (returns new Complex)
    Complex operator+(const Complex& rhs) const {
        return Complex(real + rhs.real, imag + rhs.imag);
    }

    // member subtract
    Complex operator-(const Complex& rhs) const {
        return Complex(real - rhs.real, imag - rhs.imag);
    }

    // compound assignment
    Complex& operator+=(const Complex& rhs) {
        real += rhs.real;
        imag += rhs.imag;
        return *this;
    }
    Complex& operator-=(const Complex& rhs) {
        real -= rhs.real;
        imag -= rhs.imag;
        return *this;
    }

    // magnitude helper
    double magnitude() const { return sqrt(real*real + imag*imag); }

    // relational operators based on magnitude
    friend bool operator==(const Complex& a, const Complex& b) {
        // consider exact equality of both parts as well
        return (a.real == b.real) && (a.imag == b.imag);
    }
    friend bool operator<(const Complex& a, const Complex& b) {
        return a.magnitude() < b.magnitude();
    }
    friend bool operator>(const Complex& a, const Complex& b) {
        return b < a;
    }
    // non-member + and - (two variants: Complex+Complex and double + Complex)
    friend Complex operator+(double lhs, const Complex& rhs) {
        return Complex(lhs + rhs.real, rhs.imag);
    }
    friend Complex operator+(const Complex& lhs, double rhs) {
        return Complex(lhs.real + rhs, lhs.imag);
    }
    friend Complex operator-(const Complex& a, const Complex& b) {
        return Complex(a.real - b.real, a.imag - b.imag);
    }
    // display
    void display() const {
        cout << "(" << real << (imag >= 0 ? " + " : " - ") << fabs(imag) << "i)";
    }
};


/*
  4) Student class
    - Has a String name (composition)
    - Age/roll number and assignment operator implemented
    - Demonstrates correct assignment when containing another class with dynamic memory
*/
class Student {
private:
    int roll;
    String name; // composed String object
public:
    Student(int r = 0, const String& n = String()) : roll(r), name(n) {}

    // copy constructor (compiler-generated would call String copy ctor; but define for clarity)
    Student(const Student& other) : roll(other.roll), name(other.name) {}

    // assignment operator
    Student& operator=(const Student& rhs) {
        if (this != &rhs) {
            roll = rhs.roll;
            name = rhs.name; // uses String::operator=
        }
        return *this;
    }

    void display() const {
        cout << "Student(roll=" << roll << ", name=";
        name.display();
        cout << ")";
    }
};


/* ---------------------------
   Main: Demonstrate everything
   --------------------------- */
int main() {
    cout << "===== String tests =====\n";
    String s1("Hello"), s2("World");
    String s3 = s1 + String(" ") + s2; // concatenation chaining
    s1.display(); s2.display(); s3.display();
    cout << "s1 == s2 ? " << (s1 == s2 ? "true" : "false") << "\n";
    cout << "s3: "; s3.display();

    cout << "\n===== Point tests =====\n";
    Point p1(1.2, 3.4), p2(2.8, -1.4);
    Point p3 = p1 + p2; // member +
    p1 += p2;           // member +=
    cout << "p3 = "; p3.display(); cout << "\n";
    cout << "p1 after += p2: "; p1.display(); cout << "\n";

    cout << "\n===== Complex tests =====\n";
    Complex c1(3, 4), c2(1, -2);
    cout << "c1 = "; c1.display(); cout << "\n";
    cout << "c2 = "; c2.display(); cout << "\n";
    Complex c3 = c1 + c2; // member +
    cout << "c3 = c1 + c2 -> "; c3.display(); cout << "\n";
    c3 += Complex(0.5, 0.5);
    cout << "c3 after += (0.5+0.5i): "; c3.display(); cout << "\n";
    Complex c4 = 5.0 + c2; // non-member double + Complex
    cout << "c4 = 5.0 + c2 -> "; c4.display(); cout << "\n";
    Complex c5 = c1 - c2; // non-member - (friend)
    cout << "c5 = c1 - c2 -> "; c5.display(); cout << "\n";

    cout << "c1 magnitude = " << c1.magnitude() << "\n";
    cout << "c2 magnitude = " << c2.magnitude() << "\n";
    cout << "Is c1 > c2 ? " << (c1 > c2 ? "yes" : "no") << "\n";
    cout << "Is c1 == c1 ? " << (c1 == c1 ? "yes" : "no") << "\n";

    cout << "\n===== Student tests =====\n";
    Student st1(101, String("Aisha"));
    Student st2(102, String("Bilal"));
    cout << "Before assignment:\n";
    cout << "st1: "; st1.display(); cout << "\n";
    cout << "st2: "; st2.display(); cout << "\n";
    st2 = st1; // uses Student::operator=
    cout << "After st2 = st1:\n";
    cout << "st1: "; st1.display(); cout << "\n";
    cout << "st2: "; st2.display(); cout << "\n";

    // show chaining of assignment
    Student sA(1, String("X")), sB(2, String("Y")), sC;
    sC = sB = sA; // chaining must work
    cout << "\nAfter chaining sC = sB = sA:\n";
    cout << "sA: "; sA.display(); cout << "\n";
    cout << "sB: "; sB.display(); cout << "\n";
    cout << "sC: "; sC.display(); cout << "\n";

    return 0;
}
