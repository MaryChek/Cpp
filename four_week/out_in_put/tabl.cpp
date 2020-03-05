// 1) размер ячейки равен 10,
// 2) соседние ячейки отделены друг от друга пробелом,
// 3) последняя ячейка в строке НЕ оканчивается пробелом,
// 4) последняя строка НЕ оканчивается символом перевода строки. Гарантируется, что в таблице будет ровно N строк и M столбцов, значение каждой из ячеек — целое число. Пример ввода

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	ifstream input("input.txt");
	int N, M;
	input >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int n;
			input >> n;
			cout << setw(10) << n;
			if (j + 1 != M)
				cout << " ";
			input.ignore(1);
		}
		if (i + 1 != N)
			cout << endl;
	}
}