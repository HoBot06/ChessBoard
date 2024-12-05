#include "Piece.h"
#include "Varutil.h"

using namespace Varutil;

class King : public Piece {
public:
	King(std::string color) {
		if (color == s_White) {
			image = u8"♔";
		}
		else if (color == s_Black) {
			image = u8"♚";
		}
		type = s_King;
		this->color = color;
	};

	virtual bool canMove(Piece* board[8][8], int from_x, int from_y, int to_x, int to_y) override {
		if (board[to_x][to_y]->color == color) {
			return false;
		}

		int dx = abs(to_x - from_x);
		int dy = abs(to_y - from_y);

		if ((dx <= 1 && dy <= 1) && (dx + dy > 0)) {
			return true;
		}
		return false;
	}
};