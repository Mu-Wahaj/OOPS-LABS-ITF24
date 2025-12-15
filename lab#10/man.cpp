
#include <iostream>
using namespace std;
#include <string>
#include "Phone.h"
#include "Windows.h"
#include "Android.h"
#include "ApplePhone.h"

int main()
{
    ApplePhone myPhone("iPhone 13", "iOS 15");
    myPhone.turnOn();
    myPhone.showInfo();
    string phoneNumber("12345684");
   
    myPhone.makeVoiceCall(phoneNumber);
    myPhone.endVoiceCall();
    myPhone.sendSMS("Hello, this is a test message.", 9876543210);
    myPhone.takePhoto("D:/Photos/Android/android_img1.jpg ");
 myPhone.openBrowser("www.android.com");
    return 0;
}
