#pragma once
#include <ostream>
#include "CarPart.h"

class Engine : CarPart
{
	unsigned int _horsePowers = 0;

public:
	Engine(unsigned int, const char *, const char *, unsigned short);

	unsigned int getHorsePowers() const;

	friend std::ostream &operator<<(std::ostream &, const Engine &);
};
