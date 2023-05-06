#include "Engine.hpp"

Engine::Engine(unsigned int id, String manufacturer, String description, size_t horsePower) : CarPart(id, manufacturer, description)
{
	this->horsePower = horsePower;
}

size_t Engine::getHorsePower() const 
{
	return this->horsePower;
}

std::ostream& operator<<(std::ostream& os, const Engine& engine)
{
	return os << engine.carPartId << " by " << engine.manufacturer << " - " << engine.horsePower << "hp";
}