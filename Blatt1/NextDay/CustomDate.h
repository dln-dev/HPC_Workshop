#pragma once

#include <iostream>
#include <string>

class CustomDate {
	private:
	unsigned short int t, m, j;
	static const unsigned short int daysInMonth[13];
	bool isLeapYear;

	bool checkLeapYear(unsigned short int jahr);

	public:
	CustomDate() : CustomDate(1,1,1600) {}
	CustomDate(unsigned short int tag, unsigned short int monat, unsigned short int jahr);

	void setDay(unsigned short int tag);
	void setMonth(unsigned short int monat);
	void setYear(unsigned short int jahr);
	void setDate(unsigned short int tag, unsigned short int monat, unsigned short int jahr);
	void advanceDays(unsigned short int days);
	void advanceMonths(unsigned short int months);
	void advanceYears(unsigned short int years);

	void printDate();
};

