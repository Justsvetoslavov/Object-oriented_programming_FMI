#include "Person.h"
#include <iostream>

Person::Person() : Person("n/n", "n/n", 'm', 2000)
{

}

Person::Person(const char* fName, const char* lName, const char gender, const unsigned yearOfBirth)
{
	setFName(fName);
	setLName(lName);
	setGender(gender);
	setYearOfBirth(yearOfBirth);
}

Person::Person(const Person& person) : Person(person.getFName(), person.getLName(), person.getGender(), person.getYearOfBirth()) {}

Person& Person::operator=(const Person& other)
{
	delete[] this->fName;
	this->setFName(other.getFName());
	delete[] this->lName;
	this->setLName(other.getLName());
	this->setGender(other.getGender());
	this->setYearOfBirth(other.getYearOfBirth());
	return *this;
}

Person::~Person()
{
	delete[] this->fName;
	delete[] this->lName;
}

char* Person::getFName() const
{
	return this->fName;
}
char* Person::getLName() const
{
	return this->lName;
}
char Person::getGender() const
{
	return this->gender;
}
unsigned Person::getYearOfBirth() const
{
	return this->yearOfBirth;
}

void Person::setFName(const char* fName)
{
	if (strlen(fName) <= 0)
	{
		std::cout << "Invalid first name\n";
		return;
	}
	this->fName = new char[strlen(fName) + 1];
	strcpy_s(this->fName, strlen(fName), fName);
}
void Person::setLName(const char* lName)
{
	if (strlen(lName) <= 0)
	{
		std::cout << "Invalid last name\n";
		return;
	}
	this->lName = new char[strlen(lName) + 1];
	strcpy_s(this->lName, strlen(lName), lName);
}
void Person::setGender(const char gender)
{
	if (gender != 'f' && gender != 'm')
	{
		std::cout << "Invalid gender (options: m f)\n";
		return;
	}
	this->gender = gender;
}
void Person::setYearOfBirth(const unsigned year)
{
	if (year > 2023 || year <= 0)
	{
		std::cout << "Invalid year of birth\n";
		return;
	}
	this->yearOfBirth = year;
}