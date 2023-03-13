//
// Created by nicholas on 11/8/21.
//

#include "TumblingDie.h"

TumblingDie::TumblingDie(int numSides) {
    distrib = std::uniform_int_distribution<>{1, numSides};
    numberOfSides = numSides;
}

TumblingDie::~TumblingDie() {
    rolls.clear();
    rolls.shrink_to_fit();
}

unsigned char TumblingDie::rollDie() {
    int roll = distrib(gen);
    currentRoll = roll;
    rolls.push_back(roll);
    return roll;
}







