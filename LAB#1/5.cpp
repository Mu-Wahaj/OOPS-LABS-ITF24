#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int hours, minutes;
    cout << "Enter hours (0-23): ";
    cin >> hours;
    cout << "Enter minutes (0-59): ";
    cin >> minutes;

    string period = "AM";

    if (hours == 0) {
        hours = 12;
        period = "AM";
    } else if (hours == 12) {
        period = "PM";
    } else if (hours > 12) {
        hours -= 12;
        period = "PM";
    }

    cout << "Time in 12-hour format: " 
         << setw(2) << setfill('0') << hours << ":"
         << setw(2) << setfill('0') << minutes 
         << " " << period << endl;

    return 0;
}
