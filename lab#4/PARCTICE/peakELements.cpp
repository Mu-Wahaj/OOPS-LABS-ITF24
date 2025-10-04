#include <iostream>
using namespace std;

// peak an valley  elemnts with positions aslo 

void findPeaksValleys(int *arr, int size, int *numPeaks, int *numValleys)
{
    if (size < 3 || size > 50) {
        cout << "Invalid array size! Must be between 3 and 50." << endl;
        return;
    }

    int *p = arr + 1; // start from 2nd element
    int index = 1;    // to track positions
    *numPeaks = 0;
    *numValleys = 0;

    cout << "Peaks at positions: ";
    for (; p < arr + size - 1; p++, index++) {
        if (*p > *(p - 1) && *p > *(p + 1)) {
            cout << index << " ";
            (*numPeaks)++;
        }
    }

    cout << endl;

    // Reset pointer for valleys
    p = arr + 1;
    index = 1;
    cout << "Valleys at positions: ";
    for (; p < arr + size - 1; p++, index++) {
        if (*p < *(p - 1) && *p < *(p + 1)) {
            cout << index << " ";
            (*numValleys)++;
        }
    }

    cout << endl;
}

int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    if (size < 3 || size > 50) {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    int arr[50];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }

    int numPeaks = 0, numValleys = 0;

    findPeaksValleys(arr, size, &numPeaks, &numValleys);

    cout << "\nTotal Peaks: " << numPeaks << endl;
    cout << "Total Valleys: " << numValleys << endl;

    return 0;
}
