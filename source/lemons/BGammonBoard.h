//------------------------------------------------------------------------------
// CS 281-0798
// 
// BGammonBoard class declaration/definition file
//------------------------------------------------------------------------------
#pragma once
#ifndef BGAMMONBOARD_H
#define BGAMMONBOARD_H

#include "BGammonPlayer.h"

//constexpr int PIECES_PLAYING = 15;
constexpr int PIECES_PLAYING = 3;

struct Piece
{
    int onPoint;  // pieces occupy points 0-21: 0 is bar, 21 is borne off
    int id;
};

class BGammonPlayer;

class BGammonBoard
{
private:
    int nPieces;

public:
    BGammonPlayer playBlack = BGammonPlayer("Black", "black");
    BGammonPlayer playWhite = BGammonPlayer("White", "white");

    BGammonBoard() : BGammonBoard(PIECES_PLAYING) {}
    BGammonBoard(int n)
    {
        this->nPieces = (n <= PIECES_PLAYING && n > 0) ?
            n : PIECES_PLAYING;
    }

    void setPieceCount(int count) {}
    int getPieceCount() const { return nPieces; }
};

#endif  // BGAMMONBOARD_H
