#include "Tyre.hpp"

Tyre::Tyre(unsigned int id, String manufacturer, String description,unsigned int width, unsigned int profile, unsigned int diameter) : CarPart(id, manufacturer, description)
{
	setWidth(width);
	setProfile(profile);
	setDiameter(diameter);
}

void Tyre::setWidth(unsigned int width)
{
	if (width >= 155 && width <= 365)
	{
		this->width = width;
	}
	else
	{
		throw std::logic_error("Width must be between 155 and 365");
	}
}

void Tyre::setProfile(unsigned int profile)
{
	if (profile >= 30 && profile <= 80)
	{
		this->profile = profile;
	}
	else
	{
		throw std::logic_error("Profile must be between 30 and 80");
	}
}

void Tyre::setDiameter(unsigned int diameter)
{
	if (diameter >= 13 && diameter <= 21)
	{
		this->diameter = diameter;
	}
	else
	{
		throw std::logic_error("Diameter must be between 13 and 21");
	}
}

std::ostream& operator<<(std::ostream& os, const Tyre& tyre)
{
	return os << tyre.carPartId << " by " << tyre.manufacturer << " - " << tyre.description << "-" << tyre.width << "/" << tyre.profile << "R" << tyre.diameter;
}