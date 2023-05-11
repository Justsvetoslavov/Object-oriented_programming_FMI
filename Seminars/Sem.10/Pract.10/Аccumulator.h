#pragma once
#include "CarPart.h"

class Accumulator : public CarPart {
	size_t capacity = 0;
	String batteryId;

public:
	Accumulator(size_t capacity, const String& batterId);

	size_t getCapacity() const;
	const String& GetBatteryId() const;

	void SetCapacity(size_t capacity);
	void setBatterId(const String& batterId);

	friend std::ostream& operator<<(std::ostream& os, const Accumulator& accumulator);
};