#include <iostream>
using namespace std;
void LeaderELement(int *arr, int size);
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
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
    LeaderELement(arr, size);
    delete[] arr;
    arr = nullptr;
    return 0;
}
void LeaderELement(int *arr, int size)
{

    cout << "Leader elements are: ";
    int maxSofar = *(arr + size - 1);
    cout << maxSofar << " ";
    for (int i = 0; i < size - 2; i++)
    {
        if (*(arr + i) > maxSofar)
        {
            maxSofar = *(arr + i);
            cout << maxSofar << " ";
        }
    }
}
