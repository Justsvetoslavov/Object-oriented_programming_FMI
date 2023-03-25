#include <iostream>
#include <fstream>
#include <cstring>

const int name_max_size = 40;
const int requirement_max_size = 400;
const int exam_max_tasks = 10;
const char file_Name[18] = "ExamQuestions.dat";

bool IsFileOpened(std::ofstream& file) {
	if (!file.is_open()) {
		std::cout << "File couldn't open!";
		return 0;
	}
	return 1;
}

bool IsFileOpened(std::ifstream& file) {
	if (!file.is_open()) {
		std::cout << "File couldn't open!";
		return 0;
	}
	return 1;
}

class Task {
private:
	char name[name_max_size + 1];
	char requirement[requirement_max_size + 1];
	int points;

public:
	Task();
	Task(const char* name, const char* requirement, int points);

	const char* GetName() const;
	const char* GetRequirement() const;
	int GetPoints() const;

	void SetName(const char* name);
	void SetRequirement(const char* requirement);
	void SetPoints(int points);
};

Task::Task() : Task("Unknown", "Unknown", 0) {}

Task::Task(const char* name, const char* requirement, int points) {
	SetName(name);
	SetRequirement(requirement);
	SetPoints(points);
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
	if (strlen(name) > name_max_size)
		strcpy_s(this->name, "Unknown");
	else
		strcpy_s(this->name, name);
}

void Task::SetRequirement(const char* requirement) {
	if (strlen(requirement) > requirement_max_size)
		strcpy_s(this->requirement, "Unknown");
	else
		strcpy_s(this->requirement, requirement);
}

void Task::SetPoints(int points) {
	if (points < 0)
		points = 0;
	this->points = points;
}

struct Exam {
private:
	Task task[exam_max_tasks];
	int minimumPoints = 0;
	int countOfTasks = 0;
public:
	Exam();
	Exam(const Task* tasks, int minimumPoints, int numOfUnsavedTasks);

	void WriteToFile() const;
	void ReadFromFile();
	void PrintExam() const;
	void ChangeMin(int newValue);
	int GetMax() const;
};

Exam::Exam() : Exam(nullptr, 0, 0) {}

Exam::Exam(const Task* tasks, int minimumPoints, int numOfUnsavedTasks) {
	if (tasks == nullptr)
		return;
	if (minimumPoints > 0)
		this->minimumPoints = minimumPoints;
	if (countOfTasks + numOfUnsavedTasks > exam_max_tasks)
		numOfUnsavedTasks = exam_max_tasks - countOfTasks;
	for (int i = 0; i < numOfUnsavedTasks; i++)
	{
		task[i] = tasks[i];
		countOfTasks++;
	}
}

void Exam::WriteToFile() const {
	std::ofstream file(file_Name, std::ios::binary);
	if (!IsFileOpened(file))
		return;

	file.write((const char*)this, sizeof(Exam));

	file.close();
}

void Exam::ReadFromFile() {
	std::ifstream file(file_Name, std::ios::binary);
	if (!IsFileOpened(file))
		return;

	Exam exam;
	file.read((char*)&exam, sizeof(Exam));
	this->minimumPoints = exam.minimumPoints;
	this->countOfTasks = exam.countOfTasks;
	for (int i = 0; i < exam.countOfTasks; i++)
		this->task[i] = exam.task[i];

	file.close();
}

void Exam::ChangeMin(int newValue) {
	this->minimumPoints = newValue;
}

int Exam::GetMax() const {
	int pointsCounter = 0;
	for (int i = 0; i < countOfTasks; i++)
		pointsCounter += task[i].GetPoints();
	return pointsCounter;
}

void Exam::PrintExam() const {
	std::cout << "----Exam----\n";
	for (int i = 0; i < countOfTasks; i++)
	{
		std::cout << task[i].GetName() << std::endl;
		std::cout << task[i].GetRequirement() << std::endl;
		std::cout << "Points: " << task[i].GetPoints() << std::endl;
	}
}

int main()
{
	Task tasks[3] = {
		Task("Answer the question: ", "What is 2 + 2?", 10),
		Task("Write down the answer: ", "What's the name of our planet?", 15),
		Task("Write an essay on topic: ", "Why do humans breathe?", 25)
	};
	Exam exam(tasks, 10, 3);
	exam.WriteToFile();
	exam.ReadFromFile();
	exam.ChangeMin(15);
	exam.PrintExam();
	std::cout << "Max points are: " << exam.GetMax() << std::endl;
}
