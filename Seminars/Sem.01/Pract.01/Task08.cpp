// Bozhidar, Group 1, practicum date 22.02.2023

#include <iostream>

const int NAME_MAX_CHARS = 31;
const int MAX_STUDENTS_IN_GROUP = 30;

struct Student
{
    char name[NAME_MAX_CHARS] = {'\0'};
    double grade = 0;
};

struct Group
{
    Student students[MAX_STUDENTS_IN_GROUP] = {{'\0', 0}};
    int studentsInGroup = 0;
    double averageGroupGrade = 0;
};

void initName(Student &student, const char name[])
{
    for (int i = 0; i < NAME_MAX_CHARS; ++i)
    {
        student.name[i] = name[i];
    }
}

void initStudent(Student &student, const char name[], const double &grade)
{
    if (name && grade)
    {
        initName(student, name);
        student.grade = grade;
    }
}

Group initGroup()
{
    Group group;
    int studentsCount = 0;
    double sumGrade = 0;

    std::cout << "Number of students: ";
    std::cin >> studentsCount;

    group.studentsInGroup = studentsCount;

    if (studentsCount < 0 || studentsCount > MAX_STUDENTS_IN_GROUP)
    {
        return group;
    }

    for (int i = 0; i < studentsCount; ++i)
    {
        Student student;

        char name[NAME_MAX_CHARS] = {'\0'};
        double grade = 0;

        std::cout << std::endl;

        std::cout << "Name: ";
        std::cin >> name;

        std::cin.ignore(1000, '\n');

        std::cout << "Grade: ";
        std::cin >> grade;

        if (std::cin.fail())
        {
            return group;
        }

        initStudent(student, name, grade);
        group.students[i] = student;

        sumGrade += grade;
    }

    std::cout << std::endl;

    group.averageGroupGrade = (double)sumGrade / studentsCount;

    return group;
}

void printStudentsList(const Student studentsList[], const int &studentsListSize, const double &minGrade)
{
    for (int i = 0; i < studentsListSize; ++i)
    {
        if (studentsList[i].grade < minGrade)
        {
            return;
        }

        std::cout << "Name: " << studentsList[i].name
                  << " -> Grade: " << studentsList[i].grade
                  << std::endl;
    }
    std::cout << std::endl;
};

void swap(Student studentsList[], const int &i, const int &j)
{
    Student temp = studentsList[i];
    studentsList[i] = studentsList[j];
    studentsList[j] = temp;
}

void sortStudentsByGrade(Student studentsList[], const int &studentsListSize)
{
    int idxCurrTopStudent = 0;

    for (int i = 0; i < studentsListSize - 1; ++i)
    {
        for (int j = i + 1; j < studentsListSize; ++j)
        {
            if (studentsList[idxCurrTopStudent].grade < studentsList[j].grade)
            {
                idxCurrTopStudent = j;
            }
        }
        swap(studentsList, idxCurrTopStudent, i);
    }
}

void scholarshipEligibleStudents(Group &group, const double &minGrade)
{
    sortStudentsByGrade(group.students, group.studentsInGroup);
    printStudentsList(group.students, group.studentsInGroup, minGrade);
}

int numberOfEligibleStudents(const Group &group, const double &minGrade)
{
    int count = 0;

    for (int i = 0; i < group.studentsInGroup; ++i)
    {
        if (group.students[i].grade >= minGrade)
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    Group group = initGroup();

    std::cout << "Number of eligible students: " << numberOfEligibleStudents(group, 5) << std::endl;
    scholarshipEligibleStudents(group, 4.5);
}

/* Example input
7
a
2.89
b
6
c
3.63
d
5.57
e
3.14
f
4.24
e
3.98
*/