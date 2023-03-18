#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

const int MAX_SIZE = 16;
const int MAX_STUDENT = 1024;
const char* FILE_NAME = "Students.csv";

enum HairColor {
    brown,
    black,
    blond,
    red,
    white
};

struct Student {
    char name[MAX_SIZE];
    char surname[MAX_SIZE];
    int fn;
    double averageGrade;
    HairColor hairColor;
};

void InitStudent(Student& student)
{
    cin.ignore();
    cin.clear();

    cout << "Enter name: ";
    cin.getline(student.name, MAX_SIZE);

    cout << "Enter surname: ";
    cin.getline(student.surname, MAX_SIZE);

    cout << "Enter fc: ";
    do {
        cin >> student.fn;
    } while (student.fn < 10000 && student.fn < 9999);

    cout << "Enter average grade: ";
    cin >> student.averageGrade;

    int hairColor;
    cout << "Enter hair color(0 - brouwn, 1 - black, 2 - blond, 3 - red, 4 - white): ";
    cin >> hairColor;
    student.hairColor = (HairColor)hairColor;
}

void WriteStudentToFile(ofstream& file, Student& student)
{
    if (!file.is_open())
    {
        cout << "Error";
        return;
    }

    file << "Name: " << student.name << ", " << endl;

    file << "Surname: " << student.surname << ", " << endl;

    file << "FN: " << student.fn << ", " << endl;

    file << "Average grade: " << student.averageGrade << ", " << endl;

    file << "Hair color: ";
    switch (student.hairColor)
    {
    case HairColor::brown:file << "brown"; break;
    case HairColor::black:file << "black"; break;
    case HairColor::blond:file << "blond"; break;
    case HairColor::red:file << "red"; break;
    case HairColor::white:file << "white"; break;
    }
}

static const char* enum_string[] = { "brown",
    "black",
    "blond",
    "red",
    "white" };

string convertToenum(int val)
{
    string MyStr(enum_string[val]);
    return MyStr;
}

void ReadSudentFromFile(ifstream& file, Student& student)
{
    if (!file.is_open())
    {
        cout << "Error";
        return;
    }

    file.getline(student.name, MAX_SIZE, ',');

    file.getline(student.surname, MAX_SIZE, ',');

    file >> student.fn;

    string hairColorStr;
    file >> hairColorStr;
    for (int i = 0; i < sizeof(enum_string) / sizeof(enum_string[0]); i++)
    {
        if (hairColorStr == enum_string[i])
        {
            student.hairColor = static_cast<HairColor>(i);
            break;
        }
    }
}

struct System {
    Student students[MAX_STUDENT];
    unsigned int count = 0;
};

void AddStudentToSystem(System& system, Student student)
{
    if (system.count <= MAX_STUDENT)
    {
        system.students[system.count] = student;
        system.count++;
    }
}

void WriteSystemToFile(ofstream& file, System& system)
{
    if (!file.is_open())
    {
        cout << "Error";
        return;
    }

    for (size_t i = 0; i < system.count; i++)
    {
        WriteStudentToFile(file, system.students[i]);
        file << endl;
    }
}

void ReadSystemFromFile(ifstream& file, System& system)
{
    if (!file.is_open())
    {
        cout << "Error";
        return;
    }

    for (size_t i = 0; i < system.count; i++)
    {
        ReadSudentFromFile(file, system.students[i]);
        
    }
}

void CreateSystem(System& system, Student& student, ofstream& writeFile, ifstream& readFile, size_t i)
{
    cout << "Enter student " << i + 1 << ": " << endl;
    InitStudent(student);
    AddStudentToSystem(system, student);
    WriteSystemToFile(writeFile, system);
    ReadSystemFromFile(readFile, system);
    cout << endl;
}

int main()
{
    Student student;
    System system;
    ofstream writeFile(FILE_NAME, std::ios::app);
    ifstream readFile(FILE_NAME);

    cout << "Enter the number of students: ";
    int studentsCount;

    do {
        cin >> studentsCount;
    } while (studentsCount < 1 && studentsCount > 1024);

    for (size_t i = 0; i < studentsCount; i++)
    {
        CreateSystem(system, student, writeFile, readFile, i);
    }

    writeFile.close();
    readFile.close();
}

