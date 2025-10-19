#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int N;
    cout << "Enter number of students: ";
    cin >> N;

    string *name = new string[N];
    int *rollNo = new int[N];
    int **marks = new int *[N];
    for (int i = 0; i < N; i++)
    {
        marks[i] = new int[3];
    }

    for (int i = 0; i < N; i++)
    {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> name[i];
        cout << "Roll Number: ";
        cin >> rollNo[i];
        cout << "Marks of each subject : ";
        cin >> marks[i][0] >> marks[i][1] >> marks[i][2];
    }

    ofstream fout("marks.txt");
    fout << "Name RollNo Math Science English\n";
    for (int i = 0; i < N; i++)
    {
        fout << name[i] << " " << rollNo[i] << " "
             << marks[i][0] << " " << marks[i][1] << " " << marks[i][2] << "\n";
    }
    fout.close();

    ifstream fin("marks.txt");
    ofstream fout2("results.txt");
    string header;
    getline(fin, header); 

    fout2 << "Name RollNo Total Average Grade\n";

    string n;
    int r, m1, m2, m3;
    int highestTotal = 0;
    string topStudent;

    while (fin >> n >> r >> m1 >> m2 >> m3)
    {
        int total = m1 + m2 + m3;
        float avg = total / 3.0;
        char grade;

        if (avg >= 80)
            grade = 'A';
        else if (avg >= 70)
            grade = 'B';
        else if (avg >= 60)
            grade = 'C';
        else
            grade = 'F';

        fout2 << n << " " << r << " " << total << " " << avg << " " << grade << "\n";

        if (total > highestTotal)
        {
            highestTotal = total;
            topStudent = n;
        }
    }

    fin.close();
    fout2.close();

    ifstream fin2("results.txt");
    string line;

    cout << "\n---- Results ----\n";
    getline(fin2, line);
    while (getline(fin2, line))
    {
        cout << line << endl;
    }
    fin2.close();

    cout << "\nHighest Scorer: " << topStudent << " (" << highestTotal << ")" << endl;

    for (int i = 0; i < N; i++)
        delete[] marks[i];
    delete[] marks;
    delete[] name;
    delete[] rollNo;

    return 0;
}
