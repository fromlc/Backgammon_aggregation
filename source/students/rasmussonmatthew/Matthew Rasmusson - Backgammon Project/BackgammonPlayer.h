//------------------------------------------------------------------------------
// Matthew Rasmusson
// CS 281-0798
// November 15, 2021	   
//------------------------------------------------------------------------------
// BackgammonPlayer class declaration file
//------------------------------------------------------------------------------
#ifndef BACKGAMMONPLAYER_H
#define BACKGAMMONPLAYER_H

#include <string>
#include <vector>
#include "TumblingDie.h"

class BackgammonPlayer 
{
private:
    //private position variables to do comparisons for placing men
    int bestPosition = 1;
    int secondPosition = 1;
    int thirdPosition = 1;
    //this vector sets the men all to the first position by default, updates with setter methods
    std::vector<int> positionTracker{1,1,1}; 
    //each player receives two 6-sided dice
    TumblingDie die1, die2 = TumblingDie::TumblingDie();

public:
    int rollDice();
    //Getter and setter methods,
    int getIndex(int man) const;
    void setPosition(int manPos, int newPosition);
    int getBest() const;
    void setBest();
    int getSecond() const;
    void setSecond();
    int getThird() const;
    void setThird();
    //checking functions that access the vector positionTracker
    bool findPositionIn2(BackgammonPlayer& player2, int posToCheck);
    bool findPositionIn1(BackgammonPlayer& player1, int posToCheck);
    void readPositions();
    void bearOff();
    bool checkVectors();
};

#endif
