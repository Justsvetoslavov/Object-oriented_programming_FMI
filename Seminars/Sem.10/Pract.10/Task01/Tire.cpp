#include "Tire.h"

Tire::Tire(const unsigned id, const char* manufacturer, const char* description, const unsigned width, const unsigned profile,
	const unsigned diameterInches) : CarPart(id, manufacturer, description)
{
	if (!isInRange(width, MIN_WIDTH, MAX_WIDTH))
	{
		throw std::range_error("Width out of range.");
	}
	if (!isInRange(profile, MIN_PROFILE, MAX_PROFILE))
	{
		throw std::range_error("Profile out of range.");
	}
	if (!isInRange(diameterInches, MIN_DIAMETER, MAX_DIAMETER))
	{
		throw std::range_error("Diameter out of range.");
	}

	this->width = width;
	this->profile = profile;
	this->diameterInches = diameterInches;
}

std::ostream& operator<<(std::ostream& ofs, const Tire& tire)
{
	ofs << (CarPart&)tire << " - " << tire.width << '/' << tire.profile << 'R' << tire.diameterInches;
	return ofs;
}

bool isInRange(const int number, const int lowerBound, const int upperBound)
{
	return number >= lowerBound && number <= upperBound;
}
