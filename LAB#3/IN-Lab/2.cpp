#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bookSeat(int seats[][4], int &row, int &col);
int main()
{
    srand(time(0));
    int seats[4][4];

    cout << "enter elements of an array\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            seats[i][j] = rand() % 2;
        }
    }
    // printing of rray

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }

    // asking user to input the location they want to book

    int row, col;
    cout << "\nEnter row (0-3) and column (0-3) to book a seat: ";
    cin >> row >> col;
    bookSeat(seats, row, col);
    if (row == -1 && col == -1)
    {
        cout << "Booking failed! Invalid or already booked seat.\n";
        return 0;
    }
    else
    {
        cout << "Seat booked successfully at (" << row << ", " << col << ").\n";
        cout << "\nUpdated Seating Chart:\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
    }

    

    return 0;
}
void bookSeat(int seats[][4], int &row, int &col)
{
    if (row < 0 || row >= 4 || col < 0 || col >= 4)
    {
        row = -1;
        col = -1;
        return;
    }
    if (seats[row][col] == 1)
    {
        row = -1;
        col = -1;
        return;
    }

    seats[row][col] = 1;
}