#pragma once
#include <ostream>
#include <map>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#include "date.h"

using Event = pair<Date, string>;

ostream& operator << (ostream& stream, const Event& e);

class Database {
public:
	void Add(Date date, string event);
	void Print(ostream& stream) const;
	Event Last(const Date& date) const;

	template <class Predicate> int RemoveIf(Predicate predicate) {
		int counter = 0;
		for (auto current = data.begin();
			current != data.end();) {
			auto unary_predicate = [current, predicate](const string& event) 
				{return !predicate(current->first, event); };
			auto border = stable_partition((current->second).begin(), (current->second).end(), unary_predicate);
			for (auto current_it = border;
				current_it != (current->second).end(); current_it++) {
				data_unique.erase({ current->first, *current_it });
				counter++;
			}
			current->second = { (current->second).begin(), border };
			if ((current->second).size() == 0) {
				data.erase((current++)->first);
			}
			else {
				current++;
			}
		}
		return counter;
	}

	template <class Predicate> vector<string> FindIf(Predicate predicate) const{
		vector<string> suitable_data;
		for (auto i : data) {
			for (auto item : i.second) {
				if (predicate(i.first, item)) {
					stringstream ss;
					ss << i.first << " " << item;
					suitable_data.push_back(ss.str());
				}
			}
		}
		return suitable_data;
	}
private:
	set<Event> data_unique;
	map<Date, vector<string>> data;
};