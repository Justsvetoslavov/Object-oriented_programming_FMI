#pragma once
#include "CarPart.hpp"
#include <ostream>

class Tyre : protected CarPart
{
private:
	unsigned int width;
	unsigned int profile;
	unsigned int diameter;
public:
	Tyre() = default;

	Tyre(unsigned int id, String manufacturer, String description,unsigned int width, unsigned int profile, unsigned int diameter);	

	void setWidth(unsigned int width);

	void setProfile(unsigned int profile);

	void setDiameter(unsigned int diameter);

	friend std::ostream& operator<<(std::ostream& os, const Tyre& tyre);
};