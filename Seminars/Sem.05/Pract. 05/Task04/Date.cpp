#include "Date.h"

#include <iostream>

Date::Date()
{
	this->year = 2000;
}

Date::Date(const size_t day, const size_t month, const size_t year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

size_t Date::getMonth() const
{
	return this->month;
}

size_t Date::getYear() const
{
	return this->year;
}

size_t Date::getDay() const
{
	return this->day;
}

void Date::setYear(const size_t year)
{
	MAX_DAYS[1] = this->isLeapYear(year) ? 29 : 28;
	this->year = year;
}

void Date::setMonth(const size_t month)
{
	if (month == 13)
	{
		this->month = 1;
		this->setYear(this->year + 1);
	}
	else if (month == 0)
	{
		this->month = 12;
		this->setYear(this->year - 1);
	}
	else this->month = month;
}

void Date::addDays(size_t days)
{
	while (days + this->day > this->MAX_DAYS[this->month - 1]) // days overflow max
	{
		days -= this->MAX_DAYS[this->month - 1] - this->day;
		setMonth(this->month + 1);
		this->day = 0;
	}
	this->day += days;
}

void Date::subtractDays(long long days)
{
	while ((long long)this->day - days < 1) // days overflow max
	{
		days -= this->MAX_DAYS[this->month == 1 ? 11 : this->month - 2] + this->day;
		setMonth(this->month - 1);
		this->day = 0;
	}
	this->day -= days;
}

bool Date::isLeapYear() const
{
	return this->isLeapYear(this->year);
}

bool Date::isLeapYear(const size_t year) const
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			return year % 400 == 0;
		}
		return true;
	}
	return false;
}

size_t Date::daysLeftToChristmas() const
{
	Date christmas(25, 12, this->year);

	size_t nextChristmasYear = this->isLaterThan(christmas) ? this->year + 1 : this->year;
	christmas.setYear(nextChristmasYear);
	return this->daysLeftToDate(christmas);
}

size_t Date::daysLeftToYearEnd() const
{
	Date yearEnd(1, 1, this->year + 1);
	return this->daysLeftToDate(yearEnd);
}

long long Date::daysLeftToDate(const Date& other) const
{
	if (!other.isLaterThan(*this))
	{
		std::cout << "Target date is earlier than current.\n";
		return -1;
	}

	size_t daysLeft = 0;
	Date temp = *this;
	while (!(temp.day == other.day && temp.month == other.month &&
		temp.year == other.year))
	{
		temp.addDays(1);
		daysLeft++;
	}
	return daysLeft;
}

bool Date::isLaterThan(const Date& other) const
{
	if (this->year > other.year)
	{
		return true;
	}
	else if (this->year < other.year)
	{
		return false;
	}
	else
	{
		if (this->month > other.month)
		{
			return true;
		}
		else if (this->month < other.month)
		{
			return false;
		}
		else return this->day > other.day;
	}
}
