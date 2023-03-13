//------------------------------------------------------------------------------
// CS 281-0798, Fall 2021
// Week 11	   
//------------------------------------------------------------------------------
// TumblingDie class declaration file
//------------------------------------------------------------------------------
#pragma once
#include <vector>
#include <string>
#include <iostream>

class TumblingDie
{
private:
	//private variables
	int sides = 12;
	int menu = 0;
	int randomRolls = 5;

public:

	//Function prototype
	void testDriver();

	//default constructor
	TumblingDie() { }

	//gives result of two six sided dice
	TumblingDie(int sides)
	{
		randomRolls = rand() % sides + 2; // result 2-12
		//std::cout << "Test p";
	}



	//hold die roll results
	//std::vector <int> diceRolls;

	////ask user for sides 
	//void getRolls() 
	//{
	//	std::cout << "How many sides does the die have (1-256):  ";
	//	std::cin >> sides;
	//	/*if (sides > 256)
	//	{
	//		std::cout << "There is to many sides, try a number lower than 257";
	//		sides = 0;
	//	}*/
	//}
	////roll a six sided die by default
	//TumblingDie() { 
	//	sides = 6;
	//	//diceRolls.push_back(sides);
	//	//std::cout << "test i";
	//}

};