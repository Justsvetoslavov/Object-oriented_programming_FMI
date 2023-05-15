#include "Time.h"

Time::Time() : Time(0, 0, 0, 0) {}
Time::Time(unsigned hours, unsigned minutes, unsigned seconds, bool action) {
	SetHours(hours);
	SetMinutes(minutes);
	SetSeconds(seconds);
	SetAction(action);
}

void Time::SetHours(unsigned hours) {
	if (hours >= 24)
		this->hours = 0;

	this->hours = hours;
}
void Time::SetMinutes(unsigned minutes) {
	if (minutes >= 60)
		this->minutes = 0;

	this->minutes = minutes;
}
void Time::SetSeconds(unsigned seconds) {
	if (seconds >= 60)
		this->seconds = 0;

	this->seconds = seconds;
}

void Time::SetAction(bool action) {
	this->action = action;
}

unsigned Time::GetHours() const {
	return this->hours;
}
bool Time::GetAction() const {
	return this->action;
}

int Time::GetTimeInSeconds() const {
	return this->seconds + this->minutes * 60 + this->hours * 3600;
}

std::istream& operator>>(std::istream& is, Time& time) {
	is.ignore();
	char action = is.get();
	if (action == '-') time.action = 0;
	else if (action == '+') time.action = 1;
	is >> time.hours >> time.minutes >> time.seconds;
	return is;
}
