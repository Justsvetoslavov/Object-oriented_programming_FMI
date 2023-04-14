#include "Task.h"

Task::Task() {
    name = new char[1];
    name[0] = '\0';
    count_students = 0;
    student = nullptr;
}

void Task::free() {
    delete[] name;
    for (int i = 0; i < count_students; ++i) {
        delete[] student[i];
    }
    delete[] student;
    count_students = 0;
}

Task::~Task() {
    free();
}

Task::Task(const char *name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    count_students = 0;
    student = nullptr;
}

void Task::setName(const char *name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Task::addStudent(const int num, const int grade, const int teacher) {
    int **n_student = new int *[count_students + 1];
    for (int i = 0; i < count_students; ++i) {
        n_student[i] = new int[SIZE];
        for (int j = 0; j < SIZE; ++j)
            n_student[i][j] = student[i][j];
    }
    n_student[count_students] = new int[SIZE];
    n_student[count_students][0] = num;
    n_student[count_students][1] = grade;
    n_student[count_students][2] = teacher;
    for (int i = 0; i < count_students; ++i) {
        delete[] student[i];
    }
    delete[] student;
    count_students++;
    student = n_student;
}

const char *Task::getName() const {
    return name;
}


void Task::copyFrom(const Task &task) {
    name = new char[strlen(task.name) + 1];
    strcpy(name, task.name);
    count_students = task.count_students;
    student = new int *[count_students];
    for (int i = 0; i < count_students; ++i) {
        student[i] = new int[SIZE];
        for (int j = 0; j < SIZE; ++j)
            student[i][j] = task.student[i][j];
    }
}

Task::Task(const Task &Task) {
    copyFrom(Task);
}

Task &Task::operator=(const Task &Task) {
    if (this != &Task) {
        free();
        copyFrom(Task);
    }
    return *this;
}

int Task::findStudent(const int num) const {
    for (int i = 0; i < count_students; ++i)
        if (num == student[i][0])
            return i;
    return -1;
}

int Task::getTeacher(const int pos) const {
    return student[pos][2];
}

int Task::diffGrade(const int pos, const int grade) const {
    return grade - student[pos][1];
}

void Task::editGrade(const int pos, const int grade) {
    student[pos][1] = grade;
}

double Task::getAverageGrade() const {
    int grade = 0;
    for (int i = 0; i < count_students; ++i)
        grade += student[i][1];
    return (double) grade / count_students;
}