//------------------------------------------------------------------------------
// CS 281-0798
// 
// Piece class declaration/definition file
//------------------------------------------------------------------------------
#pragma once
#ifndef PIECE_H
#define PIECE_H

#include <string>

//------------------------------------------------------------------------------
// Piece : position and id for each piece in BGammonPlayer
//------------------------------------------------------------------------------
class Piece
{
public:
    std::string color;
    int onPoint;  // pieces occupy points 0-21: 0 is bar, >=21 is borne off
    int id;

    // default constructor
    Piece() : Piece("black") {}

    // overload constructor
    Piece(const std::string& color)
    {
        this->color   = color;
        this->onPoint = 1;
        this->id = -1;      // known initial value
    }

    // copy constructor
    Piece(const Piece& pieceOnRight)
    {
        this->color   = pieceOnRight.color;
        this->onPoint = pieceOnRight.onPoint;
        this->id = pieceOnRight.id;
    }

    // destructor
    //~Piece()

    // operator > overload compares onPoint values
    bool operator>(Piece& pieceOnRight)
    { return (this->onPoint > pieceOnRight.onPoint); }

};

#endif  // PIECE_H

