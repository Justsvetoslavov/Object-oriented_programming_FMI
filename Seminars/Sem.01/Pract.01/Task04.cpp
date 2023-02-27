#include <iostream>

const int NAME_SIZE = 30;

struct Student
{
	char name[NAME_SIZE + 1];
	unsigned int fn;
};

void initSTudent(Student& student)
{
	std::cout << "Enter name: ";
	std::cin.getline(student.name, NAME_SIZE + 1);
	std::cout << "Enter faculty number: ";
	std::cin >> student.fn;
	std::cin.ignore();
}

void printStudent(const Student& student) {
	std::cout << "Name: " << student.name <<std:: endl;
	std::cout << "Faculty number: " << student.fn << std::endl;
}

int main()
{
	Student student{};
	initSTudent(student);
	printStudent(student);
	
	Student st = { "Gosho", 10 };
	printStudent(st);

	Student* pSt = &st;
	printStudent(*pSt);

	const Student* pCSt = &st;
	printStudent(*pCSt);

	Student* const cPSt = &st;
	printStudent(*cPSt);

	const Student* const cpCSt = &st;
	printStudent(*cpCSt);

	Student& refSt = st;
	printStudent(refSt);

	const Student& refCSt = st;
	printStudent(refCSt);

	//the function does work with all of the operations above
}