#pragma once
#include <ostream>

class CarPart
{
	char *_manufacturer = nullptr;
	char *_description = nullptr;
	unsigned int _ID = 0;

public:
	CarPart(unsigned int, const char *, const char *);
	CarPart(const CarPart &);
	CarPart &operator=(const CarPart &);

public:
	friend std::ostream &operator<<(std::ostream &, const CarPart &);

private:
	void copyFrom(const CarPart &);
	void copyManufacturer(const char *);
	void copyDescription(const char *);
	void free();
};
