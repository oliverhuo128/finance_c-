#include <string>
#include <iostream>
#include"PrintHeader.h"

using namespace std;

// Print a string.
int print(string s) {
	cout << s << endl;
	return cout.good();
}

// Print a double in default precision.
int print(double dvalue) {
	cout << dvalue << endl;
	return cout.good();
}

//  Print a double in specified precision.
//  Positive numbers for precision indicate how many digits
//  precision after the decimal point to show. Negative
//  numbers for precision indicate where to round the number
//  to the left of the decimal point.
int print(double dvalue, int prec) {
	// Use table-lookup for rounding/truncation.
	static const double rgPow10[] = {
		10E-7, 10E-6, 10E-5, 10E-4, 10E-3, 10E-2, 10E-1,
		10E0, 10E1, 10E2, 10E3, 10E4, 10E5, 10E6
	};
	const int iPowZero = 6;

	// If precision out of range, just print the number.
	if (prec < -6 || prec > 7) {
		return print(dvalue);
	}
	// Scale, truncate, then rescale.
	dvalue = floor(dvalue / rgPow10[iPowZero - prec]) *
					 rgPow10[iPowZero - prec];
	cout << dvalue << endl;
	return cout.good();
}