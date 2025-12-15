#include<ApplePhone.h>
#include <iostream>
using namespace std;
ApplePhone::ApplePhone(const string &model, const string manufacturer)
    : MobilePhone(manufacturer, model) {}
void ApplePhone::makeVoiceCall(string &phoneNumber)
{
    if (isPoweredOn())
    {
       cout << "ApplePhone making voice call to " << phoneNumber <<endl;
    }
    else
    {
       cout << "ApplePhone is powered off. Cannot make a call." <<endl;
    }
}
void ApplePhone::endVoiceCall()
{
    if (isPoweredOn())
    {
       cout << "ApplePhone ending voice call." <<endl;
    }
    else
    {
       cout << "ApplePhone is powered off. No call to end." <<endl;
    }
}
void ApplePhone::sendSMS(const string &message, long recipientNumber)
{
    if (isPoweredOn())
    {
       cout << "ApplePhone sending SMS to " << recipientNumber << ": " << message <<endl;
    }
    else
    {
       cout << "ApplePhone is powered off. Cannot send SMS." <<endl;
    }
}
void ApplePhone::takePhoto(const string &filePath)
{
    if (isPoweredOn())
    {
       cout << "ApplePhone taking photo and saving to " << filePath <<endl;
    }
    else
    {
       cout << "ApplePhone is powered off. Cannot take photo." <<endl;
    }
}
void ApplePhone::openBrowser(const string &url)
{
    if (isPoweredOn())
    {
       cout << "ApplePhone opening browser to " << url <<endl;
    }
    else
    {
       cout << "ApplePhone is powered off. Cannot open browser." <<endl;
    }
}


