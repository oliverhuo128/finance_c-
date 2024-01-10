#include "cRational.h"

using namespace OOP;

//default constructor
cRational::cRational() :
	myNumerator(0),
	myDenominator(1) {

}

//complete constructor
cRational::cRational(long long n, long long d) :
	myNumerator(n),
	myDenominator(d) {
}

//copy constructor
cRational::cRational(const cRational& b) :
	myNumerator(b.Numerator()),
	myDenominator(b.Denominator()) {
}

//Destructor
cRational::~cRational() {
}

// Set the numerator to the given value. The denominator should be set to be 1.
void cRational::Set(long long numerator) {
	myNumerator = numerator;
	myDenominator = 1;
};

// Set both the numerator and denominator. Reduce to canonical form the rational if necessary.
void cRational::Set(long long numerator, long long denominator) {
	long long gcd = GCD(numerator, denominator);

	myNumerator = numerator / gcd;
	myDenominator = denominator / gcd;
	if (myDenominator < 0) {
		myNumerator = -myNumerator;
		myDenominator = -myDenominator;
	}
};

//Accessor functions
void cRational::SetNumerator(long long numerator) {
	myNumerator = numerator;
};

void cRational::SetDenominator(long long denominator) {
	myDenominator = denominator;
};

// Return the numerator.
long long cRational::Numerator(void)const {
	return myNumerator;
};

// Return the denominator.
long long cRational::Denominator(void)const {
	return myDenominator;
};


// Return the floating point value of the rational.
double cRational::RealValue(void) const {
	return (myNumerator / (double)myDenominator);
};

// Compute GCD of two integers
long long cRational::GCD(long long a, long long b)const {
	if (a < 0) {
		a = -a;
	}
	if (b < 0) {
		b = -b;
	}
	while (b != 0) {
		long long x = b;
		b = a % b;
		a = x;
	}
	return a;
}

// Reduce rational to canonical form
void cRational::canonicalform(void) {
	long long gcd = GCD(myNumerator, myDenominator);

	myNumerator = myNumerator / gcd;
	myDenominator = myDenominator / gcd;
	if (myDenominator < 0) {
		myNumerator = -myNumerator;
		myDenominator = -myDenominator;
	}
}


// Add two rationals producing a new rational. The new rational should be canonical form.
cRational cRational::operator +(const cRational& b) const {
	cRational plus;
	plus.Set((this->Numerator() * b.Denominator()) + (this->Denominator() * b.Numerator()), this->Denominator() * b.Denominator());
	return plus;
};

// Add Function producing a new rational.
cRational cRational::Add(cRational& r1, cRational& r2) const {
	cRational plus;
	plus.Set((r1.Numerator() * r2.Denominator()) + (r1.Denominator() * r2.Numerator()), r1.Denominator() * r2.Denominator());
	return plus;
};

// Subtract two rationals producing a new rationals. The new rationals should be canonical form.
cRational cRational::operator -(const cRational& b) const {
	cRational minus;
	minus.Set((this->Numerator() * b.Denominator()) - (this->Denominator() * b.Numerator()), this->Denominator() * b.Denominator());
	return minus;
};

// Multiply two rationals producing a new rationals. The new rationals should be canonical form.
cRational cRational::operator *(const cRational& b) const {
	cRational multiply;
	multiply.Set(this->Numerator() * b.Numerator(), this->Denominator() * b.Denominator());
	return multiply;
}

// Divide two rationals producing a new rational. The new rational should be canonical form.
cRational cRational::operator /(const cRational& b) const {
	cRational divide;
	divide.Set(this->Numerator() * b.Denominator(), this->Denominator() * b.Numerator());
	return divide;
};

// produce a new rational which is the opposite of this
cRational cRational::opposite(void)const {
	cRational opposite;
	opposite.Set(this->Numerator() * -1, this->Denominator());
	return opposite;
};


// produce a new rational which is the reciprocal of this
cRational cRational::reciprocal(void)const {
	cRational reciprocal;
	reciprocal.Set(this->Denominator(), this->Numerator());
	return reciprocal;
};

long long pow(long long a, long long b) {
	if (b > 0) {
		long long c = 1;
		while (b != 0) {
			c *= a;
			--b;
		}
		return c;

	}
	else {
		return 1;
	}
}

// produce a new rational which is Exponentiation to integer power n
cRational cRational::exp(const int n)const {
	cRational power;
	if (n >= 0) {
		long long x = this->Numerator();
		long long y = this->Denominator();
		power.Set(pow(x, n), pow(y, n));
		return power;
	}
	else {
		long long x = this->Numerator();
		long long y = this->Denominator();
		int r;
		r = -n;
		power.Set(pow(y, r), pow(x, r));
		return power;

	}

}


// We'll make gcd static so that it can be part of class rational without
// requiring an object of type cRational
static long long Greatest_Comon_Denominator(long long a, long long b) {
	while (b != 0) {
		long long x = b;
		b = a % b;
		a = x;
	}
	return a;
}


// access the numerator [0] or denominator [1]
long long& cRational::operator[](std::size_t idx) {
	if (idx == 0) {
		return myNumerator;
	}
	else {
		return myDenominator;
	}
}


// access the numerator [0] or denominator [1]
const long long& cRational::operator[](std::size_t idx) const {
	if (idx == 0) {
		return myNumerator;
	}
	else {
		return myDenominator;
	}
}
