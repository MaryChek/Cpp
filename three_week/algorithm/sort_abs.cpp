#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool	my_abs(int x, int y){
	return (abs(x) < abs(y));
}

int main()
{
	int n;
	vector<int> array;

	cin >> n;
	for (int i = 0; i < n; i++){
		int elem;
		cin >> elem;
		array.push_back(elem);
	}
	sort(begin(array), end(array), my_abs);
	for (const auto &a: array)
		cout << a << " ";
	cout << endl;
	return 0;
}