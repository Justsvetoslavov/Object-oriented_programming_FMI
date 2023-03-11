#include <iostream>
using std:: cout;
using std:: cin;

const int MAX_LENGHT = 30;

struct Student
{
    char studName[MAX_LENGHT];
    unsigned int facultyNum;
};

bool isCorrectLenght(const char* studName)
{
    int i = 0;
    while(studName[i] + '\0')
    {
        i++;
    }

    if(i<=MAX_LENGHT)
    {
        return true;
    }

    return false;
}

void saveName(const char* name, char* stdName)
{
    int br = 0;

    while(name[br] != '\0')
    {
        stdName[br] = name[br];
        br++;
    }

    stdName[br] = '\0';

}

void initStuden(Student& st, const char* name, const unsigned int& facultyNum)
{
    if(isCorrectLenght(name))
    {
        st.facultyNum = facultyNum;
        saveName(name, st.studName);
    }
}

void printStud(Student& std)
{
    char* studName = std.studName;
    cout << "Name: " << studName << "; Faculty number: " << std.facultyNum << '\n';
}

int main()
{
    Student st = { "Gosho", 10 }; // predefied - can; properties - can be changed
    Student *pSt = &st; // predefied - can; properties - can be changed
    const Student* pCSt = &st; // predefied - can; properties - cannot be changed
    Student* const cPSt = &st; // predefied - cannot; properties - can be changed
    const Student* const cpCSt = &st; // predefied - cannot; properties - cannot be changed
    Student& refSt = st; // predefied - can; properties - can be changed
    const Student& refCSt = st; // predefied - cannnot; properties - cannot be changed

    Student myStudent;
    initStuden(myStudent, "Ivan Petrov", 28);
    printStud(myStudent);

}