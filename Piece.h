#pragma once

#include "Varutil.h"
#include <iostream>

using namespace Varutil;

class Piece {
public:
	Piece() : color(NULL_), type(NULL_), image(NULL_) {};
	Piece(std::string color, std::string type, std::string image) : color(color), type(type), image(image) {};

	std::string image;
	std::string color;
	std::string type;
	int remove_Loc[2] = {-1,-1};

	std::string getColor();
	std::string getImage();

	virtual bool canMove(Piece* board[8][8], int from_x, int from_y, int to_x, int to_y) { return false; };

	virtual ~Piece() {}
};