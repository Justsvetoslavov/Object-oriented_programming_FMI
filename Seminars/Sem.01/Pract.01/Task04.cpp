// Bozhidar, Group 1, practicum date 22.02.2023

#include <iostream>

const int NAME_MAX_CHARS = 31;

struct Student
{
    char name[NAME_MAX_CHARS] = {'\0'};
    unsigned int facultyNumber = 0;
};

void initName(Student &student, const char name[])
{
    for (int i = 0; i < NAME_MAX_CHARS; ++i)
    {
        student.name[i] = name[i];
    }
}

void initStudent(Student &student, const char name[], const unsigned int &facultyNumber)
{
    if (name && facultyNumber)
    {
        initName(student, name);
        student.facultyNumber = facultyNumber;
    }
}

void printStudent(const Student &student)
{
    std::cout << "Name: ";

    for (int i = 0; i < NAME_MAX_CHARS; ++i)
    {
        std::cout << student.name[i];
    }

    std::cout << std::endl;

    std::cout << "Faculty number: " << student.facultyNumber << std::endl;
}

int main()
{
    Student student;

    char name[NAME_MAX_CHARS] = {'\0'};

    unsigned int facultyNumber = 0;

    std::cout << "Enter a name: ";
    std::cin >> name;

    std::cin.ignore();

    std::cout << "Enter a faculty number: ";
    std::cin >> facultyNumber;

    std::cout << std::endl;

    if (std::cin.fail())
    {
        std::cout << "Error taking input.";
        return 1;
    }

    initStudent(student, name, facultyNumber);

    printStudent(student);

    /*
                                    Pre definition    |   Change struct field
    Student st = {"Gosho", 10};          YES                    YES
    Student *pSt = &st;                  YES                    YES
    const Student *pCSt = &st;           YES                    NO    (read-only)
    Student *const cPSt = &st;           NO                     YES
    const Student *const cpCSt = &st;    NO                     NO
    Student &refSt = st;                 YES                    YES
    const Student &refCSt = st;          NO                     NO    (read-only)
    */

    return 0;
}

/* Sample input
Bozhidar
123456
*/