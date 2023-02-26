#include <iostream>

using std::cin, std::cout, std::endl;

const int nameSize = 30;

struct Student {
    char name[nameSize + 1];
    unsigned int facultyNumber;
};

void initStudent(Student &student) {
    cout << "Enter name: ";
    cin.getline(student.name, 31);
    cout << "Enter faculty number: ";
    cin >> student.facultyNumber;
    cin.ignore();
}

void printStudent(const Student &student) {
    cout << "Name: " << student.name << endl;
    cout << "Faculty number: " << student.facultyNumber << endl;
}

int main() {
    Student student{};
    initStudent(student);
    printStudent(student);
    return 0;
}
