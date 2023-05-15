#pragma once
#include <iostream>
struct Time
{
private:
	unsigned hours;
	unsigned minutes;
	unsigned seconds;

	bool action;
public:
	Time();
	Time(unsigned hours, unsigned minutes, unsigned seconds, bool action);

	void SetHours(unsigned hours);
	void SetMinutes(unsigned minutes);
	void SetSeconds(unsigned seconds);
	void SetAction(bool action);

	unsigned GetHours() const;
	bool GetAction() const;

	int GetTimeInSeconds() const;

	friend std::istream& operator>>(std::istream& is, Time& time);
};

