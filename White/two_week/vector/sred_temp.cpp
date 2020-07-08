#include <iostream>
#include <vector>

using namespace std;

int main(){
	int average_metr = 0;
	int N;
	cin >> N;
	vector<int> temp(N);
	for (int i = 0; i < N; i++){
		cin >> temp[i];
		average_metr += temp[i];
	}
	average_metr /= N;
	vector<int> hig;
	
	for (auto &num : temp)
		if (num > average_metr)
			count++;
	for (int i = 0; i < N; i++)
		if (temp[i] > average_metr){
			cout << i ;
		}
	return 0;
}