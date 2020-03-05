#include <iostream>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <string>

using namespace std;

string	to_lower(const string& a){
	string str;

	for (auto c : a)
		str += tolower(c);
	return str;
}

int main()
{
	int n;

	cin >> n;
	vector<string> array(n);
	for (auto &elem : array){
		cin >> elem;
	}
	sort(begin(array), end(array), [](const string& a, const string& b) {return to_lower(a) < to_lower(b);});
	for (const auto &a: array)
		cout << a << " ";
	cout << endl;
	int a;
	{
		a = 5;
	}
		cout << a;
	return 0;
}