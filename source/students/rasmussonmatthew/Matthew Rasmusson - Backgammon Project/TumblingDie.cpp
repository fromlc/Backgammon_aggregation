//------------------------------------------------------------------------------
// Matthew Rasmusson
// CS 281-0798
// November 8, 2021
//------------------------------------------------------------------------------
// TumblingDie.cpp
//
// TumblingDie class definition file
//------------------------------------------------------------------------------
#include "TumblingDie.h"
#include <vector>

//------------------------------------------------------------------------------
// TumblingDie(): default constructor of TumblingDie Class
//------------------------------------------------------------------------------
TumblingDie::TumblingDie()
{
    DieSides = 6;
}

//------------------------------------------------------------------------------
// TumblingDie(int sides): initial setter of DieSides with passed int argument
//------------------------------------------------------------------------------
TumblingDie::TumblingDie(int sides)
{
    DieSides = sides;
}

//------------------------------------------------------------------------------
// getRoll(): uses push_back to add a value onto the RollTracker Vector
//------------------------------------------------------------------------------
int TumblingDie::getRollValue()
{
    int roll = rand() % DieSides + 1;
    return roll;
}