#include "Course.h"

Course::Course() {
    students = nullptr;
    tasks = nullptr;
    count_teachers = count_students = 0;
}

Course::Course(const char *lecture) : Course() {
    this->teachers[count_teachers++].setName(lecture);
}

Course::Course(const char *lecture, const char *assist1) : Course(lecture) {
    teachers[count_teachers++].setName(assist1);
}

Course::Course(const char *lecture, const char *assist1, const char *assist2) : Course(lecture, assist1) {
    teachers[count_teachers++].setName(assist2);
}

Course::Course(const char *lecture, const char *assist1, const char *assist2, const char *assist3) : Course(lecture,
                                                                                                            assist1,
                                                                                                            assist2) {
    teachers[count_teachers++].setName(assist3);
}

void Course::free() {
    delete[] students;
    delete[] tasks;
    count_teachers = count_students = 0;
}

Course::~Course() {
    free();
}

void Course::addStudent(const Student &student) {
    Student *new_students = new Student[count_students + 1];
    for (int i = 0; i < count_students; ++i)
        new_students[i] = students[i];
    new_students[count_students++] = student;
    delete[] students;
    students = new_students;
}

int Course::findTask(const char *name) const {
    for (int i = 0; i < count_tasks; ++i) {
        if (strcmp(tasks[i].getName(), name) == 0)
            return i;
    }
    return -1;
}

int Course::findTeacher(const char *name) const {
    for (int i = 0; i < count_teachers; ++i) {
        if (strcmp(teachers[i].getName(), name) == 0)
            return i;
    }
    return -1;
}

int Course::findStudent(const int fac_num) const {
    for (int i = 0; i < count_students; ++i) {
        if (students[i].getNum() == fac_num)
            return i;
    }
    return -1;
}

void Course::addTask(const Task &task) {
    Task *new_task = new Task[count_tasks + 1];
    for (int i = 0; i < count_tasks; ++i)
        new_task[i] = tasks[i];
    new_task[count_tasks++] = task;
    delete[] tasks;
    tasks = new_task;
}

void Course::addGrade(const int num, const char *task, int grade, const char *teacher) {
    int pos_stud = findStudent(num),
            pos_task = findTask(task),
            pos_teacher = findTeacher(teacher);
    if (pos_stud != -1 && pos_teacher != -1) {
        if (pos_task == -1) {
            addTask(Task(task));
            pos_task = findTask(task);
        }
        if (tasks[pos_task].findStudent(num) == -1) {
            tasks[pos_task].addStudent(num, grade, pos_teacher);
            teachers[pos_teacher].addGrade(grade);
            students[pos_stud].addGrade(grade);
        }
    }
}

void Course::editGrade(const int num, const char *task, int new_grade, const char *teacher) {
    int pos_stud = findStudent(num),
            pos_task = findTask(task),
            pos_teacher = findTeacher(teacher);
    if (pos_stud != -1 && pos_teacher != -1 && pos_task != -1) {
        int pos_stund_task = tasks[pos_task].findStudent(num);
        if (pos_stund_task != -1) {
            if (pos_teacher == tasks[pos_task].getTeacher(pos_stund_task)) {
                int diff = tasks[pos_task].diffGrade(pos_stund_task, new_grade);
                tasks[pos_task].editGrade(pos_stund_task, new_grade);
                teachers[pos_teacher].editGrade(diff);
                students[pos_stud].editGrade(diff);
            }
        }
    }
}

double Course::getAverageForCourse() const {
    double res = 0;
    for (int i = 0; i < count_tasks; ++i)
        res += tasks[i].getAverageGrade();
    return res / count_tasks;
}

double Course::getAverageGradePerTask(const char *name) const {
    int pos = findTask(name);
    if (pos != -1)
        return tasks[pos].getAverageGrade();
    return 0;
}

double Course::getAverageFromTeacher(const char *name) const {
    int pos = findTeacher(name);
    if (pos != -1)
        return teachers[pos].getAverageGrade();
    return 0;
}

void Course::mySwapStudents(Student &st1, Student &st2) {
    Student temp = st1;
    st1 = st2;
    st2 = temp;
}

void Course::removeStudent(const int num) {
    int pos = findStudent(num);
    if (pos != -1) {
        Student *n_student = new Student[count_students - 1];
        mySwapStudents(students[pos], students[--count_students]);
        for (int i = 0; i < count_students; ++i)
            n_student[i] = students[i];
        delete[] students;
        students = n_student;
    }
}