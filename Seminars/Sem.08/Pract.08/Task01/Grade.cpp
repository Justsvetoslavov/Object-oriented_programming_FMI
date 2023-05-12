#include "Grade.h"
#include <sstream>

Grade::Grade(int grade) {
	SetGrade(grade);
}

Grade::Grade(const char* task, int grade, const Teacher* teacher) {
	this->task = task;
	SetGrade(grade);
	this->teacher = teacher;
}

const String& Grade::GetTask() const{
	return task;
}

int Grade::GetGrade() const{
	return grade;
}

const char* Grade::GetTeacher() const{
	return teacher->GetName();
}

void Grade::SetGrade(int grade) {
	if (grade < 2 || grade > 6)
		throw std::invalid_argument("Grade must be between 2 and 6!");

	this->grade = grade;
}
