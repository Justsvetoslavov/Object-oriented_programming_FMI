#include <iostream>

using std::cin;
using std::cout;

const int MAX_SIZE_NAME = 31;

struct Student
{
	unsigned int FN;
	char name[MAX_SIZE_NAME];
};

void initStudent(Student& student)
{
	cin >> student.name >> student.FN;
}

void printStudentInfo(const Student& student)
{
	cout << "The name of the student is: " << student.name << ". And the Fn is: " << student.FN;
}