#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool IsPalindrom(string str){
	int size = str.size();
	for (int i = 0; i < (size / 2); i++)
		if (str[i] != str[size - i - 1])
			return false;
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
	vector<string> str;
	for (string a : words)
		if (IsPalindrom(a) && a.size() >= minLength)
			str.push_back(a);
	return (str);
}
