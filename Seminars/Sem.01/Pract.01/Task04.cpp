#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct Student
{
    char name[31];
    unsigned int number;
};

void initStudent(Student& st)
{
    cout << "Enter name: ";
    cin.getline(st.name, 31);
    cout << "Enter faculty number: ";
    cin >> st.number;
    cin.ignore();
}

void printStudent(const Student& st)
{
    cout << "Name: " << st.name << endl;
    cout << "faculty number: " << st.number << endl;
}

int main()
{
    Student st;
    initStudent(st);
    cout << endl;
    printStudent(st);
}

