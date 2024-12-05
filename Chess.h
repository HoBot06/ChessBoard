#include "ChessBoard.h"
class Chess : public ChessBoard{
public:
	Chess(const ChessBoard& other);

	std::string p_turn = s_White;
	void setupBoard();
	bool currentSel(std::string turn, std::string loc);
	bool currentSel(std::string loc);
	void changeturn();
	bool isEnd();
	void movePiece(std::string loc);
};