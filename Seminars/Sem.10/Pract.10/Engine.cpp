#include "Engine.h"

Engine::Engine(unsigned int ID, const char *manufacturer, const char *description, unsigned short horsePowers) : CarPart(ID, manufacturer, description)
{
	_horsePowers = horsePowers;
}

unsigned int Engine::getHorsePowers() const
{
	return _horsePowers;
}

std::ostream &operator<<(std::ostream &out, const Engine &obj)
{
	return out << (const CarPart &)obj << " - "
			   << obj._horsePowers << " hp";
}
