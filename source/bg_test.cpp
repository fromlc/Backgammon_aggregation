//------------------------------------------------------------------------------
// td_test.cpp
// CS 281-0798, Fall 2021
//
// Auto Backgammon app
//		- uses class definition BGammonPlayer.cpp
//		= set number of player pieces in BGammonPlayer.h
//------------------------------------------------------------------------------

#include <algorithm>	// std::fill() array init
#include <iostream>
#include <string>
#include <iomanip>

#include "BGammonPlayer.h"
#include "ansi_colors.h"

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int POSITION_FIELDWIDTH = 3;		// for piece position display
constexpr char PIECE_BORNE_OFF    = '.';	// for piece position display
constexpr char CONFLICT_FLAG      = 'c';	// for piece position display

//------------------------------------------------------------------------------
// struct BGammonBoard : aggregates two BGammonPlayer instances
//------------------------------------------------------------------------------
struct BGammonBoard
{
	// 2 players with their previous and current piece positions
	BGammonPlayer player1 = BGammonPlayer("Blue", "Blue", FG_CYAN);
	int aPositions1[PIECES_PLAYING] = { START_POINT };
	
	// players move in opposite directions on board
	BGammonPlayer player2 = BGammonPlayer("Orange", "Orange", FG_YELLOW);
	int aPositions2[PIECES_PLAYING] = { END_POINT };

	// start with first game
	int gameNum   = 1;
	// even playerNum => player1, odd playerNum => player2
	int playerNum = 0;

	std::string banner = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
};

//------------------------------------------------------------------------------
// global variables
//------------------------------------------------------------------------------

// board with 2 players
BGammonBoard g_bb;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

inline void showBanner();
inline void initBoard();
inline bool winningMove();
bool move(BGammonPlayer& player);
void showMove(BGammonPlayer& player, int rollValue, bool conflicts);
void showPiecePositions(BGammonPlayer& player);
inline void showPos(int* pPos);
bool allPiecesBorneOff(BGammonPlayer& player);
bool playAgain();

//------------------------------------------------------------------------------
// main() : entry point
//------------------------------------------------------------------------------
int main()
{
	// display app info and game rules
	showBanner();

	// one board per do
	do
	{
		// prepare board and players
		initBoard();

		// function returns true on player win
		do { } while (!winningMove());

	} while (playAgain());

	system("pause");

	return 0;
}

//------------------------------------------------------------------------------
// showBanner()
//------------------------------------------------------------------------------
inline void showBanner()
{
	std::string color1 = g_bb.player1.getColor();
	std::string color2 = g_bb.player2.getColor();

	std::cout << g_bb.banner << '\n';
	std::cout << "\t" << "Auto " << g_bb.player1.colorEscSeq << color1 
		<< RESET << " & " << g_bb.player2.colorEscSeq << color2 
		<< RESET << " Simple Backgammon Variant\n\n";
	std::cout << "\t" << PIECES_PLAYING << " pieces per player, "
		<< g_bb.player1.colorEscSeq << color1
		<< RESET << " moves first.\n\n";
	std::cout << "\t" << g_bb.player1.colorEscSeq << color1
		<< RESET << " pieces start on the " << START_POINT << "-point\n";
    std::cout << "\t" << "and bear off from the " << END_POINT
		<< "-point.\n\n";
	std::cout << "\t" << g_bb.player2.colorEscSeq << color2
		<< RESET << " pieces start on the " << END_POINT << "-point\n";
	std::cout << "\t" << "and bear off from the " << START_POINT
		<< "-point.\n\n";
	std::cout << "\t" << "Pieces cannot land on points occupied\n";
	std::cout << "\t" << "by any opponent pieces.\n\n";
	std::cout << "\t" << "A '" << FG_RED << CONFLICT_FLAG 
		<< RESET << "' means a move conflict occurred.\n\n";
    std::cout << "\t" << "The piece farthest along the board is moved.\n\n";
    std::cout << "\t" << "Each '" << PIECE_BORNE_OFF 
		<< "' is a piece borne off the board.\n";
	std::cout << "\t" << "First player to bear off all pieces wins!\n\n";
	std::cout << g_bb.banner << "\n\n";
}

//------------------------------------------------------------------------------
// initBoard()
//------------------------------------------------------------------------------
inline void initBoard()
{
	std::cout << "Board #" << g_bb.gameNum << '\n';

	// clear current game info
	g_bb.player1.resetPlayer(START_POINT);
	g_bb.player2.resetPlayer(END_POINT);

	// set both player opponent pointers for piece position access
	g_bb.player1.setOpponent(&g_bb.player2);
	g_bb.player2.setOpponent(&g_bb.player1);

	// player1 starts at lowest numbered point
	g_bb.player2.lowToHigh = true;

	// player2 starts at highest numbered point
	g_bb.player2.lowToHigh = false;

	// initialize previous/current piece position arrays
	std::fill(g_bb.aPositions1, g_bb.aPositions1 + PIECES_PLAYING, START_POINT);
	std::fill(g_bb.aPositions2, g_bb.aPositions2 + PIECES_PLAYING, END_POINT);

	// output uses 0 for player1, 1 for player2 to
	// select previous positions array for display
	g_bb.playerNum = 0;
}

//------------------------------------------------------------------------------
// winningMove() : returns true if a player won after moving, false otherwise
//------------------------------------------------------------------------------
inline bool winningMove()
{
	bool moveWon = move(g_bb.player1);

	if (!moveWon)
	{
		moveWon = move(g_bb.player2);
	}

	std::cout << '\n';
	return moveWon;
}

//------------------------------------------------------------------------------
// move() : returns true if player wins after moving, false otherwise
// 
// get 2 die values and move one piece for both
//------------------------------------------------------------------------------
bool move(BGammonPlayer& player)
{
	int die1, die2;

	// fill-in function sets 2 die values #TODO unused
	int rollValue = player.rollDice(die1, die2);

	// class code chooses best move per game rules
	int conflictCount = player.makeBestMove(rollValue);

	// display piece positions before and after move
	showMove(player, rollValue, conflictCount);

	// check for all pieces borne off
	return allPiecesBorneOff(player);
}

//------------------------------------------------------------------------------
// showMove()
// 
// show player name and dice values for roll
//------------------------------------------------------------------------------
void showMove(BGammonPlayer& player, int movePoints, bool conflicts)
{
	// static var retains value between calls to this function
	static int playerNum, gameNum;

	// in case previous game won by player 1 
	if (gameNum != g_bb.gameNum)
	{
		gameNum = g_bb.gameNum;
		playerNum = 0;
	}

	// assume player 1
	char moveDirection = '+';

	// display roll number only before player1 positions
	if (!(playerNum++ % 2))
	{
		std::cout << "  Roll " << player.getNumRolls() << '\n';
	}
	else
	{
		moveDirection = '-';
	}

	std::cout << player.colorEscSeq << '\t' << player.getName() << '\t';
		
	// indicate move conflict with ! char
	char conflictFlag = conflicts ? CONFLICT_FLAG : ' ';
	std::cout << std::setw(POSITION_FIELDWIDTH) << movePoints 
		<< moveDirection << ' ' << FG_RED << conflictFlag
		<< player.colorEscSeq << " :";
	
	showPiecePositions(player);

	std::cout << RESET;

}

//------------------------------------------------------------------------------
// showPiecePositions()
// 
// show player piece positions after move
//------------------------------------------------------------------------------
void showPiecePositions(BGammonPlayer& player)
{
	// determine which player and point to their previous positions
	int* pPos = g_bb.playerNum++ % 2 ? g_bb.aPositions2 : g_bb.aPositions1;

	// show this player's previous position
	showPos(pPos);
	std::cout << "  ->";

	// fill in copy of player's current piece positions
	player.getPiecePositions(pPos);

	// show this player's current position
	showPos(pPos);
	std::cout << '\n';
}

//------------------------------------------------------------------------------
// showPos() : utility function shows previous or current point positions
//------------------------------------------------------------------------------
inline void showPos(int* pPos)
{
	std::cout.right;

	for (int x = 0; x < PIECES_PLAYING; x++)
	{
		int pos = pPos[x];
		std::cout << std::setw(POSITION_FIELDWIDTH);

		if (pos == 0)
			std::cout << PIECE_BORNE_OFF;
		else
			std::cout << pos;
	}
}

//------------------------------------------------------------------------------
// allPiecesBorneOff() : returns true if player won
//------------------------------------------------------------------------------
bool allPiecesBorneOff(BGammonPlayer& player)
{
	// zero pieces left on board => player won
	if (!player.getPieceCount())
	{
		std::string name = player.getName();

		// display stats
		std::cout << '\n' << name << " wins in "
			<< player.getNumRolls() << " rolls!\n";
		std::cout << "\nBoards won: " << name << ' ' << player.getGamesWon()
			<< ", " << player.getOpponent()->getName() << ' ' 
			<< player.getOpponent()->getGamesWon()
			<< '\n';

		// increment game counter for correct display
		g_bb.gameNum++;

		return true;
	}

	return false;
}

//------------------------------------------------------------------------------
// playAgain()
//
// returns true if user wants to play again, false otherwise
//------------------------------------------------------------------------------
bool playAgain()
{
	char answer;
	//Get user input
	do
	{
		std::cout << "Play another board? (Y/N): ";
		std::cin >> answer;
	}
	while (!std::cin);

	std::cout << '\n';

	return toupper(answer) == 'Y' ? true : false;
}

