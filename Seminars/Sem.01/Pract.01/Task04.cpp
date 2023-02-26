#include <iostream>
int strLenght(char* str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
struct Student
{
    char name[30];
    unsigned int facultyNumber;
};  
Student initStudent(Student student)
{
    std::cin.getline(student.name, 30);
    std::cin >> student.facultyNumber;
    if (strLenght(student.name) > 30 || strLenght(student.name) < 1)
    {
        std::cout << "Name must be more than 0 or lower than 30 symbols" << std::endl;
    }
    if (student.facultyNumber < 0)
    {
        std::cout << "facultyNum must be positive" << std::endl;
    }
}

int main()
{
    Student student = { "Paco", 123 };
    Student *pStudent = &student;
    const Student* pCstudent = &student;
    Student* const cPStudent = &student;
    const Student* const cpCStudent = &student;
    Student& reftStudent = student;
    const Student& refCStudent = student;
}