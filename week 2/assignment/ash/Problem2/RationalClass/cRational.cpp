
// include files
#include "cRational.h"

using namespace OOP;

cRational::cRational() {// Default constructor
	num = 0;
	den = 1;
}

cRational::cRational(long long n, long long d) { // Constructor with input n and d
	if (n == d) {
		n = 1;
		d = 1;
	}

	if (d < 0) {
		n = -n;
		d = -d;
	}
	num = n;
	den = d;

	canonicalform();
}

cRational::cRational(const cRational& b) { // Copy constructor
	num = b.num;
	den = b.den;
}

cRational::~cRational() {// Destuctor
}

//long long& cRational::operator[](std::size_t idx) { // Access the numerator [0] or denominator [1]
//const long long& operator[](std::size_t idx)const; // Accesss the numerator [0] or denominator [1]

cRational cRational::opposite(void)const { // Produce opposite rational
	cRational neg;
	neg.num = this->Numerator() * -1;
	neg.den = this->Denominator();
	neg.canonicalform();

	return neg;
}

cRational cRational::reciprocal(void)const { // Produce the reciprocal  rational
	cRational opp;
	opp.num = this->Denominator();
	opp.den = this->Numerator();
	opp.canonicalform();

	return opp;
}

cRational cRational::exp(const int n)const { // Produce a new rational which is the exponentiation to integer power n
	cRational exp;

	long long e = this->Numerator();
	long long f = this->Denominator();

	if (n > 0) {
		int m = n - 1;

		std::cout << e << "/" << f << std::endl;

		while (m != 0) {
			e = e * this->Numerator();
			f = f * this->Denominator();
			--m;
		}

		exp.num = e;
		exp.den = f;
	}
	else {
		if (n < 0) {
			int m = -(n)-1;

			std::cout << e << "/" << f << std::endl;

			while (m != 0) {
				e = e * this->Numerator();
				f = f * this->Denominator();
				--m;
			}

			exp.num = f;
			exp.den = e;
		}
		else {
			exp.num = 1;
			exp.den = 1;
		}
	}

	exp.canonicalform();

	return exp;
}

long long cRational::GCD(long long a, long long b)const { // Compute GCD of two integers
	if (a < 0) {
		a = -a;
	}

	if (b < 0) {
		b = -b;
	}

	while (b != 0) {
		long long t = b;

		b = a % b;
		a = t;
	}
	return a;
}

void cRational::canonicalform(void) { // Reduce rational to canonical form
	long long d = GCD(num, den);

	num = num / d;
	den = den / d;

	if (den < 0) {
		num = -num;
		den = -den;
	}
}

static long long Greatest_Comon_Denominator(long long a, long long b) { // Static so part of the class without requiring oject
	while (b != 0) {
		long long t = b;

		b = a % b;
		a = t;
	}
	return a;
}

// Overloading the four standard arithmetic operators

cRational cRational::operator+(const cRational& b) const { // Add two rationals
	cRational r3((this->Numerator() * b.Denominator()) + (this->Denominator() * b.Numerator()), this->Denominator() * b.Denominator());
	r3.canonicalform();
	return r3;
}

cRational cRational::Add(const cRational& r1, const cRational& r2) const { // Add function
	cRational r3((r1.Numerator() * r2.Denominator()) + (r1.Denominator() * r2.Numerator()), r1.Denominator() * r2.Denominator());
	r3.canonicalform();
	return r3;
}

cRational cRational::operator-(const cRational& b) const { // Subtract two rationals
	cRational r3((this->Numerator() * b.Denominator()) - (this->Denominator() * b.Numerator()), this->Denominator() * b.Denominator());
	r3.canonicalform();
	return r3;
}

cRational cRational::operator*(const cRational& b) const { // Multiply two rationals together
	cRational r3(this->Numerator() * b.Numerator(), this->Denominator() * b.Denominator());
	r3.canonicalform();
	return r3;
}

//friend cRational operator*(const cRational& r1, long long value);
//friend cRational operator*(long long value, const cRational& f1);
//cRational& operator*=(const cRational& rhs);

cRational cRational::operator/(const cRational& b) const { // Divide two rationals
	cRational r3(this->Numerator() * b.Denominator(), this->Denominator() * b.Numerator());
	r3.canonicalform();
	return r3;
}

