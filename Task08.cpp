#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int MAX_NAME_SIZE = 30;

struct Student {
    char name[MAX_NAME_SIZE + 1];
    int fac_num;
    float grade;
};

struct Group {
    int number_of_students;
    Student *students = new Student[number_of_students];
    double average_grade;
    ~Group() {
        delete[] students;
    }
};

Group create_group() {
    int num;
    double average_grade = 0;
    cout << "Number of students: ";
    cin >> num;
    Group res{num};
    for (int i = 0; i < num; ++i) {
        cout << "Name of student " << i + 1 << ": ";
        cin.getline(res.students[i].name, MAX_NAME_SIZE);
        cin.ignore();
        cout << "Fac. number of student " << i + 1 << ": ";
        cin >> res.students[i].fac_num;
        cout << "Grade of student " << i + 1 << ": ";
        cin >> res.students[i].grade;
        average_grade += res.students[i].grade;
    }
    res.average_grade = average_grade / num;
    return res;
}

int how_many_students_get_money(const Group& group, const double min_grade) {
    int res = 0;
    for (int i = 0; i < group.number_of_students; ++i) {
        if (group.students[i].grade < min_grade)
            continue;
        res++;
    }
    return res;
}

void swap_students(Student& st1, Student& st2) {
    Student agent = st1;
    st1 = st2;
    st2 = agent;
}

void sort_by_grade(Group& group) {
    int max_pos;
    for (int i = 0; i < group.number_of_students - 1; ++i) {
        max_pos = i;
        for (int j = i + 1; j < group.number_of_students; ++j)
            if (group.students[j].grade > group.students[max_pos].grade)
                max_pos = j;
        if (max_pos != i)
            swap_students(group.students[i], group.students[max_pos]);
    }
}

Group students_with_money(const Group& group, const double min_grade) {
    int pos = 0;
    double average_grade = 0;
    Group res{how_many_students_get_money(group, min_grade)};
    for (int i = 0; i < group.number_of_students; ++i) {
        if (group.students[i].grade < min_grade)
            continue;
        res.students[pos++] = group.students[i];
        average_grade += group.students[i].grade;
    }
    res.average_grade = average_grade / res.number_of_students;
    sort_by_grade(res);
    return res;
}

void print_student(const Student student) {
    cout << "Name: " << student.name << endl;
    cout << "Fac. num: " << student.fac_num << endl;
    cout << "Grade: " << student.grade << endl;
}

void print_group(const Group& group) {
    cout << "Number of students in group: " << group.number_of_students << endl;
    for (int i = 0; i < group.number_of_students; ++i)
        print_student(group.students[i]);
    cout << "Average grade: " << group.average_grade << endl;
}

int main()
{
    Group ex1 = create_group();
    Group ex2 = students_with_money(ex1, 2);
    print_group(ex2);
}
