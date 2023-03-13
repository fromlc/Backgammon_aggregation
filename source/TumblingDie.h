//------------------------------------------------------------------------------
// CS 281-0798
//
// TumblingDie class declaration file
//------------------------------------------------------------------------------
#ifndef TUMBLINGDIE_H
#define TUMBLINGDIE_H

#include <string>
#include <vector>

// default
constexpr int DIE_SIDES = 6;

class TumblingDie
{
private:
    int sides;
    int value;
    std::vector<int> vRolls;    // stores die roll values

public:
    TumblingDie();
    TumblingDie(int sides);
    ~TumblingDie();             // #TODO delete vector memory

    void setDieSides(int sides);
    int getDieSides() const;

    std::vector <int> getRollHistory() const;

    int rollDie();
    int getValue();
};

#endif  // TUMBLINGDIE_H