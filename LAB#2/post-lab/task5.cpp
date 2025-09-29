#include <iostream>
using namespace std;

void checkStrongnumber(int n, int &sum);
int factorial(int n);

int main()
{
    int number, result;
    cout << "Enter a number: ";
    cin >> number;

    if (number <= 0)
    {
        cout << "Please enter a valid positive integer.";
    }
    else
    {
        checkStrongnumber(number, result);

        if (result == number)
            cout << number << " is a Strong Number";
        else
            cout << number << " is NOT a Strong Number";
    }

    return 0;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void checkStrongnumber(int n, int &sum)
{
    sum = 0;
    int temp = n;

    while (temp > 0)
    {
        int digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }
}