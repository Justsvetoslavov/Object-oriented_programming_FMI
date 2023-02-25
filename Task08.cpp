#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Student {
    char name[30];
    int fac_num;
    float grade;
};

struct Group {
    int number_of_students;
    Student *students = new Student[number_of_students];
    double avarage_grade;
    ~Group() {
        delete[] students;
    }
};

Group create_group() {
    int num;
    double avarage_grade = 0;
    cout << "Number of students: ";
    cin >> num;
    Group res{num};
    for (int i = 0; i < num; ++i) {
        cout << "Name of student " << i + 1 << ": ";
        cin >> res.students[i].name;
        cout << "Fac. number of student " << i + 1 << ": ";
        cin >> res.students[i].fac_num;
        cout << "Grade of student " << i + 1 << ": ";
        cin >> res.students[i].grade;
        avarage_grade += res.students[i].grade;
    }
    res.avarage_grade = avarage_grade / num;
    return res;
}

int how_many_students_get_money(const Group& group, double min_grade) {
    int res = 0;
    for (int i = 0; i < group.number_of_students; ++i) {
        if (group.students[i].grade < min_grade)
            continue;
        res++;
    }
    return res;
}

Group students_with_money(const Group& group, double min_grade) {
    int pos = 0;
    double avarage_grade = 0;
    Group res{how_many_students_get_money(group, min_grade)};
    for (int i = 0; i < group.number_of_students; ++i) {
        if (group.students[i].grade < min_grade)
            continue;
        res.students[pos++] = group.students[i];
        avarage_grade += group.students[i].grade;
    }
    res.avarage_grade = avarage_grade / res.number_of_students;
    return res;
}

int main()
{
    Group ex1 = create_group();
    Group ex2 = students_with_money(ex1, 4);
}