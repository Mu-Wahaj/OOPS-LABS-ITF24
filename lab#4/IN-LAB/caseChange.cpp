#include <iostream>
#include <cstring>
using namespace std;

void changeUpper(char *str)
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (ch >= 'a' && ch <= 'z')
        {
            str[i] = ch - 32;
        }
    }
}
void changelower(char *str)
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            str[i] = ch + 32;
        }
    }
}

int main()
{

    char str[100];
    int choice = 0;
    cout << "Enter a string: ";
    cin.getline(str, 100);
    cout << "Choose an option:\n1. Convert to Uppercase\n2. Convert to Lowercase\nEnter your choice (1 or 2): ";
    cin >> choice;
    if (choice == 1)
    {

        changeUpper(str);
        cout << "Shifted string to upper : " << str << endl;
    }

    else
    {
        changelower(str);
        cout << "Shifted string to lower: " << str << endl;
    }

    return 0;
}
