#include <string>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m){
    set<string> set;
    for (auto& str : m){
        set.insert(str.second);
    }
    return set;
}
