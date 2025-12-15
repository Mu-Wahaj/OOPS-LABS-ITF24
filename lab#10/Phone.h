#pragma once
#include <string>
class MobilePhone
{
private:
    string manufacturer;
    string model;
    bool poweredOn;

public:
    MobilePhone();
    MobilePhone(const string &manufacturer, const string &model);
    ~MobilePhone();

    void turnOn();
    void turnOff();
    bool isPoweredOn() const;

    string getManufacturer() const;
    string getModel() const;
    void setManufacturer(const string &manufacturer);
    void setModel(const string &model);

    void showInfo() const;
    friend istream &operator>>(istream &in, MobilePhone &s);
    friend ostream &operator<<(ostream &out, const MobilePhone &s);
};

ostream &operator<<(ostream &out, const MobilePhone &s)
{
    out << s.manufacturer << s.model << s.poweredOn;
    return out;
}

istream &operator>>(istream &in, MobilePhone &s)
{
    in >> s.manufacturer >> s.model >> s.poweredOn;

    return in;
}
