#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_NAME_SIZE = 31;

void copyStr(char* copy, const int copyLenght, const char* arr, const int arrLength)
{
	if (copyLenght >= arrLength)
	{
		int count = 0;

		while (arr[count] != '\0')
		{
			copy[count] = arr[count];
			count++;
		}

		copy[count] = '\0';
	}
}

int getStrLength(const char* str)
{
	int count = 0;

	while (str[count] != '\0') { count++; }	

	return count;
}

struct Student
{
	unsigned int facultyNumber;
	char name[MAX_NAME_SIZE];
};

void initStudent(Student& student, const char* name, const unsigned int facultyNumber)
{
	if (getStrLength(name) <= MAX_NAME_SIZE)
	{
		copyStr(student.name, getStrLength(student.name), name, getStrLength(name));
		student.facultyNumber = facultyNumber;
	}
}

void printStudentInfo(const Student& student)
{	
	cout << "Student:" << endl << "Name: " << student.name << endl << "FN: " << student.facultyNumber;
}

int main()
{
	Student st = { "Gosho", 10 }; // can be predefined, properties can be changed
	Student* pSt = &st; // can be predefined, properties can be changed
	const Student* pCSt = &st; // can be predefined, properties cannot be changed
	Student* const cPSt = &st; // cannot be predefined, properties can be changed
	const Student* const cpCSt = &st; // cannot be predefined, properties cannot be changed
	Student& refSt = st; // can be predefined, properties can be changed
	const Student& refCSt = st; // cannot be predefined, properties cannot be changed

	Student student;
	initStudent(student, "Pesho", 20);
	printStudentInfo(student);
}