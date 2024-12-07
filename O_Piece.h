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
        type = s_Othello;
        this->color = color;
    };

};