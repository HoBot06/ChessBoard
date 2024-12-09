#include "ChessBoard.h"
#include "Piece.h"
#include "Varutil.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace Varutil;

ChessBoard::ChessBoard() {
	sel_Loc[0] = 0; sel_Loc[1] = 0;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			Board[x][y] = new Piece;
		}
	}
}

ChessBoard::ChessBoard(const ChessBoard& other) {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			Board[x][y] = other.Board[x][y];
		}
	}
}

void ChessBoard::showBoard(int menu) {
	system("cls");
	UINT uint = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (menu == 1 || menu == 2) {
		std::cout << "   A   B   C   D   E   F   G   H" << std::endl;
		for (int y = 0; y < 8; y++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			std::cout << y + 1;
			for (int x = 0; x < 8; x++) {
				if (sel_Loc[0] != 0 && sel_Loc[1] != 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE * 16);
					if (Board[sel_Loc[0] - 1][sel_Loc[1] - 1]->canMove(Board, sel_Loc[0] - 1, sel_Loc[1] - 1, x, y)) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + YELLOW * 16);
					}
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE * 16);
				}
				if (sel_Loc[0] - 1 == x && sel_Loc[1] - 1 == y) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN * 16);
				}
				if (Board[x][y]->color != NULL_ && Board[x][y]->type != NULL_) {
					std::cout << "[" << Board[x][y]->image << " ]";
				}

				else {
					std::cout << "[  ]";
				}
			}
			std::cout << std::endl;
		}
	}
	else if (menu == 3) {
		std::cout << "   A   B   C   D   E   F   G   H" << std::endl;
		for (int y = 0; y < 8; y++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			std::cout << y + 1;
			for (int x = 0; x < 8; x++) {
				if (othelloPlace(x, y)) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + YELLOW * 16);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE * 16);
				}
				if (Board[x][y]->color != NULL_ && Board[x][y]->type != NULL_) {
					std::cout << "[" << Board[x][y]->image << " ]";
				}

				else {
					std::cout << "[  ]";
				}
			}
			std::cout << std::endl;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	SetConsoleOutputCP(uint);
}

void ChessBoard::clearBoard() {};
void ChessBoard::setupBoard() {};

void ChessBoard::setPiece(Piece* piece, int x, int y) {
	Board[x][y] = piece;
}

void ChessBoard::selectPiece(std::string loc) {
	int* loc_ = returnLoc_int(loc);
	int x = loc_[0];
	int y = loc_[1];
	Piece* piece = getPiece(x, y);
	sel_Piece = piece;
	sel_Loc[0] = x; sel_Loc[1] = y;
};

Piece* ChessBoard::getPiece(int x, int y) {
	if (Board[x-1][y-1]->type != NULL_) {
		return Board[x-1][y-1];
	}
	else {
		return new Piece;
	}
}

void ChessBoard::movePiece(std::string loc) {};

int* ChessBoard::returnLoc_int(std::string loc) {
	std::string x_loc = loc.substr(0, 1);
	std::string y_loc = loc.substr(1, 2);
	int loc_[2] = {0, 0};
	if (x_loc == "A") loc_[0] = 1;
	else if (x_loc == "B") loc_[0] = 2;
	else if (x_loc == "C") loc_[0] = 3;
	else if (x_loc == "D") loc_[0] = 4;
	else if (x_loc == "E") loc_[0] = 5;
	else if (x_loc == "F") loc_[0] = 6;
	else if (x_loc == "G") loc_[0] = 7;
	else if (x_loc == "H") loc_[0] = 8;

	loc_[1] = std::stoi(y_loc);

	return loc_;
}