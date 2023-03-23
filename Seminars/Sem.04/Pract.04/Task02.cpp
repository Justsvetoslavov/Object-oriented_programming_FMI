#include <iostream>
#include <cstring>
#include <fstream>

#include "Exam_Task02.h"

int main()
{
    Task tasks[3] = {
            Task("Task1", "Description", 15),
            Task("Task2", "Description1", 25),
            Task("Task3", "Description2", 35)
    };

    Exam ex(5, tasks, 3);

    std::ofstream writer("file.dat");
    ex.WriteToFile(writer);

    writer.close();

    std::ifstream reader("file.dat");

    Exam ex1;
    ex1.ReadFromFile(reader);

    std::cout << "======ORIGINAL======\n";
    ex.Print();
    std::cout << "======READ======\n";
    ex1.Print();
}
