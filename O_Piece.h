#include "Piece.h"
#include "Varutil.h"

using namespace Varutil;

class O_Piece : public Piece {
public:
    O_Piece(std::string color) {
        if (color == s_White) {
            image = u8"𐤏";
        }
        else if (color == s_Black) {
            image = u8"𒊹";
        }
        type = s_Rook;
        this->color = color;
    };

    virtual bool canMove(Piece* board[8][8], int from_x, int from_y, int to_x, int to_y) override {
        // 목표 위치가 범위를 벗어나면 이동 불가
        if (to_x < 0 || to_x >= 8 || to_y < 0 || to_y >= 8) {
            return false;
        }

        // 목표 위치가 이미 점유된 경우 이동 불가
        if (board[to_x][to_y]->type != NULL_) {
            return false;
        }

        // 8개의 방향으로 상대 돌을 가둘 수 있는지 검사
        int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1}, // 위쪽 대각선, 위쪽, 위쪽 대각선
            {0, -1},          {0, 1},  // 왼쪽, 오른쪽
            {1, -1}, {1, 0}, {1, 1}    // 아래쪽 대각선, 아래쪽, 아래쪽 대각선
        };

        // 각 방향 탐색
        for (auto& dir : directions) {
            int dx = dir[0], dy = dir[1];
            int x = to_x + dx, y = to_y + dy;
            bool found_opponent = false;

            // 방향을 따라 상대방 돌이 있는지 확인
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (board[x][y]->type == NULL_) {
                    break; // 빈 칸이면 멈춤
                }
                if (board[x][y]->color != color) {
                    found_opponent = true; // 상대방 돌 발견
                }
                else {
                    if (found_opponent) {
                        return true; // 상대방 돌을 가두는 위치
                    }
                    break; // 자신의 돌을 만났지만 상대 돌을 가두지 못함
                }
                x += dx;
                y += dy;
            }
        }

        // 모든 방향에서 가둘 수 없다면 이동 불가
        return false;
    }
};