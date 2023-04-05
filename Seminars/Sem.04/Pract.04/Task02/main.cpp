#include <iostream>

#include "Task02/Exam.h"

int main()
{
    Task tasks[3] = {
            Task("Task1", "Description", 15),
            Task("Task2", "Description1", 25),
            Task("Task3", "Description2", 35)
    };

    Exam ex(5, tasks, 3);

    ex.WriteToFile("file.dat");

    Exam ex1;
    ex1.ReadFromFile("file.dat");

    std::cout << "======ORIGINAL======\n";
    ex.Print();
    std::cout << "======READ======\n";
    ex1.Print();
}
