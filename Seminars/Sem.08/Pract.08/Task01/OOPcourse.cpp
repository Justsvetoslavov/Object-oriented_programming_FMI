#include "OOPcourse.h"

void OOPcourse::copyFrom(const OOPcourse& other) {
	_numberOfStudents = other._numberOfStudents;
	_arraySize = other._arraySize;

	_students = new Student * [_arraySize] {nullptr};

	for (int i = 0; i < _numberOfStudents; i++) {
		_students[i] = other._students[i];
	}

	_lecturer = other._lecturer;

	for (int i = 0; i < MAX_NUMBER_OF_ASSISTANTS; i++) {
		_assistants[i] = other._assistants[i];
	}

}

void OOPcourse::free() {
	// Delete the array of pointers, but not the actual students 
	delete[] _students;
	_students = nullptr;

	_lecturer = nullptr;
	_numberOfStudents = _arraySize = 0;

	for (int i = 0; i < MAX_NUMBER_OF_ASSISTANTS; i++) {
		_assistants[i] = nullptr;
	}
}

void OOPcourse::resize() {
	unsigned newArraySize = _arraySize * 2;
	Student** newStudentArray = new Student * [newArraySize] {nullptr};

	for (int i = 0; i < _arraySize; i++) {
		newStudentArray[i] = _students[i];
	}

	delete[] _students;
	_students = newStudentArray;
	_arraySize = newArraySize;
}

OOPcourse::OOPcourse() {
	_students = new Student * [_arraySize];
}

OOPcourse::OOPcourse(const OOPcourse& other) {
	copyFrom(other);
}

OOPcourse& OOPcourse::operator=(const OOPcourse& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

OOPcourse::~OOPcourse() {
	free();
}

void OOPcourse::addStudent(Student& st) {
	if (_numberOfStudents >= _arraySize) {
		resize();
	}

	_students[_numberOfStudents++] = &st;
}

void OOPcourse::addGrade(unsigned FN, const char* taskName, double gradeValue, const Teacher& teacher) {
	int foundInd = find(FN);
	if (foundInd < 0) {
		return;
	}

	_students[foundInd]->addGrade(gradeValue, taskName, teacher);
}

double OOPcourse::getAverageForCourse() const {
	double res = 0;
	unsigned totalNumberOfGrades = 0;

	for (int i = 0; i < _numberOfStudents; i++) {

		for (int j = 0; j < _students[i]->getNumberOfGrades(); j++) {
			res += _students[i]->getGradeValueAtIndex(j);
		}

		totalNumberOfGrades += _students[i]->getNumberOfGrades();
	}

	if (totalNumberOfGrades == 0) {
		return 0;
	}

	return res / totalNumberOfGrades;
}

bool OOPcourse::removeStudent(unsigned FN) {
	int foundInd = find(FN);
	if (foundInd < 0) {
		return false;
	}

	_students[foundInd] = _students[_numberOfStudents - 1];
	_numberOfStudents--;
}

double OOPcourse::getAverageGradePerTask(const char* taskName) const {
	double res = 0;
	unsigned numberOfStudents = 0;

	for (int i = 0; i < _numberOfStudents; i++) {
		int taskInd = _students[i]->getTaskIndex(taskName);

		if (taskInd >= 0) {
			res += _students[i]->getGradeValueAtIndex(taskInd);
			numberOfStudents++;
		}
	}

	if (numberOfStudents == 0) {
		return 0;
	}

	return res / numberOfStudents;
}

double OOPcourse::getAverageFromTeacher(const Teacher& teacher) const {
	double res = 0;
	unsigned numberOfStudents = 0;

	for (int i = 0; i < _numberOfStudents; i++) {
		const Grade* currentGrades = _students[i]->getGrades();

		for (int j = 0; j < _students[i]->getNumberOfGrades(); j++){
			if (currentGrades[j].getTeacher() == &teacher) {
				res += currentGrades[j].getValue();
				numberOfStudents++;
			}
		}
	}

	if (numberOfStudents == 0) {
		return 0;
	}

	return res / numberOfStudents;
}

int OOPcourse::find(unsigned FN) {
	for (int i = 0; i < _numberOfStudents; i++) {
		if (_students[i]->getFN() == FN) {
			return i;
		}
	}
	return -1;
}

OOPcourse::OOPcourse(Teacher* lecturer, Teacher* a1, Teacher* a2, Teacher* a3) : OOPcourse(){
	_lecturer = lecturer;
	_assistants[0] = a1;
	_assistants[1] = a2;
	_assistants[2] = a3;
}

std::ostream& operator << (std::ostream& os, const OOPcourse& c) {
	for (int i = 0; i < c._numberOfStudents; i++) {
		os << *c._students[i];
	}

	os << *c._lecturer << std::endl;

	for (int i = 0; i < MAX_NUMBER_OF_ASSISTANTS && c._assistants[i] != nullptr; i++) {
		os << *c._assistants[i] << ' ';
	}
	os << std::endl;

	return os;
}

void OOPcourse::changeGrade(unsigned FN, const char* taskName, double newGrade) {
	int studentInd = find(FN);
	if (studentInd < 0) {
		return;
	}

	int taskInd = _students[studentInd]->getTaskIndex(taskName);
	if (taskInd < 0) {
		return;
	}

	_students[studentInd]->setGradeAtIndex(taskInd, newGrade);
}