#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>

# define A "ADD" // word1 word2 добавить в словарь пару синонимов
# define C_T "COUNT" // word узнать количество синонимов слова
# define C_K "CHECK" // word1 word2 проверить, являются ли слова синонимами (ADD word1 word2 или ADD word2 word1.)

using namespace std;

void    creat_map_word(map<string, set<string>>& syn)
{
    string word1, word2;
    set<string> words;

    cin >> word1 >> word2;
    syn[word1].insert(word2);
    syn[word2].insert(word1);
}

int main()
{
    int Q;
    string oper, word1, word2;
    map<string, set<string>> syn;

    cin >> Q;
    for (int i = 0; i < Q; i++){
        cin >> oper;
        if (oper == A)
            creat_map_word(syn);
        else if (oper == C_T){
            int count = 0;
            cin >> word1;
            cout << syn[word1].size() << endl;
        }
        else if (oper == C_K){
            cin >> word1 >> word2;
            if (syn[word1].count(word2))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}