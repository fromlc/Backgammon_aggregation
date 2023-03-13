//---------------------------------------------------------------------------------
// Backgammon.cpp
//
// Natalie Diaz
// CS 281 Fall 2021
// Week 13 Assignment - Backgammon
// November 20, 2021
//
// Backgammon App Demo
//---------------------------------------------------------------------------------

#include <iostream>
#include <ctime>
#include <vector>

#include "TumblingDie.h"
#include "BackgammonPlayer.h"

//---------------------------------------------------------------------------------
// main() : entry point
//---------------------------------------------------------------------------------
int main()
{
	// Display intro message
	std::cout << "This is an Automated Game of Backgammon" << std::endl;
	std::cout << "Each player has 3 men." << std::endl;

	// PSEUDOCODE DESIGN:
	// Create two players
	// For each player:
	// Start player at position 1
	// Roll two die with 6-sides each and total the value
	// Add value to player position
	// Display move outcome
	// Repeat until position > 20
	// Repeat 3 times (one for each man)
	// Player to complete 3x first wins. Declare winner
	// Ask if player would like to play again or quit

	// Create two BackgammonPlayer class instances that represent each player
	BackgammonPlayer p1;
	BackgammonPlayer p2;

	// Declare a TumblingDie class object
	TumblingDie d1;

	// Play full round of backgammon until user quits
	do {
		// Repeat 3 times (one for each man)
		for (int i = 0; i < 3; i++)
		{
			do {
				// For player 1, roll the dice and return value of moves
				int moves = p1.playerRoll();
				std::cout << "Player 1 rolled: " << moves << std::endl;

				// For player 1, set new position after roll
				p1.setPosition(moves);
				std::cout << "Player 1 now has position " << p1.getPosition()
					<< " for man #" << i << std::endl;

				// For player 2, roll the dice and return value of moves
				// LRC fix moves redefinition error
				moves = p2.playerRoll();
				//int moves = p2.playerRoll();
				std::cout << "Player 2 rolled: " << moves << std::endl;

				// For player 2, set new position after roll
				p2.setPosition(moves);
				std::cout << "Player 2 now has position " << p2.getPosition()
					<< " for man #" << i << std::endl;
			} 
			while ((p1.getPosition() < 22) || (p2.getPosition() < 22));
		}
	}
	while (d1.playAgain() != false);

	std::cout << "Exiting program." << std::endl;
	

	/*
	// Declare a class object
	TumblingDie d1;

	// Get number of sides for d1
	int sides = 6;
	// std::cout << "How many sides to the die? " << std::endl;
	// std::cin >> sides;
	d1.setSides(sides);
	// Play until user quits
	do {
		// Prompt for number of rolls
		int rolls = d1.getRolls();
		for (int i = 0; i < rolls; i++)
			d1.rollDie();
		
		// Report all rolls so far
		for (auto e : d1.getHistory())
		{
			std::cout << e << ' ';
		}
		std::cout << std::endl;
	} 
	while (d1.playAgain() == true);

	std::cout << "Exiting program." << std::endl;
	*/

	system("pause");

	return 0;
}