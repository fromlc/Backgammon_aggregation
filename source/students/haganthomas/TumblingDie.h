//Include guard
#pragma once

//#includes
#include<vector>

//Class
class TumblingDie
{

	//Class variables
private:
	unsigned char diceSides;

	//Class vector
private:
	std::vector<unsigned char> diceRolls;

public:

	//Default constructor
	TumblingDie();

	//Overload constructor
	TumblingDie(unsigned char diceSides);

	//Destructor
	~TumblingDie();

	//Setters
	void setDiceSides(unsigned char diceSides);

	//Getters
	unsigned char getDiceSides() const;
	std::vector<unsigned char> getDiceRolls() const;

	//Class behavior functions
	void rollDice();
	void clearDiceRolls();


};
