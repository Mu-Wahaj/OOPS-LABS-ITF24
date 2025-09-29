#include <iostream>
using namespace std;

int main() {
    int arr[5][5] = {0}; 
    int num = 1;
    arr[0][0] = num++;
    arr[0][4] = num++;
    arr[1][1] = num++;
    arr[1][3] = num++;
    arr[2][2] = num++;
    arr[3][1] = num++;
    arr[3][3] = num++;
    arr[4][0] = num++;
    arr[4][4] = num++;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
