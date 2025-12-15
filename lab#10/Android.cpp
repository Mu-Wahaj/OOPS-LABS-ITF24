#include<Android.h>
#include <iostream>
using namespace std;
AndroidPhone::AndroidPhone(const string &model, const string manufacturer)
    : MobilePhone(manufacturer, model) {}
void AndroidPhone::makeVoiceCall(const string &phoneNumber)
{
    if (isPoweredOn())
    {
        cout << "AndroidPhone making voice call to " << phoneNumber << endl;
    }
    else
    {
        cout << "AndroidPhone is powered off. Cannot make a call." << endl;
    }
}
void AndroidPhone::endVoiceCall()
{
    if (isPoweredOn())
    {
        cout << "AndroidPhone ending voice call." << endl;
    }
    else
    {
        cout << "AndroidPhone is powered off. No call to end." << endl;
    }
}
void AndroidPhone::sendSMS(const string &message, long recipientNumber)
{
    if (isPoweredOn())
    {
        cout << "AndroidPhone sending SMS to " << recipientNumber << ": " << message << endl;
    }
    else
    {
        cout << "AndroidPhone is powered off. Cannot send SMS." << endl;
    }
}
void AndroidPhone::takePhoto(const string &filePath)
{
    if (isPoweredOn())
    {
        cout << "AndroidPhone taking photo and saving to " << filePath << endl;
    }
    else
    {
        cout << "AndroidPhone is powered off. Cannot take photo." << endl;
    }
}
void AndroidPhone::openBrowser(const string &url)
{
    if (isPoweredOn())
    {
        cout << "AndroidPhone opening browser to " << url << endl;
    }
    else
    {
        cout << "AndroidPhone is powered off. Cannot open browser." << endl;
    }
}



