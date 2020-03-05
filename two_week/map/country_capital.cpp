#include <iostream>
#include <string>
#include <vector>
#include <map>

#define C "CHANGE_CAPITAL" // [country new_capital]изменение столицы страны на capital.
#define R "RENAME" // переименование страны из old_name в new_name
#define A "ABOUT" // [country] вывод столицы страны country.
#define D "DUMP" //вывод столиц всех стран.

using namespace std;

inline void	change_capital(map<string, string>& world, const string& country, const string& capital)
{
	if (!world.count(country))
		cout << "Introduce new country " << country << " with capital " << capital << endl;
	else if (world[country] == capital)
		cout << "Country " << country << " hasn't changed its capital" << endl;
	else
		cout << "Country " << country << " has changed its capital from " << world[country] << " to " << capital << endl;
	world[country] = capital;
}

void	rename(map<string, string>& world, const string& country, const string& new_name)
{
	if (!world.count(country) || world.count(new_name)){
		cout << "Incorrect rename, skip" << endl;
		return ;
	}
	cout << "Country " << country << " with capital " << world[country] << " has been renamed to " << new_name << endl;
	world[new_name] = world[country];
	world.erase(country);
}

inline void	about(map<string, string>& world, const string& country)
{
	if (!world.count(country))
		cout << "Country " << country << " doesn't exist" << endl;
	else
		cout << "Country "<< country << " has capital " << world[country] << endl;
}

int main()
{
	map<string, string> world;
	string	country, capital, oper, new_name;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> oper;
		if (oper == C){
			cin >> country >> capital;
			change_capital(world, country, capital);
		}
		else if (oper == R){
			cin >> country >> new_name;
			rename(world, country, new_name);
		}
		else if (oper == A){
			cin >> country;
			about(world, country);
		}
		else if (oper == D){
			if (world.size() == 0)
				cout << "There are no countries in the world";
			else
				for (auto& temp : world)
					cout << temp.first << "/" << temp.second << " ";
			cout << endl;
		}
	}
	return 0;
}