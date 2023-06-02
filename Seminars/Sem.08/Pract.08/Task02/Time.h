#pragma once
#include <iostream>

struct Time{
private:
	unsigned hours;
	unsigned minutes;
	unsigned seconds;
public:
	Time();
	Time(int hours, int minutes, int seconds);

	int GetHours() const;
	int GetMinutes() const;
	int GetSeconds() const;
	friend std::istream& operator>>(std::istream& file, Time& time);

private:
	void SetHours(int hours);
	void SetMinutes(int minutes);
	void SetSeconds(int seconds);
};

std::istream& operator>>(std::istream& file, Time& time);
