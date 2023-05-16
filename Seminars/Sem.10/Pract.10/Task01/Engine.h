#pragma once
#include "CarPart.h"

class Engine : public CarPart{
private:
	int horsePower = 0;

public:
	Engine() = default;
	Engine(int id, const char* name, const char* details, int horsePower);

	int GetHorsePower() const;

	friend std::ostream& operator<<(std::ostream& os, const Engine& other);
};

std::ostream& operator<<(std::ostream& os, const Engine& other);

