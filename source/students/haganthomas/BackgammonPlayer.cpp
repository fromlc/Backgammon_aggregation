//Includes
#include "BackgammonPlayer.h"
#include "TumblingDie.h"

//Default constructor
Player::Player() 
{ 
	playerscore = 0;
	manonepos = 1;
	mantwopos = 1;
	manthreepos = 1;
}

//Overload constructor
Player::Player(int playerscore, int manonepos, int mantwopos, int manthreepos)
{
	this->playerscore = playerscore;
	this->manonepos = manonepos;
	this->mantwopos = mantwopos;
	this->manthreepos = manthreepos;
}

//Setter functions
void Player::setPlayerScore(int playerscore)
{
	this->playerscore = playerscore;
}

void Player::setManOnePos(int manonepos)
{
	this->manonepos = manonepos;
}

void Player::setManTwoPos(int mantwopos)
{
	this->mantwopos = mantwopos;
}

void Player::setManThreePos(int manthreepos)
{
	this->manthreepos = manthreepos;
}

//Getter functions
int Player::getPlayerScore() const
{
	return playerscore;
}

int Player::getManOnePos() const
{
	return manonepos;
}

int Player::getManTwoPos() const
{
	return mantwopos;
}

int Player::getManThreePos() const
{
	return manthreepos;
}

//Class behavior functions
int Player::rollTwoDice(int result)
{
	//Creates two empty vectors
	std::vector<unsigned char> outcomeone;
	std::vector<unsigned char> outcometwo;

	//Calls roll dice function for each die
	this->dieOne.rollDice();
	this->dieTwo.rollDice();

	//Fills vectors with the diceRolls vector data
	outcomeone = dieOne.getDiceRolls();
	outcometwo = dieTwo.getDiceRolls();

	//Sets result to first element of each vector added together
	result = outcomeone[0] + outcometwo[0];

	//Clears outcomeone, outcometwo, and both diceRoll vectors
	outcomeone.clear();
	outcometwo.clear();
	dieOne.clearDiceRolls();
	dieTwo.clearDiceRolls();

	return result;
}



//Sets temp variable to current player score + 1 then sets new player score using temp
void Player::givePlayerPoints()
{
	int temp = this->getPlayerScore() + 1;
	this->setPlayerScore(temp);
}

//Sets temp variable to current man one position plus result of dice rolls and then sets new man one position using temp
void Player::moveManOne(int d)
{
	int temp = this->getManOnePos() + d;
	this->setManOnePos(temp);
}

//Sets temp variable to current man two position plus result of dice rolls and then sets new man two position using temp
void Player::moveManTwo(int e)
{
	int temp = this->getManTwoPos() + e;
	this->setManTwoPos(temp);
}

//Sets temp variable to current man three position plus result of dice rolls and then sets new man three position using temp
void Player::moveManThree(int f)
{
	int temp = this->getManThreePos() + f;
	this->setManThreePos(temp);
}

void Player::removeMan()
{
	//Sets a mans position to zero once it reaches 21 so its removed from the game
	if (this->getManOnePos() >= 21)
	{
		this->setManOnePos(0);
	}
	if (this->getManTwoPos() >= 21)
	{
		this->setManTwoPos(0);
	}
	if (this->getManThreePos() >= 21)
	{
		this->setManThreePos(0);
	}
}
