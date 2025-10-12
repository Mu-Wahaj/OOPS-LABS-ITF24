#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("example.txt", ios::out);
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    file << "Hello, World!" << endl;
    file.close();
    file.open("example.txt", ios::in);
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    return 0;
}
