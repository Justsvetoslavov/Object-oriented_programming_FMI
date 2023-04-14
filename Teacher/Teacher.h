#pragma once

#include <cstring>

class Teacher {
    char *name;
    int sum_grades;
    int count_grades;

    void free();

public:
    Teacher();

    Teacher(const Teacher &student) = delete;

    ~Teacher();

    Teacher &operator=(const Teacher &student) = delete;

    void setName(const char *name);

    const char *getName() const;

    void addGrade(const int grade);

    void editGrade(const int grade);

    double getAverageGrade() const;
};