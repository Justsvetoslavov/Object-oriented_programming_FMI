#include <iostream>
#include <cstring>
#include "Header.h"

bool IsUpper(char ch) {
	return ch >= 'A' && ch <= 'Z';
}
bool IsLower(char ch) {
	return ch >= 'a' && ch <= 'z';
}

teacher::teacher() {
	SetDefaultName();
	SetDefaultAge();
	SetDefaultYearsInternship();
}

teacher::teacher(char* name, unsigned age, unsigned yearsInternship) {
	SetName(name);
	SetAge(age);
	SetYearsInternship(yearsInternship);
}

const char* teacher::GetName() const {
	return name;
}

unsigned teacher::GetAge() const {
	return age;
}

unsigned teacher::GetYearsInternship() const {
	return yearsInternship;
}

void teacher::SetDefaultName() {
	strcpy_s(name, "Unknown");
}

void teacher::SetDefaultAge() {
	age = 18;
}

void teacher::SetDefaultYearsInternship() {
	yearsInternship = 0;
}

bool teacher::IsNameValid(char* name) const {
	unsigned nameLength = strlen(name);
	if (nameLength < 3 || nameLength > MAX_TEACHER_NAME_LENGTH)
		return false;
	if (!IsUpper(name[0]))
		return false;
	for (size_t i = 1; i < nameLength; i++) {
		if (!IsLower(name[i]))
			return false;
	}
	return true;
}

bool teacher::IsAgeValid(unsigned age) const {
	return age >= 18 && age <= 100;
}

bool teacher::IsYearsInternshipValid(unsigned yearsOfInternship) const {
	return yearsInternship <= 80;
}

void teacher::SetName(char* newName) {
	if (!IsNameValid(newName)) {
		//error message
		return;
	}
	strcpy_s(name, newName);
}

void teacher::SetAge(unsigned newAge) {
	if (!IsAgeValid(age)) {
		//error message
		return;
	}
	age = newAge;
}

void teacher::SetYearsInternship(unsigned newYearsInternship) {
	if (!IsYearsInternshipValid(newYearsInternship)) {
		//error message
		return;
	}
	yearsInternship = newYearsInternship;
}

int main() {
	teacher t;
	char name[MAX_TEACHER_NAME_LENGTH] = "Ivan";
	t.SetName(name);
	t.SetAge(20);
	t.SetYearsInternship(1);
	std::cout << t.GetName() << std::endl;
	std::cout << t.GetAge() << std::endl;
	std::cout << t.GetYearsInternship() << std::endl;
}