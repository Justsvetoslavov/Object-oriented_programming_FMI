#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable : 4996)

const int TASKS_MAX_COUNT = 15;
const char EXAM_FILE_NAME[] = "exam.txt";

const int MAX_NAME_SIZE = 15;
const int MAX_REQUIREMENT_SIZE = 256;

class Task {
private:
	char name[MAX_NAME_SIZE];
	char requirement[MAX_REQUIREMENT_SIZE];
	int points;

	bool IsInvalidName(const char* name) const;
	bool IsInvalidRequirement(const char* requirement) const;

public:
	Task();
	Task(const char* name, const char* requirement, int points);

	const char* GetName() const;
	const char* GetRequirement() const;
	int GetPoints() const;

	void SetName(const char* name);
	void SetRequirement(const char* requirement);
	void SetPoints(int points);
	void PrintTask() const;

};

struct Exam {
private:
	Task tasks[TASKS_MAX_COUNT];
	int minPoints = 0;
	int numberOfTasks = 0;

public:
	Exam();
	Exam(const Task* tasks, int numberOfTasks, int minPoints);

	void WriteToFile(const char* filePath);
	void ReadFromFile(const char* filePath);

	const Task* GetTasks() const;
	void ChangeMin(int newMin);
	int GetMax(int numberOfTasks) const;

	void PrintExam() const;

};


Task::Task() : Task("Unknown", "Unknown", 0) {}

Task::Task(const char* name, const char* requirement, int points) {
	SetName(name);
	SetRequirement(requirement);
	SetPoints(points);
}

bool Task::IsInvalidName(const char* name) const {
	return (strlen(name) > 20 || !name);
}

bool Task::IsInvalidRequirement(const char* requirement) const {
	return (strlen(requirement) > 256 || !requirement);
}

const Task* Exam::GetTasks() const {
	return tasks;
}

const char* Task::GetName() const {
	return name;
}

const char* Task::GetRequirement() const {
	return requirement;
}

int Task::GetPoints() const {
	return points;
}

void Task::SetName(const char* name) {
	if(IsInvalidName(name)) return;
	
	strcpy(this->name, name);
}

void Task::SetRequirement(const char* requirement) {
	if (IsInvalidRequirement(requirement)) return;

	strcpy(this->requirement, requirement);
}

void Task::SetPoints(int points) {
	if(points >= 0)
		this->points = points;

	return;
}

void Task::PrintTask() const {
	std::cout << "Task name: " << this->name << std::endl;
	std::cout << "Task requirement: " << this->requirement << std::endl;
	std::cout << "Task points: " << this->points << std::endl;
}

bool IsFileOpen(std::fstream& file) {
	if (!file.is_open()) {
		std::cout << "Error opening file!";
		return false;
	}

	return true;
}

Exam::Exam() : Exam(nullptr, 0, 0){}

Exam::Exam(const Task* tasks, int numberOfTasks, int minPoints) {
	if (numberOfTasks > TASKS_MAX_COUNT)
		return;

	for (size_t i = 0; i < numberOfTasks; i++)
	{
		this->tasks[this->numberOfTasks++] = tasks[i];
	}
	this->numberOfTasks = numberOfTasks;
	this->minPoints = minPoints;
}

void Exam::WriteToFile(const char* filePath) {
	//made it fstream in order to pass it by the IsFileOpen function.
	std::fstream writeFile(filePath, std::ios::binary | std::ios::out);

	if (!IsFileOpen(writeFile))
		return;

	writeFile.write((const char*)this, sizeof(Exam));
	writeFile.close();
}

void Exam::ReadFromFile(const char* filePath) {
	std::fstream readFile(filePath, std::ios::binary | std::ios::in);

	Exam exam;

	if (!IsFileOpen(readFile))
		return;

	readFile.read((char*)&exam, sizeof(Exam));
	readFile.close();
	this->numberOfTasks = exam.numberOfTasks;
	this->minPoints = exam.minPoints;
	for (size_t i = 0; i < exam.numberOfTasks; i++)
	{
		this->tasks[i] = exam.tasks[i];
	}
}

void Exam::ChangeMin(int newMinPoints) {
	this->minPoints = newMinPoints;
}

int Exam::GetMax(int numberOfTasks) const {
	int maxPoints = 0;
	for (size_t i = 0; i < numberOfTasks; i++)
	{
		maxPoints += this->tasks[i].GetPoints();
	}

	return maxPoints;
}

void Exam::PrintExam() const {
	for (size_t i = 0; i < this->numberOfTasks; i++)
	{
		this->tasks[i].PrintTask();
		std::cout << std::endl;
	}
}

int main()
{
	Task task1("task1", "aaa", 3);
	Task task2("task2", "aaabbb", 1);
	Task task3("task3", "aaabbbccc", 4);
	Task task4("task4", "aaabbbcccdd", 5);

	Task tasks[TASKS_MAX_COUNT]{ task1, task2, task3, task4 };
	
	Exam exam(tasks, 4, 10);

	
	std:: cout << "Max points from exam is: " << exam.GetMax(4) << std::endl;
	std::cout << "Exam: " << std::endl;
	exam.PrintExam();

	exam.WriteToFile(EXAM_FILE_NAME);

	Exam exam2;
	exam2.ReadFromFile(EXAM_FILE_NAME);

	std::cout << "Exam from file: " << std::endl;
	exam2.PrintExam();
}
