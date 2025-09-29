#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    if (a <= 0 || b <= 0) {
        cout << "Error: Please enter positive integers only.";
    } else {
        int g = gcd(a, b);
        int l = (a * b) / g;
        cout << "GCD of " << a << " and " << b << " = " << g << endl;
        cout << "LCM of " << a << " and " << b << " = " << l;
    }
    return 0;
}
