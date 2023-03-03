#include <iostream>

struct Student
{
    char facultyNumber[11];
    float avgGrade;
};

void initStudent(Student& student)
{
    std::cout << "Enter student's faculty number: ";
    std::cin >> student.facultyNumber;

    std::cout << "Enter student's average grade: ";
    std::cin >> student.avgGrade;
    if (student.avgGrade < 2 || student.avgGrade > 6)
        student.avgGrade = 2;
}

struct Group
{
    Student* students;
    unsigned int count = 0;
    float avgGrade = 0;
};

void initGroup(Group& group, const unsigned int count)
{
    group.students = new Student[count];
    for (size_t i = 0; i < count; i++)
    {
        initStudent(group.students[i]);
        group.avgGrade += group.students[i].avgGrade;
    }
    group.count = count;
    group.avgGrade /= count;
}

int countOfScholarships(const Group group, const float minGrade)
{
    int count = 0;
    for (size_t i = 0; i < group.count; i++)
    {
        if (group.students[i].avgGrade >= minGrade)
            count++;
    }
    return count;
}

void printStudent(Student student)
{
    std::cout << "Student's FN: " << student.facultyNumber << "\n";
    std::cout << "Student's average grade: " << student.avgGrade << "\n\n";
}

void bubbleSort(Student* students, int count)
{
    for (size_t i = 0; i < count - 1; i++)
    {
        for (size_t j = i + 1; j < count; j++)
        {
            if (students[i].avgGrade < students[j].avgGrade)
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printScholarshipStudents(const Group group, const float minGrade)
{
    Student* scholarships = new Student[countOfScholarships(group, minGrade)];
    int scholarshipsIndex = 0;
    for (size_t i = 0; i < group.count; i++)
    {
        if (group.students[i].avgGrade >= minGrade)
            scholarships[scholarshipsIndex++] = group.students[i];
    }
    
    bubbleSort(scholarships, scholarshipsIndex);

    std::cout << "List of students who are going to get a scholarship\n" << 
                 "-----------------------------------------------------\n";

    for (int i = 0; i < scholarshipsIndex; i++)
        printStudent(scholarships[i]);

    delete[] scholarships;
}

int main()
{
    Group group;
    initGroup(group,3);
    printScholarshipStudents(group, 5.5);
    return 0;
}