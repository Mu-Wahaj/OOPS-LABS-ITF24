#include <iostream>
using namespace std;

// Function prototype
void diagonalAnalysis(int mat[][100], int n);

int main()
{
    int n;
    cout << "Enter size of square matrix (n x n): ";
    cin >> n;

    int mat[100][100]; // fixed max size

    cout << "\nEnter matrix elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "\nMatrix entered:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    diagonalAnalysis(mat, n);

    return 0;
}

void diagonalAnalysis(int mat[][100], int n)
{
int mainDig, seconderydig ,countUnique=0 ,sumUnique=0 ;
    cout << "Primary diagonal elements: ";
    for (int i = 0; i < n; i++)
    {
        mainDig=mat[i][i];
        cout << mainDig << " ";
    }

    cout << "\nSecondary diagonal elements: ";
    for (int i = 0; i < n; i++)
    {

        seconderydig=mat[i][n - i - 1] ;
        cout << seconderydig<< " ";
    }

    
    cout << "\nAll Diagonal Elements (non-repeating): ";

    for (int i = 0; i < n; i++) {
        cout << mat[i][i] << " ";
        sumUnique += mat[i][i];
        countUnique++;

        if (i != n - i - 1) { 
            cout << mat[i][n - i - 1] << " ";
            sumUnique += mat[i][n - i - 1];
            countUnique++;
        }
    }

    cout << "\nSum of all diagonals : " << sumUnique;
    double avg = (double)sumUnique / countUnique;
    cout << "\n Average of all diagonals : " << avg << endl;

}
