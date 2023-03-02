#include <iostream>
using std::cin;
using std::cout;
using std::endl;
//Natalia Nakollofski   1MI8000034    GR.1


//Една група се състои от краен брой студенти, като броят на студентите се задава от вас.
//
//Създайте структура, която описва група.Структурата също така трябва да пази средния успех на групата.
//
//Направете функция, която създава група, вземайки информация от стандартния вход.Средния успех трябва да се сметне след въвеждане на информацията.
//Напишете функция, която приема група и минимален успех за стипендия, и връща колко студента ще получават стипендия.
//Създайте функция, която приема група и минимален успех за стипендия и извежда сортирани всички студенти, които ще получават стипендия
//идния семестър.
const int MAX = 50;
struct Student {
	char name[MAX];
	double grade;
};
struct Group {
	Student student[MAX];
	int numberofstudents;
	double gpa;
};
void swap(Student& a, Student& b) {
	Student temp = a;
	a = b;
	b = temp;
}
void selectionSort(Group& group) {
	int n = group.numberofstudents;
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (group.student[j].grade < group.student[minIndex].grade) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(group.student[i], group.student[minIndex]);
		}
	}

}
Group creategroup() {
	Group group;
	cout << "Enter number of students:" << endl;
	cin >> group.numberofstudents;
	double totalGPA = 0;
	for (int i = 0; i < group.numberofstudents; i++) {
		cin >> group.student[i].name >> group.student[i].grade;
		totalGPA+=group.student[i].grade;
	}
	group.gpa = totalGPA / group.numberofstudents;
	return group;


}
int numScholarship(Group& group, double mingpa) {
	int nrscholar = 0;
	for (int i = 0; i < group.numberofstudents; i++)
	{
		if (group.student[i].grade >= mingpa) {
			nrscholar++;
		}
	}
	return nrscholar;
}



void displayScholarships(Group& group, double mingpa) {
	cout << "students who will receive a scholarship are:" << endl;
	for (int i = 0; i < group.numberofstudents; i++) {
		if (group.student[i].grade >= mingpa) {
			cout << group.student[i].name << "-GPA:" << group.student[i].grade << endl;
		}
	}
}


int main() {
	Group group = creategroup();
	cout << "Group average success:" << group.gpa << endl;
	double mingpa;
	cout << "Enter minimum scholarship GPA: ";
	cin >> mingpa;
	cout << "Number of students receiving a scholarship: " << numScholarship(group, mingpa) << endl;
	selectionSort(group);
	displayScholarships(group, mingpa);
	return 0;
}
