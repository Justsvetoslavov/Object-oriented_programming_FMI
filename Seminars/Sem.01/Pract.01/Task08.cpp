#include <iostream>

const int NAME_SIZE = 30;
const int NUMBER_OF_STUDENTS_IN_GROUP = 3;

struct Student {
	char name[NAME_SIZE + 1];
	double grade;
};

void InitStudent(Student& student) {
	std::cout << "Name: ";
	std::cin >> student.name;
	std::cout << "Grade: ";
	std::cin >> student.grade;
	
}

void PrintStudent(const Student& student) {
	std::cout << "Name: " << student.name << std::endl;
	std::cout << "Grade: " << student.grade << std::endl;
}

struct Group {
	Student students[NUMBER_OF_STUDENTS_IN_GROUP];
	double average;
};

double GetAverage(const Student* students) {
	double sumOfGrades = 0;
	for (size_t i = 0; i < NUMBER_OF_STUDENTS_IN_GROUP; i++)
	{
		sumOfGrades += students[i].grade;
	}
	return sumOfGrades / NUMBER_OF_STUDENTS_IN_GROUP;
}

void MakeGroup(Group& group) {
	for (size_t i = 0; i < NUMBER_OF_STUDENTS_IN_GROUP; i++)
	{
		Student student;
		InitStudent(student);
		group.students[i] = student;
	}
	double average = GetAverage(group.students);
	group.average = average;
}

int CalculateCountOfScolarship(const Group& group, double minimalGradeForScolarship) {
	int count = 0;

	for (size_t i = 0; i < NUMBER_OF_STUDENTS_IN_GROUP; i++)
	{
		if (group.students[i].grade >= minimalGradeForScolarship)
		{
			count++;
		}
	}

	return count;
}

void SortGroupByScolarship(Group& group) {
	for (size_t i = 0; i < NUMBER_OF_STUDENTS_IN_GROUP; i++)
	{
		int maxScolarshipStudent = i;

		for (size_t j = 0; j < NUMBER_OF_STUDENTS_IN_GROUP; j++)
		{
			if (group.students[j].grade < group.students[maxScolarshipStudent].grade) {
				maxScolarshipStudent = j;
			}
		}
		if (maxScolarshipStudent != i) {
			std::swap(group.students[maxScolarshipStudent], group.students[i]);
		}
	}
}

int main()
{
	Group studentsGroup;
	MakeGroup(studentsGroup);

	std::cout << "Group average grade: " << studentsGroup.average << std::endl;

	double minimalGrade = 4.80;
	int countOfScolarship = CalculateCountOfScolarship(studentsGroup, minimalGrade);
	std::cout << "Number of students getting scolarship: " << countOfScolarship << std::endl;

	SortGroupByScolarship(studentsGroup);

	std::cout << "Students getting scolarship: " << std::endl;
	for (size_t i = 0; i < countOfScolarship; i++)
	{
		PrintStudent(studentsGroup.students[i]);
	}
}
