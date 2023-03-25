#include <iostream>
#include <fstream>

const int max_Count_Of_Students = 1024;
const int max_Name_Size = 16;
const char file_Name[17] = "studentsInfo.csv";


int IsFileOpened(std::ifstream& file) {
	if (!file.is_open())
	{
		std::cout << "File couldn't open!";
		return 0;
	}
	return 1;
}

int IsFileOpened(std::ofstream& file) {
	if (!file.is_open())
	{
		std::cout << "File couldn't open!";
		return 0;
	}
	return 1;
}

enum class hairColor {
	brown,
	black,
	blonde,
	red,
	white
};

struct Student {
	char firstName[max_Name_Size + 1];
	char familyName[max_Name_Size + 1];
	unsigned facultyNumber;
	double averageScore;
	hairColor color;
};

void SaveDataToFile(const Student& student) {
	std::ofstream writeFile(file_Name, std::ios::app);
	if (!IsFileOpened(writeFile))
		return;

	writeFile << student.firstName << ','
		<< student.familyName << ','
		<< student.facultyNumber << ','
		<< student.averageScore << ','
		<< (int)student.color << '\n';
	writeFile.close();
}

bool IsFacultyNumberValid(Student student) {
	int countOfDigits = 0;
	while (student.facultyNumber > 0)
	{
		countOfDigits++;
		student.facultyNumber /= 10;
	}
	if (countOfDigits <= 5)
		return true;
	std::cout << "Faculty number must not be longer than 5 digits!\n";
	return false;
}

bool AreWordsEqual(const char* first, const char* second) {
	int i;
	for (i = 0; first[i] != '\0' && second[i] != '\0'; i++) {
		if (first[i] != second[i])
			return false;
	}
	if ((first[i] == '\0' && second[i] != '\0') || (first[i] != '\0' && second[i] == '\0'))
		return false;
	return true;
}

hairColor CheckHairColor(char* currColor) {
	if (AreWordsEqual(currColor, "brown"))
		return hairColor::brown;
	else if (AreWordsEqual(currColor, "black"))
		return hairColor::black;
	else if (AreWordsEqual(currColor, "blonde"))
		return hairColor::blonde;
	else if (AreWordsEqual(currColor, "red"))
		return hairColor::red;
	else if (AreWordsEqual(currColor, "white"))
		return hairColor::white;
	else
	{
		std::cout << "Wrong hair color! Please enter a new one: ";
		std::cin >> currColor;
		CheckHairColor(currColor);
	}
}

void GetStudentsData(Student& student) {
	std::cout << "Enter first name: ";
	std::cin >> student.firstName;
	std::cout << "Enter family name: ";
	std::cin >> student.familyName;
	do {
		std::cout << "Enter faculty number: ";
		std::cin >> student.facultyNumber;
	} while (!IsFacultyNumberValid(student));
	std::cout << "Enter average score: ";
	std::cin >> student.averageScore;
	char currColor[8];
	std::cout << "Enter hair color: ";
	std::cin >> currColor;
	student.color = CheckHairColor(currColor);
}

int CountOfStudents(std::ifstream& file) {
	int rowCounter = 0;
	int currPosition = file.tellg();
	file.seekg(0, std::ios::beg);
	while (true) {
		if (file.eof())
			break;
		if (file.get() == '\n')
			rowCounter++;
	}
	file.seekg(currPosition);
	return rowCounter;
}

int LengthOfCharArray(char* array) {
	int length = 0;
	for (int i = 0; array[i] != '\0'; i++)
		length++;
	return length;
}

int CharToInt(char* buffer) {//351
	int result = 0;
	int length = LengthOfCharArray(buffer);
	for (int i = 0; buffer[i] != '\0'; i++)
		result += (buffer[i] - '0') * pow(10, --length);
	return result;
}

Student ReadStudentFromFile(std::ifstream& file) {
	Student st;
	char buffer[10];
	file.getline(st.firstName, max_Name_Size + 1, ',');
	file.getline(st.familyName, max_Name_Size + 1, ',');
	file.getline(buffer, 6, ',');
	st.facultyNumber = CharToInt(buffer);
	file.getline(buffer, 5, ',');
	st.averageScore = strtod(buffer, nullptr);
	file.getline(buffer, 2, '\n');
	st.color = (hairColor)(int)(buffer[0] - '0');
	return st;
}

bool IsFileAtMaxCapacity(std::ifstream& file, unsigned& countOfUnsavedStudents, const int countOfSavedStudents) {
	if (countOfSavedStudents + countOfUnsavedStudents == max_Count_Of_Students)
	{
		std::cout << "The file already has 1024 students!";
		return true;
	}
	else if (countOfSavedStudents + countOfUnsavedStudents > max_Count_Of_Students) {
		countOfUnsavedStudents = max_Count_Of_Students - countOfSavedStudents;
		std::cout << "The maximum count of students you can enter is " << countOfUnsavedStudents << '\n';
	}
	return false;
}

const char* PrintHairColor(int hairIndex) {
	if (hairIndex == (int)hairColor::brown)
		return "brown";
	else if (hairIndex == (int)hairColor::black)
		return "black";
	else if (hairIndex == (int)hairColor::blonde)
		return "blonde";
	else if (hairIndex == (int)hairColor::red)
		return "red";
	else
		return "white";
}

void PrintStudent(const Student& student) {
	std::cout << "Student: " << student.firstName << ' ' << student.familyName << std::endl;
	std::cout << "FN: " << student.facultyNumber << std::endl;
	std::cout << "Average score: " << student.averageScore << std::endl;
	std::cout << "Hair color: " << PrintHairColor((int)student.color) << std::endl;
}

int main()
{
	unsigned countOfUnsavedStudents;
	std::cout << "How many students will you enter?\n";
	std::cin >> countOfUnsavedStudents;
	std::ifstream readFile(file_Name);
	if (!IsFileOpened(readFile))
		return 1;

	int countOfSavedStudents = CountOfStudents(readFile);
	if (IsFileAtMaxCapacity(readFile, countOfUnsavedStudents, countOfSavedStudents))
		return 1;
	readFile.close();

	for (int i = 0; i < countOfUnsavedStudents; i++) {
		Student student;
		GetStudentsData(student);
		SaveDataToFile(student);
		countOfSavedStudents++;
	}

	std::ifstream file(file_Name);
	std::cout << "Printing the students: \n";
	for (int i = 0; i < countOfSavedStudents; i++)
	{
		Student student = ReadStudentFromFile(file);
		PrintStudent(student);
	}
	file.close();
}
