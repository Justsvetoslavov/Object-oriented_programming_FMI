#include "Student.h"
#include <sstream>

void Student::SetGrade(const char* type, int grade, const Teacher* teacher){
	if (gradesCount >= 7)
		throw std::out_of_range("This student has reached the maximum capacity of grades!\n");

	for (int i = 0; i < gradesCount; i++) {
		if (!strcmp(grades[i].GetTask().c_str(), type))
			throw std::exception("The student already has a grade\n");
	}
	grades[gradesCount++] = Grade(type, grade, teacher);
}

void Student::ChangeGrade(const char* type, int grade, const Teacher* teacher){
	for (int i = 0; i < gradesCount; i++) {
		if (!strcmp(grades[i].GetTask().c_str(), type)) {
			grades[i] = Grade(type, grade, teacher);
			return;
		}
	}
	throw std::invalid_argument("There is no such type of grade!\n");
}

Student::Student(const char* name, int facultyNumber){
	this->name = name;
	this->facultyNumber = facultyNumber;
}

int Student::GetFN() const{
	return facultyNumber;
}
