#include "FunctionUtils.h" 
#include "cRational.h"
#include <iostream>
using namespace OOP;

void OOP::PrintcRational(const cRational& Rational) {
	// TODO ADD THIS 
	if (Rational.Numerator() == 0) {
		std::cout << 0;
		return;
	}
	if (Rational.Denominator() == 1) {
		std::cout << Rational.Numerator();
		return;
	}
	else {
		std::cout << Rational.Numerator() << "/" << Rational.Denominator();
		return;
	}
};

void OOP::PrintMixedRational(const cRational& MixedRational) {
	long long a = MixedRational.Numerator();
	long long b = MixedRational.Denominator();
	bool NegativeSymbol = 0;
	cRational e;

	if (b < 0) {// to ensure the case -a/-b is counted as a positive fraction
		a = -a;
		b = -b;
	}
	if (a < 0) {
		a = -a;
		NegativeSymbol = 1;
	}

	if (a < b) {
		if (a == 0) {
			std::cout << 0;
			return;
		}
		if (b == 1) {
			if (NegativeSymbol == 1) {
				a = -a;
			}
			std::cout << a;
			return;
		}
		else {
			if (NegativeSymbol == 1) {
				a = -a;
			}
			std::cout << a << "/" << b;
			return;
		}
	}
	else {
		long long d;
		d = a % b;
		int c = int(a / b);
		if (NegativeSymbol == 1) {
			c = -c;
		}
		if (d == 0) {
			std::cout << c;
			return;
		}
		else {
			if (NegativeSymbol == 1) {
				a = -a;
			}
			e.Set(d, b);
		std::cout << c << " " << e;
			return;
		}		
	}
};
