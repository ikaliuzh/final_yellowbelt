#include <iostream>
#include <string>

using namespace std;

#include "date.h"

bool operator< (const Date& lhs, const Date& rhs) {
	if (lhs.year != rhs.year) {
		return lhs.year < rhs.year;
	}
	else if (lhs.month != rhs.month) {
		return lhs.month < rhs.month;
	}
	else { return (lhs.day < rhs.day) ? true : false; }
}
bool operator> (const Date& lhs, const Date& rhs) {
	if (lhs.year != rhs.year) {
		return lhs.year > rhs.year;
	}
	else if (lhs.month != rhs.month) {
		return lhs.month > rhs.month;
	}
	else { return lhs.day > rhs.day; }
}
bool operator== (const Date& lhs, const Date& rhs) {
	return (lhs.year == rhs.year) && (lhs.month == rhs.month)
		&& (lhs.day == rhs.day);
}
bool operator!= (const Date& lhs, const Date& rhs) {
	return (lhs.year != rhs.year) || (lhs.month != rhs.month)
		|| (lhs.day != rhs.day);
}
bool operator>= (const Date& lhs, const Date& rhs) {
	return (lhs > rhs) || (lhs == rhs);
}
bool operator<= (const Date& lhs, const Date& rhs) {
	return (lhs < rhs) || (lhs == rhs);
}
ostream& operator<< (ostream& stream, const Date& date) {

	stream << setw(4) << setfill('0') << date.year << "-" <<
		setw(2) << setfill('0') << date.month << "-" <<
		setw(2) << setfill('0') << date.day;
	return stream;
}

Date ParseDate(istream& stream) {
	int day, month, year;
	stream >> year;
	stream.ignore(1);
	stream >> month;
	stream.ignore(1);
	stream >> day;
	return { year, month, day };
}