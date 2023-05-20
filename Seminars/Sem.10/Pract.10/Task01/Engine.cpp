#include "Engine.h"

Engine::Engine(int id, const char* name, const char* details, int horsePower) : CarPart(id, name, details) {
	if (horsePower < 0)
		throw std::out_of_range("The horse power cannot be less than zero");

	this->horsePower = horsePower;
}

int Engine::GetHorsePower() const {
	return horsePower;
}

std::ostream& operator<<(std::ostream& os, const Engine& other) {
	os << (CarPart&)other << " - " << other.horsePower << " hp";
	return os;
}
