#include "CarPart.h"
#pragma once
#include <iostream>

class Engine :protected CarPart
{
	unsigned horsepower;

public:
	Engine();
	Engine(unsigned, char*, char*, unsigned);
	unsigned getHorsepower() const;
	void setHorsepower(unsigned);

	friend std::ostream& operator<<(std::ostream&, const Engine&);
};
