#include "LogFile.h"
#include <sstream>
#include <fstream>

namespace {
	int TimeToSeconds(const Time& time) {
		int currSeconds = time.GetSeconds();
		currSeconds += time.GetMinutes() * 60;
		currSeconds += time.GetHours() * 3600;
		return currSeconds;
	}
}

void LogFile::copyFrom(const LogFile& other)
{
	timesCount = other.timesCount;
	times = new Time[timesCount];
	for (int i = 0; i < timesCount; i++)
		times[i] = other.times[i];
}

void LogFile::free()
{
	delete[] times;
	times = nullptr;
	timesCount = 0;
}

LogFile::LogFile(const char* filePath)
{
	if (filePath == nullptr)
		throw std::invalid_argument("File path is invalid!\n");

	std::ifstream file(filePath);

	if (!file.is_open())
		throw std::runtime_error("File could not open!\n");

	readFile(file);

	file.close();
}

LogFile::LogFile(const LogFile& other)
{
	copyFrom(other);
}

LogFile& LogFile::operator=(const LogFile& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

LogFile::~LogFile()
{
	free();
}

void LogFile::readFile(std::ifstream& file)
{
	file >> timesCount;
	times = new Time[timesCount];
	file.ignore(3, '\\');

	int index = 0;
	while (!file.eof())
	{
		file >> times[index++];
		file.ignore(3, '\\');
	}
}

int LogFile::timesOfEnterAfter(int hour) const
{
	if (hour < 0 || hour > 23)
		throw std::invalid_argument("Invalid hour!");

	int enterTimes = 0;
	for (int i = 0; i < timesCount; i++)
	{
		if (hour <= times[i].GetHours())
		{
			if ((times[i].GetAction() && i % 2 == 0) || (!times[i].GetAction() && i % 2 == 1))
				enterTimes++;
		}
	}

	return enterTimes;
}

int LogFile::timesOfEnterBetweenTwoHours(int startHour, int endHour) const
{
	if (startHour < 0 || startHour > 23 || endHour < 0 || endHour > 23)
		throw std::invalid_argument("Invalid hour!");
	if (endHour <= startHour)
		throw std::invalid_argument("End hour should be after the beginning hour");

	int enterTimes = 0;
	for (int i = 0; i < timesCount; i++)
	{
		if (startHour <= times[i].GetHours() && endHour > times[i].GetHours() && ((times[i].GetAction() && i % 2 == 0) || (!times[i].GetAction() && i % 2 == 1)))
			enterTimes++;
	}
}

int LogFile::mostSecondsSpendIn() const
{
	int secondsSpent = 0;
	int maxSecondsSpent = 0;
	int i = 0;

	for (i; i < timesCount - 1; i += 2)
	{
		secondsSpent = TimeToSeconds(times[i + 1]) - TimeToSeconds(times[i]);
		if (maxSecondsSpent < secondsSpent)
			maxSecondsSpent = secondsSpent;
	}

	return maxSecondsSpent;
}

bool LogFile::hasEnteredAt(int hour) const
{
	if (hour < 0 || hour > 23)
		throw std::invalid_argument("Invalid hour!");

	for (int i = 0; i < timesCount; i++)
	{
		if (hour == times[i].GetHours() && (times[i].GetAction() && i % 2 == 0) && (!times[i].GetAction() && i % 2 == 1))
		{
			return true;
		}
	}
	return false;
}

void LogFile::print() const {
	for (size_t i = 0; i < timesCount; i++)
	{
		char action = times[i].GetAction() ? '+' : '-';
		std::cout << "/" << action << " " << times[i].GetHours() << " " << times[i].GetMinutes() << " " << times[i].GetSeconds() << std::endl;
	}
}