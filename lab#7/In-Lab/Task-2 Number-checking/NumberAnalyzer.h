#pragma once

class NumberAnalyzer {
private:
    int number;                    // Stores the integer to analyze
    static int totalNumbers;       // Static: counts total NumberAnalyzer objects

public:
    // Constructor: Initializes the number and increments object counter
    NumberAnalyzer(int n);
    
    // Destructor: Decrements the object counter
    ~NumberAnalyzer();
    
    // Logical/Analysis methods
    bool isPrime() const;          // Returns true if number is prime
    bool isEven() const;           // Returns true if number is even
    bool isArmstrong() const;      // Returns true if number is Armstrong
    bool isPerfect() const;        // Returns true if number is a perfect number
    bool isPalindrome() const;     // Returns true if number reads the same backward
    int digitSum() const;          // Returns sum of digits
    int reverseNumber() const;     // Returns the number reversed
    
    void displayProperties() const; // Displays all analysis results
    
    // Static method
    static int getTotalNumbers();  // Returns total NumberAnalyzer objects
};

