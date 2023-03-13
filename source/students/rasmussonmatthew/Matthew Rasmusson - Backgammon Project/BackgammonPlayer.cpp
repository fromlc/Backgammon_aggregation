//------------------------------------------------------------------------------
// Matthew Rasmusson
// CS 281-0798
// November 15, 2021
//------------------------------------------------------------------------------
// BackgammonPlayer.cpp
//
// BackgammonPlayer class definition file
//------------------------------------------------------------------------------
#include "BackgammonPlayer.h"
#include "TumblingDie.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

//------------------------------------------------------------------------------
// RollDice(): calls getRollValue() from TumblingDie.cpp, returns two int values 
//             that get added together and displayed.
//------------------------------------------------------------------------------
int BackgammonPlayer::rollDice()
{
    int value1 = die1.getRollValue();
    int value2 = die2.getRollValue();
    std::cout << " rolls " << value1 << " + " << value2 <<": " << (value1 + value2) << "\n";
    return (value1 + value2);
}

//------------------------------------------------------------------------------
// getIndex(): uses std::find() to return the index of the positionTracker that 
//             matches a passed value "manPos"
//------------------------------------------------------------------------------
int BackgammonPlayer::getIndex(int manPos) const
{
    auto it = std::find(this->positionTracker.begin(), this->positionTracker.end(), manPos);
    int index = it - this->positionTracker.begin();
    return index;
}

//------------------------------------------------------------------------------
// setPosition(): updates the value at the index of "manPos" in positionTracker 
//                by adding the dice roll passed in "newPosition"
//------------------------------------------------------------------------------
void BackgammonPlayer::setPosition(int manPos, int newPosition)
{
    this->positionTracker[manPos] += newPosition;
}

//------------------------------------------------------------------------------
// getBest(): returns the value of the bestPosition private variable 
//------------------------------------------------------------------------------
int BackgammonPlayer::getBest() const
{
    return this->bestPosition;
}

//------------------------------------------------------------------------------
// setBest(): uses *std::max_element to set the value of bestPosition to the 
//            highest value in the player's positionTracker vector
//------------------------------------------------------------------------------
void BackgammonPlayer::setBest()
{
    bestPosition = *std::max_element(std::begin(positionTracker), std::end(positionTracker));
}

//------------------------------------------------------------------------------
// getSecond(): returns the value of the secondPosition private variable 
//------------------------------------------------------------------------------
int BackgammonPlayer::getSecond() const
{
    return this->secondPosition;
}

//------------------------------------------------------------------------------
// setsecond(): uses a for loop to compare the values in the positionTracker
//              vector to the best and third positions, setting the 'middle' 
//              value to secondPosition
//------------------------------------------------------------------------------
void BackgammonPlayer::setSecond()
{
    for (int value : positionTracker)
    {
        if (value >= thirdPosition && value <= bestPosition)
        {
            secondPosition = value;
        }
    }
}

//------------------------------------------------------------------------------
// getThird(): returns the value of the thirdPosition private variable
//------------------------------------------------------------------------------
int BackgammonPlayer::getThird() const
{
    return this->thirdPosition;
}

//------------------------------------------------------------------------------
// setThird(): uses *std::min_element to set the value of thirdPosition to the 
//            lowest value in the player's positionTracker vector
//------------------------------------------------------------------------------
void BackgammonPlayer::setThird()
{
    thirdPosition = *std::min_element(std::begin(positionTracker), std::end(positionTracker));
}

//------------------------------------------------------------------------------
// findPositionIn2(): uses std::find() to locate the "posToCheck" value in the 
//                    player2 positionTracker vector. If found, returns "true".
//------------------------------------------------------------------------------
bool BackgammonPlayer::findPositionIn2(BackgammonPlayer& player2, int posToCheck)
{
    auto it = std::find(player2.positionTracker.begin(), player2.positionTracker.end(), posToCheck);
    if (it != player2.positionTracker.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//------------------------------------------------------------------------------
// findPositionIn1(): uses std::find() to locate the "posToCheck" value in the 
//                    player1 positionTracker vector. If found, returns "true".
//------------------------------------------------------------------------------
bool BackgammonPlayer::findPositionIn1(BackgammonPlayer& player1, int posToCheck)
{
    auto it = std::find(player1.positionTracker.begin(), player1.positionTracker.end(), posToCheck);
    if (it != player1.positionTracker.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//------------------------------------------------------------------------------
// readPositons(): outputs the three positions of the 'men' from the positionTracker 
//------------------------------------------------------------------------------
void BackgammonPlayer::readPositions()
{
    for (int value : this->positionTracker)
    {
        std::cout << value << " ";
    }
}

//------------------------------------------------------------------------------
// bearOff(): replaces the value of a man's position with '0' once their position
//            value exceeds 20, and prints a message to the user.
//------------------------------------------------------------------------------
void BackgammonPlayer::bearOff()
{
    for (int value : this->positionTracker)
    {
        if (value > 20)
        {
            int off = this->getIndex(value);
            this->positionTracker[off] = 0;
            std::cout << "A man has been beared off.\n\n";
        }
    }
}

//------------------------------------------------------------------------------
// checkVectors(): checks the player's positionTracker for three '0' values, if
//                 "true", that player wins the game
//------------------------------------------------------------------------------
bool BackgammonPlayer::checkVectors()
{
    int bearedPieces = 0;
    for (int value : this->positionTracker)
    {
        if (value == 0)
        {
            bearedPieces++;
        }
    }
    if (bearedPieces == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}