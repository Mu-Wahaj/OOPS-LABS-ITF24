#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of matrix (n): ";
    cin >> n;
    int arr[50][50];
    int value = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right)
    {                                       
        for (int i = left; i <= right; i++) 
        {
            arr[top][i] = value++;
        } 
        top++; 

        for (int i = top; i <= bottom; i++) // i=1 2 ; i<=2; i++
        {
            arr[i][right] = value++;
        } 
        right--; 

        if (top <= bottom) // 1<=2
        {
            for (int i = right; i >= left; i--) // i=1 0 ; i>=0; i--
            {
                arr[bottom][i] = value++;
            }         
            bottom--; 
        }

        if (left <= right) 
        {
            for (int i = bottom; i >= top; i--) // i=1 ; i>=1; i--
            {
                arr[i][left] = value++;
            }       
            left++; 
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
