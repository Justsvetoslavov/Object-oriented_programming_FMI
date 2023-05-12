#include "OOPCourse.h"
#include <sstream>

OOPCourse::OOPCourse(const Teacher* teacher, const Teacher* as1, const Teacher* as2, const Teacher* as3) {
	if (teacher == nullptr)
		throw std::invalid_argument("The name doesn't exist");

	teachers[0] = *teacher;
	teachersCount = 1;
	if (as1 != nullptr) {
		teachers[1] = *as1;
		teachersCount++;
		if (as2 != nullptr) {
			teachers[2] = *as2;
			teachersCount++;
			if (as3 != nullptr) {
				teachers[3] = *as3;
				teachersCount++;
			}
		}
	}

	students = new Student * [studentsCapacity];
}

OOPCourse::OOPCourse(const OOPCourse& other){
	copyFrom(other);
}

OOPCourse& OOPCourse::operator=(const OOPCourse& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

OOPCourse::~OOPCourse(){
	free();
}

void OOPCourse::AddStudent(const char* name, int facultyNumber) {
	if (studentsCount >= studentsCapacity)
		Resize();

	students[studentsCount++] = new Student(name, facultyNumber);
}

void OOPCourse::AddGrade(int facNum, const char* task, int grade, const Teacher* teacher){
	int index = IndexOfStudent(facNum);
	if (index == -1)
		throw std::invalid_argument("There is no student with such faculty number!");

	students[index]->SetGrade(task, grade, teacher);
}

void OOPCourse::ChangeGrade(int facNum, const char* task, int newGrade, const Teacher* teacher){
	int index = IndexOfStudent(facNum);
	if (index == -1)
		throw std::invalid_argument("There is no student with such faculty number!");

	students[index]->ChangeGrade(task, newGrade, teacher);
}

int OOPCourse::IndexOfStudent(int facNum) const{
	for (int i = 0; i < studentsCount; i++) {
		if (students[i]->GetFN() == facNum)
			return i;
	}
	return -1;
}

double OOPCourse::GetAverageForCourse() const{
	double average = 0;
	int count = 0;
	for (int i = 0; i < studentsCount; i++) {
		for (int j = 0; j < students[i]->gradesCount; j++) {
			average += students[i]->grades[j].GetGrade();
			count++;
		}
	}
	if (count == 0)
		return 0;
	return average / count;
}

void OOPCourse::RemoveStudent(int facNum){
	int index = IndexOfStudent(facNum);
	if (index == -1)
		throw std::invalid_argument("There is no such student!\n");

	delete students[index];
	for (int i = index; i < studentsCount - 1; i++) {
		students[i] = students[i + 1];
	}
	studentsCount--;
}

double OOPCourse::GetAverageGradePerTask(const char* task) const{
	double average = 0;
	int count = 0;
	for (int i = 0; i < studentsCount; i++) {
		for (int j = 0; j < students[i]->gradesCount; j++) {
			if (!strcmp(students[i]->grades[j].GetTask().c_str(), task)) {
				average += students[i]->grades[j].GetGrade();
				count++;
			}
		}
	}
	if (count == 0)
		return 0;
	return average / count;
}

double OOPCourse::GetAverageFromTeacher(const char* teacher) const{
	if (!teacher)
		throw std::invalid_argument("Teacher name doesn't exist!");

	double average = 0;
	int count = 0;
	for (int i = 0; i < studentsCount; i++) {
		for (int j = 0; j < students[i]->gradesCount; j++) {
			if (!strcmp(students[i]->grades[j].GetTeacher(), teacher)) {
				average += students[i]->grades[j].GetGrade();
				count++;
			}
		}
	}
	if (count == 0)
		return 0;
	return average / count;
}

void OOPCourse::free(){
	for (int i = 0; i < studentsCount; i++)
		delete students[i];
	delete[] students;
	students = nullptr;
	studentsCapacity = 2;
	studentsCount = teachersCount = 0;
}

void OOPCourse::copyFrom(const OOPCourse& other){
	for (int i = 0; i < other.teachersCount; i++) {
		teachers[i] = other.teachers[i];
	}
	teachersCount = other.teachersCount;
	students = new Student*[other.studentsCapacity];
	for (int i = 0; i < other.studentsCount; i++) {
		students[i] = new Student(*other.students[i]);
	}
	studentsCapacity = other.studentsCapacity;
	studentsCount = other.studentsCount;
}

void OOPCourse::Resize() {
	studentsCapacity *= 2;
	Student** temp = new Student * [studentsCapacity];
	for (int i = 0; i < studentsCount; i++) {
		temp[i] = students[i];
	}
	delete[] students;
	students = temp;
}
