#include "Student.h"

Student::Student() {
    name = new char[1];
    name[0] = '\0';
    fac_num = 0;
    grades = 0;
}

void Student::free() {
    delete[] name;
    fac_num = 0;
}

void Student::copyFrom(const Student &student) {
    name = new char[strlen(student.name) + 1];
    strcpy(name, student.name);
    fac_num = student.fac_num;
    grades = student.grades;
    count_grades = student.count_grades;
}

Student::Student(const Student &student) {
    copyFrom(student);
}

Student::~Student() {
    free();
}

Student &Student::operator=(const Student &student) {
    if (this != &student) {
        free();
        copyFrom(student);
    }
    return *this;
}

Student::Student(const char *name, const int num) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    fac_num = num;
}

void Student::addGrade(const int grade) {
    count_grades++;
    grades += grade;
}

void Student::editGrade(const int grade) {
    grades += grade;
}

int Student::getNum() const {
    return fac_num;
}

double Student::getAverageGrade() const {
    return (double) grades / count_grades;
}