#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#include "database.h"
#include "date.h"

using Event =  pair<Date, string>;


void Database::Add(Date date,  string event) {
	Event new_member = { date, event };
	if (data_unique.count(new_member) == 0) {
		data[date].push_back(event);
		data_unique.insert(new_member);
	}
}
void Database::Print(ostream& stream) const{
	for (const auto& item : data) {
		for (const auto& event : item.second) {
			stream << item.first << " " << event << endl;
		}
	}
}

Event Database::Last(const Date& date) const {
	auto it_lower = data.upper_bound(date);
	if (it_lower != data.begin()) {
		it_lower--;
		return { it_lower->first, *((it_lower->second).end() - 1) };
	}
	throw invalid_argument("Invalid argument was given");
}

ostream& operator << (ostream& stream, const Event& event) {
	stream << event.first << ' ' << event.second;
	return stream;
}