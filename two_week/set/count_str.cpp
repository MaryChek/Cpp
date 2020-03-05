#include <set>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int N;
    string elem;
    set<string> elems;

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> elem;
        elems.insert(elem);
    }
    cout << elems.size();
}