#include "CarPart.h"
#pragma once

class Tires : protected CarPart
{
	unsigned width;
	unsigned profil;
	unsigned rimSize;

public:
	Tires() = default;
	Tires(unsigned, char*, char*, unsigned, unsigned, unsigned);
	unsigned getWidth()const;
	unsigned getProfil()const;
	unsigned getRimSize()const;

	void setWidth(unsigned);
	void setProfil(unsigned);
	void setRimSize(unsigned);

	friend std::ostream& operator<<(std::ostream&, const Tires&);
};
