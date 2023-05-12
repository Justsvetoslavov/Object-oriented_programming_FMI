#include "Time.h"

Time::Time() : Time(0, 0, 0){}

Time::Time(int hours, int minutes, int seconds){
	SetHours(hours);
	SetMinutes(minutes);
	SetSeconds(seconds);
}

int Time::GetHours() const{
	return hours;
}

int Time::GetMinutes() const{
	return minutes;
}

int Time::GetSeconds() const{
	return seconds;
}

void Time::SetHours(int hours) {
	if (hours <= 0 || hours >= 24)
		hours = 0;
	this->hours = hours;
}

void Time::SetMinutes(int minutes){
	if (minutes < 0 || minutes > 59)
		minutes = 0;
	this->minutes = minutes;
}

void Time::SetSeconds(int seconds) {
	if (seconds < 0 || seconds > 59)
		seconds = 0;
	this->seconds = seconds;
}

std::istream& operator>>(std::istream& is, Time& time){
	is >> time.hours;
	is >> time.minutes;
	is >> time.seconds;
	return is;
}
