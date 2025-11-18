#include <iostream>
#include "NumberAnalyzer.h"
using namespace std;

int main() {
    cout << "=== Number Analyzer Program ===" << endl;
    
    // Create three NumberAnalyzer objects with different integers
    NumberAnalyzer num1(371);   // Armstrong number
    NumberAnalyzer num2(28);    // Perfect number
    NumberAnalyzer num3(12321); // Palindrome number
    
    cout << "\n--- Displaying Properties ---" << endl;
    
    // Call displayProperties() for all objects
    num1.displayProperties();
    num2.displayProperties();
    num3.displayProperties();
    
    // Test with additional numbers
    cout << "\n--- Additional Tests ---" << endl;
    {
        NumberAnalyzer num4(17);   // Prime number
        NumberAnalyzer num5(256);  // Even number
        
        num4.displayProperties();
        num5.displayProperties();
        
        cout << "Total objects inside block: " << NumberAnalyzer::getTotalNumbers() << endl;
    } // num4 and num5 destroyed here
    
    // Display total number of NumberAnalyzer objects at the end
    cout << "\n=== Final Statistics ===" << endl;
    cout << "Total NumberAnalyzer objects created: " << NumberAnalyzer::getTotalNumbers() << endl;
    
    return 0;
}