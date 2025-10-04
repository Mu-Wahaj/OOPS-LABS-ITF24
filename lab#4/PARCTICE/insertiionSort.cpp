// insertion sort
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > key; j++)
        {

            arr[j + 1] = arr[j];
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    insertionSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
