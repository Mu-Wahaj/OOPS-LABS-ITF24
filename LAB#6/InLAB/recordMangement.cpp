#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// --- Function Declarations ---
void inputData(string* names, int* ages, string* departments, double* salaries, int N);
void writeFiles(string* names, int* ages, string* departments, double* salaries, int N);
void mergeFiles(int N);
void displayMerged();
void processStats(int N);
void searchEmployee();
int getValidInt(string prompt, int minVal, int maxVal);
double getValidDouble(string prompt, double minVal);

// --- Main Function ---
int main() {
    int N;
    cout << "Enter number of employees: ";
    N = getValidInt("", 1, 1000);

    string* names = new string[N];
    int* ages = new int[N];
    string* departments = new string[N];
    double* salaries = new double[N];

    inputData(names, ages, departments, salaries, N);
    writeFiles(names, ages, departments, salaries, N);
    mergeFiles(N);
    displayMerged();
    processStats(N);
    searchEmployee();

    delete[] names;
    delete[] ages;
    delete[] departments;
    delete[] salaries;

    return 0;
}

// --- Function Definitions ---

// Get integer input with validation
int getValidInt(string prompt, int minVal, int maxVal) {
    int val;
    while (true) {
        if (!prompt.empty()) cout << prompt;
        cin >> val;
        if (cin.fail() || val < minVal || val > maxVal) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again: ";
        } else break;
    }
    return val;
}

// Get double input with validation
double getValidDouble(string prompt, double minVal) {
    double val;
    while (true) {
        if (!prompt.empty()) cout << prompt;
        cin >> val;
        if (cin.fail() || val < minVal) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again: ";
        } else break;
    }
    return val;
}

// Input Phase
void inputData(string* names, int* ages, string* departments, double* salaries, int N) {
    for (int i = 0; i < N; i++) {
        cout << "\nEnter details for employee " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> ws;
        getline(cin, names[i]);

        ages[i] = getValidInt("Age: ", 16, 79);

        cout << "Department: ";
        cin >> ws;
        getline(cin, departments[i]);

        salaries[i] = getValidDouble("Salary: ", 1);
    }
}

// File Storage Phase
void writeFiles(string* names, int* ages, string* departments, double* salaries, int N) {
    ofstream personal("personal.txt");
    ofstream official("official.txt");

    if (!personal || !official) {
        cout << "Error opening files!\n";
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        personal << names[i] << "," << ages[i] << endl;
        official << names[i] << "," << departments[i] << "," << salaries[i] << endl;
    }

    personal.close();
    official.close();
    cout << "\nData successfully written to personal.txt and official.txt\n";
}

// Merging Phase
void mergeFiles(int N) {
    ifstream pRead("personal.txt");
    ifstream oRead("official.txt");
    ofstream merged("merged.txt");

    if (!pRead || !oRead || !merged) {
        cout << "Error creating merged file!\n";
        exit(1);
    }

    cout << "Merging files into merged.txt...\n";

    string line, pname, oname, dept;
    int age;
    double sal;

    for (int i = 0; i < N; i++) {
        getline(pRead, line);
        size_t commaPos = line.find(',');
        pname = line.substr(0, commaPos);
        age = stoi(line.substr(commaPos + 1));

        getline(oRead, line);
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        oname = line.substr(0, pos1);
        dept = line.substr(pos1 + 1, pos2 - pos1 - 1);
        sal = stod(line.substr(pos2 + 1));

        if (pname == oname) {
            merged << "Name: " << pname
                   << " | Age: " << age
                   << " | Department: " << dept
                   << " | Salary: " << sal << endl;
        }
    }

    pRead.close();
    oRead.close();
    merged.close();
    cout << "Merged file created successfully!\n";
}

// Display Phase
void displayMerged() {
    ifstream mergedRead("merged.txt");
    cout << "\n---- Employee Records ----\n";
    string line;
    while (getline(mergedRead, line)) {
        cout << line << endl;
    }
    mergedRead.close();
}

void processStats(int N) {
    int itCount = 0, hrCount = 0, otherCount = 0;
    double totalSalary = 0, highestSalary = 0;
    string highestName, line;

    ifstream stats("merged.txt");
    while (getline(stats, line)) {
        size_t namePos = line.find("Name: ") + 6;
        size_t agePos = line.find("| Age:");
        string name = line.substr(namePos, agePos - namePos - 1);

        size_t deptPos = line.find("Department: ") + 12;
        size_t salPos = line.find("| Salary:");
        string dept = line.substr(deptPos, salPos - deptPos - 1);

        double salary = stod(line.substr(salPos + 10));

        if (dept == "IT"|| dept=="it") itCount++;
        else if (dept == "HR" ||dept=="HR") hrCount++;
        else otherCount++;

        totalSalary += salary;
        if (salary > highestSalary) {
            highestSalary = salary;
            highestName = name;
        }
    }
    stats.close();

    cout << "---- Statistics ----\n";
    cout << "Total Employees in IT: " << itCount << endl;
    cout << "Total Employees in HR: " << hrCount << endl;
    if (otherCount > 0)
        cout << "Total Employees in Other Departments: " << otherCount << endl;
    cout << "Average Salary: " << fixed << setprecision(2) << (totalSalary / N) << endl;
    cout << "Highest Paid Employee: " << highestName << " (" << highestSalary << ")\n";
}

void searchEmployee() {
    cout << "\nEnter name to search: ";
    string searchName, line;
    cin >> ws;
    getline(cin, searchName);

    ifstream searchFile("merged.txt");
    bool found = false;
    while (getline(searchFile, line)) {
        size_t namePos = line.find("Name: ") + 6;
        size_t agePos = line.find("| Age:");
        string name = line.substr(namePos, agePos - namePos - 1);

        if (name == searchName) {
            cout << "Record found:\n" << line << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Employee not found.\n";
    searchFile.close();
}
