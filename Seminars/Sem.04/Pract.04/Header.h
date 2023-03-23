#pragma once

const int MAX_TEACHER_NAME_LENGTH = 25;

class teacher {
	char name[MAX_TEACHER_NAME_LENGTH + 1];
	unsigned age;
	unsigned yearsInternship;
	void SetDefaultName();
	void SetDefaultAge();
	void SetDefaultYearsInternship();
	bool IsNameValid(char* name) const;
	bool IsAgeValid(unsigned age) const;
	bool IsYearsInternshipValid(unsigned yearsOfInternship) const;
public:
	teacher();
	teacher(char* name, unsigned age, unsigned yearsInternship);
	const char* GetName() const;
	unsigned GetAge() const;
	unsigned GetYearsInternship() const;
	void SetName(char* newName);
	void SetAge(unsigned newAge);
	void SetYearsInternship(unsigned newYearsInternship);
};