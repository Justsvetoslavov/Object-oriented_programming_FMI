#include <iostream>
#include <fstream>
#include <cstring>

using std::cin;
using std::cout;

const int FIRST_NAME_LENGTH = 16;
const int LAST_NAME_LENGTH = 16;
const int FACULTY_NUMBER_LENGTH = 5;
const int STUDENTS_MAX_COUNT = 1024;

enum class HairColor
{
	brown,
	black,
	blonde,
	red,
	white
};

enum MenuOption
{
	inputStudent = 1,
	readStudents = 2,
	exportToCsv = 3,
	exitProgram = 4
};

struct Student {
	char firstName[FIRST_NAME_LENGTH + 1]{};
	char lastName[LAST_NAME_LENGTH + 1]{};
	unsigned int facultyNumber;
	double gradePointAverage;
	HairColor hairColor{};

	Student()
	{
		facultyNumber = 0;
		gradePointAverage = 3.0;
		hairColor = HairColor::black;
	}

	Student(const char* _firstName, const char* _lastName,
		const unsigned int _facultyNumber, const double _gradePointAverage, const HairColor _hairColor) {
		strcpy_s(firstName, _firstName);
		strcpy_s(lastName, _lastName);
		facultyNumber = _facultyNumber;
		gradePointAverage = _gradePointAverage;
		hairColor = _hairColor;
	}
};

const char* enumFieldToString(const HairColor& hairColor) {
	switch (hairColor)
	{
	case HairColor::brown:
		return "brown";
	case HairColor::black:
		return "black";
	case HairColor::blonde:
		return "blonde";
	case HairColor::red:
		return "red";
	case HairColor::white:
		return "white";
	default:
		return "";
	}
}

bool getMappedHairColor(const char* hairColorInput, HairColor& outputColor) {
	if (strcmp(hairColorInput, "brown") == 0)
	{
		outputColor = HairColor::brown;
		return true;
	}
	if (strcmp(hairColorInput, "black") == 0)
	{
		outputColor = HairColor::black;
		return true;
	}
	if (strcmp(hairColorInput, "blonde") == 0)
	{
		outputColor = HairColor::blonde;
		return true;
	}
	if (strcmp(hairColorInput, "red") == 0)
	{
		outputColor = HairColor::red;
		return true;
	}
	if (strcmp(hairColorInput, "white") == 0)
	{
		outputColor = HairColor::white;
		return true;
	}

	return false;
}

bool isNameInputValid(const char* str, const short MAX_STR_SIZE)
{
	return str[MAX_STR_SIZE] == '\0';
}

void getName(char* name, const short MAX_LENGTH)
{
	do
	{
		cin >> name;
		if (!isNameInputValid(name, MAX_LENGTH))
		{
			cout << "Please enter a valid name (max 16 chars): ";
		}
		else break;
	} while (true);
}

unsigned short getFacultyNumber()
{
	unsigned short facultyNumber = 0;

	cout << "Input faculty number: ";
	do
	{
		cin >> facultyNumber;
		if (!(std::pow(10, FACULTY_NUMBER_LENGTH - 1) <= facultyNumber && facultyNumber <= (std::pow(10, FACULTY_NUMBER_LENGTH) - 1)))
		{
			cout << "Please enter a valid faculty number (" << FACULTY_NUMBER_LENGTH << " digits): ";
		}
		else break;
	} while (true);

	return facultyNumber;
}

double getGradePointAverage()
{
	double gradePointAverage = 0;

	cout << "Input grade point average: ";
	do
	{
		cin >> gradePointAverage;
		if (!(2 <= gradePointAverage && gradePointAverage <= 6))
		{
			cout << "Please enter a valid grade point average (between 2.00 and 6.00): ";
		}
		else break;
	} while (true);

	return gradePointAverage;
}

void getHairColor(HairColor& hairColor)
{
	cout << "Input hair color\n(brown, black, blonde, red, white): ";
	do
	{
		char hairColorInput[7];
		cin >> hairColorInput;
		if (!getMappedHairColor(hairColorInput, hairColor))
		{
			cout << "Please enter a valid hair color: ";
		}
		else break;
	} while (true);
}

void initStudentFromConsole(Student& outputStudent) {
	cin.ignore();

	cout << "Input first name: ";
	char firstName[FIRST_NAME_LENGTH + 1]{};
	getName(firstName, FIRST_NAME_LENGTH);

	cout << "Input last name: ";
	char lastName[LAST_NAME_LENGTH + 1]{};
	getName(lastName, LAST_NAME_LENGTH);

	const unsigned int facultyNumber = getFacultyNumber();

	const double gradePointAverage = getGradePointAverage();

	HairColor hairColor{};
	getHairColor(hairColor);

	outputStudent = Student(firstName, lastName, facultyNumber, gradePointAverage, hairColor);
}

void writeStudentToFile(std::fstream& binaryFile, const Student& student) {
	binaryFile.write((const char*)&student, sizeof(student));
	binaryFile.flush();
}

size_t getStudentsCountInBinaryFile(std::fstream& studentsBinaryFile) {
	size_t currPos = studentsBinaryFile.tellg();
	studentsBinaryFile.seekg(0, std::ios::end);

	const size_t studentsCount = studentsBinaryFile.tellg() / sizeof(Student);

	studentsBinaryFile.seekg(currPos, std::ios::beg);
	return studentsCount;
}

Student* loadStudentsArray(std::fstream& studentsBinaryFile, const size_t studentsCount) {
	size_t currPos = studentsBinaryFile.tellg();
	studentsBinaryFile.seekg(0, std::ios::beg);

	Student* students = new Student[studentsCount];

	studentsBinaryFile.read((char*)students, studentsCount * sizeof(Student));

	studentsBinaryFile.seekg(currPos, std::ios::beg);
	return students;
}

void printStudents(std::fstream& studentsBinaryFile) {
	const size_t studentsCount = getStudentsCountInBinaryFile(studentsBinaryFile);
	const Student* students = loadStudentsArray(studentsBinaryFile, studentsCount);

	cout << "First name\tLast name\tFaculty number\tGrade point average\tHair color" << std::endl;

	for (size_t i = 0; i < studentsCount; i++)
	{
		cout <<
			students[i].firstName << "\t\t" <<
			students[i].lastName << "\t\t" <<
			students[i].facultyNumber << "\t\t" <<
			students[i].gradePointAverage << "\t" <<
			enumFieldToString(students[i].hairColor) <<
			std::endl;
	}

	delete[] students;
}

void exportStudentsToCsv(std::fstream& studentsBinaryFile) {
	const size_t studentsCount = getStudentsCountInBinaryFile(studentsBinaryFile);
	const Student* students = loadStudentsArray(studentsBinaryFile, studentsCount);

	std::ofstream csvOutputFile("output.csv", std::ios::out | std::ios::trunc);

	if (!csvOutputFile.is_open())
	{
		return;
	}

	csvOutputFile << "First name,Last name,Faculty number,Grade point average,Hair color" << std::endl;

	for (size_t i = 0; i < studentsCount; i++)
	{
		csvOutputFile <<
			students[i].firstName << ',' <<
			students[i].lastName << ',' <<
			students[i].facultyNumber << ',' <<
			students[i].gradePointAverage << ',' <<
			enumFieldToString(students[i].hairColor) <<
			std::endl;
	}

	delete[] students;
	csvOutputFile.close();
}

void handleMenuInput(std::fstream& studentsBinaryFile)
{
	unsigned short menuOptionInput = 0;

	cout << "Menu options:\n1) Input student\n2) Read students\n3) Export to csv\n4) Exit\n";

	do
	{
		cout << "Input menu option (1-4): ";
		cin >> menuOptionInput;
		if (menuOptionInput == MenuOption::inputStudent)
		{
			if (getStudentsCountInBinaryFile(studentsBinaryFile) > STUDENTS_MAX_COUNT)
			{
				cout << "Too many students saved (max " << STUDENTS_MAX_COUNT << ")" << "\n\n";
				continue;
			}

			Student student;
			initStudentFromConsole(student);
			writeStudentToFile(studentsBinaryFile, student);
			cout << "Success\n\n";
		}
		else if (menuOptionInput == MenuOption::readStudents)
		{
			if (getStudentsCountInBinaryFile(studentsBinaryFile) == 0)
			{
				cout << "No students to print\n\n";
				continue;
			}
			printStudents(studentsBinaryFile);
			cout << "\n\n";
		}
		else if (menuOptionInput == MenuOption::exportToCsv)
		{
			exportStudentsToCsv(studentsBinaryFile);
			cout << "Success\n\n";
		}
		else if (menuOptionInput != MenuOption::exitProgram)
		{
			cout << "Choose a valid option: ";
		}
	} while (menuOptionInput != MenuOption::exitProgram);
}

int main()
{
	std::fstream studentsBinaryFile;

	studentsBinaryFile.open("students.dat", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

	if (!studentsBinaryFile.is_open())
	{
		cout << "File not open";
		return EXIT_FAILURE;
	}

	handleMenuInput(studentsBinaryFile);
	studentsBinaryFile.close();
}