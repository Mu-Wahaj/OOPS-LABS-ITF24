#include<iostream>
using namespace std;
 
void peakElement(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0 && array[i] >= array[i + 1]) 
        {
            cout << array[i] << " ";
        }
        else if (i == n - 1 && array[i] >= array[i - 1]) 
        {
            cout << array[i] << " ";
        }
        else if (array[i] >= array[i - 1] && array[i] >= array[i + 1]) 
        {
            cout << array[i] << " ";
        }
    }
}
int main()
{
    //peak element in array
    int SIZE;
    cout << "Enter size of array: ";
    cin >> SIZE;
    int array[SIZE];
    cout << "Enter array elements: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> array[i];
    }
    cout << "Peak elements are: ";
    peakElement(array, SIZE);
    return 0;
}