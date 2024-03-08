#include <iostream>
#include <cstring>
#include "Task.h"

unsigned Task::getPoints() const {
	return this->points;
}

void Task::setName(const char* _name) {
	if (!_name) {
		std::cout << ERROR_MESSAGE << std::endl;
		return;
	}

	strcpy_s(this->name, _name);
}

void Task::setDescription(const char* _description) {
	if (!_description) {
		std::cout << ERROR_MESSAGE << std::endl;
		return;
	}

	strcpy_s(this->description, _description);
}

void Task::setPoints(const int& _points) {
	if (_points <= 0) {
		std::cout << ERROR_MESSAGE << std::endl;
		return;
	}

	this->points = _points;
}

void Task::writeToFile(std::ofstream& file) const {
	file.write((const char*)this, sizeof(this));
}

void Task::readFromFile(std::ifstream& file) {
	file.read((char*)this, sizeof(this));
}