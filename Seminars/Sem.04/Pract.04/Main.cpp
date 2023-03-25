#include <iostream>
#include "Task.h"
#include "Exam.h"

int main() {
	Task t1;
	char name[20] = "Zad2";
	char descr[20] = "des2";
	Task t2(name, descr, 20);
	Task tasks[2] = { t1,t2 };
	Exam e(tasks, 2, 10);
	e.WriteToFile("file.dat");
	/*Exam e;
	e.ReadFromFile("file.dat");
	for (size_t i = 0; i < 2; i++)
	{
		std::cout << e.GetTasks()[i].GetName() << std::endl;
		std::cout << e.GetTasks()[i].GetDescription() << std::endl;
		std::cout << e.GetTasks()[i].GetPoints() << std::endl;
	}*/
}