//
// Created by nicholas on 11/18/21.
//

#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "TumblingDie.h"


class BackgammonPlayer {
private:

    TumblingDie die1;
    TumblingDie die2;
    int currentRoll;
    std::vector<int> menPositions = {1, 1, 1};
    int bearOffScore = 21;
    std::string playerName;

public:

    /**
     * explicit BackgammonPlayer(std::string name = {})
     *
     * Constructor for player with optional player name
    **/

    explicit BackgammonPlayer(std::string name = {});

    /**
     * unsigned char rollDice()
     *
     * Rolls the dice returning a random number
    **/

    int rollDice();

    /**
     * int getManPosition(int pos = 0)
     *
     * Gets position of the specified man
    **/

    int getManPosition(int pos = 0);

    /**
     * void bearOff(int pos)
     *
     * Removes man from positions vector
    **/

    void bearOff(int pos);

    /**
     * void moveBestMan(BackgammonPlayer &opponent)
     *
     * Moves the best man, with the highest current position
    **/

    void moveBestMan(BackgammonPlayer &opponent);

    /**
     * bool winConditionMet()
     *
     * Returns true if player has met win condition of all men being off board, false otherwise.
    **/

    bool winConditionMet();

    /**
     * std::vector<int> getMenPositions()
     *
     * Gets Positions of players men
    **/

    std::vector<int> getMenPositions();

    /**
     * void printPositions(BackgammonPlayer &opponent)
     *
     * Prints moves to user
    **/

    void printPositions(BackgammonPlayer &opponent);



};


