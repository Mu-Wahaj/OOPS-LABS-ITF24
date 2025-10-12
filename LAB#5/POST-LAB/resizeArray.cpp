#include <iostream>
using namespace std;

int *resizeArray(int *inArray, const int size)
{
    int newSize = size * 2;
    int *newArray = new int[newSize];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = inArray[i];
    }

    for (int i = 0; i < size; i++)
    {
        newArray[size + i] = inArray[i] * 2;
    }

    return newArray;
}

int main()
{
    int size;

    cout << "Enter size of the array: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int *resizedArr = resizeArray(arr, size);

    cout << "Resized array: ";
    for (int i = 0; i < size * 2; i++)
    {
        cout << resizedArr[i]<<" ";
       
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;
    delete[] resizedArr;
    resizedArr = nullptr;

    return 0;
}
