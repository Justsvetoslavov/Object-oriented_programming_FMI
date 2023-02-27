#include <iostream>

using std::cin;
using std::cout;

const int MAX_SIZE_NAME = 31;

struct Student
{
	double grade;
	unsigned int FN;
	char name[MAX_SIZE_NAME];
};

struct StudentGroup
{
	double averageGrade;
	int amountOfStudents;
	Student* groupArr;
};

void initGroupOfStudents(StudentGroup& group)
{
	double sumOfGrades{};

	for (int i = 0; i < group.amountOfStudents; i++)
	{
		cin >> group.groupArr->FN >> group.groupArr->name >> group.groupArr->grade;

		sumOfGrades += group.groupArr->grade;

		group.groupArr++;
	}

	group.averageGrade = sumOfGrades / group.amountOfStudents;

	//returning the pointer to the start
	for (int i = 0; i < group.amountOfStudents; i++)
	{
		group.groupArr--;
	}

}

int amountStudentsTakeScholarship(StudentGroup& group, const double minGrade)
{
	int studentCounter{};

	for (int i = 0; i < group.amountOfStudents; i++)
	{
		if (group.groupArr->grade >= minGrade)
		{
			studentCounter++;
		}
		group.groupArr++;
	}

	//returning the pointer to the start
	for (int i = 0; i < group.amountOfStudents; i++)
	{
		group.groupArr--;
	}

	return studentCounter;
}

void mySwap(Student& a, Student& b)
{
	Student temp = a;
	a = b;
	b = temp;
}

void sortStudentsByGrade(Student* students, const int size)
{
	int min_idx{};

	for (int i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (int j = i + 1; j < size; j++)
		{
			if (students[j].grade < students[min_idx].grade)
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			mySwap(students[min_idx], students[i]);
		}
	}
}

void printStudent(const Student& student)
{
	cout << "Faculty number: " << student.FN << ", Name: " << student.name <<
		", Grade: " << student.grade << std::endl;
}

bool isTakingScholarship(Student* students, const int pos, const double minGrade)
{
	if (students[pos].grade >= minGrade)
	{
		return true;
	}

	return false;
}

void studentsTakeScholarship(StudentGroup& group, const double minGrade)
{
	int amountAgreedStudents = amountStudentsTakeScholarship(group, minGrade);

	Student* agreedStudents = new Student[amountAgreedStudents];

	int j{};

	for (int i = 0; i < group.amountOfStudents; i++)
	{
		if (isTakingScholarship(group.groupArr, i, minGrade) == true)
		{
			agreedStudents[j] = group.groupArr[i];
			j++;
		}
	}

	sortStudentsByGrade(group.groupArr, amountAgreedStudents);

	for (int i = 0; i < amountAgreedStudents; i++)
	{
		printStudent(agreedStudents[i]);
	}

}

int main()
{
	StudentGroup group{};

	cin >> group.amountOfStudents;

	group.groupArr = new Student[group.amountOfStudents];

	initGroupOfStudents(group);

	studentsTakeScholarship(group, 5);
}