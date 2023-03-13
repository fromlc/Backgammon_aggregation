//---------------------------------------------------------------------------------
// TumblingDie.h : class declaration
//
// Natalie Diaz
// CS 281 Fall 2021
// Week 13 Assignment - Backgammon
// November 20, 2021
//
// Class definitions
//---------------------------------------------------------------------------------

// Include guard
#pragma once
#ifndef TUMBLINGDIE_H
#define TUMBLINGDIE_H

#include <vector>

//---------------------------------------------------------------------------------
// TumblingDie class : 
//
//---------------------------------------------------------------------------------
class TumblingDie{

// Private members (DATA)
private:
	int sides;			// Number of sides on the die
	int value;			// Value of die after roll
	std::vector<int> rolls;

// Public members (BEHAVIORS - METHODS)
public:
	// Default constructor - sets die to a cube
	TumblingDie();

	// Overloaded constructor - sets die sides to user input
	TumblingDie(int numSides);

	// Deconstructor
	~TumblingDie();

	// Mutator functions (SET METHODS : set the values)
	void setSides(int sides);

	// Accessor functions (GET METHODS : return the values)
	int getSides() const;

	// Class tools
	int rollDie();
	bool playAgain();
	int getRolls();

	// Report rolls so far
	std::vector<int> getHistory();
};

#endif  // TUMBLINGDIE_H

