#pragma once
#include "Time.h"

const int TIMES_MAX_COUNT = 100;

class LogFile
{
private:
	Time times[TIMES_MAX_COUNT];
	size_t timesCount = 0;

	void ReadFile(const char* filePath);
public:
	LogFile(const char* filePath);

	size_t EnteringsCountAfterCertainHour(unsigned hour) const;
	size_t EnteringsCountBetweenHours(unsigned begHour, unsigned endHour) const;
	int MostSecondsSpent() const;
	bool HasEnteredAtHour(int hour) const;
};

