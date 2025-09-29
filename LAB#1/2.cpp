#include <iostream>
using namespace std;

int main() {
    int num, count = 0, sum = 0, maxVal = -1, minVal = 1e9;

    while (true) {
        cout << "Enter a Positive Number and -1 to terminate: ";
        cin >> num;

        if (num == -1) break;
        if (num < 0) {
            cout << "Only positive numbers allowed!" << endl;
            continue;
        }

        count++;
        sum += num;

        if (num > maxVal) maxVal = num;
        if (num < minVal) minVal = num;
    }

    if (count > 0) {
        cout << "Number of positive integers is: " << count << endl;
        cout << "The maximum value is: " << maxVal << endl;
        cout << "The minimum value is: " << minVal << endl;
        cout << "The average is: " << (double)sum / count << endl;
    } else {
        cout << "No numbers entered." << endl;
    }

    return 0;
}
