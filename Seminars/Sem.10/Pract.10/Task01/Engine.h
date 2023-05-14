#pragma once
#include "CarPart.h"

class Engine : public CarPart
{
public:
	unsigned horsePower = 0;

	Engine() = default;
	Engine(unsigned id, const char* manufacturer, const char* description, unsigned horsePower);

	friend std::ostream& operator<<(std::ostream& ofs, const Engine& engine);
};
std::ostream& operator<<(std::ostream& ofs, const Engine& engine);

