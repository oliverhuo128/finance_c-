//------------------------------------------------------------------------------
//
// ComplexNumber
// ComplexNumbers.h
// ComplexNumber is a class that can represent complex numbers. 
//  Arithmetic operations are performed through overloaded operators
// a streaming operator is provided
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include guard

#ifndef OOP_COMPLEXNUMBER_H
#define OOP_COMPLEXNUMBER_H

//------------------------------------------------------------------------------
// include files
#include <iostream>

//------------------------------------------------------------------------------
// namespace definition
namespace OOP {

	//------------------------------------------------------------------------------
	/*! \class ComplexNumber ComplexNumbers.h  
	 *   \brief This ComplexNumber class .
	 */ 
	class ComplexNumber  {
			public:
			//Default constructor
			ComplexNumber();
			//Constructor explicitly setting real and imaginary part
			ComplexNumber(double real, double imaginary);
			// Copy constructor
			ComplexNumber(const ComplexNumber & source);
			// Destructor
			~ComplexNumber();

			// Overloading the four standard arithmetic operators such that we can use them to perform operations with ottther complex numbers or with doubles
			ComplexNumber operator+(const ComplexNumber& z) const;
			ComplexNumber Add2(const ComplexNumber& z) const;
			ComplexNumber operator+(const double& x) const;
			ComplexNumber operator-(ComplexNumber& z) const;
			ComplexNumber operator-(const double& x) const;
			ComplexNumber operator*(const ComplexNumber& z) const;
			ComplexNumber operator*(const double& x) const;
			ComplexNumber operator/(const ComplexNumber& z) const;
			ComplexNumber operator/(const double& x) const;
			ComplexNumber& operator=(const ComplexNumber& z);
			ComplexNumber& operator=(const double x);

			// Standard accessor functions
			void SetReal(double x) { myReal = x; }
			double GetReal() const { return myReal; }
			void SetImaginary(double y) { myImaginary = y; }
			double GetImaginary() const { return myImaginary; }

			// Get the norm in the usual way
			double GetNorm() const { return myReal * myReal + myImaginary*myImaginary; }

			// Conjugation is implemented in the expected way
			ComplexNumber GetConjugate() const;

			// Prints the number to the command line. Advanced: you can also overload the << operator so you can output complex numbers directly with cout
			void PrintComplexNumber(void);

			// streaming operator
			// friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& i);
			//------------------------------------------------------------------------------
			/*! \fn  operator<<(std::ostream& os, const ComplexNumber& a)
			 *   \brief    stream a ComplexNumber
			 */
			friend inline std::ostream& operator<<(std::ostream& os, const OOP::ComplexNumber& a) {
				os << a.GetReal() << " + " << a.GetImaginary() << "i";
				return os;
			}


	private:
			double myReal;
			double myImaginary;
	};	// class Libmain

}	 // namespace OOP



#endif	// OOP_COMPLEXNUMBER_H

//------------------------------------------------------------------------------


