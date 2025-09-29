#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;

    int result = 0;
    int positiveB = (b < 0) ? -b : b; 

    for (int i = 0; i < positiveB; i++) {
        result += a;
    }

    if (b < 0)
        result = -result;

    cout << "The product of " << a << " and " << b << " is: " << result << endl;

    return 0;
}
