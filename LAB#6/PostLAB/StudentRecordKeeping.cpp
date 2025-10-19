#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    int rollNumber;
    double marks[3];

public:
    void setName(string n) { name = n; }
    string getName() { return name; }

    void setRollNumber(int r) { rollNumber = r; }
    int getRollNumber() { return rollNumber; }

    void setMarks(double m1, double m2, double m3)
    {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    double *getMarks() { return marks; }

    void inputStudentData()
    {
        cout << "Name: ";
        cin >> name;
        cout << "Roll Number: ";
        cin >> rollNumber;
        cout << "Marks (3 subjects): ";
        cin >> marks[0] >> marks[1] >> marks[2];
    }

    double calculateTotal()
    {
        return marks[0] + marks[1] + marks[2];
    }

    void displayStudentData()
    {
        cout << "Name: " << name
             << " | Roll No: " << rollNumber
             << " | Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2]
             << " | Total: " << calculateTotal() << endl;
    }
};

int main()
{
    int N;
    cout << "Enter number of students: ";
    cin >> N;

    Student *students = new Student[N];

    for (int i = 0; i < N; i++)
    {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].inputStudentData();
    }

    cout << "\n---- Student Records ----\n";
    for (int i = 0; i < N; i++)
    {
        students[i].displayStudentData();
    }

    double highestTotal = 0;
    string topStudent;

    for (int i = 0; i < N; i++)
    {
        double total = students[i].calculateTotal();
        if (total > highestTotal)
        {
            highestTotal = total;
            topStudent = students[i].getName();
        }
    }

    cout << "\nHighest Scorer: " << topStudent << " Total: " << highestTotal << "\n";

    delete[] students;

    return 0;
}
