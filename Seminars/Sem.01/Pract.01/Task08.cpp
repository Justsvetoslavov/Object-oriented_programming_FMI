#include <iostream>

using namespace std;

const int FIRST = 1;
const int SECOND = 2;
const int THIRD = 3;
const int FOURTH = 4;

struct Student
{
	char name[30];
	char surname[30];
	int fn;
	int year;
	double gpa;
};

void studentInfo(Student& student)
{
	cout << "Enter first name: ";
	cin >> student.name;

	cout << "Enter surname: ";
	cin >> student.surname;

	cout << "Enter falcultety number: ";
	cin >> student.fn;

	cout << "Enter a year (please, enter a number): ";
	cin >> student.year;
	switch (student.year)
	{
	case 1:
		cout << "First" << endl;
		break;
	case 2:
		cout << "Second" << endl;
		break;
	case 3:
		cout << "Third" << endl;
		break;
	case 4:
		cout << "Fourth" << endl;
		break;
	default:
		cout << "Error" << endl;
	}

	cout << "Enter gpa: ";
	cin >> student.gpa;
	cout << endl;
}

const int GROUP_SIZE = 3;

struct Group
{
	Student student[GROUP_SIZE];
	double groupGpa;
};

void createGroup(Group& group)
{
	group.groupGpa = 0.0;
	for (size_t i = 1; i < GROUP_SIZE; i++)
	{
		cout << "Enter student #" << i << " information: " << endl;
		studentInfo(group.student[i]);
		group.groupGpa += group.student[i].gpa;
	}
	group.groupGpa /= GROUP_SIZE;
}

int countScholarshipStudents(const Group& group, double minGpa)
{
	int scholarshipCount = 0;
	for (size_t i = 0; i < GROUP_SIZE; i++)
	{
		if (group.student[i].gpa >= minGpa)
			scholarshipCount++;
	}
	return scholarshipCount;
}

void sortStudentsByGpa(Group& group)
{
	int n = GROUP_SIZE;
	bool swapped;
	do
	{
		swapped = false;
		for (size_t i = 1; i < n - 1; i++)
		{
			if (group.student[i].gpa < group.student[i + 1].gpa)
				swap(group.student[i], group.student[i + 1]);
			swapped = true;
		}
		n--;
	} while (swapped);
}

void printStudents(Group& group, double minGpa)
{
	for (size_t i = 1; i < GROUP_SIZE; i++)
	{
		if (group.student[i].gpa >= minGpa)
			cout << group.student[i].name << " " << group.student[i].surname << " " << group.student[i].gpa << endl;
	}
}

int main()
{
	Group group;
	createGroup(group);

	cout << "Group gpa is: " << group.groupGpa << endl;
	cout << "Enter the minimum scholarship: ";
	double minGpa;
	cin >> minGpa;
	int scholarshipCount = countScholarshipStudents(group, minGpa);
	cout << "Number of students receiving a scholarship: " << scholarshipCount << endl;
	cout << "Scholarship students (sorted by gpa):" << endl;
	sortStudentsByGpa(group);
	printStudents(group, minGpa);

	return 0;
}