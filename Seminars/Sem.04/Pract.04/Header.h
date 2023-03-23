#pragma once


class teacher {
	char name[MAX_TEACHER_NAME_LENGTH + 1];
	unsigned age;
	unsigned yearsInternship;
	void SetDefaultName();
	void SetDefaultAge();
	void SetDefaultYearsInternship();
	bool IsNameValid(char* name);
	bool IsAgeValid(unsigned age);
	bool IsYearsInternshipValid(unsigned yearsOfInternship);
public:
	teacher();
	teacher(char* name, unsigned age, unsigned yearsInternship);
	char* GetName();
	unsigned GetAge();
	unsigned GetYearsInternship();
	void SetName(char* newName);
	void SetAge(unsigned newAge);
	void SetYearsInternship(unsigned newYearsInternship);
};