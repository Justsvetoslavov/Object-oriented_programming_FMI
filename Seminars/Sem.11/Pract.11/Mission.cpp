
#include "Mission.h"
#include <string>

Mission::Mission(unsigned int points, const char *title, const char *desc) : points(points), progress(0) {
    setTitle(title);
    setDescription(desc);
}

bool Mission::isComplete() const {
    return progress == 100;
}

unsigned Mission::getProgress() const {
    return progress;
}

void Mission::addProgress() {
    progress += 1;
}

const char *Mission::getTitle() const {
    return title;
}

const char *Mission::getDescription() const {
    return description;
}

unsigned Mission::getPoints() {
    return points;
}

void Mission::setTitle(const char *title) {
    this->title = new char[std::strlen(title) + 1];
    strcpy(this->title, title);
}

void Mission::setDescription(const char *desc) {
    this->description = new char[std::strlen(desc) + 1];
    strcpy(this->description, desc);
}

Mission::Mission(const Mission &other) {
    copyFrom(other);
}

Mission::Mission(Mission &&other) {
    moveFrom(std::moveFrom(other));
}

Mission &Mission::operator=(const Mission &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Mission &Mission::operator=(Mission &&other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Mission::~Mission() {
    free();
}

void Mission::free() {
    delete[]title;
    delete[] description;
}

void Mission::copyFrom(const Mission &other) {
    progress = other.progress;
    points = other.points;
    setDescription(other.description);
    setTitle(other.title);
}

void Mission::moveFrom(Mission &&other) {
    progress = other.progress;
    points = other.points;
    setDescription(other.description);
    other.description = nullptr;
    setTitle(other.title);
    other.title = nullptr;
}


