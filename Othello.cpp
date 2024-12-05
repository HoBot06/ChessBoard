#include "O_Piece.h"
#include "Othello.h"
#include "ChessBoard.h"
#include "Varutil.h"
#include <iostream>
#include <cstdlib>

using namespace Varutil;

Othello::Othello(const ChessBoard& other) {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			Board[x][y] = other.Board[x][y];
		}
	}
}

void Othello::setupBoard() {
	//¹é
	Board[3][4] = new O_Piece(s_White);
	Board[4][3] = new O_Piece(s_White);
	//Èæ
	Board[3][3] = new O_Piece(s_Black);
	Board[4][4] = new O_Piece(s_Black);
}

bool Othello::currentSel(std::string turn, std::string loc) {
	int* loc_ = returnLoc_int(loc);
	int x = loc_[0];
	int y = loc_[1];
	Piece* piece = getPiece(x, y);
	if (piece->type == NULL_) return false;
	if (piece->color != turn) return false;
	return true;
};

bool Othello::currentSel(std::string loc) {
	int* loc_ = returnLoc_int(loc);
	int x = loc_[0];
	int y = loc_[1];
	Piece* piece = getPiece(x, y);
	if (sel_Piece->canMove(Board, sel_Loc[0] - 1, sel_Loc[1] - 1, x - 1, y - 1)) {
		return true;
	}
	return false;
};

void Othello::changeturn() {
	if (p_turn == s_White) p_turn = s_Black;
	else if (p_turn == s_Black) p_turn = s_White;
}

bool Othello::isEnd() {
	int count = 0;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (Board[x][y]->type == s_King) {
				count++;
			}
		}
	}
	if (count >= 2) {
		return false;
	}
	return true;
}