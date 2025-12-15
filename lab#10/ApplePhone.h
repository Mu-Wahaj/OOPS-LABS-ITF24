#pragma once
#include "Phone.h"

class ApplePhone : public MobilePhone
{
public:
    ApplePhone(const string &model, const string manufacturer);

    void makeVoiceCall(string &phoneNumber);
    void endVoiceCall();
    void sendSMS(const string &message, long recipientNumber);
    void takePhoto(const string &filePath);
    void openBrowser(const string &url);
};