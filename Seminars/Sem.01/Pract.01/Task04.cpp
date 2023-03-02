#include <iostream>

const int NAME_SIZE = 30;

struct Student {
	char name[NAME_SIZE + 1];
	unsigned int facultyNumber;
};

void InitStudent(Student& student) {
	std::cout << "Enter student name: ";
	std::cin.getline(student.name, 31);
	std::cout << "Enter student faculty number: ";
	std::cin >> student.facultyNumber;
}

void PrintStudent(const Student& student) {
	std::cout << "Name: " << student.name << std::endl;
	std::cout << "Faculty number: " << student.facultyNumber << std::endl;
}

int main()
{
	Student myStudent;

	InitStudent(myStudent);
	PrintStudent(myStudent);
}
