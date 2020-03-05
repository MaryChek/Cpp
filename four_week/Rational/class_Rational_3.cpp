#include <iostream>

# define abs(x) (x > 0) ? x : -x

using namespace std;

int		GetGreatestCommonFactor(int a, int b) {
	a = abs(a);
	b = abs(b);
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

	int		Numerator() const { return (p != 0) ? (p / GCF) : p; }

	int		Denominator() const { return (p != 0) ? (q / GCF) : q; }

private:
	int p, q, GCF;

	int		Is_ZeroNumerator(int denominator) { return (p == 0) ? 1 : denominator; }

	void	NegativeValueCheck(int& num, int& den) {
		if ((den < 0 && num > 0) || (num < 0 && den < 0)) {
			num *= -1;
			den *= -1;
		}
	}
};

bool		operator==(const Rational& r1, const Rational& r2) {
	if (r1.Numerator() == r2.Numerator() 
			&& r1.Denominator() == r2.Denominator())
			return true;
	return false;
}

Rational	operator+(const Rational& r1, const Rational& r2) {
	return {r1.Numerator() * r2.Denominator() + r2.Numerator() * r1.Denominator(), 
	r2.Denominator() * r1.Denominator()
	};
}

Rational	operator-(const Rational& r1, const Rational& r2) {
	return {
	r1.Numerator() * r2.Denominator() - r2.Numerator() * r1.Denominator(), 
	r2.Denominator() * r1.Denominator()
	};
}

Rational	operator*(const Rational& r1, const Rational& r2) {
	return {
	r1.Numerator() * r2.Numerator(),
	r1.Denominator() * r2.Denominator()
	};
}

Rational	operator/(const Rational& r1, const Rational& r2) {
	return {
	r1.Numerator() * r2.Denominator(),
	r1.Denominator() * r2.Numerator()
	};
}

int main() {
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

	cout << "OK" << endl;
	return 0;
}