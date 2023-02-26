#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

const int MAX_NAME_SIZE = 31;
const double EPSYLON = 0.0000001;

// return true if second is bigger, else false
bool compareDoubles(const double firstNum, const double secondNum)
{
	return (secondNum - firstNum) > EPSYLON;
}

// 8
struct Student
{
	double grade;
	char name[MAX_NAME_SIZE];
};

struct Group
{
	Student* students;
	double averageGrade;
	int numberOfStudents;
	char major[MAX_NAME_SIZE];
};

void initStudent(Student& student)
{
	cout << "Student grade: ";
	cin >> student.grade;
	cout << endl;
	cin.ignore();
	cout << "Student name: ";
	cin >> student.name;
	cout << endl;
}

void calculateAverageGrade(Group& group)
{
	double sum = 0;

	for (size_t i = 0; i < group.numberOfStudents; i++)
	{
		sum += group.students[i].grade;
	}

	double averageGrade = sum / group.numberOfStudents;
	group.averageGrade = averageGrade;

}

void initGroup(const int numberOfStudents, Group& group)
{
	cin.ignore();
	cout << "Group major: ";
	cin >> group.major;
	cout << endl;

	group.numberOfStudents = numberOfStudents;
	group.students = new Student[numberOfStudents];

	for (size_t i = 0; i < numberOfStudents; i++)
	{
		Student student;
		initStudent(student);
		group.students[i] = student;
	}

	calculateAverageGrade(group);
}

int getCountOfStudentsReceivingScolarship(const double minimumGrade, const Group& group)
{
	int count = 0;

	for (size_t i = 0; i < group.numberOfStudents; i++)
	{
		if (compareDoubles(minimumGrade, group.students[i].grade))
		{
			count++;
		}
	}

	return count;
}

Student* GetStudentsReceivingScolarship(const double minimumGrade, const Group& group)
{
	int index = 0;
	int count = getCountOfStudentsReceivingScolarship(minimumGrade, group);
	Student* studentsReceivingScolarship = new Student[count];

	for (size_t i = 0; i < group.numberOfStudents; i++)
	{
		if (compareDoubles(minimumGrade, group.students[i].grade))
		{
			studentsReceivingScolarship[index++] = group.students[i];
		}
	}

	return studentsReceivingScolarship;
}

void sortStudentsByGrade(Student* studentsReceivingScolarship, const int count)
{
	for (size_t i = 0; i < count - 1; i++)
	{
		size_t indexOfMaxElement = i;
		for (size_t j = 0; j < count - i - 1; j++)
		{
			if (compareDoubles(studentsReceivingScolarship[indexOfMaxElement].grade, studentsReceivingScolarship[j].grade))
			{
				indexOfMaxElement = j;
			}
		}

		swap(movies[i], movies[indexOfMaxElement]);
	}
}

void printStudentsReceivingScolarshipSortedByGrade(const double minimumGrade, const Group& group)
{
	Student* studentsReceivingScolarship = GetStudentsReceivingScolarship(minimumGrade, group);
	int count = getCountOfStudentsReceivingScolarship(minimumGrade, group);

	sortStudentsByGrade(studentsReceivingScolarship, count);

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

	printStudentsReceivingScolarshipSortedByGrade(4.5, group);
}