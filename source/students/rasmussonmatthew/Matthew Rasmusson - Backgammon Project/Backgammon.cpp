/*******************************************************************************
* Backgammon.cpp
* Matthew Rasmusson
* CS 281-0798, Fall 2021
* November 15, 2021
*
* Write a console app that simulates a game of Backgammon using class inheritance
*********************************************************************************/

#include <iostream>
#include <cstdlib> //used for rand()
#include <ctime> //used for time()
#include <string>
#include <iomanip>
#include <vector>
#include "TumblingDie.h"
#include "BackgammonPlayer.h"

//function prototypes
void welcomeMessage();
void playGame();
void playRound(BackgammonPlayer& player1, BackgammonPlayer& player2, int turn);
void updatePositions(BackgammonPlayer& passedPlayer);
void player1Turn(BackgammonPlayer& player1, BackgammonPlayer& player2);
void player2Turn(BackgammonPlayer& player1, BackgammonPlayer& player2);
void checkWin(BackgammonPlayer& player1, BackgammonPlayer& player2);
void playAgain();
void quitGame();

/*******************************************************************************
* int main()
*
* Intro to function
*********************************************************************************/
int main()
{
	srand(time(nullptr)); //'seeds' the random function.
	welcomeMessage();
	playGame();
	quitGame();
	system("pause");

	return 0;
}

// Local functions go after main()

/**********************************************************************
Function name:	WelcomeMessage()

Purpose: 		Displays the message to welcome user as well as indicate 
				the start of a new game

Inputs: 		none

Returns: 		void

Revision history
Date		By			Description
------------------------------------------------------------------------
************************************************************************/
void welcomeMessage()
{
    std::cout << "\nWelcome to Backgammon!\n";
    std::cout << "______________________________________________\n\n";
}

/**********************************************************************
Function name:	playGame()

Purpose: 		plays simulated backgammon until user quits

Inputs: 		none

Returns: 		void

Revision history
Date		By			Description
------------------------------------------------------------------------
************************************************************************/
void playGame()
{
	//Do-while loop to play game until user enters 'q' (to upper/lower for input recognition)
	char selection;
	int turn = 1;
	BackgammonPlayer player1, player2;
	do
	{
		std::cout << "(P)lay or (Q)uit: ";
		std::cin >> selection;
		switch (toupper(selection))
		{
		case 'P':
			//play code
			playRound(player1, player2, turn);
			break;
		case 'Q':
			quitGame();
			break;
		default:
			std::cout << "Invalid selection! Please try again!\n";
			break;
		}
		turn++;
	} while (selection != 'Q' && selection != 'q');
}

/**********************************************************************
Function name:	playRound()

Purpose: 		Goes through one turn of the backgammon game, returning 
				to the switch statement in playGame() after each turn.

Inputs: 		two BackgammonPlayer objects(ref) player1 and player2,
				int turn

Returns: 		void

Revision history
Date		By			Description
------------------------------------------------------------------------
************************************************************************/
void playRound(BackgammonPlayer& player1, BackgammonPlayer& player2, int turn)
{
	std::cout << "\nTurn " << turn <<":";
	std::cout << "\n______________________________________________\n";
	player1Turn(player1, player2);
	player2Turn(player1, player2);
}

/**********************************************************************
Function name:	player1Turn()

Purpose: 		Contains all the logic for moving player1's best 'man'
				relative to the piece positions of player2.

Inputs: 		two BackgammonPlayer objects(ref) player1 and player2

Returns: 		void

Revision history
Date		By			Description
------------------------------------------------------------------------
************************************************************************/
void player1Turn(BackgammonPlayer& player1, BackgammonPlayer& player2)
{
	/*
	Essentially, this nested if statement checks if the bestPosition (which
	is a private member variable of BackgammonPlayer) added to the dice roll matches 
	a position of the other player's men.
	*/
	std::cout << "Player 1";
	int player1Roll = player1.rollDice();
	int move1 = player1.getBest() + player1Roll;
	if (player1.findPositionIn2(player2, move1))
	//findPositionIn#() uses the std::find() function 
	//to check the values in the other player's positionTracker vector.
	{
		int move2 = player1.getSecond() + player1Roll;
		if (player1.findPositionIn2(player2, move2) || player1.getSecond() == 0) //the '0' here is an indicator of a 'beared off' piece
		//The logic goes: if the dice roll + your best positioned man = a value in the 
		//other player's positionTracker, try adding the value to your second best position...
		{
			int move3 = player1.getThird() + player1Roll;
			if (player1.findPositionIn2(player2, move3) || player1.getThird() == 0)
			//and if your second postion fails, try the third position...
			{
				std::cout << "Player 1 is unable to move!\n";
				//And if the third position fails, you are unable to move.
				std::cout << "Player 1 has men at positions: ";
				player1.readPositions();
				std::cout << "\n\n";
			}
			else
			{
				player1.setPosition(player1.getIndex(player1.getThird()), player1Roll);
				std::cout << "Player 1 has men at positions: ";
				player1.readPositions();
				std::cout << "\n\n";
			}
		}
		else
		{
			player1.setPosition(player1.getIndex(player1.getSecond()), player1Roll);
			std::cout << "Player 1 has men at positions: ";
			player1.readPositions(); 
			std::cout << "\n\n";
		}
	}
	else
	{
		player1.setPosition(player1.getIndex(player1.getBest()), player1Roll);
		std::cout << "Player 1 has men at positions: ";
		player1.readPositions();
		std::cout << "\n\n";
	}
	//After the player's move, check to see if any pieces can be 'beared off'
	player1.bearOff();

	//update the values of the best, second best, and third best pieces.
	updatePositions(player1);

	//Finally, check to see if the player has won.
	checkWin(player1, player2);
}

/**********************************************************************
Function name:	player2Turn()

Purpose: 		Contains all the logic for moving player2's best 'man' 
				relative to the piece positions of player1.

Inputs: 		two BackgammonPlayer objects(ref) player1 and player2

Returns: 		void

Revision history
Date		By			Description
------------------------------------------------------------------------
************************************************************************/
void player2Turn(BackgammonPlayer& player1, BackgammonPlayer& player2)
{
	//see explanations above ^^(starting at line 147)
	std::cout << "Player 2";
	int player2Roll = player2.rollDice();
	int move1 = player2.getBest() + player2Roll;
	if (player2.findPositionIn1(player1, move1))
	{
		int move2 = player2.getSecond() + player2Roll;
		if (player2.findPositionIn1(player1, move2) || player2.getSecond() == 0)
		{
			int move3 = player2.getThird() + player2Roll;
			if (player2.findPositionIn1(player1, move3) || player2.getThird() == 0)
			{
				std::cout << "Player 2 is unable to move!\n";
				std::cout << "Player 2 has men at positions: ";
				player2.readPositions();
				std::cout << "\n\n";
			}
			else
			{
				player2.setPosition(player2.getIndex(player2.getThird()), player2Roll);
				std::cout << "Player 2 has men at positions: ";
				player2.readPositions();
				std::cout << "\n\n";
			}
		}
		else
		{
			player2.setPosition(player2.getIndex(player2.getSecond()), player2Roll);
			std::cout << "Player 2 has men at positions: ";
			player2.readPositions();
			std::cout << "\n\n";
		}
	}
	else
	{
		player2.setPosition(player2.getIndex(player2.getBest()), player2Roll);
		std::cout << "Player 2 has men at positions: ";
		player2.readPositions();
		std::cout << "\n\n";
			
	}
	player2.bearOff();
	updatePositions(player2);
	checkWin(player1, player2);
}

/**********************************************************************
Function name:	updatePositions()

Purpose: 		utilizes setter methods in BackgammonPlayer class to
				update the values for best, second, and third best piece

Inputs: 		one BackgammonPlayer object(ref) passedPlayer

Returns: 		void

Revision history
Date		By			Description
------------------------------------------------------------------------
************************************************************************/
void updatePositions(BackgammonPlayer& passedPlayer)
{
	passedPlayer.setBest();
	passedPlayer.setSecond();
	passedPlayer.setThird();
}

/**********************************************************************
Function name:	checkWin()

Purpose: 		utilizes the checkVectors method in BackgammonPlayer to
				check if a player has won the game

Inputs: 		two BackgammonPlayer objects(ref) player1 and player2

Returns: 		void

Revision history
Date		By			Description
------------------------------------------------------------------------
************************************************************************/
void checkWin(BackgammonPlayer& player1, BackgammonPlayer& player2)
{
	if (player1.checkVectors())
	{
		std::cout << "Player 1 WINS!\n\n";
		playAgain();
	}
	if (player2.checkVectors())
	{
		std::cout << "Player 2 WINS!\n\n";
		playAgain();
	}
}

/**********************************************************************
Function name:	playAgain()

Purpose: 		prompts the user to play again (Y/N), calls quitGame()
				on 'n' entry, returns to main() on 'y' entry - restarting
				the game.

Inputs: 		none

Returns: 		void

Revision history
Date		By			Description
------------------------------------------------------------------------
************************************************************************/
void playAgain()
{
	char choice;
	std::cout << "Play again? (Y/N): ";
	std::cin >> choice;
	switch (toupper(choice))
	{
	case 'Y':
		main();
		break;
	case 'N':
		quitGame();
		break;
	default:
		std::cout << "Invalid selection! Please try again!\n";
		break;
	}
}


/**********************************************************************
Function name:	quitGame()

Purpose: 		exits the application

Inputs: 		none

Returns: 		void

Revision history
Date		By			Description
------------------------------------------------------------------------
************************************************************************/
void quitGame()
{
	std::cout << "Thanks for playing!\n\n";
	exit(0);
}