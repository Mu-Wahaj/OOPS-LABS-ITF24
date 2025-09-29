#include<iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a two-digit number as XY coordinate points: ";
    cin >> num;
int x = num / 10;
int y = num % 10;

if (x > 0 && y > 0)
        cout << "First Quadrant." << endl;
    else if (x < 0 && y > 0)
        cout << "Second Quadrant." << endl;
    else if (x < 0 && y < 0)
        cout << "Third Quadrant." << endl;
    else if (x > 0 && y < 0)
        cout << "Fourth Quadrant." << endl;
    else if (x == 0 && y == 0)
        cout << "Origin." << endl;
    else if (x == 0)
        cout << "Y-axis." << endl;
    else if (y == 0)
        cout << "X-axis." << endl;

    return 0;
} 