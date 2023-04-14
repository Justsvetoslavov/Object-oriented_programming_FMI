#include "../Student/Student.h"
#include "../Teacher/Teacher.h"
#include "../Task/Task.h"

class Course {
    Teacher teachers[4];
    Student *students;
    Task *tasks;
    int count_students;
    int count_teachers;
    int count_tasks;

    void free();

    int findTask(const char *name) const;

    int findTeacher(const char *name) const;

    int findStudent(const int fac_num) const;

    void addTask(const Task &task);

    void mySwapStudents(Student &st1, Student &st2);

public:
    Course &operator=(const Course &course) = delete;

    Course(const Course &course) = delete;

    Course();

    ~Course();

    Course(const char *lecture);

    Course(const char *lecture, const char *assist1);

    Course(const char *lecture, const char *assist1, const char *assist2);

    Course(const char *lecture, const char *assist1, const char *assist2, const char *assist3);

    void addStudent(const Student &student);

    void addGrade(const int num, const char *task, int grade, const char *teacher);

    void editGrade(const int num, const char *task, int new_grade, const char *teacher);

    double getAverageForCourse() const;

    double getAverageGradePerTask(const char *name) const;

    double getAverageFromTeacher(const char *name) const;

    void removeStudent(const int num);
};
