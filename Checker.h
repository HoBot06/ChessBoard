#pragma once
#include "ChessBoard.h"
class Checker : public ChessBoard {
public:
	Checker(const ChessBoard& other);

	bool isRemove = false;
	std::string p_turn = s_Black;
	void setupBoard();
	bool currentSel(std::string turn, std::string loc);
	bool currentSel(std::string loc);
	void changeturn();
	bool isEnd();
	void movePiece(std::string loc);
};