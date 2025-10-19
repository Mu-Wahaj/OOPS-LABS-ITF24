#include <iostream>
using namespace std;

class Time
{
    int hours;
    int minutes;
    int seconds;

public:
    void setHours(int h)
    {
        if (h >= 0 && h < 24)
            hours = h;
        else
            hours = 0;
    }

    void setMinutes(int m)
    {
        if (m >= 0 && m < 60)
            minutes = m;
        else
            minutes = 0;
    }

    void setSeconds(int s)
    {
        if (s >= 0 && s < 60)
            seconds = s;
        else
            seconds = 0;
    }

    int getHours()
    {
        return hours;
    }

    int getMinutes()
    {
        return minutes;
    }

    int getSeconds()
    {
        return seconds;
    }

    void setTime(int h, int m, int s)
    {
        setHours(h);
        setMinutes(m);
        setSeconds(s);
    }

    void displayTime()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    void addTime(Time t1, Time t2)
    {
        seconds = t1.seconds + t2.seconds;
        minutes = t1.minutes + t2.minutes;
        hours = t1.hours + t2.hours;

        if (seconds >= 60)
        {
            minutes = minutes + (seconds / 60);
            seconds = seconds % 60;
        }

        if (minutes >= 60)
        {
            hours = hours + (minutes / 60);
            minutes = minutes % 60;
        }

        if (hours >= 24)
            hours = hours % 24;
    }
};

int main()
{
    Time t1, t2, t3;
    int h, m, s;

    cout << "Hours: ";
    cin >> h;
    cout << "Minutes: ";
    cin >> m;
    cout << "Seconds: ";
    cin >> s;
    t1.setTime(h, m, s);

    cout << "Enter second time:" << endl;
    cout << "Hours: ";
    cin >> h;
    cout << "Minutes: ";
    cin >> m;
    cout << "Seconds: ";
    cin >> s;
    t2.setTime(h, m, s);

    cout << endl;
    cout << "Time 1: ";
    t1.displayTime();

    cout << "Time 2: ";
    t2.displayTime();

    t3.addTime(t1, t2);
    cout << "Total Time: ";
    t3.displayTime();

    return 0;
}