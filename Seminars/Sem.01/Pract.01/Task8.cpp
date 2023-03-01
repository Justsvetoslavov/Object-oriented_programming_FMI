#include <iostream>

struct Student
{
    char name[31];
    char FN[11];
    double grade;
};

struct Group
{
    Student* students;
    double avgGrade;
};

void initStudent(Student& st);
bool validName(const char* name);
bool validGrade(const double grade);
void createGroup(Group& gr, const size_t numsOfSt);
void sumAvgGrade(Group& gr, const size_t numsOfSt);
void studentGetScholarship(Group& gr, const size_t numsOfSt, const double scholGrade);
void swap(Student& st1, Student& st2);
void bubbleSort(Student* st, const size_t numsOfSt);

int main()
{
    size_t numOfStudent;
    std::cin >> numOfStudent;
    std::cin.ignore();
    Group gr;
    createGroup(gr, numOfStudent);
    sumAvgGrade(gr, numOfStudent);
    std::cout << '\n' << "The avd grade is: " << gr.avgGrade << '\n';
    double scholGrade;
    std::cout << "Enter min grade for scholarship: ";
    std::cin >> scholGrade;
    studentGetScholarship(gr, numOfStudent, scholGrade);
    

    return 0;
}

void initStudent(Student& st)
{
    do
    {
        std::cin.getline(st.name, 31);
    } while (validName(st.name));
    std::cin.getline(st.FN, 11);
    do
    {
        std::cin >> st.grade;
    } while (!validGrade(st.grade));
    std::cin.ignore();
}

bool validName(const char* name)
{
    bool result = true;
    int index = 0;
    while (name[index] != '\0')
    {
        if (!('a' <= name[index] && name[index] <= 'z') || !('A' <= name[index] || name[index] <= 'Z'))
            result = false;
        index += 1;
    }
    return result;
}

bool validGrade(const double grade)
{
    return 2 <= grade && grade <= 6;
}

void createGroup(Group& gr, const size_t numsOfSt)
{
    Student* st = new Student[numsOfSt];
    for (size_t i = 0; i < numsOfSt; i++)
    {
        initStudent(st[i]);
    }
    gr.students = st;
}

void sumAvgGrade(Group& gr, const size_t numsOfSt)
{
    double sum = 0;
    for (size_t i = 0; i < numsOfSt; i++)
    {
        sum += gr.students[i].grade;
    }
    gr.avgGrade = sum / numsOfSt;
}

void studentGetScholarship(Group& gr, const size_t numsOfSt, const double scholGrade)
{
    bubbleSort(gr.students, numsOfSt);
    for (size_t i = 0; i < numsOfSt; i++)
    {
        if (gr.students[i].grade >= scholGrade)
            std::cout << gr.students[i].name << ": " << gr.students[i].grade << '\n';
    }
}

void swap(Student& st1, Student& st2)
{
    Student temp = st1;
    st1 = st2;
    st2 = temp;
}

void bubbleSort(Student* st, const size_t numsOfSt)
{
    for (size_t i = 0; i < numsOfSt; i++)
    {
        for (size_t j = i; j < numsOfSt; j++)
        {
            if (st[i].grade > st[j].grade)
                swap(st[i], st[j]);
        }
    }
}