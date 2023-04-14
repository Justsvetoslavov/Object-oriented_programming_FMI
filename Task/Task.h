#pragma once

#include <cstring>

const int SIZE = 3;

class Task {
    char *name;
    int **student;
    int count_students;

    void free();

    void copyFrom(const Task &task);

public:
    Task();

    Task(const Task &student);

    Task(const char *name);

    ~Task();

    Task &operator=(const Task &student);

    void setName(const char *name);

    void addStudent(const int num, const int grade, const int teacher);

    const char *getName() const;

    int findStudent(const int num) const;

    int getTeacher(const int pos) const;

    int diffGrade(const int pos, const int grade) const;

    void editGrade(const int pos, const int grade);

    double getAverageGrade() const;
};