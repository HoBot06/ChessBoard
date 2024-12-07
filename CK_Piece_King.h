﻿#include "Piece.h"
#include "Varutil.h"

using namespace Varutil;

class CK_Piece_King : public Piece {
public:
    CK_Piece_King(std::string color) {
        if (color == s_White) {
            image = u8"☆";
        }
        else if (color == s_Black) {
            image = u8"★";
        }
        type = s_Checker_King;
        this->color = color;
    };

    virtual bool canMove(Piece* board[8][8], int from_x, int from_y, int to_x, int to_y) override {
        remove_Loc[0] = -1;
        remove_Loc[1] = -1;

        if (to_x < 0 || to_x >= 8 || to_y < 0 || to_y >= 8) {
            return false;
        }

        if (board[to_x][to_y]->type != NULL_) {
            return false;
        }

        if (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 1) {
            return true;
        }

        if (abs(to_x - from_x) == 2 && abs(to_y - from_y) == 2) {
            int mid_x = (from_x + to_x) / 2;
            int mid_y = (from_y + to_y) / 2;

            if (board[mid_x][mid_y]->type != NULL_ && board[mid_x][mid_y]->color != color) {
                remove_Loc[0] = mid_x;
                remove_Loc[1] = mid_y;
                return true;
            }
        }
        return false;
    }
};