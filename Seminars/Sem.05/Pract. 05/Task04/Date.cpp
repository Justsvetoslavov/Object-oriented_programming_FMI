<<<<<<< Updated upstream
#include <iostream>
#include "Dates.h"

const short DEFAULT = 1;
const short DEFAULT_YEAR = 2000;

//Constructors
Date::Date()
{
	days = month = DEFAULT;
	year = DEFAULT_YEAR;
}

Date::Date(const int days, const int month, const int year)
{
	this->days = days;
	this->month = month;
	this->year = year;
}

//Methods to Add/Remove days
void Date::addDays(const int days)
{
	int dd = this->days + days;
	int DaysInMonth = NumDaysInMonth(month,year);
	while (dd > DaysInMonth)
	{
		dd -= DaysInMonth;
		month++;
		if (month > 12)
		{
			year++;
			month = 1;
		}
	DaysInMonth = NumDaysInMonth(month, year);
	}
	this->days = dd;
}

void Date::substractDays(const int days)
{
	if (days < this->days)
		this->days -= days;
	else
	{
		int dd = abs(this->days - days);
		month--;
		if (month < 1)
		{
			year--;
			month = 12;
		}

		int DaysInMonth = NumDaysInMonth(month, year);
		while (dd >= DaysInMonth)
		{
			dd -= DaysInMonth;
			month--;
			if (month < 1)
			{
				year--;
				month = 12;
			}
			DaysInMonth = NumDaysInMonth(month, year);
		}
		this->days = DaysInMonth - dd;
	}
}

//Methods calculating days - Date to Date
long long Date::daysBetweenDates(const Date& other) const
{
	return abs(sumOfDays(*this) - sumOfDays(other));
}
long long Date::daysToXmas() const
{
	int temp_year = (month == 12 && days > 25) ? year + 1 : year;
	const Date Xmas(25, 12,year);
	return(daysBetweenDates(Xmas));
}
long long Date::daysToNewYear() const
{
	const Date NewYear(1, 1, year + 1);
	return(daysBetweenDates(NewYear));
}

//Flags
bool Date::isLeapYear() const
{
	return isLeap(year);
}

bool Date::isLaterThan(const Date& other) const
{
	if (sumOfDays(*this) - sumOfDays(other) < 0)
		return true;

	return false;
}

//Accessors
int Date::getDays() const
{
	return days;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}

void Date::Display() const
{
	if (days < 10)
		std::cout << "Current Date is: 0" << days;
	else
		std::cout << "Current Date is: " << days;

	if (month < 10)
		std::cout << "/0" << month << "/" << year;
	else
		std::cout << month << "/" << year;
}

//Private functions
long long Date::sumOfDays(const Date& other) const
{
	long long sum = 0;
	sum += other.days;
	for (size_t i = 0; i < other.month - 1; i++)
		sum += NumDaysInMonth(other.month, other.year);
	sum += other.year * 365;
	
	return sum;
}
int Date::isLeap(int year) const
{
	return (year % 100 == 0) ? ((year % 400) == 0) : (year % 4 == 0);
}
int Date::NumDaysInMonth(int month, int year) const
{
	if (month <= 7)
	{
		if(month != 2)
				return 30 + (month % 2);
			else
				return (isLeap(year)) ? 29 : 28;
	}
	else
		return 30 + ((month + 1) % 2);
=======
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
>>>>>>> Stashed changes
}
