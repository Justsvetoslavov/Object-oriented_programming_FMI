#pragma once
#include "CarPart.h"

typedef unsigned short ushort;

class Engine : public CarPart{
	ushort _horsepower = 100; 

public:
	Engine() = default; 
	Engine(unsigned ID, MyString manufacturer, MyString description, ushort horsepower);

	void setHorsepower(ushort horsepower);
	ushort getHorsepower() const;
};

std::ostream& operator << (std::ostream& os, const Engine& e);