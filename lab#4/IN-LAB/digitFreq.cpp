#include <iostream>
using namespace std;

int frequency(int *num, int *freq);
int main()
{

    int number;
    int freq[10] = {0};
    cout << "enter a number";
    cin >> number;

    int *ptrs = &number;

    frequency(&number, freq);
    for (int i = 0; i < 10; i++)
    {
        cout<<freq[i];
    }
    


    return 0;
}
int frequency(int *num, int *freq)
{

    for (int i = *num; i > 0; i++)
    {

        int digit = *num % 10;
        if (digit == 0)
        {
            freq[0]++;
        }
        else if (digit == 1)
        {

            freq[1]++;
        }
        else if (digit == 1)
        {

            freq[2];
        }
        else if (digit == 1)
        {

            freq[3]++;
        }
        else if (digit == 1)
        {

            freq[4]++;
        }
        else if (digit == 1)
        {

            freq[5]++;
        }
        else if (digit == 1)
        {

            freq[6]++;
        }
        else if (digit == 1)
        {

            freq[7]++;
        }
        else if (digit == 1)
        {

            freq[8]++;
        }
        else if (digit == 1)
        {

            freq[9]++;
        }
        *num = digit / 10;
    }
    return *freq;
}
