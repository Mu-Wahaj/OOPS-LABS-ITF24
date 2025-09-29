#include <iostream>
using namespace std;

int main() {
    int accountNumber;
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    int temp = accountNumber, reverse = 0, sum = 0;

    while (temp > 0) {
        int digit = temp % 10;
        reverse = reverse * 10 + digit;
        sum += digit;
        temp /= 10;
    }

    cout << "Secret PIN = " << reverse << sum << endl;

    return 0;
}
