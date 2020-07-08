#include <iostream>
#include <string>
#include <vector>
#include <map>

#define N "NEW_BUS" // [num_bus] [stop_count] [ [stop1] [stop2] ...] - add new bus with stops
#define A "ALL_BUSES" // display a list of all bus routes with stops
#define B "BUSES_FOR_STOP" // [STOP] - name of all bus routes passing through STOP stop  
#define S "STOPS_FOR_BUS" // [name_bus] - display the name of all the stops of the route BUS with a list of buses that you can take at each of the stops.

using namespace std;

struct bus_and_stops
{
	map<string, vector<string>> stops;
	map<string, vector<string>> buses;
};

void	stop_description(vector<string>& stops, string stop, const string& exception)
{
	int count = 0;

	for (auto &bus : stops)
		if (bus != exception){
			cout << bus << " ";
			count++;
	}
	if (count == 0)
		cout << "no interchange";
	cout << endl;
}

void	print_stops_for_bus(bus_and_stops b_n_s, string bus)
{
	if (!b_n_s.buses.count(bus)){
		cout << "No bus" << endl;
		return ;
	}
	for (auto& stop : b_n_s.buses[bus]){
		cout << "Stop " << stop << ": ";
		stop_description(b_n_s.stops[stop], stop, bus);
	}
}

void	list_of_bus(const map<string, vector<string>>& buses)
{
	if (!buses.size()){
		cout << "No buses" << endl;
		return ;
	}
	for (auto& bus : buses){
		cout << "Bus " << bus.first << ": "; 
		for (auto& stop : bus.second)
			cout << stop << " ";
		cout << endl;
	}
}

void	print_buses_for_stop(map<string, vector<string>>& stops, string stop)
{
	if (!stops.count(stop)){
		cout << "No stop" << endl;
		return ;
	}
	stop_description(stops[stop], stop, "\0");
}

void	new_bus(bus_and_stops& b_n_s, const string& bus, int& count_stop)
{
	string stop;
	for (; count_stop > 0; count_stop--){
		cin >> stop;
		b_n_s.buses[bus].push_back(stop);
		b_n_s.stops[stop].push_back(bus);
	}
}

int main()
{
	int Q, count_stop;
	string oper, stop, bus;
	bus_and_stops b_n_s;

	cin >> Q;
	for (int i = 0; i < Q; i++){
		cin >> oper;
		if (oper == N){
			cin >> bus >> count_stop;
			new_bus(b_n_s, bus, count_stop);
		}
		else if (oper == A){
			list_of_bus(b_n_s.buses);
		}
		else if (oper == B){
			cin >> stop;
			print_buses_for_stop(b_n_s.stops, stop);
		}
		else if (oper == S){
			cin >> bus;
			print_stops_for_bus(b_n_s, bus);
		}
	}
	return 0;
}