#include "teacher.hpp"

Teacher::Teacher() {
    strcpy(this->name, "");
    this->age = 0;
    this->workYears = 0;
}

Teacher::Teacher(const char *name, size_t age, size_t workYears) {
    strcpy(this->name, name);
    this->age = age;
    this->workYears = workYears;

}

const char *Teacher::getName() const {
    return name;
}

size_t Teacher::getAge() const {
    return age;
}

size_t Teacher::getWorkYears() const {
    return workYears;
}

void Teacher::setName(const char *name) {
    strcpy(this->name, name);
}

void Teacher::setAge(const size_t age) {
    this->age = age;
}

void Teacher::setWorkYears(const size_t workYears) {
    this->workYears = workYears;
}
