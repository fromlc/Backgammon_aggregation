/*****************************************************************************************************************************
* Automated Backgammon App
* Thomas Hagan
* CS 281-0798, Fall 2021
* November 19, 2021
* 
* This program plays an automated game of Backgammon. It has two players and automatically takes turns rolling 2 dice each time and moves player
* peices. Everytime a play gets a peice to space 21 it awards 1 point, once a player reaches 3 points the game ends and outputs to the user which
* player won. It reprompts the user to start another game until the user quits.
* 
********************************************************************************************************************************/

//Includes
#include <iostream>
#include <ctime>
#include "TumblingDie.h"
#include "BackgammonPlayer.h"

//Prototype functons
void pOneMoveManOne(Player& playerOne, Player& playerTwo, int resultone);
void pOneMoveManTwo(Player& playerOne, Player& playerTwo, int resultone);
void pOneMoveManThree(Player& playerOne, Player& playerTwo, int resultone);
void pTwoMoveManOne(Player& playerOne, Player& playerTwo, int resulttwo);
void pTwoMoveManTwo(Player& playerOne, Player& playerTwo, int resulttwo);
void pTwoMoveManThree(Player& playerOne, Player& playerTwo, int resulttwo);

//Entry point
int main()
{
	//Seeds srand
	srand((unsigned)time(0));

	//Variables to hold dice roll data
	int resultone = 0;
	int resulttwo = 0;

	//Quit program variable
	bool quit = false;

	//Variable to hold user input
	std::string input;

	//Loops untill user quits
	while (quit != true) {
		//Creates 2 instances of Player class
		Player playerOne;
		Player playerTwo;
		
		//Displays game information output
		std::cout << "Automated Backgammon Game!" << std::endl;
		std::cout << "Press s to Start playing or q to QUIT" << std::endl;
		std::cin >> input;

		//Sets user input to lower case
		for (int i = 0; i < input.length(); i++)
		{
			input[i] = tolower(input[i]);
		}

		//Quits if user enters q
		if (input == "q")
		{
			quit = true;
			continue;
		}
		//Outputs error and prompts user to enter new input when input data is invalid
		else if (input != "s")
		{
			std::cout << "Invalid input!" << std::endl;
			continue;
		}
		//Loop to play the game until one player has 3 points
		while (playerOne.getPlayerScore() != 3 && playerTwo.getPlayerScore() != 3)
		{
			//Sets resultone to outcome of both dice rolls
			int resultone = 0;
			resultone = playerOne.rollTwoDice(resultone);

			//Calls move man functions
			pOneMoveManOne(playerOne, playerTwo, resultone);
			pOneMoveManTwo(playerOne, playerTwo, resultone);
			pOneMoveManThree(playerOne, playerTwo, resultone);

			resultone = 0;

			//Checks if player has reached space 21 and awards one point if the player has
			if (playerOne.getManOnePos() >= 21 || playerOne.getManTwoPos() >= 21 || playerOne.getManThreePos() >= 21)
			{
				std::cout << "Player one moved a man 21 spaces, 1 point scored!" << std::endl;
				system("pause");
				playerOne.givePlayerPoints();
				resultone = 0;

				//Exits loop if player has reached 3 points
				if (playerOne.getPlayerScore() == 3)
				{
					continue;
				}
			}
			
			//Calls function to remove man
			playerOne.removeMan();

			//Sets resulttwo to outcome of both dice rolls
			resulttwo = playerTwo.rollTwoDice(resulttwo);

			//Calls move man functions
			pTwoMoveManOne(playerOne, playerTwo, resulttwo);
			pTwoMoveManTwo(playerOne, playerTwo, resulttwo);
			pTwoMoveManThree(playerOne, playerTwo, resulttwo);
			
	
			resulttwo = 0;

			//Checks if player has reached position 21 and awards one point if the player has
			if (playerTwo.getManOnePos() >= 21 || playerTwo.getManTwoPos() >= 21 || playerTwo.getManThreePos() >= 21)
			{
				std::cout << "Player two moved a man 21 spaces, 1 point scored!" << std::endl;
				system("pause");
				playerTwo.givePlayerPoints();
				resulttwo = 0;

				//Exits loop if player has 3 points
				if (playerTwo.getPlayerScore() == 3)
				{
					continue;
				}
			}

			//Calls function to remove man
			playerTwo.removeMan();

		}

		//If player one has 3 points displays player one winner output
		if (playerOne.getPlayerScore() == 3)
		{
			std::cout << "***************" << std::endl;
			std::cout << "Player one wins" << std::endl;
			std::cout << "***************" << std::endl;
		}

		//If player two has 3 points displays player two winner output
		else if (playerTwo.getPlayerScore() == 3)
		{
			std::cout << "***************" << std::endl;
			std::cout << "Player two wins" << std::endl;
			std::cout << "***************" << std::endl;
		}
	}

	//Output for when user quits game
	std::cout << "Thanks for Playing! Goodbye!";
}
	


void pOneMoveManOne(Player& playerOne, Player& playerTwo, int resultone)
{
	

	//Checks if man position is equal to zero (removed from the game)
	if (playerOne.getManOnePos() != 0) {

		//Checks if man position is occupied by other player
		if (playerOne.getManOnePos() + resultone != playerTwo.getManOnePos() && playerOne.getManOnePos() + resultone != playerTwo.getManTwoPos() && playerOne.getManOnePos() + resultone != playerTwo.getManThreePos())
		{

			//Checks if man position is higher than both of the players other men
			if (playerOne.getManOnePos() >= playerOne.getManTwoPos() && playerOne.getManOnePos() >= playerOne.getManThreePos())
			{
				std::cout << "Player one moved man one: " << resultone << " spaces!" << std::endl;
				system("pause");
				playerOne.moveManOne(resultone);
			}
		}
		else
		{
			std::cout << "Move space for man one occupied by player two, moving another man!" << std::endl;
		}
	}
}

void pOneMoveManTwo(Player& playerOne, Player& playerTwo, int resultone)
{
	//Checks if man position is equal to zero (removed from the game)
	if (playerOne.getManTwoPos() != 0) {

		//Checks if man position is occupied by other player
		if (playerOne.getManTwoPos() + resultone != playerTwo.getManOnePos() && playerOne.getManTwoPos() + resultone != playerTwo.getManTwoPos() && playerOne.getManTwoPos() + resultone != playerTwo.getManThreePos())
		{

			//Checks if man position is higher than both of the players other men
			if (playerOne.getManTwoPos() >= playerOne.getManOnePos() && playerOne.getManTwoPos() >= playerOne.getManThreePos())
			{
				std::cout << "Player one moved man two: " << resultone << " spaces!" << std::endl;
				system("pause");
				playerOne.moveManTwo(resultone);
			}
		}
		else
		{
			std::cout << "Move space for man two occupied by player two, moving another man!" << std::endl;
		}
	}
}

void pOneMoveManThree(Player& playerOne, Player& playerTwo, int resultone)
{

	//Checks if man position is equal to zero (removed from the game)
	if (playerOne.getManThreePos() != 0) {

		//Checks if man position is occupied by other player
		if (playerOne.getManThreePos() + resultone != playerTwo.getManOnePos() && playerOne.getManThreePos() + resultone != playerTwo.getManTwoPos() && playerOne.getManThreePos() + resultone != playerTwo.getManThreePos())
		{

			//Checks if man position is higher than both of the players other men
			if (playerOne.getManThreePos() >= playerOne.getManOnePos() && playerOne.getManThreePos() >= playerOne.getManTwoPos())
			{
				std::cout << "Player one moved man three: " << resultone << " spaces!" << std::endl;
				system("pause");
				playerOne.moveManThree(resultone);
			}
		}
		else
		{
			std::cout << "Move space for man three occupied by player two, no moves available! Turn lost!" << std::endl;
		}
	}
}

void pTwoMoveManOne(Player& playerOne, Player& playerTwo, int resulttwo)
{
	//Checks if man position is equal to zero (removed from the game)
	if (playerTwo.getManOnePos() != 0) {

		//Checks if man position is occupied by other player
		if (playerTwo.getManOnePos() + resulttwo != playerOne.getManOnePos() && playerTwo.getManOnePos() + resulttwo != playerOne.getManTwoPos() && playerTwo.getManOnePos() + resulttwo != playerOne.getManThreePos())
		{

			//Checks if man position is higher than both of the players other men
			if (playerTwo.getManOnePos() >= playerTwo.getManTwoPos() && playerTwo.getManOnePos() >= playerTwo.getManThreePos())
			{
				std::wcout << "Player two moved man one: " << resulttwo << " spaces!" << std::endl;
				system("pause");
				playerTwo.moveManOne(resulttwo);
			}
		}
		else
		{
			std::cout << "Move space for man one occupied by player one, moving another man!" << std::endl;
		}
	}
}

void pTwoMoveManTwo(Player& playerOne, Player& playerTwo, int resulttwo)
{
	//Checks if man position is equal to zero (removed from the game)
	if (playerTwo.getManTwoPos() != 0)
	{

		//Checks if man position is occupied by other player
		if (playerTwo.getManTwoPos() + resulttwo != playerOne.getManOnePos() && playerTwo.getManTwoPos() + resulttwo != playerOne.getManTwoPos() && playerTwo.getManTwoPos() + resulttwo != playerOne.getManThreePos())
		{

			//Checks if man position is higher than both of the players other men
			if (playerTwo.getManTwoPos() >= playerTwo.getManOnePos() && playerTwo.getManTwoPos() >= playerTwo.getManThreePos())
			{
				std::cout << "Player two moved man two: " << resulttwo << " spaces!" << std::endl;
				system("pause");
				playerTwo.moveManTwo(resulttwo);
			}
		}
		else
		{
			std::cout << "Move space for man two occupied by player one, moving another man!" << std::endl;
		}
	}
}

void pTwoMoveManThree(Player& playerOne, Player& playerTwo, int resulttwo)
	{
	//Checks if man position is equal to zero (removed from the game)
	if (playerTwo.getManThreePos() != 0)
	{

		//Checks if man position is occupied by other player
		if (playerTwo.getManThreePos() + resulttwo != playerOne.getManOnePos() && playerTwo.getManThreePos() + resulttwo != playerOne.getManTwoPos() && playerTwo.getManThreePos() + resulttwo != playerOne.getManThreePos())
		{

			//Checks if man position is higher than both of the players other men
			if (playerTwo.getManThreePos() >= playerTwo.getManOnePos() && playerTwo.getManThreePos() >= playerTwo.getManTwoPos())
			{
				std::cout << "Player two moved man three: " << resulttwo << " spaces!" << std::endl;
				system("pause");
				playerTwo.moveManThree(resulttwo);
			}
		}
		else
		{
			std::cout << "Move space for man three occupied by player one, no moves available! Turn lost!" << std::endl;
		}
	}
	}




