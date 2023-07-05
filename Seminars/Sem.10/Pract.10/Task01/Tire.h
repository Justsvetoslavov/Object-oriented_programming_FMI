#pragma once

#include "CarPart.h"

typedef unsigned short ushort;

const ushort MIN_WIDTH = 155;
const ushort MAX_WIDTH = 365;

const ushort MIN_PROFILE = 30;
const ushort MAX_PROFILE = 80;

const ushort MIN_RIM_SIZE = 13;
const ushort MAX_RIM_SIZE = 21;

class Tire : public CarPart {
	ushort _width = MIN_WIDTH;
	ushort _profile = MIN_PROFILE;
	ushort _rim = MIN_RIM_SIZE;

	static bool isValidWidth(ushort width);
	static bool isValidProfile(ushort profile);
	static bool isValidDiameter(ushort diameter);

public:
	Tire() = default;
	Tire(unsigned ID, MyString manufacturer, MyString description, ushort width, ushort profile, ushort diameter);

	ushort getWidth() const;
	bool setWidth(ushort width);

	ushort getProfile() const;
	bool setProfile(ushort profile);

	ushort getRimSize() const;
	bool setRimSize(ushort diameter);
};

std::ostream& operator << (std::ostream& os, const Tire& t);