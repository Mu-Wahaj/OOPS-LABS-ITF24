#include <iostream>
#include <string>
using namespace std;
 // count unique vowels and consonants in a string with no repaetition
void countUniqueVowelsAndConsonants(string str) {
    bool visited[26] = {false};
    int vowels = 0, consonants = 0;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            int index;
            if (c >= 'A' && c <= 'Z')
                index = c - 'A';
            else
                index = c - 'a';

            if (!visited[index]) {
                visited[index] = true; 

                
                if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                    c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    vowels++;
                else
                    consonants++;
            }
        }
    }

    cout << "Unique vowels: " << vowels << endl;
    cout << "Unique consonants: " << consonants << endl;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    countUniqueVowelsAndConsonants(input);

    return 0;
}
