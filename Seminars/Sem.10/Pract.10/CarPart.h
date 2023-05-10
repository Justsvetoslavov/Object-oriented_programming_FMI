#pragma once

class CarPart
{
	unsigned id;
	char* manufacturer;
	char* description;

public:
	CarPart();
	CarPart(unsigned, char*, char*);
	CarPart(const CarPart&);
	CarPart& operator=(const CarPart&);
	~CarPart();

	unsigned getId() const;
	char* getName() const;
	char* getDescription() const;

	void setId(unsigned);
	void setName(char*);
	void setDescription(char*);

	friend std::ostream& operator<<(std::ostream&, const CarPart&);

private: 
	void copyFrom(const CarPart&);
	void free();
};