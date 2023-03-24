#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>

const int NAME_SIZE = 16;
const int FN_SIZE = 5;
const char FILE_NAME[] = "students.cvs";

enum HairColour
{
    Brown, Black, Blonde, Ginger, White
};

struct Student
{
    char firstName[NAME_SIZE + 1];
    char lastName[NAME_SIZE + 1];
    char facNumber[FN_SIZE + 1];
    float averageGrade;
    HairColour hairColour;
};

struct Group
{
    Student students[1024];
    int count = 0;
};

void initStudent(Student& student)
{

    char buffer[NAME_SIZE + 1];
    std::cout << "First name: ";
    std::cin >> student.firstName;
    std::cout << "Last name: ";
    std::cin >> student.lastName;
    do
    {
        std::cout << "5 digit FN: ";
        std::cin >> student.facNumber;
    } while (strlen(student.facNumber) != FN_SIZE);
    do
    {
        std::cout << "Average grade: ";
        std::cin >> student.averageGrade;
        student.averageGrade = round(student.averageGrade * 100.0) / 100.0;
    } while (student.averageGrade < 2 || student.averageGrade > 6);
    char hairColour[7];
    bool flag = false;
    do
    {
        std::cout << "Hair colour: ";
        std::cin >> hairColour;
        if (strcmp(hairColour, "brown") == 0)
        {
            student.hairColour = Brown;
        }
        else if (strcmp(hairColour, "black") == 0)
        {
            student.hairColour = Black;
        }
        else if (strcmp(hairColour, "blonde") == 0)
        {
            student.hairColour = Blonde;
        }
        else if (strcmp(hairColour, "ginger") == 0)
        {
            student.hairColour = Ginger;
        }
        else if (strcmp(hairColour, "white") == 0)
        {
            student.hairColour = White;
        }
        else
        {
            flag = true;
        }
    } while (flag);
}

void writeSutendtInFile(const Student& student, const char fileName[])
{
    std::ofstream file(fileName, std::ios::app);
    if (!file.is_open())
    {
        std::cout << "Couldn't open the file " << fileName << "\n";
        return;
    }
    file << student.firstName << ","
        << student.lastName << ","
        << student.facNumber << ","
        << student.averageGrade << ","
        << student.hairColour << "\n";

    file.close();
}

bool isEmpty(std::ifstream& file);

void loadStudentsToGroup(Group& group)
{
    std::ifstream file(FILE_NAME);
    if (!file.is_open())
    {
        std::cout << "Couldn't open the file " << FILE_NAME << "\n";
        return;
    }

    if (isEmpty(file))
    {
        return;
    }

    Student student;
    int helper = 1;
    while (!file.eof())
    {
        if (helper == 6)
        {
            group.students[group.count++] = student;
            helper = 1;
            continue;
        }
        switch (helper)
        {
        case 1:
            file.getline(student.firstName, NAME_SIZE, ',');
            break;
        case 2:
            file.getline(student.lastName, NAME_SIZE, ',');
            break;
        case 3:
            file.getline(student.facNumber, FN_SIZE + 1, ',');
            break;
        case 4:
            char buff[5];
            file.getline(buff, 5, ',');
            student.averageGrade = atof(buff);
            break;
        case 5:
            char hc[2];
            file.getline(hc, 10);
            if (hc[0] == '0')
            {
                student.hairColour = Brown;
            }
            else if (hc[0] == '1')
            {
                student.hairColour = Black;
            }
            else if (hc[0] == '2')
            {
                student.hairColour = Blonde;
            }
            else if (hc[0] == '3')
            {
                student.hairColour = Ginger;
            }
            else if (hc[0] == '4')
            {
                student.hairColour = White;
            }
            break;
        default:
            break;
        }
        helper++;
    }
    file.close();
}

void printGroup(const Group& group)
{
    if (group.count == 0)
    {
        std::cout << "There are no students\n";
        return;
    }
    std::cout << "Here are all the students:\n-------------------------------\n";
    for (size_t i = 0; i < group.count; i++)
    {
        std::cout << "Student's name: " << group.students[i].firstName << " " << group.students[i].lastName << "\n"
            << "FN: " << group.students[i].facNumber << "\n"
            << "Average grade: " << group.students[i].averageGrade << "\n"
            << "Hair colour: ";
        switch (group.students[i].hairColour)
        {
        case 0: 
            std::cout << "Brown\n\n";
            break;
        case 1:
            std::cout << "Black\n\n";
            break;
        case 2:
            std::cout << "Blonde\n\n";
            break;
        case 3:
            std::cout << "Ginger\n\n";
            break;
        case 4:
            std::cout << "White\n\n";
            break;
        default:
            break;
        }
    }
}

bool isEmpty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

int main()
{
    int action;
    bool exit = false;
    Student student;
    Group group;
    do
    {
        std::cout << "1. Add student\n2. Show all students\n3. Exit\n"
            << "Choose the number of the action you want to make: ";
        std::cin >> action;
        switch (action)
        {
        case 1:
            initStudent(student);
            writeSutendtInFile(student, FILE_NAME);
            break;
        case 2:
            loadStudentsToGroup(group);
            printGroup(group);
            break;
        case 3:
            exit = true;
            break;
        default: std::cout << "Wrong input!\n";
            break;
        }
    } while (!exit);
    return 0;
}