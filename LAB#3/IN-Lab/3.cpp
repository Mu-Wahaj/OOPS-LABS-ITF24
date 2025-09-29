#include <iostream>
#include <cstring>
using namespace std;

void shiftString(char str[], int k)
{
    
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // Custom rule: turn 'L' into '#'
        if (ch == 'L') {
            str[i] = '#';
            continue; // skip shifting
        }

        // For uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            str[i] = (ch - 'A' + k) % 26 + 'A';
        }
        // For lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            str[i] = (ch - 'a' + k) % 26 + 'a';
        }
        // Non-alphabetic stays unchanged
    }
    }


int main()
{
    char str[100];
    int k;

    cout << "Enter a string: ";
    cin.getline(str, 100);

    cout << "Enter shift (k): ";
    cin >> k;

    shiftString(str, k);

    cout << "Shifted string: " << str << endl;

    return 0;
}
