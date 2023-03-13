//---------------------------------------------------------------------------------
// BackgammonPlayer.cpp
//
// Natalie Diaz
// CS 281 Fall 2021
// Week 13 Assignment - Backgammon
// November 20, 2021
//
// Function definitions
//---------------------------------------------------------------------------------

#include <iostream>

#include "BackgammonPlayer.h"

// Class BackgammonPlayer definition

//---------------------------------------------------------------------------------
// BackgammonPlayer() : Default constructor
//---------------------------------------------------------------------------------
BackgammonPlayer::BackgammonPlayer() { }

//---------------------------------------------------------------------------------
// BackgammonPlayer() : Overloaded constructor
//---------------------------------------------------------------------------------
BackgammonPlayer::BackgammonPlayer(TumblingDie* aDie1, TumblingDie* aDie2) { 
	this->tumblingDie1 = aDie1;
	this->tumblingDie2 = aDie2;
}

// Set methods

//---------------------------------------------------------------------------------
// setPosition() : 
//---------------------------------------------------------------------------------
void BackgammonPlayer::setPosition(int moves) 
{
	// Starting position 1 plus number of moves
	this->position += moves;
}

// Get methods

//---------------------------------------------------------------------------------
// getPosition() : 
//---------------------------------------------------------------------------------
int BackgammonPlayer::getPosition() const { return position; }


//---------------------------------------------------------------------------------
// playerRoll() : Returns the value of a roll using two 6-sided dice
//---------------------------------------------------------------------------------
int BackgammonPlayer::playerRoll()
{
	int playersRoll = ((tumblingDie1->rollDie()) + (tumblingDie2->rollDie()));
	return playersRoll;
}
