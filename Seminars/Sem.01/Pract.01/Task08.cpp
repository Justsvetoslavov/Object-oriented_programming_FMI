#include <iostream>

const int MAX_SIZE_NAME = 30;
const int MAX_GROUP_SIZE = 30;

struct Student
{
	char name[MAX_SIZE_NAME + 1];
	unsigned int fn;
	double grade;
};

struct StudentGroup
{
	size_t amountOfStudents;
	double averageGrade;
	Student groupArr[MAX_GROUP_SIZE];
};

double FindSum(const Student* arr, int numberOfStudents)
{
	double sum = 0;
	for (size_t i = 0; i < numberOfStudents; i++) {
		sum += arr[i].grade;
	}

	return sum;
}

void InitGroupOfStudents(StudentGroup& group)
{
	for (size_t i = 0; i < group.amountOfStudents; i++) {
		std::cin >> group.groupArr[i].fn;
		std::cin >> group.groupArr[i].name;
		std::cin.ignore();
		std::cin >> group.groupArr[i].grade;
	}

	group.averageGrade = FindSum(group.groupArr, group.amountOfStudents) / group.amountOfStudents;
}

size_T NumberOfStudentsTakingScholarship(const StudentGroup& group, const double minGrade) {
	size_t studentCounter = 0;

	for (size_t i = 0; i < group.amountOfStudents; i++) {
		if (group.groupArr[i].grade >= minGrade) {
			studentCounter++;
		}
	}

	return studentCounter;
}

void Swap(Student& a, Student& b) {
	Student temp = a;
	a = b;
	b = temp;
}

void SortStudentsByGrade(Student* students, const int size) {
	for (size_t i = 0; i < size - 1; i++) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < size; j++) {
			if (students[j].grade < students[minIndex].grade) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			Swap(students[minIndex], students[i]);
		}
	}

}

void PrintStudent(const Student& student) {
	std::cout << "Faculty number: " << student.FN << ", Name: " << student.name <<
		", Grade: " << student.grade << std::endl;
}

void StudentsTakingScholarship(StudentGroup& group, const double minGrade)
{
	size_T numberOfStudents = NumberOfStudentsTakingScholarship(group, minGrade);
	SortStudentsByGrade(group.groupArr, group.amountOfStudents);
	
	for (size_t i = group.amountOfStudents - 1; i >= group.amountOfStudents - numberOfStudents; i--){
		PrintStudent(group.groupArr[i]);
	}
}

int main()
{
	StudentGroup group;
	std::cin >> group.amountOfStudents;
	
	initGroupOfStudents(group);
	studentsTakingScholarship(group, 5);
}