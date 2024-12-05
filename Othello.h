#pragma once
#include "ChessBoard.h"
class Othello : public ChessBoard {
public:
	Othello(const ChessBoard& other);

	std::string p_turn = s_White;
	void setupBoard();
	bool currentSel(std::string turn, std::string loc);
	bool currentSel(std::string loc);
	void changeturn();
	bool isEnd();
};