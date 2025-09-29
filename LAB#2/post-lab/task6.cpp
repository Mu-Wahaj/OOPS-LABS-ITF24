#include <iostream>
using namespace std;

int highestPowerOf2(int n) {
    int p = 1;
    while (p * 2 <= n) p *= 2;
    return p;
}

void representAsPowers(int n) {
    if (n == 0) return;
    int p = highestPowerOf2(n);
    cout << p;
    if (n - p > 0) {
        cout << " + ";
        representAsPowers(n - p);
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Please enter a positive integer.";
    } else {
        cout << n << " can be represented as: ";
        representAsPowers(n);
    }
    return 0;
}
