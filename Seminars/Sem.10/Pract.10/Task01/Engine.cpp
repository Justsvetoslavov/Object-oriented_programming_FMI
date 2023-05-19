#include "Engine.h"
Engine::Engine(unsigned id, const MyString& manufacturerName, 
			   const MyString& descripiton, unsigned hoursePower) 
	: CarPart(id, manufacturerName, descripiton) {
	this->descripiton = descripiton;
	this->hoursePower = hoursePower;
}

unsigned Engine::GetHoursePower() const {
	return this->hoursePower;
}

std::ostream& operator<<(std::ostream& os, const Engine& engine) {
	os << (CarPart&)engine << " - " << engine.hoursePower << " hp";
	return os;
}
