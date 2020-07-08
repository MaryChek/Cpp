#include <string>
#include <vector>
#include <iostream>

using namespace std;

// struct Image {
// 	double quality;
// 	double freshness;
// 	double rating;
// };

// struct Params {
// 	double a;
// 	double b;
// 	double c;
// };

class Function_Part {
	public:
		Function_Part(char new_oper, double new_val) {
			oper = new_oper;
			val = new_val;
		}
		double Apply(double value) const {
			if (oper == '+')
				return value + val;
			else if (oper == '-')
				return value - val;
			else if (oper == '*')
				return value * val;
			else
				return value / val;
		}

		void Invert() {
			if (oper == '+')
				oper = '-';
			else if (oper == '-')
				oper = '+';
			else if (oper == '*')
				oper = '/';
			else
				oper = '*';
		}
	private:
		char oper;
		double val;
};

class Function {
	public:
		void AddPart(char oper, double val) {
			parts.push_back({oper, val});
		}

		double Apply(double val) const {
			for (const Function_Part& part : parts)
				val = part.Apply(val);
			return val;
		}

		void Invert() {
			for (Function_Part& part : parts)
				part.Invert();
			reverse(begin(parts), end(parts));
		}
	private:
		vector<Function_Part> parts;
};

// Function MakeWeightFunction(const Params& params,
// 							const Image& image) {
// 	Function function;
// 	function.AddPart('*', params.a);
// 	function.AddPart('-', image.freshness * params.b);
// 	function.AddPart('+', image.rating * params.c);
// 	return function;
// }

// double ComputeImageWeight(const Params& params, const Image& image) {
// 	Function function = MakeWeightFunction(params, image);
// 	return function.Apply(image.quality);
// }

// double ComputeQualityByWeight(const Params& params,
// 							const Image& image,
// 							double weight) {
// 	Function function = MakeWeightFunction(params, image);
// 	function.Invert();
// 	return function.Apply(weight);
// }

// int main() {
// 	Image image = {10, 2, 6};
// 	Params params = {4, 2, 6};
// 	cout << ComputeImageWeight(params, image) << endl;
// 	cout << ComputeQualityByWeight(params, image, 52) << endl;
// 	return 0;
// }
