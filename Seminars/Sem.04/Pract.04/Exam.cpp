#include <iostream>
#include "Exam.h"

Exam::Exam(const Task* tasks, int tasksLen, const unsigned int& minPointsToPass) {
	if (tasksLen != TASKS_COUNT) {
		std::cout << ERROR_MESSAGE << std::endl;
		return;
	}

	for (int i = 0; i < tasksLen; ++i)
		this->tasks[i] = tasks[i];

	changeMin(minPointsToPass);
}

void Exam::writeToFile() const {
	std::ofstream file(FILE_NAME, std::ios::out | std::ios::binary | std::ios::app);

	if (!file.is_open()) {
		std::cout << FILE_ERROR_MESSAGE << std::endl;
		return;
	}

	/*file.write((const char*)&minPointsToPass, sizeof(unsigned));
	for (Task t : this->tasks)
		t.writeToFile(file);*/

	file.write((const char*)this, sizeof(this));

	file.close();
}

void Exam::readFromFile() {
	std::ifstream file(FILE_NAME, std::ios::in | std::ios::binary);

	if (!file.is_open()) {
		std::cout << FILE_ERROR_MESSAGE << std::endl;
		return;
	}

	/*file.read((char*)&this->minPointsToPass, sizeof(unsigned));
	for (Task t : this->tasks)
		t.readFromFile(file);*/

	file.read((char*)this, sizeof(this));

	file.close();
}

void Exam::changeMin(const unsigned int& newMin) {
	if (newMin < 1) {
		std::cout << ERROR_MESSAGE << std::endl;
		return;
	}

	this->minPointsToPass = newMin;
}

void Exam::getMax() const {
	unsigned result = 0;
	for (Task t : this->tasks)
		result += t.getPoints();

	std::cout << "Max exam points: " << result << std::endl;
}