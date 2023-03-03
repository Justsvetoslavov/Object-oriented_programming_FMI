#include <iostream>

struct Student
{
    char name[31];
    unsigned int facultyNumber;
};

void initStudent(Student& student, const char name[31], const unsigned int facultyNumber)
{
    int i = 0;
    while(name[i] != '\0')
        student.name[i] = name[i++];
    student.name[i] = '\0';
    student.facultyNumber = facultyNumber;
}
void printStudent(const Student student)
{
    std::cout << "Student's name: ";
    for (size_t i = 0; student.name[i] != '\0'; i++)
        std::cout << student.name[i];
    std::cout << std::endl;
    std::cout << "Student's faculty number: " << student.facultyNumber << std::endl;
}

int main()
{
    Student st = { "Gosho", 10 };
    Student* pSt = &st;
    const Student* pCSt = &st;
    Student* const cPSt = &st;
    const Student* const cpCSt = &st;
    Student& refSt = st;
    const Student& refCSt = st;

    std::cout << "Student's start info:\n";
    printStudent(st);
    std::cout << std::endl;

    initStudent(*pSt, "Ivan", 13);
    std::cout << "Student's info after changing values via pointer:\n";
    printStudent(st);
    std::cout << std::endl;

    //initStudent(*pCSt, "Gosho", 11); - Will not work, because the pointer is refering to a constant (in this case it acts as if st is a constant)
    
    initStudent(*cPSt, "Gosho", 11); //We are not able to change the variable this pointer is refering to
    std::cout << "Student's info after changing values via constant pointer:\n";
    printStudent(st);
    std::cout << std::endl;

    //initStudent(*cpCSt, "Gosho", 11); - Will not work, because the constant pointer is refering to a constant (in this case it acts as if st is a constant)

    initStudent(refSt, "Ivan", 14); //Using a reference to change the value of st
    std::cout << "Student's info after changing values via reference:\n";
    printStudent(st);

    //initStudent(refCSt, "Gosho", 11); - Will not work, because the reference is refering to a constant (in this case it acts as if st is a constant)
    return 0;
}