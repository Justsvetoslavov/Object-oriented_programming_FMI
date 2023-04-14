#include "OOPcourse.h"

#include <iostream>

int main()
{
    Teacher l1("Lecturer1");
    Teacher a1("Assistant1");
    Teacher a2("Assistant2");
    Teacher a3("Assistant3");

    Student arr[4];
    arr[0] = Student("Ivan1", 18382);
    arr[1] = Student("Ivan2", 288239);
    arr[2] = Student("Ivan3", 121332);
    arr[3] = Student("Ivan4", 2646372);

    OOPcourse c(&l1, &a1, &a2, &a3);
    for (int i = 0; i < 4; i++) {
        c.addStudent(arr[i]);
    }

    c.addGrade(18382, "HW1", 5.51, l1);
    c.addGrade(18382, "HW1", 5.52, l1); // The grade will not be changed
    c.addGrade(18382, "HW2", 5.23, a1);
    c.addGrade(18382, "HW3", 4.56, a2);
    c.addGrade(18382, "HW4", 3.56, a3);

    c.addGrade(288239, "HW1", 3.35, a1);
    c.addGrade(288239, "HW2", 5.13, a1);
    c.addGrade(288239, "HW3", 6.00, l1);
    c.addGrade(288239, "HW4", 4.18, a3);

    c.addGrade(121332, "HW1", 4.35, a1);
    c.addGrade(121332, "HW2", 3.73, a1);
    c.addGrade(121332, "HW3", 5.96, a2);
    c.addGrade(121332, "HW4", 4.21, a3);

    c.addGrade(2646372, "HW1", 3.16, l1);
    c.addGrade(2646372, "HW2", 5.72, l1);
    c.addGrade(2646372, "HW3", 4.82, a3);
    c.addGrade(2646372, "HW4", 4.21, a3);

    c.changeGrade(121332, "HW3", 3.45);
    c.changeGrade(121332, "HW4", 5.55);
    c.changeGrade(2646372, "HW1", 4.83);

    std::cout << "Average grade for course: " << c.getAverageForCourse() << std::endl;
    std::cout << std::endl;

    std::cout << c;

    c.removeStudent(121332);

    std::cout << std::endl;
    std::cout << "After removing student 3: " << std::endl;
    std::cout << c;
    std::cout << std::endl;

    std::cout << "Average from l1: " << c.getAverageFromTeacher(l1) << std::endl;
    std::cout << "Average from a1: " << c.getAverageFromTeacher(a1) << std::endl;
    std::cout << "Average from a2: " << c.getAverageFromTeacher(a2) << std::endl;
    std::cout << "Average from a3: " << c.getAverageFromTeacher(a3) << std::endl;

    std::cout << std::endl;
    std::cout << "Average for HW1: " << c.getAverageGradePerTask("HW1") << std::endl;
    std::cout << std::endl;

    c.~OOPcourse();
    std::cout << "After calling destructor:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << arr[i]; // After OOPcourse stops existing, the students and teachers still exist
    }

    std::cout << l1 << std::endl; 
    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;
    std::cout << a3 << std::endl;
}


