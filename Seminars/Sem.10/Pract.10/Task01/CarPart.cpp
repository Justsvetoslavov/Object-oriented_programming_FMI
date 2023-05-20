#include "CarPart.h"
#include <sstream>

CarPart::CarPart(int id, const char* name, const char* details){
	if (id < 0)
		throw std::out_of_range("The id cannot be less than 0");
	if (name == nullptr || details == nullptr)
		throw std::invalid_argument("The text doesn't exist");

	this->id = id;
	this->name = name;
	this->details = details;
}

std::ostream& operator<<(std::ostream& os, const CarPart& other){
	os << other.id << " by " << other.name.c_str() << " - " << other.details.c_str();
	return os;
}
