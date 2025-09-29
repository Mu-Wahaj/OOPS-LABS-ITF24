#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generatePassword(int n) {
    if (n < 4) {
        cout << "Password length must be at least 4 to include all categories!" << endl;
        return;
    }

    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    string special = "@#$%&";

    string all = uppercase + lowercase + digits + special;
    char password[n + 1];

    srand(time(0));

    password[0] = uppercase[rand() % uppercase.size()];
    password[1] = lowercase[rand() % lowercase.size()];
    password[2] = digits[rand() % digits.size()];
    password[3] = special[rand() % special.size()];

 
    for (int i = 4; i < n; i++) {
        password[i] = all[rand() % all.size()];
    }

   
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        swap(password[i], password[j]);
    }

    password[n] = '\0'; 
    cout << "Generated Password: " << password << endl;
}

int main() {
    int length;
    cout << "Enter password length: ";
    cin >> length;

    generatePassword(length);

    return 0;
}
