#include <iostream>

struct Student
{
    char name[30];
    unsigned int factNum;
};

void initStudent(Student st);
void printStudent(Student st);

int main()
{
    Student st;
    initStudent(st);
    printStudent(st);
}

void initStudent(Student st)
{
    std::cin.getline(st.name, 30);
    std::cin.ignore();
    std::cin >> st.factNum;
}

void printStudent(Student st)
{
    std::cout << st.name << " is student in FMI and his/her FN is " << st.factNum;
}
