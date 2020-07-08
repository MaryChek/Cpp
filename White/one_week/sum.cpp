#include <iostream>

using namespace std;

inline double discount(double n, double t){

	n *= (1.00 - t / 100.0);
	return (n);
}

int	main(){

	double n, a, b, x, y;
	
	cin >> n >> a >> b >> x >> y;
	if (n > b)
		cout << discount(n, y);
	else if (n > a)
		cout << discount(n, x);
	else
		cout << n;
	return 0;
}