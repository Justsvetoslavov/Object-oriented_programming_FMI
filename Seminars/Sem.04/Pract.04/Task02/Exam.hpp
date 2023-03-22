#include "task.hpp"
#include <fstream>

using std::ifstream, std::ofstream;

const size_t MAX_TASKS = 30;

struct Exam{
    Task tasks[MAX_TASKS];
    size_t minPointsToPass;

    Exam();

    Exam(Task tasks[], size_t numberOfTasks, int minPointsToPass);

    void writeToFile(const char *fileName);

    void readFromFile(const char *fileName);

    void changeMinPointsToPass(int newMinPointsToPass);

    size_t getMaxPoints();
};
