#include "Piece.h"
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
        // 목표 칸이 범위를 벗어나면 이동 불가
        if (to_x < 0 || to_x >= 8 || to_y < 0 || to_y >= 8) {
            return false;
        }

        // 목표 칸이 비어 있지 않으면 이동 불가
        if (board[to_x][to_y]->type != NULL_) {
            return false;
        }

        // 대각선 한 칸 이동 (앞뒤 모두 가능)
        if (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 1) {
            return true;
        }

        // 대각선 두 칸 뛰어넘기 (상대방 말 제거)
        if (abs(to_x - from_x) == 2 && abs(to_y - from_y) == 2) {
            int mid_x = (from_x + to_x) / 2;
            int mid_y = (from_y + to_y) / 2;

            // 중간 칸에 상대방 말이 있는지 확인
            if (board[mid_x][mid_y]->type != NULL_ && board[mid_x][mid_y]->color != color) {
                remove_Loc[0] = mid_x;
                remove_Loc[1] = mid_y;
                return true;
            }
        }

        // 규칙에 맞지 않으면 이동 불가
        return false;
    }
};