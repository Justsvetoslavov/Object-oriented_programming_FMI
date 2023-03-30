#include "Date.h"
#include <iostream>


Date::Date()
	:Date(1, 1, 2020) {

}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;

}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

void Date::setDay(int day) {
	this->day = day;
}

void Date::setMonth(int month) {
	this->month = month;
}

void Date::setYear(int year) {
	this->year = year;
}

void Date::Increase(int n) {
	day += n;
	while (day > getDaysInAMonth(month)) {
		day -= getDaysInAMonth(month);
		month++;
		if (month > 12) {
			month -= 12;
			year++;
		}
	}
}

void Date::Decrease(int n) {
	day -= n;
	while (day <= 0) {
		day += getDaysInAMonth(month) + 1;
		month--;
		if (month <= 0) {
			month = 12;
			year--;
		}
	}

}

bool Date::isLeapYear() {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}
	return false;
}
void Date::Print() const {
	std::cout << day << "." << month << "." << year << "\n";
}
int Date::getDaysInAMonth(int month) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	} else if (month == 2) {
		if (isLeapYear()) {
			return 29;
		} else {
			return 28;
		}
	}
	return -1;

}
