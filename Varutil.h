#pragma once

#include <iostream>
#include <cstdlib>
namespace Varutil {
	const std::string NULL_ = "NULL__";
	const std::string s_White = "WHITE";
	const std::string s_Black = "Black";
	const std::string s_Rook = "R";
	const std::string s_Bishop = "B";
	const std::string s_Knight = "N";
	const std::string s_Pawn = "P";
	const std::string s_Queen = "Q";
	const std::string s_King = "K";
	const std::string s_Checker = "C";
	const std::string s_Checker_King = "CK";
	const std::string s_Othello = "O";

	//color=foreground+background*16
	const int BLACK = 0;
	const int BLUE = 1;
	const int GREEN = 2;
	const int CYAN = 3;
	const int RED = 4;
	const int MAGENTA = 5;
	const int BROWN = 6;
	const int LIGHTGRAY = 7;
	const int DARKGRAY = 8;
	const int LIGHTBLUE = 9;
	const int LIGHTGREEN = 10;
	const int LIGHTCYAN = 11;
	const int LIGHTRED = 12;
	const int LIGHTMAGENTA = 13;
	const int YELLOW = 14;
	const int WHITE = 15;
}