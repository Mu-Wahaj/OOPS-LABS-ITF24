
#include <iostream>
#include "Windows.h"
using namespace std;
WindowsPhone::WindowsPhone(const string &model, const string manufacturer)

    : MobilePhone(manufacturer, model)
{
}
void WindowsPhone::makeVoiceCall(const string &phoneNumber)
{
    if (isPoweredOn())
    {
        cout << "WindowsPhone making voice call to " << phoneNumber << endl;
    }
    else
    {
        cout << "WindowsPhone is powered off. Cannot make a call." << endl;
    }
}
void WindowsPhone::endVoiceCall()
{
    if (isPoweredOn())
    {
        cout << "WindowsPhone ending voice call." << endl;
    }
    else
    {
        cout << "WindowsPhone is powered off. No call to end." << endl;
    }
}
void WindowsPhone::sendSMS(const string &message, long recipientNumber)
{
    if (isPoweredOn())
    {
        cout << "WindowsPhone sending SMS to " << recipientNumber << ": " << message << endl;
    }
    else
    {
        cout << "WindowsPhone is powered off. Cannot send SMS." << endl;
    }
}
void WindowsPhone::takePhoto(const string &filePath)
{
    if (isPoweredOn())
    {
        cout << "WindowsPhone taking photo and saving to " << filePath << endl;
    }
    else
    {
        cout << "WindowsPhone is powered off. Cannot take photo." << endl;
    }
}
void WindowsPhone::openBrowser(const string &url)
{
    if (isPoweredOn())
    {
        cout << "WindowsPhone opening browser to " << url << endl;
    }
    else
    {
        cout << "WindowsPhone is powered off. Cannot open browser." << endl;
    }
}
