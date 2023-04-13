#pragma once
class Date {
private:
	int day;
	int month;
	int year;
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	Date();
	Date(int day, int month, int year);
	void SetYear(int year);
	void SetMonth(int month);
	void SetDay(int day);
	
	bool IsLeapYear() const;
	bool IsLeapYear(int year) const;
	void IncreaseDate(int days);
	void DecreaseDate(int days);
	int DaysToChristmas() const;
	int DaysToNewYear() const;
	int DaysToEvent(const Date& event) const;
	bool IsEarlierThan(const Date& date) const;
};

