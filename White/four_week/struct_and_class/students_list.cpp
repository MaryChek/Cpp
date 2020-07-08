#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

struct student {
	string name;
	string last_name;
	Date date;
};

int main() {
	vector<student> stud_list;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		student stud;
		cin >> stud.name >> stud.last_name >> stud.date.day >> stud.date.month >> stud.date.year;
		stud_list.push_back(stud);
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		string oper;
		int num;
		cin >> oper >> num;
		--num;
		if (num > stud_list.size() || num < 0)
			cout << "bad request" << endl;
		else if (oper == "name")
			cout << stud_list[num].name << " " << stud_list[num].last_name << endl;
		else if (oper == "date")
			cout << stud_list[num].date.day << "." << stud_list[num].date.month << "."<< stud_list[num].date.year << endl;
		else 
			cout << "bad request" << endl;
	}
	return 0;
}