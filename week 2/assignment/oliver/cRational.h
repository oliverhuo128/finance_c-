//------------------------------------------------------------------------------
//
// cRational
// cRational.h
// cRational is a class that can represent rational numbers. 
//  Arithmetic operations are performed through overloaded operators
// a streaming operator is provided
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include guard

#ifndef OOP_RATIONALNUMBER_H
#define OOP_RATIONALNUMBER_H

//------------------------------------------------------------------------------
// include files
#include <iostream>

//------------------------------------------------------------------------------
// namespace definition
namespace OOP {

	//------------------------------------------------------------------------------
	/*! \class cRational cRational.h
	 *   \brief This is the cRational class .
	 */
	class cRational {
	public:
		// Initialize the rational The default value should be 0/1
		// Default Constructor
		cRational();

		// Complete Constructor
		cRational(long long n, long long d);

		// Copy Constructor
		cRational(const cRational& b);

		// Destructor
		~cRational();

		// Set the numerator to the given value. The denominator should be set to be 1.
		void Set(long long numerator);

		// Set both the numerator and denominator. Reduce to canonical form the rational if necessary.
		void Set(long long numerator, long long denominator);

		void SetNumerator(long long numerator);

		void SetDenominator(long long denominator);

		// Return the numerator.
		long long Numerator(void)const;

		// Return the denominator.
		long long Denominator(void)const;

		// Return the floating point value of the rational.
		double RealValue(void) const;

		// Add two rationals producing a new rational. The new rational should be canonical form.
		cRational operator +(const cRational& b) const;

		// Add Function producing a new rational.
		cRational Add(cRational& r1, cRational& r2)const;

		// Subtract two rationals producing a new rationals. The new rationals should be canonical form.
		cRational operator -(const cRational& b) const;

		// Multiply two rationals producing a new rationals. The new rationals should be canonical form.
		cRational operator *(const cRational& b) const;

		friend cRational operator*(const cRational& r1, long long value);
		friend cRational operator*(long long value, const cRational& f1);
		cRational& operator*=(const cRational& rhs);

		// Divide two rationals producing a new rational. The new rational should be canonical form.
		cRational operator /(const cRational& b) const;

		// Comparison of two rationals
		friend bool operator < (const cRational& lhs, const cRational& rhs) {
			return((lhs.Numerator() * rhs.Denominator()) < (rhs.Numerator() * lhs.Denominator()));
		}

		// once operator< is provided, the other relational operators are implemented in terms of operator<
		friend bool operator > (const cRational& lhs, const cRational& rhs) { // Comparison of two rational
			return(lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator());
		}

		// Implement the operator<
		friend bool operator <=(const cRational& lhs, const cRational& rhs) {
			return((lhs < rhs) || (lhs == rhs));
		};

		// Implement the operator<
		friend bool operator >=(const cRational& lhs, const cRational& rhs) {
			return ((lhs > rhs) || (lhs == rhs));
		};

		// Implement the operator ==
		friend bool operator ==(const cRational& lhs, const cRational& rhs) {
			return(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
		};

		// the inequality operator is typically implemented in terms of operator==
		friend bool operator !=(const cRational& lhs, const cRational& rhs) {
			return !(lhs == rhs);
		};

		// access the numerator [0] or denominator [1]
		long long& operator[](std::size_t idx);


		// access the numerator [0] or denominator [1]
		const long long& operator[](std::size_t idx) const;

		// produce a new rational which is the opposite of this
		cRational opposite(void)const;

		// produce a new rational which is the reciprocal of this
		cRational reciprocal(void)const;

		// produce a new rational which is Exponentiation to integer power n
		cRational exp(const int n)const;

		// Compute the Greatest Comon Denominator of two integers. See notes below.
		long long GCD(long long a, long long b) const;

		// Reduce the rational to its canonical form
		void canonicalform(void);

		// We'll make gcd static so that it can be part of class rational without
		// requiring an object of type cRational
		static long long Greatest_Comon_Denominator(long long a, long long b);

		friend std::istream& operator>>(std::istream& is, cRational& obj) {
			is >> obj.myNumerator >> obj.myDenominator;
			return is;
		};


		friend inline std::ostream& operator<<(std::ostream& os, const OOP::cRational& a) {
			os << a.Numerator() << "/" << a.Denominator();
			return os;
		}


	private:
		long long myNumerator;
		long long myDenominator;
	};
}

#endif