#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;  //36

    int temp = num, sum = 0, digits = 0;

  
    int n = num; //n=36
    while (n > 0) {
        digits++; //1 2
        n /= 10;
    }

    temp = num; // 36
    while (temp > 0) {  
        int digit = temp % 10; //6 3
        sum += pow(digit, digits); //6^2=36  + 3^2=9 =45
        temp /= 10; //3
    }

    if (sum == num) //45==36
        cout << num << " is an Armstrong Number." << endl;
    else
        cout << num << " is NOT an Armstrong Number." << endl;

    return 0;
}
