#include <fstream>
#include "Exam.h"

Exam::Exam() {
	tasksCount = 0;
	SetMinPoints(0);
}

const Task* Exam::GetTasks() const {
	return tasks;
}

unsigned Exam::GetMinPoints() const {
	return minPoints;
}

void Exam::SetMinPoints(unsigned newMinPoints) {
	if (!AreMinPointsValid(newMinPoints)) {
		//error message
		return;
	}
	minPoints = newMinPoints;
}

bool Exam::AreMinPointsValid(unsigned minPoints) const {
	return minPoints <= GetMaxPoints();
}

void Exam::SetTasks(Task* tasks, unsigned tasksCount) {
	if (tasksCount > MAX_TASKS_COUNT) {
		//error message
		return;
	}
	for (size_t i = 0; i < tasksCount; i++) {
		this->tasks[i] = tasks[i];
	}
	this->tasksCount = tasksCount;
}

Exam::Exam(Task* tasks, unsigned tasksCount, unsigned minPoints) {
	SetTasks(tasks, tasksCount);
	SetMinPoints(minPoints);
}

void Exam::WriteToFile(const char* fileName) const {
	std::ofstream file(fileName, std::ios::out | std::ios::binary);
	if (!file.is_open())
	{
		//error message
		return;
	}

	file.write((const char*)&tasksCount, sizeof(unsigned));
	for (size_t i = 0; i < tasksCount; i++)
	{
		unsigned nameLength = strlen(tasks[i].GetName()) + 1;
		file.write((const char*)&nameLength, sizeof(unsigned));
		file.write((const char*)tasks[i].GetName(), nameLength);
		unsigned descriptionLength = strlen(tasks[i].GetDescription()) + 1;
		file.write((const char*)&descriptionLength, sizeof(unsigned));
		file.write((const char*)tasks[i].GetDescription(), descriptionLength);
		unsigned points = tasks[i].GetPoints();
		file.write((const char*)&points, sizeof(unsigned));
	}
	file.write((const char*)&minPoints, sizeof(unsigned));
	file.close();
}


void Exam::ReadFromFile(const char* fileName) {
	std::ifstream file(fileName, std::ios::in | std::ios::binary);
	if (!file.is_open())
	{
		//error message
		return;
	}
	file.read((char*)&tasksCount, sizeof(unsigned));
	for (size_t i = 0; i < tasksCount; i++)
	{
		unsigned nameLength = 0;
		file.read((char*)&nameLength, sizeof(unsigned));
		char* name = new char[nameLength];
		file.read((char*)name, nameLength);
		tasks[i].SetName(name);

		unsigned descriptionLength = 0;
		file.read((char*)&descriptionLength, sizeof(unsigned));
		char* description = new char[descriptionLength];
		file.read((char*)description, descriptionLength);
		tasks[i].SetDescription(description);

		unsigned points = 0;
		file.read((char*)&points, sizeof(unsigned));
		tasks[i].SetPoints(points);

		delete[] name;
		delete[] description;
	}
	file.read((char*)&minPoints, sizeof(unsigned));
	file.close();
}

unsigned Exam::GetMaxPoints() const {
	unsigned maxPoints = 0;
	for (size_t i = 0; i < tasksCount; i++) {
		maxPoints += tasks[i].GetPoints();
	}
	return maxPoints;
}



