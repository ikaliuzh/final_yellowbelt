#pragma once
#include <iomanip>

using namespace std;

class Date {
public:
	Date(int y, int m, int d)
		: year(y), month(m), day(d) {
	}
	const int day, year, month;
};

bool operator< (const Date& lhs, const Date& rhs);
bool operator> (const Date& lhs, const Date& rhs);
bool operator== (const Date& lhs, const Date& rhs);
bool operator!= (const Date& lhs, const Date& rhs);
bool operator>= (const Date& lhs, const Date& rhs);
bool operator<= (const Date& lhs, const Date& rhs);
ostream& operator<< (ostream& stream, const Date& date);

Date ParseDate(istream& stream);