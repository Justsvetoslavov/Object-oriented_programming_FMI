#include <iostream>
#include <fstream>

const int MAX_ST_NO = 1024;
const int  max_length = 16;
const int max_fn_length = 5;
enum class haircolor {
	brown,
	black,
	blonde,
	red,
	white,
};

class Student {
public:
	char name[max_length+1];
	char lastname[max_length+1];
	char fn[max_fn_length + 1];
	haircolor color;
	double gpa;


};

void writeToFile(const char* filename, int num, const Student* st) {
	std::ofstream file(filename, std::ios::out | std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Error opening file!";
		return;
	}
	file.write((const char*)st, sizeof(Student) * num);
	for (int i = 0; i < num; i++) {
		file << st[i].name << "," << st[i].lastname << "," << st[i].fn << "," << st[i].gpa << ",";
		switch (st[i].color) {
		case haircolor::brown:
			file << "brown";
			break;
		case haircolor::black:
			file << "black";
			break;
		case haircolor::blonde:
			file << "blonde";
			break;
		case haircolor::red:
			file << "red";
			break;
		case haircolor::white:
			file << "white";
			break;
		}
		file << "\n";
	}
	file.close();
}


size_t getFileSize(std::ifstream& file) {
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(currentPos);

	return fileSize;
}
Student* readFromFile(const char* filename, int& numStudents) {
	std::ifstream file(filename, std::ios::in | std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Error opening file!";
		return nullptr;
	}
	size_t fileSize = getFileSize(file);
	numStudents = fileSize / sizeof(Student);
	Student* students = new Student[numStudents];
	file.read((char*)students, fileSize);
	file.close();
	return students;
}


void printStudent(const Student& student) {
	std::cout << student.name << "," << student.lastname << ",";
	switch (student.color) {
	case haircolor::brown:
		std::cout << "brown";
		break;
	case haircolor::black:
		std::cout << "black";
		break;
	case haircolor::blonde:
		std::cout << "blonde";
		break;
	case haircolor::red:
		std::cout << "red";
		break;
	case haircolor::white:
		std::cout << "white";
		break;
	default:
		std::cout << "unknown";
	}
	std::cout << "," << student.fn << "," << student.gpa << std::endl;
}

int main() {

	Student students[2] = {
		{"John", "Doe", haircolor::brown, "123", 3.5},
		{"Jane", "Smith", haircolor::blonde, "67890", 4.0}
	};
	writeToFile("students.csv", 2, students);

	int numStudents;
	Student* readStudents = readFromFile("students.csv", numStudents);
	for (int i = 0; i < numStudents; i++) {
		printStudent(readStudents[i]);
	}
	delete[] readStudents;

	return 0;
}