#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
int main()
{
    const int SIZE = 5;
    int arr[5] = {5, 2, 4, 3, 1};
    cout << "before sorting\n";

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i];
    }

    sortArray(arr, 5);
    cout << "\nafter sorting \n";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i];
    }

    return 0;
}
