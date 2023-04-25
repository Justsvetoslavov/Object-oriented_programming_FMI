#pragma once
#include "Person.h"

class Car
{
private:
	char* brand;
	Person owner;
	unsigned yearOfRegistration;

public:
	Car(const char brand[128], const Person& owner, const unsigned& year);
	Car();
	Car(const Car& car);
	Car& operator=(const Car& other);
	~Car();

	char* getBrand() const;
	Person getOwner() const;
	unsigned getYearOfRegistration() const;

	void setBrand(const char brand[128]);
	void setOwner(const Person& owner);
	void setYearOfRegistration(const unsigned& year);
};
