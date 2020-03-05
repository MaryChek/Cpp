#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int	main(){

	string	str;
	int		cnt;

	cin >> str;
	if ((cnt = count(begin(str), end(str), 'f')) == 0)
		cout << -2;
	else if (cnt == 1)
		cout << -1;
	else
		cout << str.find('f', str.find('f') + 1);
	return 0;
}