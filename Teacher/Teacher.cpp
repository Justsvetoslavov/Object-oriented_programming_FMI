#include "Teacher.h"

Teacher::Teacher() {
    name = new char[1];
    name[0] = '\0';
    sum_grades = count_grades = 0;
}

void Teacher::free() {
    delete[] name;
    sum_grades = count_grades = 0;
}

Teacher::~Teacher() {
    free();
}

void Teacher::setName(const char *name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

const char *Teacher::getName() const {
    return name;
}

void Teacher::addGrade(const int grade) {
    sum_grades += grade;
    count_grades++;
}

void Teacher::editGrade(const int grade) {
    sum_grades += grade;
}

double Teacher::getAverageGrade() const {
    return (double) sum_grades / count_grades;
}