#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int x;
	vector<int> num;

	cin >> x;
	if (!x)
		cout << "0";
	else{
		while (x){
			num.push_back(x % 2);
			x /= 2;
		}
			reverse(begin(num), end(num));
			for (int &i : num)
				cout << i;
	}
	return 0;
}
