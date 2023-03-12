#pragma once
#pragma warning (disable: 4996)
#include "Student.h"

int toSeparator(const char*);

bool printStudent(const Student*, size_t, const int);

bool editFirstName(Student*, size_t, const int, const char*);

bool saveStudentsToFile(const Student* , size_t , const char*);

void interface(Student* , const int);
