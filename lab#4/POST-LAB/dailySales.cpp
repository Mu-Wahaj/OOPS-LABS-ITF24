#include <iostream>
using namespace std;
void analyzeSales(int *arr, int size, int *total, int *maxSale, int *minSale);

int main()
{
    const int SIZE = 3;
    int arr[SIZE];
    cout << "Enter the sales data for 24 hours: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> arr[i];
    }
    int total = 0, maxSale = arr[0], minSale = arr[0];
    analyzeSales(arr, SIZE, &total, &maxSale, &minSale);
    cout << "Total sales: " << total << endl;
    cout << "Maximum sales in an hour: " << maxSale << endl;
    cout << "Minimum sales in an hour: " << minSale << endl;
    return 0;
}
void analyzeSales(int *arr, int size, int *total, int *maxSale, int *minSale)
{
    for (int i = 0; i < size; i++)
    {
        *total += arr[i];
        if (arr[i] > *maxSale)
        {
            *maxSale = arr[i];
        }
        if (arr[i] < *minSale)
        {
            *minSale = arr[i];
        }
    }
}