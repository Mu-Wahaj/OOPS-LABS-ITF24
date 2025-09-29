#include <iostream>
using namespace std;

void sumOfdigit(int num, int &sum);
int main()
{

  int number, result;

  cout << "enter a number : ";
  cin >> number;
  if (number == 0 && number < 0)
  {
    cout << "please a enter a valid input";
  }

  else
  {
     sumOfdigit(number, result);
    cout << "sum of numbers : " << result;
  }

  return 0;
}
void sumOfdigit(int num, int &sum)
{
   sum = 0;
  while (num > 0)
  {
    int digit = num % 10;
    sum += digit;
    num /= 10;
  }
}
