#include <string>
#include <vector>

using namespace std;

class SortedStrings {
	public:
		void AddString(const string& s) {
			vector.push_back(s);
		}
		vector<string> GetSortedStrings() {
			sort(begin(vector), end(vector));
			return vector;
		}
	private:
		vector<string> vector;
};
