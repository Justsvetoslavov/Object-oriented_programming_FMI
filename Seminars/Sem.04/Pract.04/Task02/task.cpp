#include "task.hpp"
#include "string.h"

Task::Task() {
    strcpy(name, "");
    strcpy(description, "");
    points = 0;
}

Task::Task(const char *name, const char *description, int points) {
    strcpy(this->name, name);
    strcpy(this->description, description);
    this->points = points;
}

void Task::setName(const char *name) {
    strcpy(this->name, name);
}

void Task::setDescription(const char *description) {
    strcpy(this->description, description);
}

void Task::setPoints(int points) {
    this->points = points;
}


const char *Task::getName() const {
    return name;
}

const char *Task::getDescription() const {
    return description;
}

int Task::getPoints() const {
    return points;
}
