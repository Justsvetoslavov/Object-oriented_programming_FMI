#include "Exam.hpp"

Exam::Exam() {
    for (Task &task: tasks) {
        task = Task();
    }
    minPointsToPass = 0;
}

Exam::Exam(Task tasks[], size_t numberOfTasks, int minPointsToPass) {
    for (size_t i = 0; i < numberOfTasks; i++) {
        this->tasks[i] = tasks[i];
    }
    this->minPointsToPass = minPointsToPass;
}

void Exam::writeToFile(const char *fileName) {
    ofstream file(fileName, std::ios::binary);
    file.write((char *) this, sizeof(Exam));
    file.close();
}

void Exam::readFromFile(const char *fileName) {
    ifstream file(fileName, std::ios::binary);
    file.read((char *) this, sizeof(Exam));
    file.close();
}

void Exam::changeMinPointsToPass(int newMinPointsToPass) {
    minPointsToPass = newMinPointsToPass;
}

size_t Exam::getMaxPoints() {
    size_t maxPoints = 0;
    for (Task &task: tasks) {
        maxPoints += task.getPoints();
    }
    return maxPoints;
}