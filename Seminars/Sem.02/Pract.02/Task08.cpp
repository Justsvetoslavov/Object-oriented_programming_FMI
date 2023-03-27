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
	size_t ID;
	char name[MAX_LEN];
	Category category;
	double credits;
	ExamType examType[EXAM_TYPES] = { ExamType::Unknown };
};

const int MAX_NUMBER_OF_COURSES = 10;
ElectiveCourse electiveCourses[MAX_NUMBER_OF_COURSES];
int coursesCount = 0;

void InitCourses() {
	electiveCourses[0] = { 123, "OOP Pract", Category::PR, 2.5, {ExamType::CourseProject} };
	electiveCourses[1] = { 234, "Vim", Category::OKN, 3.0, {ExamType::CourseProject, ExamType::Test} };
	electiveCourses[2] = { 273, "Statistics", Category::PM, 4.0, {ExamType::CourseProject, ExamType::Exam} };
	coursesCount = 3;
}

size_t MyStrlen(const char* str) {
    size_t index = 0;
    while (str[index] != '\0') {
        ++index;
    }
    return index;
}

unsigned StringToInt(const char* str) {
	size_t result = 0;
	size_t powerOfTen = 1;
	size_t len = MyStrlen(str);

	for (size_t i = len - 1; i >= 0; --i) {
		result += (str[i] - '0') * powerOfTen;
		powerOfTen *= 10;
	}
	return result;
}

void MyStrcpy(char* dest, const char* src) {
    size_t index = 0;
    while (src[index] != '\0') {
        dest[index] = src[index];
        ++index;
    }
    dest[index] = '\0';
}

void SaveElectiveCourseToFile(std::ofstream& file, const ElectiveCourse& electiveCourse) {
	file << electiveCourse.ID << ",";
	file << electiveCourse.name << ",";
	file << (int)electiveCourse.category << ",";
	file << electiveCourse.credits << ",";

	for (size_t i = 0; i < EXAM_TYPES; ++i) {
		file << (int)electiveCourse.examType[i] << ",";
	}

	file << '\n';
}

void SaveElectiveCoursesToFile(const char fileName[]) {
	std::ofstream writeFile(fileName);

	if (!writeFile.is_open()) {
		std::cout << "Error\n";
		return;
	}

	writeFile << coursesCount << "\n";
	for (size_t i = 0; i < coursesCount; ++i) {
		SaveElectiveCourseToFile(writeFile, electiveCourses[i]);
	}

	writeFile.close();
}

void loadElectiveCourseFromFile(std::ifstream& file, ElectiveCourse& electiveCourse) {
	//ID
	char buff[MAX_LEN];
	file.getline(buff, MAX_LEN, ',');
	unsigned int temp = StringToInt(buff);
	electiveCourse.ID = temp;

	//Name
	file.getline(buff, MAX_LEN, ',');
	MyStrcpy(electiveCourse.name, buff);

	//Category
	file.getline(buff, MAX_LEN, ',');
	temp = StringToInt(buff);
	electiveCourse.category = (Category)temp;

	//Credits
	file.getline(buff, MAX_LEN, ',');
	electiveCourse.credits = std::stod(buff);

	//Exam type
	for (size_t i = 0; i < EXAM_TYPES; ++i) {
		file.getline(buff, MAX_LEN, ',');
		electiveCourse.examType[i] = (ExamType)StringToInt(buff);
	}
	file.get();
}

void LoadElectiveCoursesFromFile(const char* fileName) {
	std::ifstream file(fileName);

	if (!file.is_open()) {
		std::cout << "Error\n";
		return;
	}

	file >> coursesCount;
	file.get();
	for (size_t i = 0; i < coursesCount; ++i) {
		LoadElectiveCourseFromFile(file, electiveCourses[i]);
	}

	file.close();
}

int SearchByID(const size_t ID) {
	int ind = -1;

	for (size_t i = 0; i < coursesCount; ++i) {
		if (electiveCourses[i].ID == ID) {
			ind = i;
			break;
		}
	}

	return ind;
}

void PrintElectiveCourse(const size_t ID) {
	int ind = searchByID(ID);

	if (ind < 0) {
		std::cout << "Elective course not found\n";
		return;
	}

	std::cout << electiveCourses[ind].ID << " " << electiveCourses[ind].name << " ";
	std::cout << (int)electiveCourses[ind].category << " " << electiveCourses[ind].credits << " ";
	
	for (size_t i = 0; i < EXAM_TYPES; ++i) {
		std::cout << (int)electiveCourses[ind].examType[i] << " ";
	}

	std::cout << "\n";
}

void PrintElectiveCourses() {
	for (size_t i = 0; i < coursesCount; ++i) {
		PrintElectiveCourse(electiveCourses[i].ID);
	}
	std::cout << "\n\n";
}

void AddElectiveCourse(const ElectiveCourse& electiveCourse) {
	if (MAX_NUMBER_OF_COURSES <= coursesCount) {
		std::cout << "The database is full\n";
		return;
	}

	int ind = SearchByID(electiveCourse.ID);

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

void RemoveElectiveCourse(const unsigned int ID) {
	int ind = SearchByID(ID);

	if (ind < 0) {
		std::cout << "The course wasn't found\n";
		return;
	}

	else {
		//Shift all values
		for (size_t i = ind; i < coursesCount; ++i) {
			electiveCourses[i] = electiveCourses[i + 1];
		}
		coursesCount--;
		//The last value will appear twice, but will be overwritten by the 
		//next added one. It will not be printed or saved twice because 
		//the number of courses is decreased.
	}
}

void PrintElectiveCoursesInCategory(const Category& category) {
	for (size_t i = 0; i < coursesCount; ++i) {
		if (electiveCourses[i].category == category) {
			printElectiveCourse(electiveCourses[i].ID);
		}
	}
}

void PrintElectiveCoursesInInterval(const double minC, const double maxC) {
	for (size_t i = 0; i < coursesCount; ++i) {
		if (electiveCourses[i].credits >= minC && electiveCourses[i].credits <= maxC) {
			printElectiveCourse(electiveCourses[i].ID);
		}
	}
}

int main()
{
	// The first time this program is started, 
	// save the example elective courses to a file 

	// initCourses();
	// saveElectiveCoursesToFile("myfile.csv");

	LoadElectiveCoursesFromFile("myfile.csv");
	PrintElectiveCourses();

	//Overwrite OOP Pract (ID = 123) with Java
	ElectiveCourse myElectiveCourse1 = { 123, "Java", Category::OKN, 4.0, {ExamType::CourseProject, ExamType::Test} };
	AddElectiveCourse(myElectiveCourse1);
	PrintElectiveCourses();

	//Add Rust without overwriting
	ElectiveCourse myElectiveCourse2 = { 899, "Rust", Category::OKN, 4.5, {ExamType::CourseProject, ExamType::Exam} };
	AddElectiveCourse(myElectiveCourse2);
	PrintElectiveCourses();

	//Remove 234 (Vim)
	RemoveElectiveCourse(234);
	PrintElectiveCourses();

	std::cout << "Courses in category OKN:\n";
	PrintElectiveCoursesInCategory(Category::OKN);

	std::cout << "\n\nCourses in interval:\n";
	PrintElectiveCoursesInInterval(3, 4);

	//Save all changes
	SaveElectiveCoursesToFile("myfile.csv");
}
