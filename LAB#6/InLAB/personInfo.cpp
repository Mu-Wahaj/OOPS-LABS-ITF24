#include <iostream>
using namespace std;

class Person
{
    string firstName;
    string lastName;
    int age;
    char cnic[15];

public:
    void setFirstName()
    {
        cout << "Enter First Name: ";
        cin >> firstName;
    }

    void setLastName()
    {
        cout << "Enter Last Name: ";
        cin >> lastName;
    }

    void setAge()
    {
        cout << "Enter Age: ";
        cin >> age;
        if (age < 0 || age > 120)
        {
            cout << "Invalid age. Setting to 0.\n";
            age = 0;
        }
    }
    void setCnic()
    {
        cout << "Enter CNIC: ";
        char temp[15];
        cin >> temp;

        bool valid = true;
        int i = 0;

        for (i = 0; i < 14 && temp[i] != '\0'; i++)
        {
            if (temp[i] < '0' || temp[i] > '9')
            {
                valid = false;
                break;
            }
        }
        temp[i] = '\0';

        if (!valid)
        {
            cout << " Invalid CNIC! It must contain digits only.\n";
            cnic[0] = '\0';
            return;
        }

        int j;
        for (j = 0; j <= i; j++)
        {
            cnic[j] = temp[j];
        }
        cnic[j] = '\0';
    }

    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    int getAge() { return age; }
    const char *getCnic() { return cnic; }

    void displayInfo()
    {
        cout << "\nName: " << firstName << " " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "CNIC: " << cnic << endl;

        if (isAdult())
            cout << "The person is an adult." << endl;
        else
            cout << "The person is not an adult." << endl;
    }

    bool isAdult()
    {
        return age >= 18;
    }
};

int main()
{
    Person p;
    p.setFirstName();
    p.setLastName();
    p.setAge();
    p.setCnic();

    p.displayInfo();

    return 0;
}
