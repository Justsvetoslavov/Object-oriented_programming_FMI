#pragma once
class Date {
private:
	int day;
	int month;
	int year;
	int getDaysInAMonth(int month);

public:
	Date();
	Date(int day, int month, int year);
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	void Increase(int n);
	void Decrease(int n);
	bool isLeapYear();


	void Print() const;
};

