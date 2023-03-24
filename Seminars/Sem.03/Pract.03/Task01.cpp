#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ofstream, std::ifstream;

const char *FILE_NAME = "students.csv";

const int max_length = 16;
const int max_users = 1024;
const int max_digits = 5;

enum hairColor {
    BLONDE,
    BROWN,
    BLACK,
    RED,
    WHITE,
};

const static char *hairColorNames[] = {
        "BLONDE",
        "BROWN",
        "BLACK",
        "RED",
        "WHITE",
};

struct Student {
    char name[max_length + 1];
    char surname[max_length + 1];
    char facultyNumber[max_digits + 1];
    double averageGrade;
    hairColor hair;
};

struct System {
    Student students[max_users];
    int studentsCount;

    void addStudent(const Student &student) {
        if (studentsCount >= max_users) {
            cout << "Max users reached!" << endl;
            return;
        }
        students[studentsCount] = student;
        studentsCount++;
    }
};

bool writeStudentsToFile(const char *filename, System &system) {
    ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        cout << "File could not be opened!" << endl;
        return false;
    }
    for (int i = 0; i < system.studentsCount; i++) {
        file << system.students[i].name << "," << system.students[i].surname
             << "," << system.students[i].facultyNumber << "," << system.students[i].averageGrade
             << "," << hairColorNames[system.students[i].hair] << endl;
    }
    file.close();
    return true;
}

bool readStudentsFromFile(const char *filename, System &system) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File could not be opened!" << endl;
        return false;
    }
    char buffer[1024];
    system.studentsCount = 0;
    while (!file.eof() && system.studentsCount < max_users && file.getline(buffer, 1024)) {
        Student student{};
        strcpy(student.name, strtok(buffer, ","));
        strcpy(student.surname, strtok(NULL, ","));
        strcpy(student.facultyNumber, strtok(NULL, ","));
        student.averageGrade = atof(strtok(NULL, ","));
        student.hair = (hairColor) atoi(strtok(NULL, ","));
        system.addStudent(student);
    }
    file.close();
    return true;
}

int main() {
    System system{};
    system.studentsCount = 0;

    system.addStudent({"Ivan", "Ivanov", "12345", 5.5, BLONDE});
    system.addStudent({"Pesho", "Peshev", "12346", 5.6, BROWN});

    writeStudentsToFile(FILE_NAME, system);
    readStudentsFromFile(FILE_NAME, system);

    for (int i = 0; i < system.studentsCount; i++) {
        cout << system.students[i].name << " " << system.students[i].surname << " "
             << system.students[i].facultyNumber << " " << system.students[i].averageGrade << " "
             << hairColorNames[system.students[i].hair] << endl;
    }
    return 0;
}
