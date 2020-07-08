#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

# define A "Add"
# define D "Del"
# define F "Find"
# define P "Print"

using namespace std;

class Date {
public:
	void DateParsing(const string& new_date) {
		istringstream date_stream(new_date);
		bool flag = true;

		flag = flag && (date_stream >> year);
		flag = flag && (date_stream.peek() == '-');
		date_stream.ignore(1);
		flag = flag && (date_stream >> month);
		flag = flag && (date_stream.peek() == '-');
		date_stream.ignore(1);
		flag = flag && (date_stream >> day);
		flag = flag && date_stream.eof();
		if (!flag)
			throw runtime_error("Wrong date format: " + new_date);
		EnsureTheMonthIsCorrect();
		EnsureTheDayIsCorrect();
	}
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
private:
	int day, month, year;
	void	EnsureTheMonthIsCorrect() {
		if (month < 1 || month > 12)
			throw runtime_error("Month value is invalid: " + to_string(month));
	}
	void	EnsureTheDayIsCorrect() {
		if (day < 1 || day > 31)
			throw runtime_error("Day value is invalid: " + to_string(day));
	}
};

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		db[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if (db.count(date) && db[date].count(event)) {
			db[date].erase(event);
			return true;
		}
		return false;
	}
	int DeleteDate(const Date& date) {
		int count = 0;
		if (db.count(date) > 0) {
			count = db[date].size();
			db.erase(date);
		}
		return count;
	}
	void	Find(const Date& date) const {
		if (db.count(date))
			for (const auto& d : db.at(date))
				cout << d << endl;
	}

	void Print() const {
		for (const auto& data : db) {
			for (const auto& ev : data.second) {
				int Year;
				if ((Year = data.first.GetYear()) < 0) {
					cout << "-";
					Year *= -1;
				}
				cout << setw(4) << setfill('0') << Year << "-";
				cout << setw(2) << setfill('0') << data.first.GetMonth() << "-";
				cout << setw(2) << setfill('0') << data.first.GetDay() << " ";
				cout << ev << endl;
			}
		}
	}
private:
	map<Date, set<string>> db;
};

struct DateAndEvent
{
	Date date;
	string event;
};

bool	ParsDate(stringstream& str, DateAndEvent& info) {
	string new_date;
	str >> new_date >> info.event;
	info.date.DateParsing(new_date);
	if (info.event.empty())
		return false;
	return true;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			if (lhs.GetDay() == rhs.GetDay())
				return false;
			else
				return lhs.GetDay() < rhs.GetDay();
		}
		else
			return lhs.GetMonth() < rhs.GetMonth();
	}
	return lhs.GetYear() < rhs.GetYear();
}

bool operator==(const Date& lhs, const Date& rhs) {
	return ((lhs.GetDay() == rhs.GetDay())
				&& (lhs.GetMonth() == rhs.GetMonth())
					&& (lhs.GetYear() == rhs.GetYear()));
}

int main() {
	Database db;
	string command;
	
	while (getline(cin, command)) {
		stringstream str(command);
		string oper;
		str >> oper;
		if (oper == A) {
			DateAndEvent info;
			try {
				if (ParsDate(str, info))
					db.AddEvent(info.date, info.event);
			} catch(runtime_error& e) {
				cout << e.what() << endl;
			}
		}
		else if (oper == D) {
			DateAndEvent info;
			try {
				if (ParsDate(str, info)) {
					if (db.DeleteEvent(info.date, info.event))
						cout << "Deleted successfully" << endl;
					else
						cout << "Event not found" << endl;
				} else {
				cout << "Deleted " << db.DeleteDate(info.date) << " events" << endl;
				}
			} catch(runtime_error& e) {
				cout << e.what() << endl;
			}
		}
		else if (oper == F) {
			Date date;
			string new_date;
			str >> new_date;
			try {
				date.DateParsing(new_date);
			} catch(runtime_error& e) {
				cout << e.what() << endl;
			}
			db.Find(date);
		}
		else if (oper == P) {
			db.Print();
		}
		else if (!oper.empty())
			cout << "Unknown command: " << oper << endl;
	}
	return 0;
}
