#include "Engine.h"

Engine::Engine(unsigned ID, MyString manufacturer, MyString description, ushort horsepower) : CarPart(ID, manufacturer, description), _horsepower(horsepower) {

}

void Engine::setHorsepower(ushort horsepower) {
	_horsepower = horsepower;
}

ushort Engine::getHorsepower() const {
	return _horsepower;
}

std::ostream& operator << (std::ostream& os, const Engine& e) {
	os << (CarPart)e;
	return os << '-' << e.getHorsepower() << " hp ";
}