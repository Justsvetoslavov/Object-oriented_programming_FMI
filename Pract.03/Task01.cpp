#include <iostream>
#include <fstream>

const int MAX_NUM_STUDENTS = 1024;
const int BUFF_SIZE = 1024;
const int MAX_NAME_LEN = 17;

enum class hairColor {
	brown,
	black,
	blonde,
	red,
	white
};

struct Student {
	char first_name[MAX_NAME_LEN];
	char last_name[MAX_NAME_LEN];
	int fn;
	double avg_grade;
	hairColor hair;
};

hairColor intToEnum(int i) {
	switch (i) {
	case 0: return hairColor::brown;
	case 1: return hairColor::black;
	case 2: return hairColor::blonde;
	case 3: return hairColor::red;
	case 4: return hairColor::white;
	}
}

void getHairColor(const Student& s, char* hair_color) {
	switch (s.hair) {
	case hairColor::brown: strcpy(hair_color, "brown"); break;
	case hairColor::black: strcpy(hair_color, "black"); break;
	case hairColor::blonde: strcpy(hair_color, "blonde"); break;
	case hairColor::red: strcpy(hair_color, "red"); break;
	case hairColor::white: strcpy(hair_color, "white");
	}
}

void initStudent(Student& st, const char* first_name, const char* last_name, int fn, double avg_grade, hairColor hair) {
	strcpy_s(st.first_name, first_name);
	strcpy_s(st.last_name, last_name);
	st.fn = fn;
	st.avg_grade = avg_grade;
	st.hair = hair;
}

bool is_Valid_fn(int fn) {
	if (fn >= 10000 && fn <= 99999) {
		return true;
	}
	return false;
}

bool is_valid_grade(double grade) {
	if (grade >= 2.0 && grade <= 6.0) {
		return true;
	}
	return false;
}

void getStudentInfo(Student& s) {
	char first_name[MAX_NAME_LEN];
	char last_name[MAX_NAME_LEN];
	int fn;
	double avg_grade; 
	int hair;
	std::cout << "First name:";
	std::cin.getline(first_name, MAX_NAME_LEN);
	std::cout << "Last name:";
	std::cin.getline(last_name, MAX_NAME_LEN);
	std::cout << "Faculty num:";
	do {
		std::cin >> fn;
	} while (!is_Valid_fn(fn));
	std::cout << "Average grade:";
	do {
		std::cin >> avg_grade;
	} while (!is_valid_grade(avg_grade));
	std::cout << "Hair color: Enter 0 for brown,1 for black,2 for blonde,3 for red and 4 to white: ";
	std::cin >> hair;
	hairColor h = intToEnum(hair);
	initStudent(s, first_name, last_name, fn, avg_grade, h);
}

void saveStudent(const Student& s, std::ofstream& file) {
	char* hair = new char[8];
	getHairColor(s, hair);
	file << s.first_name << "," << s.last_name << "," << s.fn << "," << s.avg_grade << "," << hair << std::endl;
	delete [] hair;
}

void saveToFile() {
	std::ofstream file;
	file.open("students.csv", std::ios::app);
	if (!file.is_open()) {
		std::cout << "Error opening the file" << std::endl;
	}
	else {
		Student s;
		getStudentInfo(s);
		saveStudent(s, file);
	}
	file.close();
}

void printStudentInfo() {
    std::ifstream file;
    file.open("students.csv", std::ios::in);
	if (!file.is_open()) {
		std::cout << "Error opening the file" << std::endl;
	}
	else {
		while (!file.eof()) {
			char buff[BUFF_SIZE];
			file.getline(buff, BUFF_SIZE, '\n');
			std::cout << buff << std::endl;
		}
	}
    file.close();
}

int main() {
	saveToFile();
	printStudentInfo();
	return 0;
}