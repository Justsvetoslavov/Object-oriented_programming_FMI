#pragma once
#include "CarPart.h"

class Engine : public CarPart{
	size_t horsePower = 0;
public:
	size_t getHorsePower() const;
	void SetHorsePower(size_t horsePower);

	friend std::ostream& operator<<(std::ostream& os, const Engine& engine);
};