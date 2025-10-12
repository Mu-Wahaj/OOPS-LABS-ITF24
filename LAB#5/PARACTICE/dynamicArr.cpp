#include <iostream>
using namespace std;

void inputArray(int *arr, int size) {
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
        cin >> *(arr + i); // same as arr[i]
}

void displayArray(int *arr, int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

int findMin(int *arr, int size) {
    int min = *arr;
    for (int i = 1; i < size; i++)
        if (*(arr + i) < min)
            min = *(arr + i);
    return min;
}

int findMax(int *arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++)
        if (*(arr + i) > max)
            max = *(arr + i);
    return max;
}

void sortArray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) > *(arr + j))
                swap(*(arr + i), *(arr + j));
        }
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];  // dynamic allocation

    inputArray(arr, size);
    displayArray(arr, size);

    cout << "Min = " << findMin(arr, size) << endl;
    cout << "Max = " << findMax(arr, size) << endl;

    sortArray(arr, size);
    cout << "After sorting: ";
    displayArray(arr, size);

    delete[] arr;  // deallocation
    arr = nullptr;

    return 0;
}
