#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

const int MAX_NAME_SIZE = 30;
const double EPSYLON = 0.0000001;

// 8
struct StudentInGroup
{
	double grade;
	char name[MAX_NAME_SIZE];
};

struct Group
{
	StudentInGroup* students;
	double averageGrade;
	int numberOfStudents;
	char major[MAX_NAME_SIZE];
};

void initStudentInGroup(StudentInGroup& student)
{
	cout << "Student grade: ";
	cin >> student.grade;
	cout << endl;
	cin.ignore();
	cout << "Student name: ";
	cin >> student.name;
	cout << endl;
}

void calculateGroupAverageGrade(Group& group)
{
	double sum = 0;

	for (size_t i = 0; i < group.numberOfStudents; i++)
	{
		sum += group.students[i].grade;
	}

	double averageGrade = sum / group.numberOfStudents;
	group.averageGrade = averageGrade;

}

void initGroup(const int& numberOfStudents, Group& group)
{
	cin.ignore();
	cout << "Group major: ";
	cin >> group.major;
	cout << endl;

	group.numberOfStudents = numberOfStudents;
	group.students = new StudentInGroup[numberOfStudents];

	for (size_t i = 0; i < numberOfStudents; i++)
	{
		StudentInGroup student;
		initStudentInGroup(student);
		group.students[i] = student;
	}

	calculateGroupAverageGrade(group);
}

int getStudentsReceivingScolarshipCount(const double& minimumGrade, const Group& group)
{
	int count = 0;

	for (size_t i = 0; i < group.numberOfStudents; i++)
	{
		bool isStudentReceivingScolarship = isSecondBiggerThanFirst(minimumGrade, group.students[i].grade);
		if (isStudentReceivingScolarship)
		{
			count++;
		}
	}

	return count;
}

StudentInGroup* GetStudentsReceivingScolarship(const double& minimumGrade, const Group& group)
{
	int index = 0;
	int count = getStudentsReceivingScolarshipCount(minimumGrade, group);
	StudentInGroup* studentsReceivingScolarship = new StudentInGroup[count];

	for (size_t i = 0; i < group.numberOfStudents; i++)
	{
		bool isStudentReceivingScolarship = isSecondBiggerThanFirst(minimumGrade, group.students[i].grade);
		if (isStudentReceivingScolarship)
		{
			studentsReceivingScolarship[index++] = group.students[i];
		}
	}

	return studentsReceivingScolarship;
}

void sortStudents(StudentInGroup* studentsReceivingScolarship, const int& count)
{
	for (size_t i = 0; i < count - 1; i++)
	{
		for (size_t j = 0; j < count - i - 1; j++)
		{
			if (isSecondBiggerThanFirst(studentsReceivingScolarship[j].grade, studentsReceivingScolarship[j + 1].grade))
			{
				swap(studentsReceivingScolarship[j].grade, studentsReceivingScolarship[j + 1].grade);
			}
		}
	}
}

void printStudentsReceivingSalarySortedByGrade(const double& minimumGrade, const Group& group)
{
	StudentInGroup* studentsReceivingScolarship = GetStudentsReceivingScolarship(minimumGrade, group);
	int count = getStudentsReceivingScolarshipCount(minimumGrade, group);

	sortStudents(studentsReceivingScolarship, count);

	for (size_t i = 0; i < count; i++)
	{
		cout << i + 1 << ". ";
		cout << "Student grade: ";
		cout << studentsReceivingScolarship[i].grade;
		cout << endl;
		cout << "Student name: ";
		cout << studentsReceivingScolarship[i].name;
		cout << endl;
	}
}

int main()
{
	int numberOfStudents;
	cout << "Number of students: ";
	cin >> numberOfStudents;
	Group group;
	initGroup(numberOfStudents, group);

	printStudentsReceivingSalarySortedByGrade(4.5, group);
}