#pragma once
#include "CarPart.h"
#include <exception>

const unsigned MIN_WIDTH = 155;
const unsigned MAX_WIDTH = 365;
const unsigned MIN_PROFILE = 30;
const unsigned MAX_PROFILE = 80;
const unsigned MIN_DIAMETER = 13;
const unsigned MAX_DIAMETER = 21;

class Tire : public CarPart
{
public:
	unsigned width = 0;
	unsigned profile = 0;
	unsigned diameterInches = 0;

	Tire() = default;
	Tire(unsigned id, const char* manufacturer, const char* description,
		unsigned width, unsigned profile, unsigned diameterInches);

	friend std::ostream& operator<<(std::ostream& ofs, const Tire& tire);
};

std::ostream& operator<<(std::ostream& ofs, const Tire& tire);

static bool isInRange(int number, int lowerBound, int upperBound);

