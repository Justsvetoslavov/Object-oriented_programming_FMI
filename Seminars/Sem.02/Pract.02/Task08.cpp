#include <iostream>
#include <fstream>
#include <string>

enum class Category {
	OKN,
	M,
	PM,
	PR,
	Other,
};

const int EXAM_TYPES = 3;

enum class ExamType {
	Exam,
	CourseProject,
	Test,
	Unknown
};

const int  MAX_LEN = 100;

struct ElectiveCourse {
	unsigned int ID;
	char name[MAX_LEN];
	Category category;
	double credits;
	ExamType examType[EXAM_TYPES] = { ExamType::Unknown };
};

const int MAX_NUMBER_OF_COURSES = 10;
ElectiveCourse electiveCourses[MAX_NUMBER_OF_COURSES];
int coursesCount = 0;

void initCourses() {
	electiveCourses[0] = { 123, "OOP Pract", Category::PR, 2.5, {ExamType::CourseProject} };
	electiveCourses[1] = { 234, "Vim", Category::OKN, 3.0, {ExamType::CourseProject, ExamType::Test} };
	electiveCourses[2] = { 273, "Statistics", Category::PM, 4.0, {ExamType::CourseProject, ExamType::Exam} };
	coursesCount = 3;
}

int myStrlen(const char* str) {
	int ctr = 0;
	while (*str) {
		ctr++;
		str++;
	}
	return ctr;
}

unsigned stringToInt(const char str[]) {
	unsigned int result = 0;
	unsigned int  powerOfTen = 1;
	int len = myStrlen(str);

	for (int i = len - 1; i >= 0; i--) {
		result += (str[i] - '0') * powerOfTen;
		powerOfTen *= 10;
	}
	return result;
}

void myStrcpy(char* dest, const char* src) {
	int ind = 0;
	while (*src) {
		dest[ind++] = *(src++);
	}
	dest[ind] = '\0';
}

void saveElectiveCourseToFile(std::ofstream& file, const ElectiveCourse& electiveCourse) {
	file << electiveCourse.ID << ",";
	file << electiveCourse.name << ",";
	file << (int)electiveCourse.category << ",";
	file << electiveCourse.credits << ",";

	for (int i = 0; i < EXAM_TYPES; i++) {
		file << (int)electiveCourse.examType[i] << ",";
	}

	file << '\n';
}

void saveElectiveCoursesToFile(const char fileName[]) {
	std::ofstream writeFile(fileName, std::ios::trunc);

	if (!writeFile.is_open()) {
		std::cout << "Error\n";
		return;
	}

	writeFile << coursesCount << "\n";
	for (int i = 0; i < coursesCount; i++) {
		saveElectiveCourseToFile(writeFile, electiveCourses[i]);
	}

	writeFile.close();
}

void loadElectiveCourseFromFile(std::ifstream& file, ElectiveCourse& electiveCourse) {
	//ID
	char buff[MAX_LEN];
	file.getline(buff, MAX_LEN, ',');
	unsigned int temp = stringToInt(buff);
	electiveCourse.ID = temp;

	//Name
	file.getline(buff, MAX_LEN, ',');
	myStrcpy(electiveCourse.name, buff);

	//Category
	file.getline(buff, MAX_LEN, ',');
	temp = stringToInt(buff);
	electiveCourse.category = (Category)temp;

	//Credits
	file.getline(buff, MAX_LEN, ',');
	electiveCourse.credits = std::stod(buff);

	//Exam type
	for (int i = 0; i < EXAM_TYPES; i++) {
		file.getline(buff, MAX_LEN, ',');
		electiveCourse.examType[i] = (ExamType)stringToInt(buff);
	}
	file.get();
}

void loadElectiveCoursesFromFile(const char fileName[]) {
	std::ifstream file(fileName);

	if (!file.is_open()) {
		std::cout << "Error\n";
		return;
	}

	file >> coursesCount;
	file.get();
	for (int i = 0; i < coursesCount; i++) {
		loadElectiveCourseFromFile(file, electiveCourses[i]);
	}

	file.close();
}

int searchByID(const unsigned int ID) {
	int ind = -1;

	for (int i = 0; i < coursesCount; i++) {
		if (electiveCourses[i].ID == ID) {
			ind = i;
			break;
		}
	}

	return ind;
}

void printElectiveCourse(const unsigned int ID) {
	int ind = searchByID(ID);

	if (ind < 0) {
		std::cout << "Elective course not found\n";
		return;
	}

	std::cout << electiveCourses[ind].ID << " " << electiveCourses[ind].name << " ";
	std::cout << (int)electiveCourses[ind].category << " " << electiveCourses[ind].credits << " ";
	
	for (int i = 0; i < EXAM_TYPES; i++) {
		std::cout << (int)electiveCourses[ind].examType[i] << " ";
	}

	std::cout << "\n";
}

void printElectiveCourses() {
	for (int i = 0; i < coursesCount; i++) {
		printElectiveCourse(electiveCourses[i].ID);
	}
	std::cout << "\n\n";
}

void addElectiveCourse(const ElectiveCourse& electiveCourse) {
	if (MAX_NUMBER_OF_COURSES <= coursesCount) {
		std::cout << "The database is full\n";
		return;
	}

	int ind = searchByID(electiveCourse.ID);

	//Overwrite
	if (ind >= 0) {
		electiveCourses[ind] = electiveCourse;
		return;
	}

	//Add at the end of the array
	else {
		electiveCourses[coursesCount++] = electiveCourse;
		return;
	}
}

void removeElectiveCourse(const unsigned int ID) {
	int ind = searchByID(ID);

	if (ind < 0) {
		std::cout << "The course wasn't found\n";
		return;
	}

	else {
		//Shift all values
		for (int i = ind; i < coursesCount; i++) {
			electiveCourses[i] = electiveCourses[i + 1];
		}
		coursesCount--;
		//The last value will appear twice, but will be overwritten by the 
		//next added one. It will not be printed or saved twice because 
		//the number of courses is decreased.
	}
}

void printElectiveCoursesInCategory(const Category& category) {
	for (int i = 0; i < coursesCount; i++) {
		if (electiveCourses[i].category == category) {
			printElectiveCourse(electiveCourses[i].ID);
		}
	}
}

void printElectiveCoursesInInterval(const double minC, const double maxC) {
	for (int i = 0; i < coursesCount; i++) {
		if (electiveCourses[i].credits >= minC && electiveCourses[i].credits <= maxC) {
			printElectiveCourse(electiveCourses[i].ID);
		}
	}
}

int main()
{
	////The first time this program is started, 
	////save the example elective courses to a file 

	//initCourses();
	//saveElectiveCoursesToFile("myfile.csv");

	loadElectiveCoursesFromFile("myfile.csv");
	printElectiveCourses();

	//Overwrite OOP Pract (ID = 123) with Java
	ElectiveCourse myElectiveCourse1 = { 123, "Java", Category::OKN, 4.0, {ExamType::CourseProject, ExamType::Test} };
	addElectiveCourse(myElectiveCourse1);
	printElectiveCourses();

	//Add Rust without overwriting
	ElectiveCourse myElectiveCourse2 = { 899, "Rust", Category::OKN, 4.5, {ExamType::CourseProject, ExamType::Exam} };
	addElectiveCourse(myElectiveCourse2);
	printElectiveCourses();

	//Remove 234 (Vim)
	removeElectiveCourse(234);
	printElectiveCourses();

	std::cout << "Courses in category OKN:\n";
	printElectiveCoursesInCategory(Category::OKN);

	std::cout << "\n\nCourses in interval:\n";
	printElectiveCoursesInInterval(3, 4);

	//Save all changes
	saveElectiveCoursesToFile("myfile.csv");
}
