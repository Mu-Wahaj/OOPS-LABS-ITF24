#pragma once
#include <iostream>

class Date {
private:
    int day, month, year;

    static Date defaultDate;     // shared default date

    int daysInMonth(int m, int y) const;
    void fixDate();              // adjusts invalid dates (rolling forward)

public:
    Date(int d = 0, int m = 0, int y = 0);

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    void setDate(int d, int m, int y);

    // Static setter
    static void setDefaultDate(int d, int m, int y);

    // Utility
    bool leapYear(int y) const;

    // Add operations
    void addDay(int x);
    void addMonth(int x);
    void addYear(int x);

    void display() const;
};
//.cpp
#include "Date.h"

// Define default date (required)
Date Date::defaultDate(1, 1, 1970);

// Helper: leap year check
bool Date::leapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Helper: days in a month
int Date::daysInMonth(int m, int y) const {
    switch (m) {
        case 2: return leapYear(y) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

// Constructor — uses defaultDate if parameters are 0
Date::Date(int d, int m, int y) {
    if (d == 0 && m == 0 && y == 0) {
        day = defaultDate.day;
        month = defaultDate.month;
        year = defaultDate.year;
    } else {
        day = d;
        month = m;
        year = y;
        fixDate();
    }
}

// Fix invalid day/month values by rolling forward
void Date::fixDate() {
    if (month < 1) month = 1;
    if (month > 12) month = 12;

    int dim = daysInMonth(month, year);
    if (day < 1) day = 1;

    // If day > maxDays, roll forward into next months
    while (day > dim) {
        day -= dim;
        month++;

        if (month > 12) {
            month = 1;
            year++;
        }

        dim = daysInMonth(month, year);
    }
}

// Set date with rolling behavior
void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
    fixDate();
}

// Static: change default date
void Date::setDefaultDate(int d, int m, int y) {
    defaultDate.day = d;
    defaultDate.month = m;
    defaultDate.year = y;
}

// Add days with rolling logic
void Date::addDay(int x) {
    day += x;
    fixDate();
}

// Add months with rolling logic
void Date::addMonth(int x) {
    month += x;

    while (month > 12) {
        month -= 12;
        year++;
    }

    while (month < 1) {
        month += 12;
        year--;
    }

    // Fix invalid day (e.g., 31 April → 1 May)
    int dim = daysInMonth(month, year);
    if (day > dim) {
        day = dim;
    }
}

// Add years (simple but correct)
void Date::addYear(int x) {
    year += x;
    fixDate();
}

// Getters
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::display() const {
    std::cout << day << "/" << month << "/" << year << std::endl;
}

//.main
#include "Date.h"
#include <iostream>

int main() {

    std::cout << "=== Task 5 Tests ===\n";

    // Test leap year day rolling
    Date d1(28, 2, 2024);    // 2024 is leap year

    std::cout << "Original date: ";
    d1.display();

    d1.addDay(1);            // should go to 29 Feb
    std::cout << "After +1 day: ";
    d1.display();

    d1.addDay(2);            // should go to 2 March
    std::cout << "After +2 days: ";
    d1.display();


    // Default date test
    std::cout << "\nSetting default date to 15/8/2000...\n";
    Date::setDefaultDate(15, 8, 2000);

    Date d2;  // should pick new default date
    std::cout << "New object with default date: ";
    d2.display();


    // Month roll test
    Date d3(31, 4, 2023);    // April has 30 days → should roll to 1 May
    std::cout << "\nRolling invalid date 31/4/2023 => ";
    d3.display();


    // Add month test
    Date d4(31, 1, 2023);
    std::cout << "\nDate: ";
    d4.display();

    d4.addMonth(1);          // Feb has 28 → go to 28/2/2023
    std::cout << "After +1 month: ";
    d4.display();

    return 0;
}
