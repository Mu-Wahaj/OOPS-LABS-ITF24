#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int **createMatrix(int row, int col);
void displayMatrix(int **mat, int row, int col);
void deleteMatrix(int **mat, int row);
int **transposeMatrix(int **mat, int row, int col);
int **multiplyMatrix(int **A, int **B, int rowA, int colA, int colB);

int main() {
    int rowA, colA, rowB, colB;
    cout << "Enter size of Matrix A (rows cols): ";
    cin >> rowA >> colA;
    cout << "Enter size of Matrix B (rows cols): ";
    cin >> rowB >> colB;

    if (colA != rowB) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    int **A = createMatrix(rowA, colA);
    int **B = createMatrix(rowB, colB);

    cout << "\nMatrix A:\n"; displayMatrix(A, rowA, colA);
    cout << "\nMatrix B:\n"; displayMatrix(B, rowB, colB);

    cout << "\nTranspose of A:\n";
    int **T = transposeMatrix(A, rowA, colA);
    displayMatrix(T, colA, rowA);

    cout << "\nMultiplication (A x B):\n";
    int **C = multiplyMatrix(A, B, rowA, colA, colB);
    displayMatrix(C, rowA, colB);

    deleteMatrix(A, rowA);
    deleteMatrix(B, rowB);
    deleteMatrix(C, rowA);
    deleteMatrix(T, colA);

    return 0;
}


int **createMatrix(int row, int col) {
    int **mat = new int*[row];
    for (int i = 0; i < row; i++)
        mat[i] = new int[col];
    cout << "Enter " << row * col << " elements:\n";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> *(*(mat + i) + j); // same as mat[i][j]
    return mat;
}

void displayMatrix(int **mat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << *(*(mat + i) + j) << " ";
        cout << endl;
    }
}

void deleteMatrix(int **mat, int row) {
    for (int i = 0; i < row; i++)
        delete[] mat[i];
    delete[] mat;
}
int **transposeMatrix(int **mat, int row, int col) {
    int **trans = new int*[col];
    for (int i = 0; i < col; i++)
        trans[i] = new int[row];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            *(*(trans + j) + i) = *(*(mat + i) + j); // trans[j][i] = mat[i][j]

    return trans;
}
int **multiplyMatrix(int **A, int **B, int rowA, int colA, int colB) {
    int **C = new int*[rowA];
    for (int i = 0; i < rowA; i++)
        C[i] = new int[colB];

    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            *(*(C + i) + j) = 0;
            for (int k = 0; k < colA; k++)
                *(*(C + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
        }
    }

    return C;
}
