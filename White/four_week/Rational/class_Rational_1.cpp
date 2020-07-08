#include <iostream>
#include <cmath>

using namespace std;

int		GetGreatestCommonFactor(int a, int b) {
	a = a < 0 ? abs(a) : a;
	b = b < 0 ? abs(b) : b;
	while (a > 0 && b > 0){
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

class Rational {
public:
	Rational() {
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator) {
		p = numerator;
		q = Is_ZeroNumerator(denominator);
		NegativeValueCheck(p, q);
		GCF = GetGreatestCommonFactor(p, q);
	}

	int		Numerator() const {
		if (p)
			return p / GCF;
		return p;
	}
	int		Denominator() const {
		if (p)
			return q / GCF;
		return q;
	}

private:
	int p, q, GCF;

	int		Is_ZeroNumerator(int denominator) {
		if (!p)
			return 1;
		return denominator;
	}
	void	NegativeValueCheck(int& num, int& den) {
		if ((den < 0 && num > 0) || (num < 0 && den < 0)) {
			num *= -1;
			den *= -1;
		}
	}
};

int main() {
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}
	cout << "OK" << endl;
	return 0;
}