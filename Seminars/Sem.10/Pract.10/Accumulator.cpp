
#include "Accumulator.hpp"
#include <ostream>

Accumulator::Accumulator(unsigned int id, String manufacturer, String description, String batteryID,size_t capacity) : CarPart(id, manufacturer, description)
{
	setCapacity(capacity);
	setBatteryID(batteryID);
}

void Accumulator::setCapacity(size_t capacity)
{
	this->capacity = capacity;
}
void Accumulator::setBatteryID(String bateryID)
{
	if (!bateryID.isEmpthy())
	{
		this->bateryID = bateryID;
	}
	else
	{
		throw std::logic_error("Battery ID can't be empty");
	}
}

std::ostream& operator<<(std::ostream& os, const Accumulator& acc)
{
	return os << acc.carPartId << " by " << acc.manufacturer << " - " << acc.description << " - " << acc.capacity <<  "Ah";
}