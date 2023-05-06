#pragma once
#include "CarPart.hpp"
#include <ostream>

class Engine : protected CarPart
{
private:
	size_t horsePower;
public:
	Engine() = default;

	Engine(unsigned int id, String manufacturer, String description, size_t horsePower);

	size_t getHorsePower() const;
	
	friend std::ostream& operator<<(std::ostream& os, const Engine& engine);
};
