#include "Password.h"

int main()
{
    PasswordManager p1("Hello123!");
    PasswordManager p2("weak");
    PasswordManager p3("Str0ng$Pass");

    p1.displayInfo();
    p2.displayInfo(); p3.displayInfo();
    p2.updatePassword("BetterPass ");
    p2.displayInfo();  cout << "Total Password Objects: " << PasswordManager::getTotalPasswords() << endl;

    return 0;
}
