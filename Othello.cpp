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

void Othello::placePiece(std::string loc) {
	int* loc_ = returnLoc_int(loc);
	int x = loc_[0] - 1;
	int y = loc_[1] - 1;
	Board[x][y] = new O_Piece(p_turn);

	int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
	int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

	for (int d = 0; d < 8; d++) {
		std::vector<std::pair<int, int>> toFlip;
		int nx = x + dx[d];
		int ny = y + dy[d];

		while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && Board[nx][ny]->type != NULL_ && Board[nx][ny]->color != p_turn) {
			toFlip.emplace_back(nx, ny);
			nx += dx[d];
			ny += dy[d];
		}

		if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && Board[nx][ny]->type != NULL_ && Board[nx][ny]->color == p_turn) {
			for (auto& pos : toFlip) {
				int fx = pos.first;
				int fy = pos.second;
				Board[fx][fy]=new O_Piece(p_turn);
			}
		}
	}
}

bool Othello::currentSel(std::string loc) {
	int* loc_ = returnLoc_int(loc);
	if (loc_ == nullptr) return false;
	int x = loc_[0];
	int y = loc_[1];
	if (x <= 0 || x > 8 || y > 8 || y <= 0) return false;
	return othelloPlace(x-1, y-1);
};

void Othello::changeturn() {
	if (p_turn == s_White) p_turn = s_Black;
	else if (p_turn == s_Black) p_turn = s_White;
}

bool Othello::isEnd() {
	int w_count = 0;
	int b_count = 0;
	int blank = 0;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (Board[x][y]->color == s_White) {
				w_count++;
			}
			if (Board[x][y]->color == s_Black) {
				b_count++;
			}
			if (Board[x][y]->type == NULL_) {
				blank++;
			}
		}
	}
	if (blank == 0) {
		return true;
	}
	if (w_count ==0||b_count ==0) {
		return true;
	}
	return false;
}