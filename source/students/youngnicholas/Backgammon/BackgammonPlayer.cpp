//
// Created by nicholas on 11/18/21.
//

#include "BackgammonPlayer.h"

#include <utility>

int BackgammonPlayer::rollDice() {
    die1.rollDie();
    die2.rollDie();
    currentRoll = die1.currentRoll + die2.currentRoll;
    return currentRoll;
}

int BackgammonPlayer::getManPosition(int pos) {
    return menPositions[pos];
}

void BackgammonPlayer::bearOff(int pos) {
    menPositions.erase(menPositions.begin() + pos);
}

void BackgammonPlayer::moveBestMan(BackgammonPlayer &opponent) {

    // Find The element with the maximum value as to be used as the default move,
    // ensuring move is legal and does not land on a spot an enemy man is on.
    int maxElement = 0;
    int maxElementIndex = 0;

    // Loop over players remaining men
    for (int index = 0; index < menPositions.size(); index++) {
        // Loop over enemy remaining men
        for (int opponentPosition : opponent.menPositions) {
            if(menPositions[index] < maxElement){
                continue;
            }
            if (menPositions[index] + currentRoll ==  opponentPosition){
                continue;
            }
        }
        maxElement = menPositions[index];
        maxElementIndex = index;
    }

    // Move man
    menPositions[maxElementIndex] += currentRoll;

    // Check if moving qualifies man to bear off
    if (menPositions[maxElementIndex] >= bearOffScore){
        bearOff(maxElementIndex);
    }
}

bool BackgammonPlayer::winConditionMet() {
    return menPositions.empty();
}

std::vector<int> BackgammonPlayer::getMenPositions() {
    return menPositions;
}

void BackgammonPlayer::printPositions(BackgammonPlayer &opponent) {

    // Print Opponent Positions

    std::cout << "   " << opponent.playerName << std::endl;

    for (int opponentPosition : opponent.menPositions) {
        if (opponentPosition < 10){
            std::cout << " 0" << opponentPosition << "  ";
            continue;
        }
        std::cout << " " << opponentPosition << "  ";
    }


    std::cout <<"\n"<< R"(\  / \  / \  /)" << std::endl;
    std::cout << R"( \/   \/   \/)" << std::endl;

    // Print Player Positions

    std::cout << "\n" << R"( /\   /\   /\)" << std::endl;
    std::cout << R"(/  \ /  \ /  \)" << std::endl;

    for (int position : menPositions) {
        if (position < 10){
            std::cout << " 0" << position << "  ";
            continue;
        }
        std::cout << " " << position << "  ";
    }


    std::cout << "\n" << "   " << playerName << std::endl;

    std::cout << "\n" << "---------------" << "\n" << std::endl;








}

BackgammonPlayer::BackgammonPlayer(std::string name) {
    currentRoll = 0;
    playerName = std::move(name);
}
