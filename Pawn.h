#include "Piece.h"
#include "Varutil.h"

using namespace Varutil;

class Pawn : public Piece {
public:
	Pawn(std::string color) {
		if (color == s_White) {
			image = u8"♙";
		}
		else if (color == s_Black) {
			image = u8"♟";
		}
		type = s_Pawn;
		this->color = color;
	};

	virtual bool canMove(Piece* board[8][8], int from_x, int from_y, int to_x, int to_y) override {
        int direction = (color == s_Black) ? -1 : 1;

        if (board[to_x][to_y]->color == color) {
            return false;
        }

        if (from_x == to_x && to_y == from_y + direction) {
            if (board[to_x][to_y]->type == NULL_) {
                return true;
            }
            return false;
        }


        if (from_x == to_x && to_y == from_y + 2 * direction) {
            if (((color == s_Black && from_y == 6) || (color == s_White && from_y == 1)) &&
                board[to_x][to_y]->type == NULL_ && board[to_x][from_y + direction]->type == NULL_) {
                return true;
            }
            return false;
        }

        if (abs(to_x - from_x) == 1 && to_y == from_y + direction) {
            if (board[to_x][to_y]->type != NULL_ && board[to_x][to_y]->color != color) {
                return true;
            }
            return false;
        }

        return false;
	}
};