#include "Chess.h"
#include "ChessBoard.h"
#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
#include "Varutil.h"
#include <iostream>
#include <cstdlib>

using namespace Varutil;

Chess::Chess(const ChessBoard& other) {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			Board[x][y] = other.Board[x][y];
		}
	}
}

void Chess::setupBoard() {
	//Æù
	for (int i = 0; i < 8; i++) {
		Board[i][1] = new Pawn(s_White);
		Board[i][6] = new Pawn(s_Black);
	}
	//·è
	for (int i = 0; i < 8; i+=7) {
		Board[i][0] = new Rook(s_White);
		Board[i][7] = new Rook(s_Black);
	}
	//³ªÀÌÆ®
	for (int i = 1; i < 7; i += 5) {
		Board[i][0] = new Knight(s_White);
		Board[i][7] = new Knight(s_Black);
	}
	//ºñ¼ó
	for (int i = 2; i < 6; i += 3) {
		Board[i][0] = new Bishop(s_White);
		Board[i][7] = new Bishop(s_Black);
	}
	//Äý
	Board[3][0] = new Queen(s_White);
	Board[3][7] = new Queen(s_Black);
	//Å·
	Board[4][0] = new King(s_White);
	Board[4][7] = new King(s_Black);
}

bool Chess::currentSel(std::string turn, std::string loc) {
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

bool Chess::currentSel(std::string loc) {
	int* loc_ = returnLoc_int(loc);
	if (loc_ == nullptr) return false;
	int x = loc_[0];
	int y = loc_[1];
	if (x <= 0 || x > 8 || y > 8 || y <= 0) return false;
	Piece* piece = getPiece(x, y);
	if (sel_Piece->canMove(Board, sel_Loc[0] - 1, sel_Loc[1] - 1, x-1, y-1)) {
		return true;
	}
	return false;
};

void Chess::changeturn() {
	if (p_turn == s_White) p_turn = s_Black;
	else if (p_turn == s_Black) p_turn = s_White;
}

bool Chess::isEnd() {
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

void Chess::movePiece(std::string loc) {
	int* loc_ = returnLoc_int(loc);
	int x = loc_[0] - 1;
	int y = loc_[1] - 1;
	if (Board[sel_Loc[0] - 1][sel_Loc[1] - 1]->canMove(Board, sel_Loc[0] - 1, sel_Loc[1] - 1, x, y)) {
		setPiece(Board[sel_Loc[0] - 1][sel_Loc[1] - 1], x, y);
		Board[sel_Loc[0] - 1][sel_Loc[1] - 1] = new Piece;
		sel_Loc[0] = 0; sel_Loc[1] = 0;
	}
};