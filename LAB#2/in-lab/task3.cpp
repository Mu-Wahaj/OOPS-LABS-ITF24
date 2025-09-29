#include <iostream>
using namespace std;
void swapNumbers(int &a, int &b);
int main()
{

    int a, b;
    cout << "enter te value a :";
    cin >> a;

    cout << "enter the value of b ";
    cin >> b;

    cout << "befor swaping :" << a << b;
    swapNumbers(a, b);

    cout << "after swaping :" << a << b;

    return 0;
}

void swapNumbers(int &a, int &b)
{

    a = a + b;
    b = a - b;
    a = a - b;
}