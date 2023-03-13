// Backgammon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>
#include<windows.h>


int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

 public class Game {
	Random generator;
	Board board;
	Stone.Color player;

	Dices dices;

	public Game() {
		generator = new Random();
		board = new Board();
		player = Stone.Color.NONE;
		dices = new Dices();
	}
 }

 int  rollDie()
 {
	srand(time(NULL));

	int number = 6;
	int result1 = 0;

	result1 = rand() % number + 1;

	switch (result1)
	{
	case 1:
		std::cout << "Karam you haz losted!" << std::endl;
		break;
	case 6:
		std::cout << "Karam you haz winned!" << std::endl;
		break;
	default:
		std::cout << "Karam what you doin?!" << std::endl;
		break;
	}

	int number = 6;
	int result2 = 0;

	result2 = rand() % number + 1;

	switch (result2)
	{
	case 1:
		std::cout << "Sam you haz losted!" << std::endl;
		break;
	case 6:
		std::cout << "Sam you haz winned!" << std::endl;
		break;
	default:
		std::cout << "Sam what you doin?!" << std::endl;
		break;
	}
	std::cout << "Result:" << result1 + result2 << std::endl;

	system("PAUSE");

	return 0;
 }
public void roll() {
	if (player == Stone.Color.NONE) {
		dices.rollDifferent();
	}
	else {
		dices.roll();
	}
	switch (player) {
	case WHITE:
		player = Stone.Color.BLACK;
		break;
	case BLACK:
		player = Stone.Color.WHITE;
		break;
	case NONE:
		if (dices.getDiceOne() > Tow()) {
			player = Stone.Color.WHITE;
		}
		else {
			player = Stone.Color.BLACK;

		}
		break;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
