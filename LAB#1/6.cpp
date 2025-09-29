#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int temp = num, sum = 0, digits = 0;

  
    int n = num;
    while (n > 0) {
        digits++;
        n /= 10;
    }

    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    if (sum == num)
        cout << num << " is an Armstrong Number." << endl;
    else
        cout << num << " is NOT an Armstrong Number." << endl;

    return 0;
}
