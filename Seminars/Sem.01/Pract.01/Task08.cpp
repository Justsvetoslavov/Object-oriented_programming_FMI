#include <iostream>
using std:: cout;
using std:: cin;

const int MAX_SIZE = 30;
const int MAX_NUM = 50;
struct Student
{
    char studentName[MAX_SIZE];
    double studentGrade;
};

struct Group
{
    char groupName[MAX_SIZE];
    int numberOfStudents;
    Student membersOfTheGroup[MAX_NUM];
    double avrGrade;
};

void addStudent(Student& member)
{
    cout << "Student name: ";
    cin >> member.studentName;
    cin.ignore();
    cout << "Student grade: ";
    cin >> member.studentGrade;
    cin.ignore();
}

void newGroup(Group& group)
{
    char* name = new char[MAX_SIZE];
    cout << "Group name: ";
    cin.getline(group.groupName, MAX_SIZE);
    cout << "The number of students in the group is: ";
    cin >> group.numberOfStudents;
    double sum=0;
    int br = 0;
    for(int i = 0; i<group.numberOfStudents; ++i)
    {
        Student student;
        addStudent(student); 
        group.membersOfTheGroup[i] = student;
        sum+=student.studentGrade;
        ++br;
    }

    group.avrGrade = sum/br;
}

int numberScholarship(const Group& group, const double& minGrade)
{
    int count = 0;
    for(int i = 0; i<group.numberOfStudents; i++)
    {
        if(group.membersOfTheGroup[i].studentGrade >= minGrade)
        {
            ++count;
        }
    }

    return count;
}

void sortScholarship(Student* membersOfTheGroup, const int& size)
{
    for(int i = 0; i<size-1; ++i)
    {
        for(int j = i+1; j<size; ++j)
        {
            if(membersOfTheGroup[i].studentGrade - membersOfTheGroup[j].studentGrade < 0)
            {
                Student temp = membersOfTheGroup[i];
                membersOfTheGroup[i] = membersOfTheGroup[j];
                membersOfTheGroup[j] = temp;
            }
        }
    }
}

void printScholarship(const Group& group, const double& minGrade)
{
    Student scholarShip[numberScholarship(group, minGrade)];
    for(int i = 0, j= 0; i<group.numberOfStudents; ++i)
    {
        if(group.membersOfTheGroup[i].studentGrade >= minGrade)
        {
            scholarShip[j] = group.membersOfTheGroup[i];
            ++j;
        }
    }

    sortScholarship(scholarShip,numberScholarship(group, minGrade));

    if(numberScholarship(group, minGrade)>0)
    {
        cout << "Top students: \n";
        for(int i = 0; i< numberScholarship(group, minGrade); ++i)
        {
            cout << i+1 << ". Name: " << scholarShip[i].studentName << " -> Grade: " << scholarShip[i].studentGrade << '\n';
        }
    }
}

int main()
{
    Group myGroup;
    newGroup(myGroup);
    const double minGrade = 4.70;
    cout << "Number of students with scholarship: " << numberScholarship(myGroup, minGrade) << '\n';
    printScholarship(myGroup, minGrade);
}