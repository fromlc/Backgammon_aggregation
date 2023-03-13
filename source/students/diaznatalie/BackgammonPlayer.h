//---------------------------------------------------------------------------------
// BackgammonPlayer.h : class declaration
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
#ifndef BACKGAMMONPLAYER_H
#define BACKGAMMONPLAYER_H

#include "TumblingDie.h"

//---------------------------------------------------------------------------------
// BackgammonPlayer class : aggregates the TumblingDie class.
//
//---------------------------------------------------------------------------------
class BackgammonPlayer
{
// Private data
private:
	TumblingDie* tumblingDie1;		// Aggregate two TumblingDie class instances
	TumblingDie* tumblingDie2;
	// int position[3] = { 1, 1, 1 };	// An array representing the position of each player's men
	int position = 1;				// Represents starting position of player's man

// Public methods
public:
	// Default constructor
	BackgammonPlayer();

	// Overloaded constructor
	BackgammonPlayer(TumblingDie* aDie, TumblingDie* aDie2);

	// Deconstructor
	//~BackgammonPlayer();

	// Mutator functions (SET METHODS : set the values)
	void setPosition(int pos);

	// Accessor functions (GET METHODS : return the values)
	int getPosition() const;

	// Class tools
	int playerRoll();
};

#endif  // BACKGAMMONPLAYER_H
