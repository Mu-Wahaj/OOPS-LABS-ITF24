#pragma once
#include <iostream>
#include <cstring>

class Student {
private:
    int rollNo;
    char name[50];

public:
    // Constructor
    Student(int r = 0, const char* n = "Unknown");

    // Const member functions
    void display() const;
    const char* getName() const;
};


//.cpp
#include "Student.h"

// Constructor
Student::Student(int r, const char* n) {
    rollNo = r;
    std::strncpy(name, n, 49);
    name[49] = '\0';
}

// Display
void Student::display() const {
    std::cout << "Roll No: " << rollNo << ", Name: " << name << std::endl;
}

// Getter
const char* Student::getName() const {
    return name;
}
//.main
#include <iostream>
#include "Student.h"

int main() {

    const Student s(101, "Ali");   // const object

    s.display();                   // valid: display() is const

    std::cout << "Name: " << s.getName() << std::endl;  // valid

    return 0;
}
