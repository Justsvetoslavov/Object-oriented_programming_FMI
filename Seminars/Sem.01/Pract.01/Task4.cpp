#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Student {
    char name[31];
    unsigned int facultyNumber;

    void initStudent() {
        cout << "Name: ";
        cin.getline(name, 31);

        cout << "Faculty number: ";
        cin >> facultyNumber;
    }

    void printStudentInfo() {
        cout << "Student info:" << endl << " Name: " << name << endl << " Faculty number: " << facultyNumber << endl;
    }
};


int main() {

    Student s;
    s.initStudent();
    s.printStudentInfo();

    Student st = { "Gosho", 10 };
    Student *pSt = &st;
    pSt->facultyNumber = 100;
    pSt = &s;

    st.printStudentInfo();
    pSt->printStudentInfo();

    const Student* pCSt = &st;
    // pCSt->facultyNumber = 100;
    pCSt = &s;

    Student* const cPSt = &st;
    cPSt->facultyNumber = 1;
    //cPSt = &s;

    const Student* const cpCSt = &st;
    //cpCSt->facultyNumber = 100;
    //cpCSt = &s;

    Student& refSt = st;
    const Student& refCSt = st;
    //refCSt.facultyNumber = 100;
    //refCSt = s;

    return 0;
}