//-----------------------------------------------------------
// colors.h
//
// ANSI escape codes for console text and background colors
//-----------------------------------------------------------

#pragma once

// 8: ANSI escape sequences for 8 foreground colors and 8 for background colors
#define NUM_COLORS	8

// ANSI escape sequences for console text foreground colors
#define BLACK		1
#define RED			2
#define GREEN		3
#define YELLOW		4
#define BLUE		5
#define MAGENTA		6
#define CYAN		7
#define WHITE		8

// ANSI escape sequences for console text foreground colors
#define FG_BLACK	"\u001b[30m"
#define FG_RED		"\u001b[31m"
#define FG_GREEN	"\u001b[32m"
#define FG_YELLOW	"\u001b[33m"
#define FG_BLUE 	"\u001b[34m"
#define FG_MAGENTA	"\u001b[35m"
#define FG_CYAN		"\u001b[36m"
#define FG_WHITE	"\u001b[37m"

// ANSI escape sequences for console text background colors
#define BG_BLACK	"\u001b[40m"
#define BG_RED		"\u001b[41m"
#define BG_GREEN	"\u001b[42m"
#define BG_YELLOW	"\u001b[43m"
#define BG_BLUE		"\u001b[44m"
#define BG_MAGENTA	"\u001b[45m"
#define BG_CYAN		"\u001b[46m"
#define BG_WHITE	"\u001b[47m"

// ANSI escape sequence for setting default console text foreground and background colors
#define RESET			"\u001b[0m"

