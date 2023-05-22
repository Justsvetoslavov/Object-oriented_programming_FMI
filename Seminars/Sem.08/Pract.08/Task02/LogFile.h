#pragma once
#include <iostream>
#include "Time.h"

class LogFile
{
	Time* times = nullptr;
	unsigned timesCount = 0;

	void copyFrom(const LogFile& other);
	void free();
public:
	LogFile() = default;
	LogFile(const char* filePath);
	LogFile(const LogFile& other);
	LogFile& operator=(const LogFile& other);
	~LogFile();

	void readFile(std::ifstream& file);
	int timesOfEnterAfter(int hour) const;
	int timesOfEnterBetweenTwoHours(int startHour, int endHour) const;
	int mostSecondsSpendIn() const;
	bool hasEnteredAt(int hour) const;

	void print() const;
};



