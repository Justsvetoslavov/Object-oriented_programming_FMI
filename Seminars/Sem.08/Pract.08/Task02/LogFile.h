#pragma once
#include "Time.h"

class LogFile{
private:
	Time* times;
	unsigned timesCount = 0;
	bool firstAction = 0;

public:
	LogFile();
	LogFile(const char* filePath);
	LogFile(const LogFile& other);
	LogFile& operator=(const LogFile& other);
	~LogFile();

	void ReadFile(std::ifstream& file);
	int TimesOfEnterAfter(int hour) const;
	int TimesOfEnterBetweenTwoHours(int begHour, int endHour) const;
	int MostSecondsSpendIn() const;
	bool HasEnteredAt(int hour) const;

private:
	void free();
	void copyFrom(const LogFile& other);
};

