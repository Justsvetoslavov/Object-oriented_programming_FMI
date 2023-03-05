// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Students {
	char first_name[20];
	char second_name[20];
	char third_name[20];
	double finalGrade;
};
double finaleGrade(double* grades,int numberOfGrades) {
	double sum = 0;
	for (int i = 0; i < numberOfGrades; i++) {
		sum += grades[i];
	}
	sum /= numberOfGrades;
	return sum;
}
void studentCreator(Students*& student,const int numberOfStudents,const int numberOfGrades,double* grades) {
	for (int i = 0; i < numberOfStudents; i++) {
		cout << "First name: ";
		cin >> student[i].first_name;
		cout << "Second name: ";
		cin >> student[i].second_name;
		cout << "Third name: ";
		cin >> student[i].third_name;
		cout << "Grades: ";
		for (int j = 0; j < numberOfGrades; j++) {
			cin >> grades[j];
		}
		student[i].finalGrade = finaleGrade(grades, numberOfGrades);
	}
}
int moneyEarners(Students* student, int numberOfStudents, double minimalGrade, int count = 0) {
	for (int i = 0; i < numberOfStudents; i++) {
		if (student[i].finalGrade >= minimalGrade) {
			count++;
		}
	}
	return count;
}
void studentsWithMoney(Students* student, int numberOfStudents, float minimalGrade) {
	for (int i = 0; i < numberOfStudents; i++) {
		if (student[i].finalGrade >= minimalGrade) {
			cout << "Name: " << student[i].first_name <<" " << student[i].second_name <<" " << student[i].second_name << " Grade: " << student[i].finalGrade << endl;
		}
	}
}
int main()
{
	Students* student = new Students[30];
	int numberOfStudents, numberOfGrades;
	float minimalGrade;
	cout << "Enter the number of students in the group: ";
	cin >> numberOfStudents;
	cout << "Enter the number of grades each student should have: ";
	cin >> numberOfGrades;
	double* arr = new double[numberOfGrades];
	cout << "Minimal grade for scholarship: ";
	cin >> minimalGrade;
	studentCreator(student, numberOfStudents, numberOfGrades,arr);
	cout << "The number of students that will earn scholarship is " << moneyEarners(student, numberOfStudents, minimalGrade)<<endl;
	studentsWithMoney(student, numberOfStudents, minimalGrade);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
