#include <string>
#include <vector>

using namespace std;

void	MoveStrings(vector<string>& src, vector<string>& des){
	for (string &a : src)
		des.push_back(a);
	src.clear();
}
