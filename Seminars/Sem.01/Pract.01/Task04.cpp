#include <iostream>

const short MAX_NAME_SIZE = 30;

struct Student
{
    char name[MAX_NAME_SIZE + 1];
    unsigned int fn;
};

void InitStudent(Student& student, const char* name, unsigned int fn)
{
    strcpy_s(student.name, MAX_NAME_SIZE, name);
    student.fn = fn;
}

void PrintStudent(const Student& student)
{
    std::cout << student.name << " " << student.fn << "\n";
}

int main()
{
    Student st = { "Joro", 10 };
    PrintStudent(st);
    st = {"Ivan", 20 };
    PrintStudent(st);
    InitStudent(st, "New Name", 82);
    PrintStudent(st);
    std::cout << "\n\n";

    Student* pSt = &st;
    *pSt = { "Valeri", 30 };
    PrintStudent(*pSt);
    InitStudent(*pSt, "PST New Name", 100);
    PrintStudent(*pSt);
    std::cout << "\n\n";

    const Student* pCSt = &st;
    //*pCSt = { "Valeri", 30 };
    //initStudent(*pCSt, "PST New Name", 100);

    Student* const cPSt = &st;
    *cPSt = { "Ivaylo", 1000 };
    PrintStudent(*cPSt);
    InitStudent(*cPSt, "CPST New Name", 100);
    PrintStudent(*cPSt);
    std::cout << "\n\n";

    const Student* const cpCSt = &st;
    //*cpCSt = { "Valeri", 30 };
    //initStudent(*cpCSt, "PST New Name", 100);

    Student& refSt = st;
    refSt = {"Valentin", 82};
    PrintStudent(refSt);
    InitStudent(refSt, "REFST New Name", 100);
    PrintStudent(refSt);

    const Student& refCSt = st;
    //refCSt = { "Valentin", 82 };
    //initStudent(refCSt, "PST New Name", 100);
}