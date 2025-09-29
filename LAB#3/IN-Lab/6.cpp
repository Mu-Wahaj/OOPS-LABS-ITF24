#include <iostream>
using namespace std;
int sumOfElements2(int matrix[][5], int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += matrix[i][j];
    return sum;
}

int studentAVG(int matrix[][5], int rows, int cols)
{
    int averageMarks = 0;
    for (int i = 0; i < rows; i++)
    {
        int currentRowSum = 0;
        for (int j = 0; j < cols; j++)
        {
            currentRowSum += matrix[i][j];
        }
        averageMarks = currentRowSum / cols; // FIXED
        cout << "Average of student " << i << " is " << averageMarks << endl;
    }
    cout << endl;
    return averageMarks;
}

int quizMarks(int matrix[][5], int rows, int cols)
{
    int averageMarks = 0;
    for (int i = 0; i < cols; i++)
    {
        int currentColSum = 0;
        for (int j = 0; j < rows; j++)
        {
            currentColSum += matrix[j][i]; 
        }
        averageMarks = currentColSum / rows; 
        cout << "Average of quiz " << i << " is " << averageMarks << endl;
    }
    cout << endl;
    return averageMarks;
}

int main()
{
    int rows = 3;
    int cols = 5;
    int matrix[3][5];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix entered:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int totalSum = sumOfElements2(matrix, rows, cols);
    cout << "Total sum of elements in the matrix is: " << totalSum << endl;
    studentAVG(matrix, rows, cols);
    quizMarks(matrix, rows, cols);
    return 0;
}
