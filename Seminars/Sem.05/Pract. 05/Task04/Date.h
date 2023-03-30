#pragma once
class Date
{
	size_t day = 1;
	size_t month = 1;
	size_t year = 1970;
	size_t MAX_DAYS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
	Date();
	Date(size_t day, size_t month, size_t year);

	size_t getDay() const;
	size_t getMonth() const;
	size_t getYear() const;

	void setYear(size_t year);
	void setMonth(size_t month);

	void addDays(size_t days);
	void subtractDays(long long days);
	bool isLeapYear() const;
	bool isLeapYear(size_t year) const;
	size_t daysLeftToChristmas() const;
	size_t daysLeftToYearEnd() const;
	long long daysLeftToDate(const Date& other) const;
	bool isLaterThan(const Date& other) const;

};

