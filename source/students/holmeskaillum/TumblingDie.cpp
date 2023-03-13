/*******************************************************************************
* Tumbling Dice App
* Kaillum Holmes
* CS 281-0798, Fall 2021
* Novemember 11, 2021
*
* This app will roll two six sided dice
********************************************************************************
*/
#include "TumblingDie.h"
#include "BackgammonPlayer.h"
#include <iostream>

//global variable
int temp = 0;

//test driver
void TumblingDie::testDriver()
{
	TumblingDie call;

	//display a menu until the user enters 3
	while (call.menu != 2)
	{
		// prompt user
		std::cout
			<< "1) roll dice \n"
			<< "2) quit \n";

		std::cin >> call.menu;
		std::cout << "\n";

	if (call.menu == 1) // roll dice
		{
		TumblingDie die(12);
		std::cout << "The value of the dice roll is: " << call.randomRolls << '\n';

		// pass dice roll results to diceValue 
		temp = call.randomRolls;
		void getRolls();

		}
	}

}

//passes dice results to the BackgammonPlayer class 
void BackgammonPlayer::getRolls() 
{
	BackgammonPlayer roll;
	temp = roll.diceValue;
}


//display a menu until the user enters 3
	//while (call.menu != 4)
	//{
	//	// prompt user
	//	std::cout
	//		<< "1) roll dice \n"
	//		<< "2) quit \n";

	//	std::cin >> call.menu;
	//	std::cout << "\n";

//	if (call.menu == 1) // display number of rolls
	//	{
	//		call.getRolls();
	//		TumblingDie die();
	/*	}
	}*/

	//	if (call.menu == 1) // display number of sides
	//	{
	//		// output all side rolls
	//		for (int i = 0; i < call.diceRolls.size(); i++)
	//		{
	//			std::cout << "number of sides: " << call.diceRolls[i] << "\n";
	//		}
	//	}

	//	if (call.menu == 2) // display number of rolls
	//	{
	//		std::cout << "number of rolls: " << call.diceRolls.size() << "\n";
	//	}

	

