#pragma once

class Date 
{
    private:
        int days, month, year;
    public: 
        Date(); //Default to 01.01.2000;
        Date(const int,const int,const int); //Constructor dd/mm/yy
    
        //Accessors
        int getDays() const;
        int getMonth() const;
        int getYear() const;
    
        void addDays(const int); //Add N days to the Date
        void removeDays(const int); //Substract N days from the Date
    
        bool isLeapYear() const; //Check if it is leap year
        bool isEarlierThan(const Date&) const; //True if given Date is after our Date

        long long daysToXmas() const;
        long long daysToNewYear() const;
        long long daysBetweenDates(const Date&) const;
    
        void print() const; //Display Date/Print Date
    private: 
        int isLeap(int) const;//Check if year is Leap
        int NumDaysInMonth(int, int) const; //Calculates number of days in current month
        long long sumOfDays(const Date&) const;//Extract total sum of days from a specific Date
};
