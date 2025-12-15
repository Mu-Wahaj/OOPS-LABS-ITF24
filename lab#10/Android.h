#pragma once
#include "Phone.h"

class AndroidPhone : public MobilePhone { 
public: 
    AndroidPhone(const string& model, const string manufacturer); 
 
    void makeVoiceCall(const string& phoneNumber); 
    void endVoiceCall(); 
    void sendSMS(const string& message, long recipientNumber); 
    void takePhoto(const string& filePath); 
    void openBrowser(const string& url); 
}; 