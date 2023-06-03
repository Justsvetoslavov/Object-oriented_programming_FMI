#include "CarBattery.h"

CarBattery::CarBattery()
{
	this->batteryId = "Unknown id";
}

CarBattery::CarBattery(const unsigned id, const char* manufacturer, const char* description, const unsigned capacityAh,
	const char* batteryId) : CarPart(id, manufacturer, description)
{
	this->capacityAh = capacityAh;
	this->batteryId = batteryId;
}

std::ostream& operator<<(std::ostream& ofs, const CarBattery& carBattery)
{
	ofs << (CarPart&)carBattery << " - " << carBattery.capacityAh << " Ah";
	return ofs;
}
