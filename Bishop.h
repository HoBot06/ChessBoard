#include "Piece.h"
#include "Varutil.h"

using namespace Varutil;

class Bishop : public Piece {
public:
	Bishop(std::string color) {
		if (color == s_White) {
			image = u8"♗";
		}
		else if (color == s_Black) {
			image = u8"♝";
		}
		type = s_Bishop;
		this->color = color;
	};

	virtual bool canMove(Piece* board[8][8], int from_x, int from_y, int to_x, int to_y) override {
		if (board[to_x][to_y]->color == color) {
			return false;
		}

		if (abs(from_x - to_x) != abs(from_y - to_y)) {
			return false;
		}
		int dx = (to_x - from_x > 0) ? 1 : -1;
		int dy = (to_y - from_y > 0) ? 1 : -1;

		int x = from_x + dx;
		int y = from_y + dy;
		while (x != to_x && y != to_y) {
			if (board[x][y]->type != NULL_) {
				return false;
			}
			x += dx;
			y += dy;
		}

		return true;
	}

};