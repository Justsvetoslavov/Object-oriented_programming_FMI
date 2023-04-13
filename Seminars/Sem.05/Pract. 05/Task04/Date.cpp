#include "Date.h"

Date::Date() : Date(1, 1, 2000) {}

Date::Date(int day, int month, int year) {
	SetYear(year);
	SetMonth(month);
	SetDay(day);
}

void Date::SetYear(int year) {
	this->year = year;
	if (IsLeapYear())
		daysInMonth[1] = 29;
	else
		daysInMonth[1] = 28;
}

void Date::SetMonth(int month) {
	if (month < 1 || month > 12)
		month = 1;
	this->month = month;
}

void Date::SetDay(int day) {
	if (daysInMonth[month - 1] < day)
		day = 1;
	this->day = day;
}

bool Date::IsLeapYear() const {
	if (year <= 1916)
		return year % 4 == 0;
	else
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

bool Date::IsLeapYear(int year) const {
	if (year <= 1916)
		return year % 4 == 0;
	else
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

void Date::IncreaseDate(int days) {
	while ((days + this->day) > daysInMonth[month - 1]) {
		days -= daysInMonth[month - 1] - this->day;
		this->day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			SetYear(year + 1);
		}
	}
	this->day += days;
}

void Date::DecreaseDate(int days) {
	while ((this->day - days) < 1) {
		days -= this->day;
		month--;
		if (month < 1)
		{
			month = 12;
			SetYear(year - 1);
		}
		this->day = daysInMonth[month - 1];
	}
	this->day -= days;
}

int Date::DaysToChristmas() const {
	if (month == 12 && day <= 25)
		return 25 - day;

	int currMonth = month;
	int currYear = year;
	int daysLeft = daysInMonth[currMonth - 1] - day;
	currMonth++;
	if (currMonth >= 12) {
		currMonth = 1;
		currYear++;
	}
	for (int i = currMonth - 1; i < 11; i++) {
		if (i == 1)
			(IsLeapYear(currYear)) ? daysLeft += 29 : daysLeft += 28;
		else
			daysLeft += daysInMonth[i];
	}
	return daysLeft + 25;
}

int Date::DaysToNewYear() const {
	int daysLeft = daysInMonth[month - 1] - day;
	for (int i = month; i < 12; i++) {
		daysLeft += daysInMonth[i];
	}
	return daysLeft;
}

int Date::DaysToEvent(const Date& event) const {
	if (month == event.month && day <= event.day)
		return event.day - day;

	int daysLeft = daysInMonth[month - 1] - day;
	int currMonth = month + 1;
	int currYear = year;
	while (currMonth > event.month) {
		if (currMonth > 12) {
			currMonth = 1;
			currYear++;
			break;
		}
		daysLeft += daysInMonth[currMonth - 1];
		currMonth++;
	}
	for (int i = currMonth - 1; i < event.month - 1; i++) {
		if (i == 1)
			(IsLeapYear(currYear)) ? daysLeft += 29 : daysLeft += 28;
		else
			daysLeft += daysInMonth[i];
	}
	return daysLeft + event.day;
}

bool Date::IsEarlierThan(const Date& date) const {
	if (date.year < year)
		return false;
	else if (date.year > year)
		return true;
	else {
		if (date.month < month)
			return false;
		else if (date.month > month)
			return true;
		else {
			if (date.day <= day)
				return false;
			return true;
		}
	}
}
