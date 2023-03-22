#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_NAME_SIZE = 16;
const int MAX_STUDENTS_SIZE = 1024;

const char *SHC_BROWN = "Brown";
const char *SHC_BLACK = "Black";
const char *SHC_BLONDE = "Blonde";
const char *SHC_RED = "Red";
const char *SHC_WHITE = "White";

enum class StudentHairColor
{
    Brown,
    Black,
    Blonde,
    Red,
    White
};

struct Student
{
    char FirstName[MAX_NAME_SIZE + 1];
    char LastName[MAX_NAME_SIZE + 1];
    unsigned FacultyNumber;
    double AverageGrade;
    StudentHairColor HairColor;
};

const char *HairColorToString(const StudentHairColor &color)
{
    switch (color)
    {
        case StudentHairColor::Brown:
            return SHC_BROWN;
        case StudentHairColor::Black:
            return SHC_BLACK;
        case StudentHairColor::Blonde:
            return SHC_BLONDE;
        case StudentHairColor::Red:
            return SHC_RED;
        case StudentHairColor::White:
            return SHC_WHITE;
    }

    return "";
}

StudentHairColor StringToHairColor(const char *str)
{
    if (strcmp(str, SHC_BROWN) == 0)
        return StudentHairColor::Brown;
    if (strcmp(str, SHC_BLACK) == 0)
        return StudentHairColor::Black;
    if (strcmp(str, SHC_BLONDE) == 0)
        return StudentHairColor::Blonde;
    if (strcmp(str, SHC_RED) == 0)
        return StudentHairColor::Red;
    if (strcmp(str, SHC_WHITE) == 0)
        return StudentHairColor::White;

    return StudentHairColor::Brown;
}

void WriteStudentToCSV(std::ofstream &file, const Student &student)
{
    if (!file.is_open())
        return;

    file <<
         student.FirstName << "," <<
         student.LastName << "," <<
         student.FacultyNumber << "," <<
         student.AverageGrade << "," <<
         HairColorToString(student.HairColor) <<
         std::endl;
}

Student ReadStudentFromCSV(std::ifstream &file)
{
    Student s{};

    char buffer[MAX_NAME_SIZE + 1];
    file.getline(s.FirstName, MAX_NAME_SIZE + 1, ',');
    file.getline(s.LastName, MAX_NAME_SIZE + 1, ',');
    file.getline(buffer, MAX_NAME_SIZE + 1, ','); // Faculty number
    s.FacultyNumber = (unsigned) strtol(buffer, nullptr, 10);
    file.getline(buffer, MAX_NAME_SIZE + 1, ','); // Average grade
    s.AverageGrade = strtod(buffer, nullptr);
    file.getline(buffer, MAX_NAME_SIZE + 1, '\n'); // Hair color.
    s.HairColor = StringToHairColor(buffer);

    return s;
}

void PrintStudent(const Student &student)
{
    std::cout << student.FirstName << " " <<
              student.LastName << " -- " <<
              student.FacultyNumber << ", " <<
              student.AverageGrade << ", " <<
              HairColorToString(student.HairColor) <<
              std::endl;
}

int main()
{
    Student students[MAX_STUDENTS_SIZE];
    size_t currentStudent = 0;

    std::cout << "===== READING FROM FILE =====\n";

    std::ifstream readFile("read.csv");
    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            students[currentStudent++] = ReadStudentFromCSV(readFile);
        }

        for (int i = 0; i < currentStudent - 1; ++i)
            PrintStudent(students[i]);
    } else
    {
        std::cout << "\"read.csv\" couldn't be opened!\n";
    }

    std::cout << "===== WRITING TO FILE =====\n";

    std::ofstream writeFile("writeFile.csv");
    if (!writeFile.is_open())
    {
        std::cout << "\"writeFile.csv\" couldn't be opened!\n";
        return -1;
    }

    students[0] = {"Ivan", "Petrov", 34546, 4.20, StudentHairColor::White};
    students[1] = {"Peter", "Ivanov", 64543, 2.40, StudentHairColor::Brown};
    currentStudent = 2;

    for (int i = 0; i < currentStudent - 1; ++i)
        WriteStudentToCSV(writeFile, students[i]);

    for (int i = 0; i < currentStudent - 1; ++i)
        PrintStudent(students[i]);
}