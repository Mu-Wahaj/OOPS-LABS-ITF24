#include <iostream>
#include <cstring>
using namespace std;
void countFrequency(char str[], int freq[]) {
//
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (ch >= 'A' && ch <= 'Z') {
            freq[ch - 'A']++;
        }
        else if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
        }
    }
}


int main() {
    char str[200];

    cout << "Enter a string: ";
    cin.getline(str, 200);

    int freq[26] = {0};  

    countFrequency(str, freq);
    

   
    cout << "\nLetter frequencies:\n";
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            cout << char(i + 'A') << " : " << freq[i] << endl;
        }
    }

    return 0;
}
