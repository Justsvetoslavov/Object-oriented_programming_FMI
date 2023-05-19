#pragma once
#include "CarPart.h"
class Engine : public CarPart
{
private:
	unsigned hoursePower = 0;
public:
	Engine() = default;
	Engine(unsigned id, const MyString& manufacturerName, 
		const MyString& descripiton, unsigned hoursePower);
	
	unsigned GetHoursePower() const;

	friend std::ostream& operator<<(std::ostream& os, const Engine& engine);
};



