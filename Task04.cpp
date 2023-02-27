#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int NAME_SIZE_MAX = 30;

struct Student {
    char name[NAME_SIZE_MAX + 1];
    uint64_t fac_num;
};

void printStudent(const Student& student) {
    cout << "Name: " << student.name << endl
         << "Fac. number: " << student.fac_num << endl;
}

void strTrans(char str1[], const char str2[]) {
    int rotator = -1;
    while (str2[++rotator] != '\0' && rotator != NAME_SIZE_MAX)
        str1[rotator] = str2[rotator];
    str1[rotator] = '\0';
}

void initStudent(Student& student, const char name[], const int fac_num) {
    strTrans(student.name, name);
    student.fac_num = fac_num;
}

int main() {
    Student st = { "Gosho", 10 };
    printStudent(st);
    Student* pSt = &st;
    printStudent(*pSt);
    initStudent(*pSt, "Test1", 1);
    printStudent(*pSt);
    const Student* pCSt = &st;
    printStudent(*pCSt);
//    initStudent(*pCSt, "Test2", 2);  can't change
//    printStudent(*pCSt);
    Student* const cPSt = &st;
    printStudent(*cPSt);
    initStudent(*cPSt, "Test3", 3);
    printStudent(*cPSt);
    const Student* const cpCSt = &st;
    printStudent(*cpCSt);
//    initStudent(*cpCSt, "Test4", 4);  can't change
//    printStudent(*cpCSt);
    Student& refSt = st;
    printStudent(refSt);
    initStudent(refSt, "Test5", 5);
    printStudent(refSt);
    const Student& refCSt = st;
    printStudent(refCSt);
//    initStudent(refCSt, "Test6", 6);  can't change
//    printStudent(refCSt);
}
