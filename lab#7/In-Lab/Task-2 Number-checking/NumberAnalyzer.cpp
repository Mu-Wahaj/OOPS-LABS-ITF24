#include "NumberAnalyzer.h"
#include <iostream>
#include <cmath>
using namespace std;

// Initialize static data member
int NumberAnalyzer::totalNumbers = 0;

// Constructor implementation
NumberAnalyzer::NumberAnalyzer(int n) : number(n) {
    totalNumbers++;
    cout << "NumberAnalyzer object created with number: " << number << endl;
}

// Destructor implementation
NumberAnalyzer::~NumberAnalyzer() {
    totalNumbers--;
    cout << "NumberAnalyzer object destroyed for number: " << number << endl;
}

// Check if number is prime
bool NumberAnalyzer::isPrime() const {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) return false;
    }
    return true;
}

// Check if number is even
bool NumberAnalyzer::isEven() const {
    return (number % 2 == 0);
}

// Check if number is Armstrong number
bool NumberAnalyzer::isArmstrong() const {
    int original = abs(number);
    int sum = 0;
    int temp = original;
    int digits = 0;
    
    // Count digits
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    
    temp = original;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }
    
    return (sum == original);
}

// Check if number is perfect number
bool NumberAnalyzer::isPerfect() const {
    if (number <= 1) return false;
    
    int sum = 1; // 1 is always a divisor
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return (sum == number);
}

// Check if number is palindrome
bool NumberAnalyzer::isPalindrome() const {
    if (number < 0) return false;
    
    int reversed = 0;
    int temp = number;
    
    while (temp != 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }
    
    return (reversed == number);
}

// Calculate sum of digits
int NumberAnalyzer::digitSum() const {
    int sum = 0;
    int temp = abs(number);
    
    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return sum;
}

// Reverse the number
int NumberAnalyzer::reverseNumber() const {
    int reversed = 0;
    int temp = abs(number);
    
    while (temp != 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }
    
    // Maintain the original sign
    return (number < 0) ? -reversed : reversed;
}

// Display all properties of the number
void NumberAnalyzer::displayProperties() const {
    cout << "\n=== Analysis for Number: " << number << " ===" << endl;
    cout << "Prime: " << (isPrime() ? "Yes" : "No") << endl;
    cout << "Even: " << (isEven() ? "Yes" : "No") << endl;
    cout << "Armstrong: " << (isArmstrong() ? "Yes" : "No") << endl;
    cout << "Perfect: " << (isPerfect() ? "Yes" : "No") << endl;
    cout << "Palindrome: " << (isPalindrome() ? "Yes" : "No") << endl;
    cout << "Digit Sum: " << digitSum() << endl;
    cout << "Reversed: " << reverseNumber() << endl;
    cout << "=================================" << endl;
}

// Static method to get total number of objects
int NumberAnalyzer::getTotalNumbers() {
    return totalNumbers;
}