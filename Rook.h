#include "Piece.h"
#include "Varutil.h"

using namespace Varutil;

class Rook : public Piece {
public:
	Rook(std::string color) {
		if (color == s_White) {
			image = u8"♖";
		}
		else if (color == s_Black) {
			image = u8"♜";
		}
		type = s_Rook;
		this->color = color;
	};

	virtual bool canMove(Piece* board[8][8], int from_x, int from_y, int to_x, int to_y) override {
        if (board[to_x][to_y]->color == color) {
            return false;
        }

        if (from_x != to_x && from_y != to_y) {
            return false;
        }

        if (from_x == to_x) {
            int step = (to_y > from_y) ? 1 : -1;
            for (int y = from_y + step; y != to_y; y += step) {
                if (board[from_x][y]->type != NULL_) {
                    return false;
                }
            }
        }

        if (from_y == to_y) {
            int step = (to_x > from_x) ? 1 : -1;
            for (int x = from_x + step; x != to_x; x += step) {
                if (board[x][from_y]->type != NULL_) {
                    return false;
                }
            }
        }

        return true;
	}
};