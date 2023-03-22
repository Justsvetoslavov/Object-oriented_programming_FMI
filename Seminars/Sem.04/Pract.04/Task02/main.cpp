#include <iostream>
#include "exam.hpp"

using std::cin, std::cout, std::endl;

int main() {
    Task tasks[] = {
            Task("Task 1", "Description 1", 10),
            Task("Task 2", "Description 2", 20)
    };

    Exam exam(tasks, (sizeof(tasks) / sizeof(Task)), 15);
    exam.writeToFile("exam.bin");

    Exam exam2;
    exam2.readFromFile("exam.bin");
    cout << exam2.tasks[0].getName() << endl;
    cout << exam2.tasks[0].getDescription() << endl;
    cout << exam2.tasks[0].getPoints() << endl;
    cout << exam2.tasks[1].getName() << endl;
    cout << exam2.tasks[1].getDescription() << endl;
    cout << exam2.tasks[1].getPoints() << endl;
    cout << exam2.minPointsToPass << endl;
    cout << exam2.getMaxPoints() << endl;

    return 0;
}
