#include <iostream>
using namespace std;

int findMode(int *arr, int size)
{
    int mode = -1;
    int maxCount = 1;

    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (*(arr + j) == *(arr + i))
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            mode = *(arr + i);
        }
    }

    if (maxCount == 1)
        return -1;

    return mode;
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> *(arr + i);
    }

    int mode = findMode(arr, size);

    cout << "Mode = " << mode << endl;

    delete[] arr;
    return 0;
}
