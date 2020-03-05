#include <vector>
#include <algorithm>

using namespace std;

vector<int>	Reversed(const vector<int>& newt){
	vector<int> num = newt;
	reverse(num.begin(), num.end());
	return (num);
}
