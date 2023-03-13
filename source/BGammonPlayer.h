//------------------------------------------------------------------------------
// CS 281-0798
// 
// BGammonPlayer class declaration file
//------------------------------------------------------------------------------
#pragma once
#ifndef BGAMMONPLAYER_H
#define BGAMMONPLAYER_H

#include <string>

#include "TumblingDie.h"

// number of pieces per player
//constexpr int PIECES_PLAYING = 15;
//constexpr int PIECES_PLAYING = 10;
constexpr int PIECES_PLAYING = 5;
//constexpr int PIECES_PLAYING = 3;

// initial piece position is the 1-point
constexpr int START_POINT = 1;
// playing board has 20 points
constexpr int END_POINT   = 20;

//------------------------------------------------------------------------------
// class BGammonPlayer : need two instances
//------------------------------------------------------------------------------
class BGammonPlayer
{
private:
    std::string name, color;

    // 2 dice per roll, pieces remaning, number of games player won
    int numRolls, pieceCount, gamesWon;

    // track point position for each piece
    int aPiecePositions[PIECES_PLAYING];

    // pair of dice
    TumblingDie die1, die2;

    // app code must set player pointer to opponent
    BGammonPlayer* pOpponent;

public:
    // true when moving from low to high numbered points
    bool lowToHigh;

    // ANSI escape sequence for player color
    std::string colorEscSeq;

public:
// constructors
    BGammonPlayer();
    BGammonPlayer(const std::string name, const std::string color,
                    const std::string colorEscSeq);
// destructor
    //~BGammonPlayer();
 
// player data 
    std::string getName() const;
    std::string getColor() const;
    int getNumRolls() const;
    int getGamesWon() const;

// internal piece position representation hidden from app
    void getPiecePositions(int aPos[]) const;

// no params: returns # of pieces on board, including on the bar
// int param: returns # of pieces on specified point (1-20)
    int getPieceCount(int point = 0);

// sets piece positions to 1 and resets piece count and move counter
    void resetPlayer(int startingPoint);

// get a new roll of 2 dice
    int rollDice(int& d1, int& d2);

// look at old dice roll
    void viewDice(int& d1, int& d2);

// #TODO moves the piece farthest along the board
// returns number of attempted move failures (conflicts)
    int makeBestMove(int movePoints);

// access opponent piece positions etc.
    void setOpponent(BGammonPlayer*);
    BGammonPlayer* getOpponent() const;

private:
    int moveLowToHigh(int movePoints);
    int moveHighToLow(int movePoints);

};

#endif  // BGAMMONPLAYER_H