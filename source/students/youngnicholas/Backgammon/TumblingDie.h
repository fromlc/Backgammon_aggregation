//
// Created by nicholas on 11/8/21.
//

#pragma once
#include <vector>
#include <random>

class TumblingDie {
private:
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> distrib;
public:

    int numberOfSides;
    int currentRoll;
    std::vector<int> rolls;


    /**
     * explicit TumblingDie(unsigned char numSides)
     *
     * Constructor for Tumbling Die Class
    **/
    explicit TumblingDie(int numSides = 6);

    /**
     * ~TumblingDie()
     *
     * Destructor for the Tumbling Die Class
    **/
    ~TumblingDie();

    /**
     * unsigned char rollDie()
     *
     * Rolls the die returning a random number
    **/
    unsigned char rollDie();


};


