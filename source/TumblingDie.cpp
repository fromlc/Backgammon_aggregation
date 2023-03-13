//------------------------------------------------------------------------------
// CS 281-0798
// 
// TumblingDie.cpp : class definition file
//------------------------------------------------------------------------------
#include "TumblingDie.h"

#include <cstdlib>
#include <ctime>
#include <vector>

//------------------------------------------------------------------------------
// default constructor
//------------------------------------------------------------------------------
TumblingDie::TumblingDie() : TumblingDie(DIE_SIDES) {}

//------------------------------------------------------------------------------
// overload constructor
//------------------------------------------------------------------------------
TumblingDie::TumblingDie(int sides)
{ 
    this->sides = sides;
    this->value = 0;
    srand(static_cast<unsigned int>(time(0)));
}

//------------------------------------------------------------------------------
// destructor
//------------------------------------------------------------------------------
TumblingDie::~TumblingDie()
{
    vRolls.clear();
    vRolls.shrink_to_fit();
}

//------------------------------------------------------------------------------
// getDieSides()
//------------------------------------------------------------------------------
int TumblingDie::getDieSides() const
{ return sides; }

//------------------------------------------------------------------------------
// setDieSides()
//------------------------------------------------------------------------------
void TumblingDie::setDieSides(int sides)
{ this->sides = sides; }

//------------------------------------------------------------------------------
// getRollHistory() : returns copy of roll history vector
//------------------------------------------------------------------------------
std::vector<int> TumblingDie::getRollHistory() const
{ return vRolls; }

//------------------------------------------------------------------------------
// rollDie()
//      - returns random value 1 <= v <= # sides
//      = adds v to roll history vector
//------------------------------------------------------------------------------
int TumblingDie::rollDie()
{
    int roll = rand() % this->sides + 1;
    value = roll;
    vRolls.push_back(roll);
    return roll;
}

//------------------------------------------------------------------------------
// getValue(): returns value of last roll
//------------------------------------------------------------------------------
int TumblingDie::getValue()
{
    this->value = rand() % this->sides + 1;
    vRolls.push_back(this->value);
    return this->value;
}