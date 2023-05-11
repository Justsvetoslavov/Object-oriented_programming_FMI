#pragma once
#include "CarPart.h"

const size_t MIN_WIDTH = 155;
const size_t MAX_WIDTH = 365;
const size_t MIN_PROFILE = 30;
const size_t MAX_PROFILE = 80;
const size_t MIN_DIAMETER = 13;
const size_t MAX_DIAMETER = 21;

class Tire :public CarPart {
	size_t widthInMilimeters = MIN_WIDTH;
	size_t profile = MIN_PROFILE;
	size_t diameterInInches = MIN_DIAMETER;

public:
	Tire() = default;
	Tire(size_t widthInMilimeters, size_t profile, size_t diametersInInches);

	size_t getWidthInMilimeters() const;
	size_t getProfile() const;
	size_t getDiameterInInches() const;
	
	void setWidthInMilimeters(size_t value);
	void setProfile(size_t value);
	void setDiameterIninches(size_t value);

	friend std::ostream& operator<<(std::ostream& os, const Tire& tire);
};