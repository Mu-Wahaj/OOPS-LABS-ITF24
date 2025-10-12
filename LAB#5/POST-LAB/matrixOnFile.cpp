#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void processStudentMarks(int numStudents, int numSubjects)
{
    int **marks = new int *[numStudents];
    for (int i = 0; i < numStudents; i++)
    {
        marks[i] = new int[numSubjects];
    }

    for (int i = 0; i < numStudents; i++)
    {
        cout << "Enter marks for Student " << i + 1 << ": ";
        for (int j = 0; j < numSubjects; j++)
        {
            cin >> marks[i][j];
        }
    }

    ofstream outFile("marks.txt");
    if (!outFile)
    {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < numStudents; i++)
    {
        for (int j = 0; j < numSubjects; j++)
        {
            outFile << marks[i][j];
            if (j < numSubjects - 1)
                outFile << " ";
        }
        outFile << endl;
    }
    outFile.close();

    cout << "\nContents of marks.txt:\n";
    ifstream inFile("marks.txt");
    string line;
    while (getline(inFile, line))
    {
        cout << line << endl;
    }
    inFile.close();

    cout << fixed << setprecision(2);
    cout << "\nAverage marks per student:\n";
    for (int i = 0; i < numStudents; i++)
    {
        double sum = 0;
        for (int j = 0; j < numSubjects; j++)
        {
            sum += marks[i][j];
        }
        double avg = sum / numSubjects;
        cout << "Student " << i + 1 << ": " << avg << endl;
    }

    cout << "\nSubject-wise average:\n";
    for (int j = 0; j < numSubjects; j++)
    {
        double sum = 0;
        for (int i = 0; i < numStudents; i++)
        {
            sum += marks[i][j];
        }
        double avg = sum / numStudents;
        cout << "Subject " << j + 1 << ": " << avg << endl;
    }

    for (int i = 0; i < numStudents; i++)
    {
        delete[] marks[i];
    }
    delete[] marks;
}

int main()
{
    int numStudents, numSubjects;

    cout << "Enter number of students: ";
    cin >> numStudents;

    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    processStudentMarks(numStudents, numSubjects);

    return 0;
}
