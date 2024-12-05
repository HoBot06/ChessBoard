#pragma once

#include "Piece.h"
#include "Location.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class ChessBoard {
public:
	Piece* Board[8][8];
	ChessBoard();
	ChessBoard(const ChessBoard& other);
	Piece* sel_Piece;
	int sel_Loc[2];
	std::vector<Location> canPlace;

	void showBoard();
	void clearBoard();
	void setupBoard();
	void setPiece(Piece* piece, int x, int y);
	void selectPiece(std::string loc);
	Piece* getPiece(int x, int y);
	void movePiece(std::string loc);
	//bool canmoveLoc(Piece piece, int p_x, int p_y, int x, int y);
	int* returnLoc_int(std::string loc);
	bool currentSel(std::string turn, std::string loc);
	bool currentSel(std::string loc);
private:
	//std::string piece_image(Piece piece);
};
