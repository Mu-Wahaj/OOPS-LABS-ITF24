#include <iostream>
using namespace std;

void countVowels(const char *str);

int main()
{
    char str[100];

    cout << "Enter a string: ";
    cin.getline(str, 100);

     countVowels(str);


    return 0;
}

void countVowels(const char *str)
{
    int Vowelcount = 0, consoenetcount = 0;

    while (*str != '\0')
    {
        char ch = *str;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            Vowelcount++;
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            consoenetcount++;
        }

        str++;
    }

    cout << "Number of consonants in the string: " << consoenetcount << endl;
    cout << "Number of vowels in the string: " << Vowelcount << endl;
}
