#include <iostream>

const int MAX_GRADES_COUNT = 15; 
const int MAX_NAME_LEN = 100;
struct Student {
	char name[MAX_NAME_LEN + 1];
	int fn;
	double grades[MAX_GRADES_COUNT];
	int numberOfSubjects; 
	double averageGrade;
};

const int MAX_STUDENTS_IN_GROUP = 30;
struct Group {
	Student students[MAX_STUDENTS_IN_GROUP];
	int numberOfStudents;
	double averageGrade;
};

double sumStudentGrades(const Student& student) {
	double sum = 0;
	for (int i = 0; i < student.numberOfSubjects; i++) {
		sum += student.grades[i];
	}
	return sum;
}

void createStudent(Student& student) {
	std::cin.ignore();
	std::cin.getline(student.name, MAX_NAME_LEN);
	std::cin >> student.fn;
	std::cin >> student.numberOfSubjects;
	for (int i = 0; i < student.numberOfSubjects; i++) {
		std::cin >> student.grades[i];
	}
	double sum = sumStudentGrades(student);
	student.averageGrade = sum / student.numberOfSubjects;
}

void calculateGroupAverage(Group& group) {
	double sum = 0;
	int totalSubjects = 0;
	for (int i = 0; i < group.numberOfStudents; i++) {
		sum += sumStudentGrades(group.students[i]);
		totalSubjects += group.students[i].numberOfSubjects;
	}
	group.averageGrade = sum / totalSubjects;
}

void createGroup(Group& group) {
	std::cin >> group.numberOfStudents;
	for (int i = 0; i < group.numberOfStudents; i++) {
		createStudent(group.students[i]);
	}
	calculateGroupAverage(group);
}

void printStudent(const Student& student) {
	std::cout << student.name << " " << student.fn;
	std::cout << "\nGrades:\n";
	for (int i = 0; i < student.numberOfSubjects; i++) {
		std::cout << student.grades[i] << " ";
	}
	std::cout << "\nAverage grade: " << student.averageGrade;
	std::cout << "\n\n";
}

void printGroup(const Group& group) {
	for (int i = 0; i < group.numberOfStudents; i++) {
		printStudent(group.students[i]);
	}
	std::cout << "Average grade for group: " << group.averageGrade << "\n";
}

bool studentHasScholarship(const Student& student, const double minimalGrade) {
	double sum = sumStudentGrades(student);
	return ((sum / student.numberOfSubjects) >= minimalGrade);
}

int countScholarshipHolders(const Group& group, const double minimalGrade) {
	int ctr = 0;
	for (int i = 0; i < group.numberOfStudents; i++) {
		if (studentHasScholarship(group.students[i], minimalGrade)) {
			ctr++;
		}
	}
	return ctr;
}

int getMaxElementIndex(const double* arr, const int size) {
	int maxInd = 0;
	for (int i = 1; i < size; i++) {
		if (arr[i] > arr[maxInd]) {
			maxInd = i;
		}
	}
	return maxInd;
}

void fillArrays(const Group& group, double* averageGrades, double* indices, const int size) {
	for (int i = 0; i < size; i++) {
		indices[i] = i;
		averageGrades[i] = group.students[i].averageGrade;
	}
}

void sortArrays(double* averageGrades, double* indices, const int size, const double minimalGrade) {
	//Sorting in descending order 
	for (int i = 0; i < size - 1; i++) {
		int maxIndex = i + getMaxElementIndex(averageGrades + i, size - i);
		
		//If the highest grade from the unsorted ones is
		//lower than the minimal grade, there is no use in sorting 
		//the other students as they will not have a scholarship
		if (averageGrades[maxIndex] < minimalGrade) {
			return;
		}

		if (maxIndex != i) {
			std::swap(averageGrades[maxIndex], averageGrades[i]);
			std::swap(indices[maxIndex], indices[i]);
		}
	}
}

void printScholarshipHolders(const Group& group, double* averageGrades, double* indices, const int size, const double minimalGrade) {
	for (int i = 0; i < size && averageGrades[i] >= minimalGrade; i++) {
		int ind = indices[i];
		printStudent(group.students[ind]);
	}
}

void sortAndPrintScholarshipHolders(const Group& group, const double minimalGrade) {
	//I will use two arrays - one with the grades 
	//of all students and another containing indices. 
	//Then, I will sort the first array(and the second one at the same time)
	//This way, I will be able to print the scholarship holders
	//without sorting the original array
	int size = group.numberOfStudents;
	double* averageGrades = new double[size];
	double* indices = new double[size];

	fillArrays(group, averageGrades, indices, size);
	sortArrays(averageGrades, indices, size, minimalGrade);
	printScholarshipHolders(group, averageGrades, indices, size, minimalGrade);

	delete[] averageGrades;
	delete[] indices;
}

int main() {
	Group myGroup;
	createGroup(myGroup);
	std::cout << "\n\n";
	printGroup(myGroup);
	std::cout << "\n\n";
	std::cout << "Number of scolarship holders: " << countScholarshipHolders(myGroup, 5.55) << "\n\n";
	sortAndPrintScholarshipHolders(myGroup, 5.55);
}

