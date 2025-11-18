#include "Password.h"

int PasswordManager::totalPasswords = 0;
int PasswordManager::nextId = 1;

class PasswordManager
{
private:
    string password;
    int id;
public:
    static int totalPasswords;
    static int nextId;

  PasswordManager(string pass)
    {
        password = pass;
        id = nextId;
        nextId++;
        totalPasswords++;
    }

    ~PasswordManager()
    {
        totalPasswords--;
    }
bool isDigit(char c) const {
        return c >= '0' && c <= '9';
    }

    bool isUpper(char c) const {
        return c >= 'A' && c <= 'Z';
    }

    bool isLower(char c) const {
        return c >= 'a' && c <= 'z';
    }

    bool isLetter(char c) const {
        return isUpper(c) || isLower(c);
    }
    bool ValidateLength() const
    {
        int count = 0;

        for (int i = 0; password[i] != '\0'; i++)
            count++;

        return count >= 8;
    }

    bool hasSpecialChar() const
    {
        for (int i = 0; password[i] != '\0'; i++)
        {
            char c = password[i];

            if (!isLetter(c)&&!isDigit(c))
                return true;
        }
        return false;
    }

    bool hasUpperLowerMix() const
    {
        bool upperFound = false;
        bool lowerFound = false;

        for (int i = 0; password[i] != '\0'; i++)
        {
            char c = password[i];
            if (isUpper(c)) upperFound = true;
            if (isLower(c)) lowerFound = true;
        }

        return upperFound && lowerFound;
    }

    bool hasNumber() const
    {
        for (int i = 0; password[i] != '\0'; i++)
        {
            if (isDigit(password[i])) return true;
        }
        return false;
    }

    int strengthScore() const
    {
        int score = 0;

        if (ValidateLength()) score++;
        if (hasNumber()) score++;
        if (hasUpperLowerMix()) score++;
        if (hasSpecialChar()) score++;

        return score;
    }

    string encrypt() const
    {
        string result = password;

        for (int i = 0; result[i] != '\0'; i++)
        {
            result[i] = result[i] + 1; 
        }

        return result;
    }

    bool match(string input) const
    {
        int i = 0;

        while (password[i] != '\0' && input[i] != '\0')
        {
            if (password[i] != input[i])
                return false;
            i++;
        }

        return password[i] == '\0' && input[i] == '\0';
    }

    void updatePassword(string newPass)
    {
        password = newPass;
    }

    void displayInfo() const
    {
        cout << " Password Inf"<<endl;
        cout << "id" << id << endl;
        cout << "Strength Score: " << strengthScore() << endl;
        cout << "Encrypted Password: " << encrypt() << endl;
    }

    static int getTotalPasswords()
    {
        return totalPasswords;
    }
};


