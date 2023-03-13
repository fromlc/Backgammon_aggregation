//------------------------------------------------------------------------------
// Matthew Rasmusson
// CS 281-0798
// November 8, 2021	   
//------------------------------------------------------------------------------
// TumblingDie class declaration file
//------------------------------------------------------------------------------
#ifndef TUMBLINGDIE_H
#define TUMBLINGDIE_H

#include <string>
#include <vector>

class TumblingDie
{
private:
    int DieSides; //initialized value upon class creation. Either 6 or passed value

public:
    TumblingDie(); //Default Constructor
    TumblingDie(int sides); //Overloaded Constructor
    int getRollValue();//Getter of rolls 
};

#endif