#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ifstream input("input.txt");
	string line;
	ofstream output("output.txt");
	while (getline(input, line))
		output << line << endl;
	return 0;
}