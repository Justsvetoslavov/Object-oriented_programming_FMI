//Gabriela Mladenova 
//SI
//Group 1
//3MI0600225
#include <iostream>

const int SIZE = 30;
struct Student
{
    char name[SIZE + 1];
    int facultyNum;
};
void initStudent(Student& st)
{
    std::cout << "Enter student's name: ";
    std::cin.getline(st.name, (SIZE + 1));
    std::cout << "Enter facuty number: ";
    std::cin >> st.facultyNum;
    std::cin.ignore();
}
void printStudent(const Student& st)
{
    std::cout << "Name: " << st.name << std::endl << "Faculty number: " << st.facultyNum << std::endl;
}
int main()
{
    Student st1 = {};
    initStudent(st1);
    printStudent(st1);

    return 0;
}
