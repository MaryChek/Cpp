#include <string>

bool IsPalindrom(string str){
	int size = str.size();
	for (int i = 0; i < (size / 2); i++)
		if (str[i] != str[size - i - 1])
			return false;
	return true;
}