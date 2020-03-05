#include <iostream>
#include <string>
#include <vector>

#define N "NEXT" 
#define D "DUMP" // [i]  
#define A "ADD" // [i] [data]

using namespace std;

void	print_vector_of_day(const vector<string>& day)
{
	cout << day.size() << " ";
	if (day.size()){
		for (auto s : day)
			cout << s << " ";
	}
	cout << endl;
}

void	next_month(vector<vector<string>>& month, const vector<int>& day_in_a_mth, int& num)
{
	int diff = day_in_a_mth[num % 12] - day_in_a_mth[(num + 1) % 12];
	if (diff >= 0)
	{
		int day = month.size() - diff - 1;
		for (int i = (day + 1); i < month.size(); i++)
			if (month[i].size())
				month[day].insert(month[day].end(), month[i].begin(), month[i].end());
	}
	month.resize(day_in_a_mth[(++num) % 12]);
}

int main()
{
	int Q, day, num = 0;
	string oper, plan;
	vector<int> day_in_a_mth {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> month(day_in_a_mth[num]);

	cin >> Q;
	for (int i = 0; i < Q; i++){
		cin >> oper;
		if (oper == N)
			next_month(month, day_in_a_mth, num);
		else if (oper == A){
			cin >> day >> plan;
			month[day - 1].push_back(plan);
		}
		else if (oper == D){
			cin >> day;
			print_vector_of_day(month[day - 1]);
		}
	}
	return 0;
}