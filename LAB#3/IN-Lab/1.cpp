#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return total - sum;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100]; 
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int number = findMissing(arr, n) ;
    cout << "Missing number is: " << number << endl;


    // aditional   part
    if (number % 2 != 0)
    {
        cout << "Missing number is odd: " << number << endl;
        return 0;
    }
    else
    {
        cout << "Missing number is even: " << number << endl;
    }
    


    return 0;
}
