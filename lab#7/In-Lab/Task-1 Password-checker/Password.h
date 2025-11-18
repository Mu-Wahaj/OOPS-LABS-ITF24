#pragma once

#include <iostream>
#include <string>
using namespace std;

class PasswordManager
{
private:
    string password;
    static int totalPasswords;
    const int id;
    static int nextId;

public:
    PasswordManager(string pass);
    ~PasswordManager();

    bool ValidateLength() const;
    bool hasSpecialChar() const;
    bool hasUpperLowerMix() const;
    bool hasNumber() const;

    int strengthScore() const;
    string encrypt() const;
    bool match(string input) const;
    void updatePassword(string newPass);
    void displayInfo() const;

    static int getTotalPasswords();
};
