#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() 
{
    int Q, bus = 1;
    map<set<string>, int> buses;

    cin >> Q;
    for (int i = 0; i < Q; i++){
        int N;
        cin >> N;
        set<string> stops;
        for (int j = 0; j < N; j++){
            string stop;
            cin >> stop;
            stops.insert(stop);
        }
        if (buses.count(stops))
            cout << "Already exists for " << buses[stops] << endl;
        else{
            buses[stops] = bus;
            cout << "New bus " << bus++ << endl;
        }
    }
    return 0;
}