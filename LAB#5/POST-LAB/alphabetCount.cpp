#include <iostream>
#include <string>
using namespace std;

void countFrequency(const char *str)
{
    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (ch >= 'a' && ch <= 'z')
        {
            freq[ch]++;
        }
    }

    cout << "\nOutput:\n";

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if ((ch >= 'a' && ch <= 'z') && freq[ch] > 0)
        {
            cout << ch << " = " << freq[ch] << endl;
            freq[ch] = 0;
        }
    }
}

int main()
{
    int size;

    cout << "Enter the maximum size of the string: ";
    cin >> size;
    cin.ignore();
    char *str = new char[size];

    cout << "Enter a string: ";
    cin.getline(str, size);

    countFrequency(str);

    delete[] str;

    return 0;
}
