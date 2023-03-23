#include <iostream>
#include <cstring>
#include "Header.h"

const int MAX_TEACHER_NAME_LENGTH = 25;

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

char* teacher::GetName() {
	return name;
}

unsigned teacher::GetAge() {
	return age;
}

unsigned teacher::GetYearsInternship() {
	return yearsInternship;
}

void teacher::SetDefaultName() {
	strcpy(name, "Unknown");
}

void teacher::SetDefaultAge() {
	age = 18;
}

void teacher::SetDefaultYearsInternship() {
	yearsInternship = 0;
}

bool teacher::IsNameValid(char* name) {
	unsigned nameLength = strlen(name);
	if (nameLength < 3 || nameLength > MAX_TEACHER_NAME_LENGTH)
		return false;
	if (!IsUpper(name[0]))
		return false;
	for (size_t i = 0; i < nameLength; i++) {
		if (!IsLower(name[i]))
			return false;
	}
	return true;
}

bool teacher::IsAgeValid(unsigned age) {
	return age >= 18 && age <= 100;
}

bool teacher::IsYearsInternshipValid(unsigned yearsOfInternship) {
	return yearsInternship <= 80;
}

void teacher::SetName(char* newName) {
	if (!IsNameValid(newName)) {
		SetDefaultName();
		return;
	}
	strcpy(name, newName);
}

void teacher::SetAge(unsigned newAge) {
	if (!IsAgeValid(age)) {
		SetDefaultAge();
		return;
	}
	age = newAge;
}

void teacher::SetYearsInternship(unsigned newYearsInternship) {
	if (!IsYearsInternshipValid(newYearsInternship)) {
		SetDefaultYearsInternship();
		return;
	}
	yearsInternship = newYearsInternship;
}

int main() {
	teacher t;
	std::cout << t.GetAge();
}