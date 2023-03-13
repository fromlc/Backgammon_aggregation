#pragma once
//------------------------------------------------------------------------------
// CS 281-0798, Fall 2021
// Week 11	   
//------------------------------------------------------------------------------
// BackgammonPlayer class declaration file
//------------------------------------------------------------------------------
#pragma once
#include <vector>
#include <string>
#include <iostream>

class BackgammonPlayer
{
private:
	//private variables
	int diceValue = 0;
	int playerPlacement = 0;

public:

	//Function prototype
	void getRolls();
	void playerTurn();

	//default constuctor
	BackgammonPlayer() {}

	//setters
	void setplayerPlacement(int x) {
		playerPlacement = x; 
	}

	//getters
	int getplayerPlacement() {
		return playerPlacement;
	}
};