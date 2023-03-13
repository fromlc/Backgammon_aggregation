//Include Guard
#pragma once

//Includes
#include "TumblingDie.h"

//Creates class Player
class Player {

//Private Data
private:
	int playerscore;
	int manonepos;
	int mantwopos;
	int manthreepos;

//Public data
public:
	TumblingDie dieOne;
	TumblingDie dieTwo;

public:
	//Overload constructor
	Player(int playerscore, int manonepos, int mantwopos, int manthreepos);

	//Default constructor
	Player();

	//Setters
	void setPlayerScore(int playerscore);
	void setManOnePos(int manonepos);
	void setManTwoPos(int mantwopos);
	void setManThreePos(int manthreepos);

	//Getter
	int getPlayerScore() const;
	int getManOnePos() const;
	int getManTwoPos() const;
	int getManThreePos() const;

	//Class behavior functions
	int rollTwoDice(int result);

	void moveManOne(int one);
	void moveManTwo(int two);
	void moveManThree(int three);

	void givePlayerPoints();

	void removeMan();

};
