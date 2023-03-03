//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225

#include <iostream>

const int SIZE = 30;

struct Student
{
    char name[SIZE + 1];
    double grade;
};

struct Group
{
    int numberOfStudents;
    Student studentsList[SIZE * 2];
    double averageGrade;
};

void inputStudentsInfo(Student& student)
{
    std::cout << "Enter the name of the student: ";
    std::cin >> student.name;
    std::cout << "Enter the grade of the student: ";
    std::cin >> student.grade;
}

void inputGroup(Group& group)
{
    double sumOfGrades = 0;
    int counter = 0;
    std::cout << "Enter the number of students in the group: ";
    std::cin >> group.numberOfStudents;

    for (int i = 0; i < group.numberOfStudents; ++i)
    {

        inputStudentsInfo(group.studentsList[i]);
        sumOfGrades += group.studentsList[i].grade;
    }

    group.averageGrade = sumOfGrades / group.numberOfStudents;
}

int countOfScholarships(const Group& group, const double minGrade)
{
    int counter = 0;

    for (int i = 0; i < group.numberOfStudents; ++i)
    {
        if (group.studentsList[i].grade >= minGrade)
        {
            ++counter;
        }
    }

    return counter;
}

void swapStudents(Student studentsList[], const int &firstIndex, const int &secondIndex)
{
    Student temp = studentsList[firstIndex];
    studentsList[firstIndex] = studentsList[secondIndex];
    studentsList[secondIndex] = temp;
}

void printScholarshipsList(const Group& group, const double minGrade, Student student[])
{
    for (int i = 0; i < group.numberOfStudents; ++i)
    {
        if (student[i].grade >= minGrade)
        {
            std::cout << student[i].name << " " << student[i].grade << std::endl;
        }
    }
}

int main()
{
    Group group;
    inputGroup(group);
    const double minGrade = 5.00;
    std::cout << "The number of students who will receive scholarsips is: "
        << countOfScholarships(group, minGrade) << std::endl;
    std::cout << "Students who will receive scholarsips are: " << std::endl;
    printScholarshipsList(group, minGrade, group.studentsList);

    return 0;
}