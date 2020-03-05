#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(string& str)
{
	map<char, int> map;
	for (char& s : str)
		++map[s];
	return map;
}

int main()
{
	int N;
	string s1, s2;
	string answer;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> s1 >> s2;
		if (BuildCharCounters(s1) == BuildCharCounters(s2))
			answer += "YES";
		else
			answer += "NO";
		if (i != N - 1)
			answer += "\n";
	}
		cout << answer << endl;
	return 0;
}