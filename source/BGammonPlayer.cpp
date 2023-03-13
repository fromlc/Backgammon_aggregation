//------------------------------------------------------------------------------
// CS 281-0798
// 
// BGammonPlayer.cpp
//
// BGammonPlayer class definition file
//------------------------------------------------------------------------------
#include "BGammonPlayer.h"

#include <algorithm>      // std::fill() array init
#include <iostream>
#include <string>

#include "ansi_colors.h"

//------------------------------------------------------------------------------
// default constructor
//------------------------------------------------------------------------------
BGammonPlayer::BGammonPlayer() : BGammonPlayer("BGplayer", "clear", RESET) {}

//------------------------------------------------------------------------------
// overload constructor
//------------------------------------------------------------------------------
BGammonPlayer::BGammonPlayer(const std::string name, const std::string color,
                                const std::string colorEscSeq)
{
    this->name  = name;
    this->color = color;
    this->colorEscSeq = colorEscSeq;

    // assume pieces move from low to high point numbers
    this->lowToHigh = true;

    // set pieces per player constant in BGammonPlayer.h
    this->pieceCount = PIECES_PLAYING;
    this->numRolls = 0;                 // per roll of 2 dice
    this->gamesWon = 0;

    this->pOpponent = nullptr;          // app code must set this

    // initialize array
    std::fill(aPiecePositions, aPiecePositions + PIECES_PLAYING, START_POINT);
}

//------------------------------------------------------------------------------
// destructor
//------------------------------------------------------------------------------
//BGammonPlayer::~BGammonPlayer() {}

//------------------------------------------------------------------------------
// getName()
//------------------------------------------------------------------------------
std::string BGammonPlayer::getName() const { return this->name; }

//------------------------------------------------------------------------------
// getColor()
//------------------------------------------------------------------------------
std::string BGammonPlayer::getColor() const { return this->color; }

//------------------------------------------------------------------------------
// getNumRolls()
//------------------------------------------------------------------------------
int BGammonPlayer::getNumRolls() const { return this->numRolls; }

//------------------------------------------------------------------------------
// getGamesWon()
//------------------------------------------------------------------------------
int BGammonPlayer::getGamesWon() const { return this->gamesWon; }

//------------------------------------------------------------------------------
// getPiecePositions() : return copy of piece positions as array
//      - requires caller memory: int aPos[PIECES_PLAYING]
//      - this fill-in function sets caller's array values
//------------------------------------------------------------------------------
void BGammonPlayer::getPiecePositions(int aPos[]) const
{
    for (int x = 0; x < PIECES_PLAYING; x++)
    {
        aPos[x] = this->aPiecePositions[x];
    }
}

//------------------------------------------------------------------------------
// pieceCount(): returns # of pieces
// no params: returns # of pieces on board, including on the bar
// int param: returns # of pieces on specified point (1-20)
//------------------------------------------------------------------------------
int BGammonPlayer::getPieceCount(int point)
{
    // no argument passed
    if (point == 0)
        return this->pieceCount; 

    int count = 0;

    // check arg-specified point number for pieces
    for (int i = 0; i < PIECES_PLAYING; i++)
    {
        if (aPiecePositions[i] == point)
            count++;
    }

    return count;

}

//------------------------------------------------------------------------------
// resetPlayer() : resets piece positions to point START_POINT or END_POINT
//------------------------------------------------------------------------------
void BGammonPlayer::resetPlayer(int startingPoint)
{
    std::fill(aPiecePositions, aPiecePositions + PIECES_PLAYING, startingPoint);

    this->pieceCount = PIECES_PLAYING;
    this->numRolls = 0;
}

//------------------------------------------------------------------------------
// rollDice() : get a new 2-dice roll for player
//------------------------------------------------------------------------------
int BGammonPlayer::rollDice(int& d1, int& d2) 
{
    d1 = this->die1.rollDie();
    d2 = this->die2.rollDie();
    numRolls++;

    return d1 + d2;
}

//------------------------------------------------------------------------------
// viewDice() : look at player's last 2-dice roll
//------------------------------------------------------------------------------
void BGammonPlayer::viewDice(int& d1, int& d2)
{
    d1 = this->die1.getValue();
    d2 = this->die2.getValue();
}

//------------------------------------------------------------------------------
// makeBestMove() : returns number of attempted move conflicts
//      - chooses piece farthest along board
//      = cannot move to point occupied by opponent's pieces
//------------------------------------------------------------------------------
int BGammonPlayer::makeBestMove(int movePoints)
{
    if (this->lowToHigh)
        return moveLowToHigh(movePoints);

    return moveHighToLow(-movePoints);
}

//------------------------------------------------------------------------------
// moveLowToHigh() : returns number of attempted move conflicts
//      - chooses piece farthest along board (highest point number)
//      = cannot move to point occupied by opponent's pieces
//------------------------------------------------------------------------------
int BGammonPlayer::moveLowToHigh(int movePoints)
{
    // pieces start at START_POINT
    int farthest = 0, index = 0, conflicts = 0;
 
    // get farthest position and 
    // fill-in conflict count and position array index for piece
    for (int i = 0; i < PIECES_PLAYING; i++)
    {
        int pos = this->aPiecePositions[i];
        // cannot move to point occupied by opponent's piece(s)
        if (pos > farthest)
        {
            int opCount = this->pOpponent->getPieceCount(pos + movePoints);
            if (!opCount)
            {
                farthest = pos;
                index = i;
            }
            else
            {
                conflicts++;
            }
        }
    }

    // check for no pieces to move, or no legal moves
    if (farthest)
    {
        // move the farthest piece along the board
        this->aPiecePositions[index] += movePoints;
    
        // check for piece borne off
        if (this->aPiecePositions[index] > END_POINT)
        {
            this->aPiecePositions[index] = 0;
            this->pieceCount--;
    
            if (!this->pieceCount)
                this->gamesWon++;
        }
    }

    return conflicts;
}

//------------------------------------------------------------------------------
// moveHighToLow() : returns number of attempted move conflicts
//      - chooses piece farthest along board (lowest point number)
//      = cannot move to point occupied by opponent's pieces
//------------------------------------------------------------------------------
int BGammonPlayer::moveHighToLow(int movePoints)
{
    // pieces start at END_POINT
    int nearest = END_POINT + 1, index = 0, conflicts = 0;

    // get farthest position and 
    // fill-in conflict count and position array index for piece
    for (int i = 0; i < PIECES_PLAYING; i++)
    {
        int pos = this->aPiecePositions[i];
        // cannot move to point occupied by opponent's piece(s)
        if (pos && pos < nearest)
        {
            int candidatePoint = pos + movePoints;
            int opCount = (candidatePoint >= START_POINT) ? 
                this->pOpponent->getPieceCount(candidatePoint) : 0;

            if (!opCount)
            {
                nearest = pos;
                index = i;
            }
            else
            {
                conflicts++;
            }
        }
    }

    // check for no pieces to move, or no legal moves
    if (nearest && nearest <= END_POINT)
    {
        // move the farthest piece along the board
        this->aPiecePositions[index] += movePoints;

        // check for piece borne off
        if (this->aPiecePositions[index] < START_POINT)
        {
            this->aPiecePositions[index] = 0;
            this->pieceCount--;

            if (!this->pieceCount)
                this->gamesWon++;
        }
    }

    return conflicts;
}

//------------------------------------------------------------------------------
// setOpponent() : set pointer to opponent class instance
//      - access opponent piece positions etc.
//------------------------------------------------------------------------------
void BGammonPlayer::setOpponent(BGammonPlayer* pOpp) { this->pOpponent = pOpp; }

//------------------------------------------------------------------------------
// getOpponent() : return pointer to opponent class instance
//      - access opponent piece positions etc.
//------------------------------------------------------------------------------
BGammonPlayer* BGammonPlayer::getOpponent() const { return this->pOpponent; }


