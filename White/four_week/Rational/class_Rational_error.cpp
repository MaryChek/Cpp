#include <iostream>

# define abs(x) (x > 0) ? x : -x

using namespace std;

int		GetGreatestCommonDivisor(int a, int b) {
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
		if (!denominator)
			throw invalid_argument("Invalid argument");
		gcd = GetGreatestCommonDivisor(numerator, denominator);
		p = numerator / gcd;
		q = denominator / gcd;
		NegativeValueCheck(p, q);
	}

	int		Numerator() const { return p; }

	int		Denominator() const { return q; }

private:
	int p, q, gcd;

	void	NegativeValueCheck(int& num, int& den) {
		if (den < 0) {
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
	if (r2.Numerator() == 0)
		throw domain_error("Division by zero");
	return {
	r1.Numerator() * r2.Denominator(),
	r1.Denominator() * r2.Numerator()
	};
}

bool		operator<(const Rational& r1, const Rational& r2) {
	return  ((r1 - r2).Numerator() < 0 ? true : false);
}

bool		operator>(const Rational& r1, const Rational& r2) {
	return ((r1 - r2).Numerator() > 0 ? true : false);
}

ostream& operator<<(ostream& stream, const Rational& fractional_num) {
	
	return stream << fractional_num.Numerator() << "/" << fractional_num.Denominator();
}

istream& operator>>(istream& stream, Rational& fractional_num) {
	int a, b;
	char c;

		stream >> a;
		stream.ignore(1);
		stream >> b;
		if (stream)
			fractional_num = {a, b};
	return stream;
}

int main() {
	Rational r1, r2, res;
	char oper;
	try {
		cin >> r1 >> oper >> r2;
	} catch (invalid_argument& e) {
		cout << e.what() << endl;
		return 0;
	}
	if (oper == '+')
		res = r1 + r2;
	if (oper == '-')
		res = r1 - r2;
	if (oper == '*')
		res = r1 * r2;
	try {
		if (oper == '/') {
			res = r1 / r2;
		}
	} catch (domain_error& e) {
		cout << e.what() << endl;
		return 0;
	}
	cout << res << endl;
	return 0;
}