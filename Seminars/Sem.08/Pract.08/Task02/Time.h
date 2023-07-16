#pragma once
#include <iostream>

class Time
{
private:
	unsigned hours = 0;
	unsigned minutes = 0;
	unsigned seconds = 0;

	bool action = false;

	void SetHours(int hours);
	void SetMinutes(int minutes);
	void SetSeconds(int seconds);
public:
	Time() = default;
	Time(int hours, int minutes, int seconds);

	int GetHours() const;
	int GetMinutes() const;
	int GetSeconds() const;
	bool GetAction() const;
	friend std::istream& operator>>(std::istream& file, Time& time);
};

