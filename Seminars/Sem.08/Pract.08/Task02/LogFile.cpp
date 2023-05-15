#include "LogFile.h"
#include <sstream>
#include <fstream>

LogFile::LogFile(const char* filePath) {
	if (!filePath)
		throw std::invalid_argument("Invalid argument!");

	ReadFile(filePath);
}

size_t LogFile::EnteringsCountAfterCertainHour(unsigned hour) const {
	if (hour > 23)
		throw std::invalid_argument("Hour should be less than 23!");

	size_t enteringsCount = 0;
	for (size_t i = 0; i < this->timesCount; i++)
	{
		if (this->times[i].GetHours() >= hour && this->times[i].GetAction() == 1)
			enteringsCount++;
	}
	return enteringsCount;
}

size_t LogFile::EnteringsCountBetweenHours(unsigned begHour, unsigned endHour) const {
	if (begHour > 23 || endHour > 23)
		throw std::invalid_argument("Hour should be less than 23!");

	if (begHour >= endHour)
		throw std::invalid_argument("Beggining hour must be less than end hour!");

	size_t enteringsCount = 0;
	for (size_t i = 0; i < this->timesCount; i++)
	{
		if (this->times[i].GetHours() >= begHour &&
			this->times[i].GetHours() < endHour &&
			this->times[i].GetAction() == 1)
			enteringsCount++;
	}
	return enteringsCount;
}

int LogFile::MostSecondsSpent() const {
	int seconds = 0;
	int maxSeconds = 0;

	bool firstAction = this->times[0].GetAction();
	for (int i = 0; i < this->timesCount - 1; i += 2)
	{
		if (i == 0 && firstAction == 0)
		{
			i--;
			continue;
		}
		seconds = this->times[i + 1].GetTimeInSeconds() - this->times[i].GetTimeInSeconds();

		if (seconds > maxSeconds)
			maxSeconds = seconds;
	}
	return maxSeconds;
}

bool LogFile::HasEnteredAtHour(int hour) const {
	if (hour > 23)
		throw std::invalid_argument("Hour should be less than 23!");

	for (size_t i = 0; i < this->timesCount; i++)
	{
		if (this->times[i].GetHours() == hour && this->times[i].GetAction() == 1)
			return true;
	}
	return false;
}

void LogFile::ReadFile(const char* filePath) {
	std::ifstream file(filePath);

	if (!file.is_open())
		throw std::runtime_error("Couldn't open file!");

	file >> this->timesCount;
	size_t timesId = 0;
	file.ignore(2);
	while (true) 
	{
		file >> this->times[timesId++];
		if (file.eof())
			break;
		file.ignore(2);
	}
	this->timesCount = timesId;
}