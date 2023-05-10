#include "CarPart.h"
#include "Engine.h"
#include <iostream>
#pragma warning (disable : 4996)

Engine::Engine()
{
	horsepower = 0;
}

Engine::Engine(unsigned id, char* manufacturer, char* description, unsigned horsepower) : CarPart(id, manufacturer, description)
{
	setHorsepower(horsepower);
}

unsigned Engine::getHorsepower() const
{
	return horsepower;
}

void Engine::setHorsepower(unsigned horsepower)
{
	this->horsepower = horsepower;
}

std::ostream& operator<<(std::ostream& os, const Engine& engine)
{
	os << (CarPart&)engine << engine.getHorsepower() << " hp";
}
