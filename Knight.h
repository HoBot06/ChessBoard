#include "Piece.h"
#include "Varutil.h"

using namespace Varutil;

class Knight : public Piece {
public:
	Knight(std::string color) {
		if (color == s_White) {
			image = u8"♘";
		}
		else if (color == s_Black) {
			image = u8"♞";
		}
		type = s_Knight;
		this->color = color;
	};

	virtual bool canMove(Piece* board[8][8], int from_x, int from_y, int to_x, int to_y) override {
		if (board[to_x][to_y]->color == NULL_ || board[to_x][to_y]->color != color) {
			if (abs(from_x-to_x) == 2 && abs(from_y-to_y)==1) {
				return true;
			}
			if (abs(from_x - to_x) == 1 && abs(from_y - to_y) == 2) {
				return true;
			}
		}
		return false;
	}
};