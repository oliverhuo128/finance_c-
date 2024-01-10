
#include "cRational.h" 
#include <iostream>
#include <string>
#include "FunctionUtils.h"
using namespace OOP;
using namespace std;

void main() {

	gobackhere:

	long long a = 0;
	long long b = 0;
	long long n = 0;
	long long d = 0;
	char s;
	char x;
	

	std::cout << "> ";

	cin >> a >> s >> b >> x >> n >> s >> d;

	if (b == 0 || d == 0) {
		return;
	}

	cRational j;
	cRational k;
	cRational ANS;
	j.Set(a, b);
	k.Set(n, d);

	if (x == '+') {
		ANS = j + k;
		PrintMixedRational(ANS);
		std::cout << "" << std::endl;
	}
	else if (x == '*') {
		ANS = j * k;
		PrintMixedRational(ANS);
		std::cout << "" << std::endl;
	}
	else if (x == '-') {
		ANS = j - k;
		PrintMixedRational(ANS);
		std::cout << "" << std::endl;
	}
	else if (x == '/') {
		ANS = j / k;
		PrintMixedRational(ANS);
		std::cout << "" << std::endl;
	}
	else {
		std::cout << "unrecognised operator" << std::endl;
	}
	goto gobackhere;
}