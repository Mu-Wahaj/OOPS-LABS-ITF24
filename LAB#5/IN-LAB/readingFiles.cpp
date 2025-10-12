#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int days;
    cout << "Enter number of days: ";
    cin >> days;

    double *sales = new double[days];

    ofstream outFile("sales.txt");
    for (int i = 0; i < days; i++) {
        cout << "Enter sales for day " << i + 1 << ": ";
        cin >> *(sales + i);
        outFile << *(sales + i) << endl;
    }
    outFile.close();

    ifstream inFile("sales.txt");
    double total = 0, value;
    int count = 0;

    cout << "\nSales data from file:\n";
    while (inFile >> value) {
        cout << "Day " << ++count << ": " << value << endl;
        total += value;
    }
    inFile.close();

    double average = (float)total / days;

    cout << "\nTotal Sales: " << total << endl;
    cout << "Average Sales: " << average << endl;

    delete[] sales;
    return 0;
}
