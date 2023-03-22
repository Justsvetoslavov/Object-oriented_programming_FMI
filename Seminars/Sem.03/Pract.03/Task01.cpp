#include <iostream>
#include <fstream>

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
	char firstName[FIRST_NAME_LENGTH + 1];
	char lastName[LAST_NAME_LENGTH + 1];
	unsigned int facultyNumber;
	double gpa;
	HairColor hairColor;

	Student() {}

	Student(const char* _firstName, const char* _lastName,
		const unsigned int _facultyNumber, const double _gpa, const HairColor _hairColor) {
		strcpy_s(firstName, _firstName);
		strcpy_s(lastName, _lastName);
		facultyNumber = _facultyNumber;
		gpa = _gpa;
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

void initStudentFromConsole(Student& outputStudent) {
	cin.ignore();

	cout << "Input first name: ";

	char firstName[FIRST_NAME_LENGTH + 1]{};
	do
	{
		cin >> firstName;
		if (!isNameInputValid(firstName, FIRST_NAME_LENGTH))
		{
			cout << "Please enter a valid name (max 16 chars): ";
		}
		else break;
	} while (true);

	cout << "Input last name: ";
	char lastName[LAST_NAME_LENGTH + 1]{};
	do
	{
		cin >> lastName;
		if (!isNameInputValid(lastName, LAST_NAME_LENGTH))
		{
			cout << "Please enter a valid name (max 16 chars): ";
		}
		else break;
	} while (true);

	cout << "Input faculty number: ";
	unsigned int facultyNumber = 0;
	do
	{
		cin >> facultyNumber;
		if (!(std::pow(10, FACULTY_NUMBER_LENGTH - 1) <= facultyNumber && facultyNumber <= (std::pow(10, FACULTY_NUMBER_LENGTH) - 1)))
		{
			cout << "Please enter a valid faculty number (" << FACULTY_NUMBER_LENGTH << " digits): ";
		}
		else break;
	} while (true);

	cout << "Input GPA: ";
	double gpa = 0;
	do
	{
		cin >> gpa;
		if (!(2 <= gpa && gpa <= 6))
		{
			cout << "Please enter a valid gpa (between 2.00 and 6.00): ";
		}
		else break;
	} while (true);

	cout << "Input hair color\n(brown, black, blonde, red, white): ";
	HairColor hairColor;

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

	outputStudent = Student(firstName, lastName, facultyNumber, gpa, hairColor);
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

	cout << "First name\tLast name\tFaculty number\tGPA\tHair color" << std::endl;

	for (size_t i = 0; i < studentsCount; i++)
	{
		cout <<
			students[i].firstName << "\t\t" <<
			students[i].lastName << "\t\t" <<
			students[i].facultyNumber << "\t\t" <<
			students[i].gpa << "\t" <<
			enumFieldToString(students[i].hairColor) <<
			std::endl;
	}

	delete[] students;
}

void exportStudentsToCsv(std::fstream& studentsBinaryFile) {
	const size_t studentsCount = getStudentsCountInBinaryFile(studentsBinaryFile);
	const Student* students = loadStudentsArray(studentsBinaryFile, studentsCount);

	std::ofstream csvOutputFile("output.csv", std::ios::out | std::ios::trunc);
	csvOutputFile << "First name,Last name,Faculty number,GPA,Hair color" << std::endl;

	for (size_t i = 0; i < studentsCount; i++)
	{
		csvOutputFile <<
			students[i].firstName << ',' <<
			students[i].lastName << ',' <<
			students[i].facultyNumber << ',' <<
			students[i].gpa << ',' <<
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

	while (true)
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
		else if (menuOptionInput == MenuOption::exitProgram)
		{
			studentsBinaryFile.close();
			return;
		}
		else
		{
			cout << "Choose a valid option: ";
		}
	}
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
}
