#include <iostream>
using namespace std;

void findConsecutiveSum(int arr[], int n, int k);

int main()
{

    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    findConsecutiveSum(arr, n, k);

    return 0;
}
void findConsecutiveSum(int arr[], int n, int k)
{
    for (int start = 0; start < n; start++)
    {
        int sum = 0;
        for (int end = start; end < n; end++)
        {
            sum += arr[end];

            if (sum == k)
            {
                cout << "Sequence: ";
                for (int k = start; k <= end; k++)
                {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }
    }
}
