#include "CK_Piece.h"
#include "CK_Piece_King.h"
#include "Checker.h"
#include "ChessBoard.h"
#include "Varutil.h"
#include <iostream>
#include <cstdlib>

using namespace Varutil;

Checker::Checker(const ChessBoard& other) {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			Board[x][y] = other.Board[x][y];
		}
	}
}

void Checker::setupBoard() {
	//¹é
	for (int i = 1; i < 8; i += 2) {
		Board[i][0] = new CK_Piece(s_White);
	}
	for (int i = 0; i < 7; i += 2) {
		Board[i][1] = new CK_Piece(s_White);
	}
	for (int i = 1; i < 8; i += 2) {
		Board[i][2] = new CK_Piece(s_White);
	}
	//Èæ
	for (int i = 0; i < 7; i += 2) {
		Board[i][7] = new CK_Piece(s_Black);
	}
	for (int i = 1; i < 8; i += 2) {
		Board[i][6] = new CK_Piece(s_Black);
	}
	for (int i = 0; i < 7; i += 2) {
		Board[i][5] = new CK_Piece(s_Black);
	}
}

bool Checker::currentSel(std::string turn, std::string loc) {
	int* loc_ = returnLoc_int(loc);
	if (loc_ == nullptr) return false;
	int x = loc_[0];
	int y = loc_[1];
	if (x <= 0 || x > 8 || y > 8 || y <= 0) return false;
	Piece* piece = getPiece(x, y);
	if (piece->type == NULL_) return false;
	if (piece->color != turn) return false;
	return true;
};

bool Checker::currentSel(std::string loc) {
	int* loc_ = returnLoc_int(loc);
	if (loc_ == nullptr) return false;
	int x = loc_[0];
	int y = loc_[1];
	if (x <= 0 || x > 8 || y > 8 || y <= 0) return false;
	Piece* piece = getPiece(x, y);
	if (sel_Piece->canMove(Board, sel_Loc[0] - 1, sel_Loc[1] - 1, x - 1, y - 1)) {
		return true;
	}
	return false;
};

void Checker::changeturn() {
	if (p_turn == s_White) p_turn = s_Black;
	else if (p_turn == s_Black) p_turn = s_White;
}

bool Checker::isEnd() {
	int b_count = 0;
	int w_count = 0;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (Board[x][y]->color == s_White) {
				w_count++;
			}
			if (Board[x][y]->color == s_Black) {
				b_count++;
			}
		}
	}
	if (b_count == 0 || w_count == 0) return true;
	return false;
}

void Checker::movePiece(std::string loc) {
	int* loc_ = returnLoc_int(loc);
	int x = loc_[0] - 1;
	int y = loc_[1] - 1;
	if (Board[sel_Loc[0] - 1][sel_Loc[1] - 1]->canMove(Board, sel_Loc[0] - 1, sel_Loc[1] - 1, x, y)) {
		if (Board[sel_Loc[0] - 1][sel_Loc[1] - 1]->remove_Loc[0] >= 0 && Board[sel_Loc[0] - 1][sel_Loc[1] - 1]->remove_Loc[0] >= 0) {
			int r_x = Board[sel_Loc[0] - 1][sel_Loc[1] - 1]->remove_Loc[0];
			int r_y = Board[sel_Loc[0] - 1][sel_Loc[1] - 1]->remove_Loc[1];
			Board[r_x][r_y] = new Piece;
			isRemove = true;
		}
		setPiece(Board[sel_Loc[0] - 1][sel_Loc[1] - 1], x, y);
		if (Board[sel_Loc[0] - 1][sel_Loc[1] - 1]->color == s_Black && y == 0) {
			setPiece(new CK_Piece_King(s_Black), x, y);
		}
		if (Board[sel_Loc[0] - 1][sel_Loc[1] - 1]->color == s_White && y == 7) {
			setPiece(new CK_Piece_King(s_White), x, y);
		}
		Board[sel_Loc[0] - 1][sel_Loc[1] - 1] = new Piece;
		sel_Loc[0] = 0; sel_Loc[1] = 0;
	}
};