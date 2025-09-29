#include <iostream>
#include <cstring>
using namespace std;

int merge(char result[], char str1[], char str2[], int len1, int len2, int resultSize)
{

    if (resultSize < len1 + len2 + 1)
    {
        return -1;
    }

    for (int i = 0; i < len1; i++)
    {
        result[i] = str1[i];
    }

    for (int j = 0; j < len2; j++)
    {
        result[len1 + j] = str2[j];
    }

    result[len1 + len2] = '\0';

    return len1 + len2;
}

int main()
{
    char str1[] = "Hello";
    char str2[] = "World";
    char result[50];

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int mergedLength = merge(result, str1, str2, len1, len2, 50);

    if (mergedLength == -1)
    {
        cout << "Error: Not enough space in result array!" << endl;
    }
    else
    {
        cout << "Merged string: " << result << endl;
        cout << "Length: " << mergedLength << endl;
    }

    return 0;
}
