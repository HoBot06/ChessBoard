#pragma once

#include "Varutil.h"
#include <iostream>

using namespace Varutil;

class Location {
public:
	Location(int x, int y) {
		this->x = x;
		this->y = y;
	};

	int x;
	int y;
};