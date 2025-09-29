#include <iostream>
#include <cstring>
using namespace std;

int merge(char str1[], char str2[], char result[], int len1, int len2)
{
    int i = 0, j = 0, k = 0;

    while (i < len1 && str1[i] != '\0')
    {
        result[k++] = str1[i++];
    }

    while (j < len2 && str2[j] != '\0')
    {
        result[k++] = str2[j++];
    }

    result[k] = '\0';
    return k;
}

int main()
{
    int len1, len2;

    cout << "Enter maximum length of string 1: ";
    cin >> len1;
    cout << "Enter maximum length of string 2: ";
    cin >> len2;

    char str1[len1 + 1], str2[len2 + 1];
    char result[len1 + len2 + 1];

    cin.ignore();

    while (true)
    {
        cout << "Enter string 1 (max " << len1 << " chars): ";
        cin.getline(str1, len1 + 1);

        if (cin.fail())
        {
            cout << " Error: String 1 exceeded maximum length (" << len1 << "). Please try again.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "Enter string 2 (max " << len2 << " chars): ";
        cin.getline(str2, len2 + 1);

        if (cin.fail())
        {
            cout << " Error: String 2 exceeded maximum length (" << len2 << "). Please try again.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
        {
            break;
        }
    }

    int mergedLength = merge(str1, str2, result, len1, len2);

    cout << "\n String 1: " << str1;
    cout << "\n String 2: " << str2;
    cout << "\n Merged String: " << result;
    cout << "\n Merged Length: " << mergedLength << endl;

    return 0;
}
