#include <iostream>
#include "Course/Course.h"

int main() {
    Course p("Lecturer1", "Assistant1");

    p.addStudent(Student("Stoycho Kyosev", 42069));
    p.addStudent(Student("Yavor Alexandrov", 69420));
    p.addStudent(Student("Angel Dimitriev", 00666));

    p.addGrade(42069, "HW1", 4, "Assistant1");
    p.addGrade(00666, "HW1", 6, "Lecturer1");
    p.addGrade(42069, "K1", 5, "Assistant1");

    std::cout << p.getAverageForCourse(); // 5

    p.removeStudent(42069);

    std::cout << p.getAverageGradePerTask("HW1"); // 5;

    std::cout << p.getAverageFromTeacher("Lecturer1"); //6

}