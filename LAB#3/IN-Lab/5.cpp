#include <iostream>
#include <cstdlib>  // for rand, srand
#include <ctime>    // for time
using namespace std;

void playTurn(int &score) {
    for (int i = 0; i < 3; i++) {
        int dice = rand() % 6 + 1; 

        if (dice < 1 || dice > 6) {
            cout << "Invalid dice roll!" << endl;
        } else {
            cout << "Rolled: " << dice << endl;
            score += dice;
        }
    }
    cout << "Turn finished. Total score: " << score << endl << endl;
}

int main() {
    srand(time(0)); // seed randomness

    int player1 = 0, player2 = 0;

    cout << "Player 1's turn:" << endl;
    playTurn(player1);

    cout << "Player 2's turn:" << endl;
    playTurn(player2);

    // Determine winner
    if (player1 > player2) {
        cout << "Player 1 wins with score " << player1 << "!" << endl;
    } else if (player2 > player1) {
        cout << "Player 2 wins with score " << player2 << "!" << endl;
    } else {
        cout << "Draw! Both scored " << player1 << "." << endl;
    }

    return 0;
}
