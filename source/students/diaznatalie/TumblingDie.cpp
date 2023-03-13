//---------------------------------------------------------------------------------
// TumblingDie.cpp
//
// Natalie Diaz
// CS 281 Fall 2021
// Week 13 Assignment - Backgammon
// November 20, 2021
//
// Function definitions
//---------------------------------------------------------------------------------

#include <iostream>
#include <ctime>
#include <vector>

#include "TumblingDie.h"

// Class TumblingDie definition

//---------------------------------------------------------------------------------
// TumblingDie() : Default constructor - sets die to a cube
//---------------------------------------------------------------------------------
TumblingDie::TumblingDie() {
	sides = 6;
}

//---------------------------------------------------------------------------------
// TumblingDie() : Overloaded constructor - sets die sides to user input
//---------------------------------------------------------------------------------
TumblingDie::TumblingDie(int numSides) {
	sides = numSides;
}

//---------------------------------------------------------------------------------
// ~TumblingDie() : Deconstructor
//---------------------------------------------------------------------------------
TumblingDie::~TumblingDie() {};

//---------------------------------------------------------------------------------
// setSides() :
//---------------------------------------------------------------------------------
void TumblingDie::setSides(int sides)
{
	this->sides = sides;
}

//---------------------------------------------------------------------------------
// getSides() : 
//---------------------------------------------------------------------------------
int TumblingDie::getSides() const { return sides; }


//---------------------------------------------------------------------------------
// getHistory() :
//---------------------------------------------------------------------------------
std::vector<int> TumblingDie::getHistory()
{
	return rolls;
}

//---------------------------------------------------------------------------------
// getRolls() : Ask user how many rolls will be played
//---------------------------------------------------------------------------------
int TumblingDie::getRolls()
{
	int numRolls;
	std::cout << "How many rolls?: " << std::endl;
	std::cin >> numRolls;
	// #TODO : validation code
	return numRolls;
}

//---------------------------------------------------------------------------------
// rollDie() : 
//---------------------------------------------------------------------------------
int TumblingDie::rollDie()
{
	value = (int)(1 + rand() % (sides - 1 + 1));
	rolls.push_back(value);
	return value;
}

//---------------------------------------------------------------------------------
// playAgain() : Ask player if they want to continue
//---------------------------------------------------------------------------------
bool TumblingDie::playAgain()
{
	char play;
	std::cout << "Do you want to play? Y or N >> ";
	std::cin >> play;
	play = tolower(play);
	return play == 'y';
}
