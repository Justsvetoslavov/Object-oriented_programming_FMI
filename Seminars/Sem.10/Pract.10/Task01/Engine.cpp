#include "Engine.h"

Engine::Engine(const unsigned id, const char* manufacturer, const char* description, const unsigned horsePower) :
	CarPart(id, manufacturer, description)
{
	this->horsePower = horsePower;
}

std::ostream& operator<<(std::ostream& ofs, const Engine& engine)
{
	ofs << (CarPart&)engine << " - " << engine.horsePower << " hp";
	return ofs;
}
