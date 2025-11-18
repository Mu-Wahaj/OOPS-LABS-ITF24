#pragma once
#include <iostream>

class StudentCounter {
private:
    int rollNo;
    static int totalStudents;   // ONE shared variable for the whole class

public:
    // Constructors
    StudentCounter(int r = 0);
    StudentCounter(const StudentCounter& other);

    // Destructor
    ~StudentCounter();

    // Static member function
    static int getTotalStudents();

    // Regular member
    void display() const;
};
//.cpp
#include "StudentCounter.h"

// Define and initialize static data member (only once)
int StudentCounter::totalStudents = 0;

StudentCounter::StudentCounter(int r)
    : rollNo(r)
{
    totalStudents++;  // new student created
}

StudentCounter::StudentCounter(const StudentCounter& other)
    : rollNo(other.rollNo)
{
    totalStudents++;  // copy also creates a new object
}

StudentCounter::~StudentCounter() {
    totalStudents--;  // object destroyed
}

int StudentCounter::getTotalStudents() {
    return totalStudents;
}

void StudentCounter::display() const {
    std::cout << "Roll No = " << rollNo << std::endl;
}

//.main
#include "StudentCounter.h"

int main() {

    std::cout << "Initially: " << StudentCounter::getTotalStudents() << std::endl;

    StudentCounter s1(10);
    std::cout << "After s1: " << StudentCounter::getTotalStudents() << std::endl;

    StudentCounter s2(20);
    std::cout << "After s2: " << StudentCounter::getTotalStudents() << std::endl;

    // Copy constructor
    StudentCounter s3 = s1;
    std::cout << "After s3 (copy of s1): " << StudentCounter::getTotalStudents() << std::endl;

    // Heap allocation
    StudentCounter* s4 = new StudentCounter(40);
    std::cout << "After s4 (heap): " << StudentCounter::getTotalStudents() << std::endl;

    // Delete heap object
    delete s4;
    std::cout << "After deleting s4: " << StudentCounter::getTotalStudents() << std::endl;

    // Access static function via class name (recommended)
    std::cout << "Using class name: " 
              << StudentCounter::getTotalStudents() << std::endl;

    return 0;
}
