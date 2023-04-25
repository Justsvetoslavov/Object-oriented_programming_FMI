#include "Car.h"
#include <iostream>

Car::Car(const char brand[128], const Person& owner, const unsigned& year)
{
	this->setBrand(brand);
	this->setOwner(owner);
	this->setYearOfRegistration(year);
}

Car::Car() : Car("", Person(), 2000) {}

Car::Car(const Car& car) : Car(car.getBrand(), car.getOwner(), car.getYearOfRegistration()) {}

Car& Car::operator=(const Car& other)
{
	delete[] this->brand;
	this->setBrand(other.getBrand());
	this->setOwner(other.getOwner());
	this->setYearOfRegistration(other.getYearOfRegistration());
	return *this;
}

Car::~Car()
{
	delete[] this->brand;
}

char* Car::getBrand() const
{
	return this->brand;
}

Person Car::getOwner() const
{
	return this->owner;
}

unsigned Car::getYearOfRegistration() const
{
	return this->yearOfRegistration;
}

void Car::setBrand(const char brand[128])
{
	if (strlen(brand) <= 0)
	{
		std::cout << "Invalid brand name\n";
		return;
	}
	this->brand = new char[strlen(brand) + 1];
	strcpy_s(this->brand, strlen(brand), brand);
}

void Car::setOwner(const Person& owner)
{
	this->owner.setFName(owner.getFName());
	this->owner.setLName(owner.getLName());
	this->owner.setGender(owner.getGender());
	this->owner.setYearOfBirth(owner.getYearOfBirth());
}

void Car::setYearOfRegistration(const unsigned& year)
{
	if (year > 2023 || year <= 0)
	{
		std::cout << "Invalid year of registration\n";
		return;
	}
	this->yearOfRegistration = year;
}