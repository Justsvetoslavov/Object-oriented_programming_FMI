#pragma once
#include "CarPart.hpp"
#include "String.hpp"


class Accumulator : protected CarPart
{
private:
	size_t capacity;
	String bateryID;
public:
	Accumulator() = default;

	Accumulator(unsigned int id, String manufacturer, String descriptio, String batteryID,size_t cacity);

	void setCapacity(size_t capacity);

	void setBatteryID(String batteryID);

	friend std::ostream& operator<<(std::ostream& os, const Accumulator& acc);
};