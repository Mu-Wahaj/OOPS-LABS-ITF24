#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of the Square Matrix: ";
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int bottom = (2 * n - 2) - i;
            int minDist = min(min(top, bottom), min(left, right));
            cout << (n - minDist) << " ";
        }
        cout << endl;
    }
    return 0;
}
