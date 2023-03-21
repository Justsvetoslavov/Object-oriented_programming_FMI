#include <iostream>
#include <fstream>

const size_t MAX_NAME_LENGTH = 16;
const size_t MAX_TASKS = 10;

void myStrCopy(char* str1, const char* str2)
{
	int counter{};

	while (str2[counter] != '\0')
	{
		str1[counter] = str2[counter];
		counter++;
	}

	str1[counter] = '\0';
}

class Task {
private:
	short points;
	char name[MAX_NAME_LENGTH];
	char condition[MAX_NAME_LENGTH];

public:
	bool setTaskPoints(size_t points)
	{
		if (points <= 0)
		{
			return false;
		}
		this->points = points;
		return true;
	}

	bool setTaskName(const char* name)
	{
		if (name==nullptr)
		{
			return false;
		}
		myStrCopy(this->name, name);
		return true;
	}

	bool setTaskCondition(const char* condition)
	{
		if (condition==nullptr)
		{
			return false;
		}
		myStrCopy(this->condition, condition);
		return true;
	}

	short getTaskPoints()const
	{
		return points;
	}

	const char* getTaskName()const
	{
		return name;
	}

	const char* getTaskCondition()const
	{
		return condition;
	}
};

class Exam {
private:
	Task tasks[MAX_TASKS];
	short minPoints;
	short countTask;
public:
	short getMinPoints()const
	{
		return minPoints;
	}

	Task getTask(const size_t pos)const
	{
		return tasks[pos];
	}
	short getCountTasks()const
	{
		return countTask;
	}

	void setTask(const Task& task, const size_t pos)
	{
		this->tasks[pos] = task;
	}

	void setMinPoints(const size_t minPoints)
	{
		this->minPoints = minPoints;
	}

	void setCountTasks(const size_t tasks)
	{
		this->countTask = tasks;
	}

	void writeToFile(std::ofstream& fileWrite)const
	{
		if (!fileWrite.is_open())
		{
			return;
		}

		fileWrite.write((const char*)this, sizeof(Exam));
	}

	void readFromFile(std::ifstream& fileRead)
	{
		if (!fileRead.is_open())
		{
			return;
		}

		fileRead.read((char*)this, sizeof(Exam));
	}

	void changeMin(const int& newPoints)
	{
		this->setMinPoints(newPoints);
	}

	int getMax()
	{
		int maxPoints{};

		for (size_t i = 0; i < this->getCountTasks(); i++)
		{
			Task temp = this->getTask(i);
			maxPoints += temp.getTaskPoints();
		}

		return maxPoints;
	}

};

