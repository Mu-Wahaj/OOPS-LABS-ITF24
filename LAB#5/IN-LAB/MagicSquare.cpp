#include <iostream>
using namespace std;
bool isMagicSquare(int **matrix, int n);
int main()
{
    int rows = 0;
    cout << "Enter number of rows: ";
    cin >> rows;

    int cols = 0;
    cout << "Enter number of columns: ";
    cin >> cols;
    if (rows != cols)
    {
        cout << "Matrix is not a magic square not square matrix." << endl;
        return 0;
    }
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    cout << "Matrix elements are:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    if (rows != cols)
    {
        cout << "Matrix is not a magic square (not square matrix)." << endl;
    }
    else
    {
        if (isMagicSquare(matrix, rows))
            cout << "Matrix is a magic square." << endl;
        else
            cout << "Matrix is not a magic square." << endl;
    }
    return 0;
}
bool isMagicSquare(int **matrix, int n)

{
    int sum = 0;
    int colSum = 0;
    int rowSum = 0;
    int diagSum1 = 0, diagSum2 = 0;
    for (int j = 0; j < n; j++)
    {
        sum += matrix[0][j];
    }
    cout << "sum is : " << sum << " \n";
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rowSum += matrix[i][j];
        }
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            colSum += matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        diagSum1 += matrix[i][i];
        diagSum2 += matrix[i][n - i - 1];
    }
    if (diagSum1 != sum || diagSum2 || colSum || rowSum != sum)
        return false;

    return true;
}
