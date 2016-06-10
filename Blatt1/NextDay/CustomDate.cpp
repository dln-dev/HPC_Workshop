#include "CustomDate.h"

using namespace std;

const unsigned short int CustomDate::daysInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

CustomDate::CustomDate(unsigned short int tag, unsigned short int monat, unsigned short int jahr) {
	isLeapYear = checkLeapYear(jahr) ? true : false;
	setYear(jahr);
	setMonth(monat);
	setDay(tag);
}

bool CustomDate::checkLeapYear(unsigned short int jahr) {
	if(jahr % 4 == 0) 
		if(jahr % 100 == 0)
			if(jahr % 400 == 0)
				return true;
			else
				return false;
		else
			return true;
	else
		return false;
}

void CustomDate::setDay(unsigned short int tag) {
	if(tag <= daysInMonth[m] && tag > 0)
		t = tag;
	else if(isLeapYear && tag == 29)
		t = 29;
	else 
		cerr << "incorrect day set: " << tag << ">" << ((m == 2 && isLeapYear) ? 29 : daysInMonth[m]) << endl;
}

void CustomDate::setMonth(unsigned short int monat) {
	if(monat <= 12 && monat > 0)
		m = monat;
	else
		cerr << "incorrect month set: " << monat << ">12" << endl;
}

void CustomDate::setYear(unsigned short int jahr) {
	if(jahr <= 2600 && jahr >= 1600)
		j = jahr;
	else
		cerr << "incompatible year set: " << jahr << ", must be 1600 < year < 2600" << endl;
}

void CustomDate::setDate(unsigned short int tag, unsigned short int monat, unsigned short int jahr) {
	setYear(jahr);
	setMonth(monat);
	setDay(tag);
}

void CustomDate::advanceDays(unsigned short int days) {
	t += days;

	if(!(t == 29 && m == 2 && isLeapYear))
		while(t > daysInMonth[m]) {
			t -= (m == 2 && isLeapYear) ? 29 : daysInMonth[m];
			advanceMonths(1);
		}
}

void CustomDate::advanceMonths(unsigned short int months) {
	m += months;

	while(m > 12) {
		m -= 12;
		advanceYears(1);
	}
}

void CustomDate::advanceYears(unsigned short int years) {
	if(j + years <= 2600)
		j += years;
	else
		cerr << "incompatible year reached, must stay < 2600" << endl;
}

void CustomDate::printDate() {
	cout << t << "." << m << "." << j << endl;
}

