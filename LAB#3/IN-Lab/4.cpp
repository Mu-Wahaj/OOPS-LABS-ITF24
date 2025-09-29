#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;
    
    // Input sizes
    cout << "Enter rows and cols of Matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of Matrix B: ";
    cin >> r2 >> c2;

    // Check compatibility
    if (c1 != r2) {
        cout << "Matrix multiplication not possible! (Cols of A != Rows of B)" << endl;
        return 0;
    }

    int A[100][100], B[100][100], C[100][100] = {0};

    // Input A
    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    // Input B
    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0; 
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    
    cout << "Resultant Matrix C (" << r1 << "x" << c2 << "):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
