#include <iostream>
#include <set>
#include <map>
#include <vector>

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
	{
		const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}
	cout << "OK" << endl;
	return 0;
}