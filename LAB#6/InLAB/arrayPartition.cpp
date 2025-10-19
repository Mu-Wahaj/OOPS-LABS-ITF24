#include <iostream>
using namespace std;

int *partitionArray(int *arr, int leftSize, int rightSize, int totalSize)
{
    cout << "Left Partition: ";
    int *p = arr;
    for (int i = 0; i < leftSize; ++i)
    {
        cout << *(p + i);
        if (i != leftSize - 1)
            cout << " ";
    }
    cout << endl;
    cout << "Right Partition: ";
    int *rightStart = arr + leftSize;
    for (int i = 0; i < rightSize; ++i)
    {
        cout << *(rightStart + i);
        if (i != rightSize - 1)
            cout << " ";
    }
    cout << endl;
    return rightStart;
}

int main()
{
    int totalSize;
    cout << "Enter total size of array: ";
    cin >> totalSize;
    int *arr = new int[totalSize];

    cout << "Enter " << totalSize << " elements:" << endl;
    for (int i = 0; i < totalSize; ++i)
    {
        cin >> *(arr + i);
    }

    int leftSize, rightSize;
    while (true)
    {
        cout << "Enter size of left partition: ";
        cin >> leftSize;
        cout << "Enter size of right partition: ";
        cin >> rightSize;
        if (leftSize + rightSize == totalSize && leftSize >= 0 && rightSize >= 0)
            break;
        cout << "Partition sizes must sum to total size. Try again." << endl;
    }

    int *rightPtr = partitionArray(arr, leftSize, rightSize, totalSize);

    cout << "Right Partition : ";
    for (int i = 0; i < rightSize; ++i)
    {
        cout << *(rightPtr + i);
        if (i != rightSize - 1)
            cout << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
