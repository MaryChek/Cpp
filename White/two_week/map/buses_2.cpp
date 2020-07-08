#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void	new_buses(map<int, vector<string>>& buses, const vector<string>& stops)
{
	int num = buses.size() + 1;

	for (auto& s: stops)
		buses[num].push_back(s);
	cout << "New bus " << num << endl;
}

bool	comparison(const vector<string>& bus_st, const vector<string>& stops)
{
	int i = 0;

	for (auto& st : bus_st)
		if (st != stops[i++])
			return 0;
	return 1;
}

void	chek_bus(map<int, vector<string>>& buses, const vector<string>& stops)
{
	if (buses.size() != 0)
		for (auto& bus : buses){
			if (bus.second.size() == stops.size())
				if (comparison(bus.second, stops)){
					cout << "Already exists for " << bus.first << endl;
					return ;
				}
		}
	new_buses(buses, stops);
}

int		main()
{
	int Q;
	map<int, vector<string>> buses;
	vector<string> stops;
	string stop;

	cin >> Q;
	for (int i = 0; i < Q; i++){
		int count_stos;
		cin >> count_stos;
		for (int j = 0; j < count_stos; j++){
			cin >> stop;
			stops.push_back(stop);
		}
		chek_bus(buses, stops);
		stops.clear();
	}
}