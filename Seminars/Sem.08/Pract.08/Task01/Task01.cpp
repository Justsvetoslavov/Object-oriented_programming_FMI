#include <iostream>
#include "OOPCourse.h"

int main()
{
	while (true) {
		Teacher teacher("Teacher");
		Teacher assistant("Assistant");

		OOPCourse course(&teacher, &assistant);
		course.AddStudent("Stoycho Kyosev", 42069);
		course.AddStudent("Yavor Alexandrov", 69420);
		course.AddStudent("Angel Dimitriev", 50666);

		course.AddGrade(50666, "HW1", 6, &assistant);
		course.AddGrade(42069, "HW1", 6, &teacher);
		course.AddGrade(42069, "Test1", 5, &assistant);

		std::cout << course.GetAverageFromTeacher("Teacher");
	}

}