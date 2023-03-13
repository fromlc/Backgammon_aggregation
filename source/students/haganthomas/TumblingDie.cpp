//#includes
#include <iostream>
#include "TumblingDie.h"

//Default constructor
TumblingDie::TumblingDie() 
{
	diceSides = 6;
}

//Overload constructor
TumblingDie::TumblingDie(unsigned char diceSides)
{
	this->diceSides = diceSides;
}

//Destructor
TumblingDie::~TumblingDie()
{
	diceRolls.clear();
	diceRolls.shrink_to_fit();
}


//Setter functions
void TumblingDie::setDiceSides(unsigned char diceSides)
{
	this->diceSides = diceSides;
}

//Getter functions
unsigned char TumblingDie::getDiceSides() const
{
	return diceSides;
}

std::vector<unsigned char> TumblingDie::getDiceRolls() const
{
	return diceRolls;
}

//Class behavior functions

//Function to roll random number up to limit input by user
void TumblingDie::rollDice()
{
	int diceface;
	int result;
	diceface = this->diceSides;
	result = rand() % diceface;
	diceRolls.push_back(result);
}

//Clears the diceRolls vector
void TumblingDie::clearDiceRolls()
{
	diceRolls.clear();
	diceRolls.shrink_to_fit();
}


