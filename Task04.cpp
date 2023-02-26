#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int NAME_SIZE_MAX = 30;

struct Student {
    char name[NAME_SIZE_MAX + 1];
    uint64_t fac_num;
};

void initStudent(const Student& student) {
    cout << "Name: " << student.name << endl
         << "Fac. number: " << student.fac_num << endl;
}

void str_trans(char str1[], const char str2[]) {
    int rotator = -1;
    while (str2[++rotator] != '\0' && rotator != NAME_SIZE_MAX)
        str1[rotator] = str2[rotator];
    str1[rotator] = '\0';
}

void change_info(Student& student, const char name[], int fac_num) {
    str_trans(student.name, name);
    student.fac_num = fac_num;
}

int main() {
    Student st = { "Gosho", 10 };
    initStudent(st);
    Student* pSt = &st;
    initStudent(*pSt);
    change_info(*pSt, "Test1", 1);
    initStudent(*pSt);
    const Student* pCSt = &st;
    initStudent(*pCSt);
//    change_info(*pCSt, "Test2", 2);  can't change
//    initStudent(*pCSt);
    Student* const cPSt = &st;
    initStudent(*cPSt);
    change_info(*cPSt, "Test3", 3);
    initStudent(*cPSt);
    const Student* const cpCSt = &st;
    initStudent(*cpCSt);
//    change_info(*cpCSt, "Test4", 4);  can't change
//    initStudent(*cpCSt);
    Student& refSt = st;
    initStudent(refSt);
    change_info(refSt, "Test5", 5);
    initStudent(refSt);
    const Student& refCSt = st;
    initStudent(refCSt);
//    change_info(refCSt, "Test6", 6);  can't change
//    initStudent(refCSt);
}
