<<<<<<< Updated upstream
﻿#include <iostream>

const short MAX_NAME_LEN = 30;

struct Student {
    char name[MAX_NAME_LEN + 1];
    unsigned int FN;
};

void initStudent(Student& student, const char name[], unsigned int FN) {
    strcpy_s(student.name, MAX_NAME_LEN, name);
    student.FN = FN;
}

void printStudent(const Student& student) {
    std::cout << student.name << " " << student.FN << "\n";
}

int main()
{
    Student st = { "Gosho", 10 };
    printStudent(st);
    st = {"Ivan", 20 };
    printStudent(st);
    initStudent(st, "New Name", 82);
    printStudent(st);
    std::cout << "\n\n";

    Student* pSt = &st;
    *pSt = { "Valeri", 30 };
    printStudent(*pSt);
    initStudent(*pSt, "PST New Name", 100);
    printStudent(*pSt);
    std::cout << "\n\n";

    const Student* pCSt = &st;
    //*pCSt = { "Valeri", 30 };
    //initStudent(*pCSt, "PST New Name", 100);

    Student* const cPSt = &st;
    *cPSt = { "Ivaylo", 1000 };
    printStudent(*cPSt);
    initStudent(*cPSt, "CPST New Name", 100);
    printStudent(*cPSt);
    std::cout << "\n\n";

    const Student* const cpCSt = &st;
    //*cpCSt = { "Valeri", 30 };
    //initStudent(*cpCSt, "PST New Name", 100);

    Student& refSt = st;
    refSt = {"Valentin", 82};
    printStudent(refSt);
    initStudent(refSt, "REFST New Name", 100);
    printStudent(refSt);

    const Student& refCSt = st;
    //refCSt = { "Valentin", 82 };
    //initStudent(refCSt, "PST New Name", 100);
}

=======
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const short MAX_NEME_LEN = 30;

struct Student
{
    char name[MAX_NEME_LEN + 1];
    unsigned int fn;
};

void initStudent(Student& st, const char name[], unsigned int FN)
{
    cout << "Enter name: ";
    cin.getline(st.name, 31);
    cout << "Enter faculty number: ";
    cin >> st.fn;
    cin.ignore();
}

void printStudent(const Student& st)
{
    cout << "Name: " << st.name << endl;
    cout << "faculty number: " << st.fn << endl;
}

int main()
{
    Student st = { "Gosho", 10 };
    printStudent(st);
    st = { "Ivan", 20 };
    printStudent(st);
    initStudent(st, "New Name", 82);
    printStudent(st);
    std::cout << endl;

    Student* pSt = &st;
    *pSt = { "Valeri", 30 };
    printStudent(*pSt);
    initStudent(*pSt, "PST New Name", 100);
    printStudent(*pSt);
    std::cout << endl;

    const Student* pCSt = &st;
    //*pCSt = { "Valeri", 30 };
    //initStudent(*pCSt, "PST New Name", 100);

    Student* const cPSt = &st;
    *cPSt = { "Ivaylo", 1000 };
    printStudent(*cPSt);
    initStudent(*cPSt, "CPST New Name", 100);
    printStudent(*cPSt);
    std::cout << endl;

    const Student* const cpCSt = &st;
    //*cpCSt = { "Valeri", 30 };
    //initStudent(*cpCSt, "PST New Name", 100);

    Student& refSt = st;
    refSt = { "Valentin", 82 };
    printStudent(refSt);
    initStudent(refSt, "REFST New Name", 100);
    printStudent(refSt);

    const Student& refCSt = st;
    //refCSt = { "Valentin", 82 };
    //initStudent(refCSt, "PST New Name", 100);
}

>>>>>>> Stashed changes
