#include <iostream>
using namespace std;

void shiftArray(int array[], int n, int k)
{
    k = k % n;

    int temp[n];

    for (int i = 0; i < n; i++)
    {
        int newIndex = (i + k) % n;
        temp[newIndex] = array[i];
    }

    for (int i = 0; i < n; i++)
    {
        array[i] = temp[i];
    }
}

int main()
{
    int SIZE;
    cout << "Enter size of array: ";
    cin >> SIZE;

    int array[SIZE];
    int k;

    cout << "Enter array elements: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> array[i];
    }

    cout << "Enter shift value (k): ";
    cin >> k;

    shiftArray(array, SIZE, k);

    cout << "Shifted array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
