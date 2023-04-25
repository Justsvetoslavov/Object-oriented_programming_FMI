#pragma once

class Person
{
private:
	char* fName;
	char* lName;
	char gender;
	unsigned yearOfBirth;
public:
	Person();
	Person(const char* fName, const char* lName, const char gender, const unsigned yearOfBirth);
	Person(const Person& person);
	Person& operator=(const Person & other);
	~Person();

	char* getFName() const;
	char* getLName() const;
	char getGender() const;
	unsigned getYearOfBirth() const;

	void setFName(const char* fName);
	void setLName(const char* lName);
	void setGender(const char gender);
	void setYearOfBirth(const unsigned year);
};