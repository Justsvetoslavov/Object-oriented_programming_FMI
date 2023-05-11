#pragma once
#include <ostream>

class Part
{
	char *_manufacturer = nullptr;
	char *_description = nullptr;
	unsigned int _ID = 0;

public:
	Part() = default;
	Part(unsigned int, const char *, const char *);
	Part(const Part &);
	Part &operator=(const Part &);

public:
	friend std::ostream &operator<<(std::ostream &, const Part &);

private:
	void copyFrom(const Part &);
	void copyManufacturer(const char *);
	void copyDescription(const char *);
	void free();
};