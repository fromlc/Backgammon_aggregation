#include <iostream>
#include "BackgammonPlayer.h"
#include "UserInput.h"

int main() {
    // Main Program loop
    while(true) {

        // Initialize Players
        BackgammonPlayer Player1("Player 1");
        BackgammonPlayer Player2("Player 2");

        // Automatically Play game
        while (true) {
            Player1.rollDice();
            Player1.moveBestMan(Player2);
            Player1.printPositions(Player2);
            if (Player1.winConditionMet()) {
                std::cout << "Player 1 Wins!" << "\n" << std::endl;
                break;
            }
            Player2.rollDice();
            Player2.moveBestMan(Player1);
            Player2.printPositions(Player1);
            if (Player2.winConditionMet()) {
                std::cout << "Player 2 Wins!" << "\n" << std::endl;
                break;
            }
        }

        char playAgain = std::tolower(getUserInput<char>("Play Again Y/N?"));
        while (true) {
            if (playAgain == 'y'|| playAgain == 'n') {
                break;
            }
            playAgain = getUserInput<char>("Play Again Y/N?");
        }

        if (playAgain == 'n'){
            break;
        }
    }
    return 0;
}
