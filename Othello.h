#pragma once
#include "ChessBoard.h"
class Othello : public ChessBoard {
public:
	Othello(const ChessBoard& other);

	std::string p_turn = s_White;
	void setupBoard();
	bool currentSel(std::string turn, std::string loc);
	bool currentSel(std::string loc);
    void placePiece(std::string loc);
	void changeturn();
	bool isEnd();

	bool othelloPlace(int to_x, int to_y) override {

        bool canPlace = false;

        int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
        int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

        for (int d = 0; d < 8; d++) {
            int x = to_x + dx[d];
            int y = to_y + dy[d];
            bool hasOpponent = false;

            while (x >= 0 && x < 8 && y >= 0 && y < 8 && Board[x][y]->type != NULL_ && Board[x][y]->color != p_turn) {
                hasOpponent = true;
                x += dx[d];
                y += dy[d];
            }

            if (hasOpponent && x >= 0 && x < 8 && y >= 0 && y < 8 && Board[x][y]->type != NULL_ && Board[x][y]->color == p_turn) {
                canPlace = true;
                break;
            }
        }

        if (Board[to_x][to_y]->type != p_turn && Board[to_x][to_y]->type != NULL_) {
            return false;
        }

        return canPlace;
	}
};