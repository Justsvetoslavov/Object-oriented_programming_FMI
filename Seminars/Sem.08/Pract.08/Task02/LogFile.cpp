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

LogFile::LogFile(const LogFile& other) {
	copyFrom(other);
}

LogFile& LogFile::operator=(const LogFile& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

LogFile::~LogFile() {
	free();
}

void LogFile::ReadFile(std::ifstream& file) {
	file >> timesCount;
	times = new Time[timesCount];
	file.ignore(3, '\\');
	char symbol;
	file >> symbol;
	(symbol == '-') ? firstAction = 0 : firstAction = 1;

	int index = 0;
	while (true) {
		if (file.eof())
			break;

		file.get();
		file >> times[index];
		index++;
		file.ignore(3, '\\');
	}
}

int LogFile::TimesOfEnterAfter(int hour) const {
	if (hour < 0 || hour > 23)
		throw std::invalid_argument("Invalid hour!");

	int enterTimes = 0;
	for (int i = 0; i < timesCount; i++) {
		if (hour <= times[i].GetHours()) {
			if (firstAction && i % 2 == 0)
				enterTimes++;
			else if (!firstAction && i % 2 == 1)
				enterTimes++;
		}
	}

	return enterTimes;
}

int LogFile::TimesOfEnterBetweenTwoHours(int begHour, int endHour) const {
	if (begHour < 0 || begHour > 23 || endHour < 0 || endHour > 23)
		throw std::invalid_argument("Invalid hour!");
	if (endHour <= begHour)
		throw std::invalid_argument("End hour must be after the beginning hour");

	int enterTimes = 0;
	for (int i = 0; i < timesCount; i++) {
		if (begHour <= times[i].GetHours() && endHour > times[i].GetHours()) {
			if (firstAction && i % 2 == 0)
				enterTimes++;
			else if (!firstAction && i % 2 == 1)
				enterTimes++;
		}
	}

	return enterTimes;
}

int LogFile::MostSecondsSpendIn() const {
	int secondsSpent = 0;
	int maxSecondsSpent = 0;
	int i = 0;

	if (!firstAction)
		i = 1;

	for (i; i < timesCount - 1; i += 2) {
		secondsSpent = TimeToSeconds(times[i + 1]) - TimeToSeconds(times[i]);
		if (maxSecondsSpent < secondsSpent)
			maxSecondsSpent = secondsSpent;
	}

	return maxSecondsSpent;
}

bool LogFile::HasEnteredAt(int hour) const {
	if (hour < 0 || hour > 23)
		throw std::invalid_argument("Invalid hour!");

	for (int i = 0; i < timesCount; i++) {
		if (hour == times[i].GetHours()) {
			if ((firstAction && i % 2 == 0) || (!firstAction && i % 2 == 1))
				return true;
		}
	}

	return false;
}

LogFile::LogFile(const char* filePath) {
	if (filePath == nullptr)
		throw std::invalid_argument("File path is invalid!\n");

	std::ifstream file(filePath);

	if (!file.is_open())
		throw std::runtime_error("File couldn't open!\n");

	ReadFile(file);

	file.close();
}

void LogFile::free() {
	delete[] times;
	timesCount = 0;
	firstAction = 0;
}

void LogFile::copyFrom(const LogFile& other) {
	timesCount = other.timesCount;
	firstAction = other.firstAction;
	times = new Time[timesCount];
	for (int i = 0; i < timesCount; i++) {
		times[i] = other.times[i];
	}
}
