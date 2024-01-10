
// include guard

#ifndef OOP_CRATIONAL_H
#define OOP_CRATIONAL_H

// include files
#include <iostream>
#include<string>

// namespace definition
namespace OOP {

	class cRational {
	public:
		//Default constructor
		cRational();
		//Constructor explicitly setting real and imaginary part
		cRational(long long n, long long d);
		// Copy constructor
		cRational(const cRational& b);
		// Destructor
		~cRational();

		// Standard accessor functions

		void Set(long long numerator) { // Set numerator with denominator = 1
			num = numerator; den = 1;
		}

		void Set(long long numerator, long long denominator) { // Set both numerator and denominator, reduce if necessar
			num = numerator;
			den = denominator;
		}

		void SetNumerator(long long numerator) { num = numerator; }
		void SetDenominator(long long denominator) { den = denominator; }

		long long Numerator(void)const { // Return numerator
			return num;
		}

		long long Denominator(void)const { // Return denominator
			return den;
		}

		double RealValue(void)const { // Return floating point value
			double x;
			x = num / (double)den;
			return x;
		}

		long long& operator[](std::size_t idx); // Access the numerator [0] or denominator [1]

		const long long& operator[](std::size_t idx)const; // Accesss the numerator [0] or denominator [1]

		cRational opposite(void)const; // Produce opposite rational

		cRational reciprocal(void)const; // Produce the reciprocal  rational

		cRational exp(const int n)const; // Produce a new rational which is the exponentiation to integer power n

		long long GCD(long long a, long long b)const; // Compute GCD of two integers

		void canonicalform(void); // Reduce rational to canonical form

		static long long Greatest_Comon_Denominator(long long a, long long b); // Static so part of the class without requiring oject

		// Overloading the four standard arithmetic operators

		cRational operator+(const cRational& b) const; // Add two rationals

		cRational Add(const cRational& r1, const cRational& r2) const; // Add fucntion

		cRational operator-(const cRational& b) const; // Subtract two rationals

		cRational operator*(const cRational& b) const; // Multiply two rationals together
		friend cRational operator*(const cRational& r1, long long value);
		friend cRational operator*(long long value, const cRational& f1);
		cRational& operator*=(const cRational& rhs);

		cRational operator/(const cRational& b) const; // Divide two rationals

		/*friend bool operator < (const cRational& lhs, const cRational& rhs) { // Comparison of two rational
			std::cout << "lhs = " << lhs.Numerator() << "/" << lhs.Denominator() << " = " << (lhs.Numerator() / (double)lhs.Denominator()) << ", rhs = " << rhs.Numerator() << "/" << rhs.Denominator() << " = " << (rhs.Numerator() /(double) rhs.Denominator()) << std::endl;
			std::cout << "lhs = " << (lhs.Numerator() /(double) lhs.Denominator()) << ", rhs = " << (rhs.Numerator() /(double) lhs.Denominator()) << std::endl;
			if ((lhs.Numerator() /(double) lhs.Denominator()) < (rhs.Numerator() /(double) rhs.Denominator())) {
				return true;
			}
			else {
				return false;
			}
		}*/

		friend bool operator < (const cRational& lhs, const cRational& rhs) { // Comparison of two rational
			return((lhs.Numerator() * rhs.Denominator()) < (rhs.Numerator() * lhs.Denominator()));

		}

		/*friend bool operator > (const cRational& lhs, const cRational& rhs) {
			if ((lhs.Numerator() /(double) lhs.Denominator()) > (rhs.Numerator() /(double) rhs.Denominator())) {
				return true;
			}
			else {
				return false;
			}
		}*/

		friend bool operator > (const cRational& lhs, const cRational& rhs) { // Comparison of two rational
			return(lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator());

		}

		/*friend bool operator <=(const cRational& lhs, const cRational& rhs){
			if ((lhs.Numerator() / (double)lhs.Denominator()) <= (rhs.Numerator() / (double)rhs.Denominator())) {
				return true;
			}
			else {
				return false;
			}
			}*/

		friend bool operator <=(const cRational& lhs, const cRational& rhs) {
			return (lhs < rhs || lhs == rhs);
		}

		/*friend bool operator >=(const cRational& lhs, const cRational& rhs) {
			if ((lhs.Numerator() / (double)lhs.Denominator()) >= (rhs.Numerator() / (double)rhs.Denominator())) {
				return true;
			}
			else {
				return false;
			}
		}*/

		friend bool operator >=(const cRational& lhs, const cRational& rhs) {
			return (lhs > rhs || lhs == rhs);
		}

		/*friend bool operator ==(const cRational& lhs, const cRational& rhs) {
			if ((lhs.Numerator() / (double)lhs.Denominator()) == (rhs.Numerator() / (double)rhs.Denominator())) {
				return true;
			}
			else {
				return false;
			}
		}*/

		friend bool operator ==(const cRational& lhs, const cRational& rhs) {
			return(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
		}

		friend bool operator !=(const cRational& lhs, const cRational& rhs) {
			return !(lhs == rhs);
		}

		friend std::ostream& operator<<(std::ostream& os, const cRational& a) {
			os << a.Numerator() << "/" << a.Denominator();
			return os;
		}

		friend std::istream& operator>>(std::istream is, cRational& obj) {

			for (int i = 0; i < 9;i++) {
				is >> obj[i];
			}

			return is;
		}

	private:
		long long num;
		long long den;
	};

}	 // namespace OOP



#endif	


