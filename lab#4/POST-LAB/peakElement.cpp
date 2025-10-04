#include <iostream>
using namespace std;

void findPeaksValleys(int *arr, int size, int *numPeaks, int *numValleys)
{

    int *p = arr + 1;
    *numPeaks = 0;
    *numValleys = 0;

    for (; p < arr + size - 1; p++)
    {
        if (*p > *(p - 1) && *p > *(p + 1))
        {
            (*numPeaks)++;
        }
        else if (*p < *(p - 1) && *p < *(p + 1))
        {
            (*numValleys)++;
        }
    }
}

int main()
{
    int numPeaks = 0, numValleys = 0;
    int size;
    cout << "Enter array size: ";
    cin >> size;

    if (size < 3 || size > 50)
    {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    int arr[50];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> *(arr + i);
    }

    findPeaksValleys(arr, size, &numPeaks, &numValleys);

    cout << "\nTotal Peaks: " << numPeaks << endl;
    cout << "Total Valleys: " << numValleys << endl;

    return 0;
}
