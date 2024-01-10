//----------------------------------------------------------------------------------------------
/*! \file person.cpp
		\brief A Implentation files for classes in person

		\details
*/
//-----------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include files
#include "ComplexNumbers.h"

using namespace OOP;

//------------------------------------------------------------------------------
/*! \fn ComplexNumber(void)
*   \brief  constructor  
*/ 
ComplexNumber::ComplexNumber(){
}

//------------------------------------------------------------------------------
/*! \fn ComplexNumber(double real, double imaginary)
*   \brief  constructor
*/
ComplexNumber::ComplexNumber(double real, double imaginary):
	myReal(real),
	myImaginary(imaginary){
}

//------------------------------------------------------------------------------
/*! \fn ComplexNumber(const ComplexNumber&)
*   \brief  Copy constructor
*/
ComplexNumber::ComplexNumber(const ComplexNumber & source):
	myReal(source.GetReal()),
	myImaginary(source.GetImaginary()){
}

//------------------------------------------------------------------------------
/*! \fn ~ComplexNumber()
*   \brief  destructor
*/
ComplexNumber::~ComplexNumber(){
}

//------------------------------------------------------------------------------
/*! \fn operator+(const ComplexNumber & z) const
*   \brief  + operator
*/
ComplexNumber ComplexNumber::operator+(const ComplexNumber & z) const {
	return ComplexNumber(this->GetReal() + z.GetReal(), this->GetImaginary() + z.GetImaginary());
}

//------------------------------------------------------------------------------
/*! \fn Add2(const ComplexNumber & z) const
*   \brief  Add2 function 
*/
ComplexNumber ComplexNumber::Add2(const ComplexNumber& z) const {
	return ComplexNumber(this->GetReal() + z.GetReal(), this->GetImaginary() + z.GetImaginary());
}

//------------------------------------------------------------------------------
/*! \fn operator+(const double & x) const
*   \brief  operator+ add a double
*/
ComplexNumber ComplexNumber::operator+(const double & x) const{
	return ComplexNumber(this->GetReal() + x, this->GetImaginary());
}

//------------------------------------------------------------------------------
/*! \fn operator+(const double & x) const
*   \brief  operator+ add a double
*/
ComplexNumber ComplexNumber::operator-(ComplexNumber& z) const{
	return ComplexNumber(this->GetReal() - z.GetReal(), this->GetReal() - z.GetImaginary());
}

//------------------------------------------------------------------------------
/*! \fn operator-(const double & x) const
*   \brief  operator- a double
*/
ComplexNumber ComplexNumber::operator-(const double & x) const{
	return (*this) + (-1.0*x);
}

//------------------------------------------------------------------------------
/*! \fn operator*(const ComplexNumber & x) const
*   \brief  operator* a ComplexNumber
*/
ComplexNumber ComplexNumber::operator*(const ComplexNumber & z) const{
	return ComplexNumber((this->GetReal()) * z.GetReal() - (this->GetImaginary()) * z.GetImaginary(), this->GetReal() * z.GetImaginary() + this->GetImaginary() * z.GetReal());
}

//------------------------------------------------------------------------------
/*! \fn operator*(const double & x) const
*   \brief  operator* a double
*/
ComplexNumber ComplexNumber::operator*(const double & x) const{
	return ComplexNumber(this->GetReal() * x, this->GetImaginary() *x);
}

//------------------------------------------------------------------------------
/*! \fn operator/(const ComplexNumber & x) const
*   \brief  operator/ a ComplexNumber
*/
ComplexNumber ComplexNumber::operator/(const ComplexNumber & z) const{
	return ComplexNumber((*this)*(z.GetConjugate())/z.GetNorm() );
}

//------------------------------------------------------------------------------
/*! \fn operator /(const double & x) const
*   \brief  operator/ a double
*/
ComplexNumber ComplexNumber::operator/(const double & x) const{
	return ComplexNumber((this->GetReal())/x , (this->GetImaginary()) / x);
}

//------------------------------------------------------------------------------
/*! \fn operator =(const ComplexNumber & x) const
*   \brief  operator= a ComplexNumber
*/
ComplexNumber & ComplexNumber::operator=(const ComplexNumber & z){
	SetReal(z.GetReal());
	SetImaginary(z.GetImaginary());
	return *this;
}

//------------------------------------------------------------------------------
/*! \fn operator =(const double & x) const
*   \brief  operator= a double
*/
ComplexNumber & ComplexNumber::operator=(const double x){
	SetReal(x);
	SetImaginary(0);
	return *this;
}

//------------------------------------------------------------------------------
/*! \fn  ComplexNumber GetConjugate() const
*   \brief  ComplexNumber GetConjugate() const
*/
ComplexNumber ComplexNumber::GetConjugate() const{
	return ComplexNumber(myReal, -myImaginary);
}


//------------------------------------------------------------------------------
/*! \fn  ComplexNumber PrintComplexNumber() const
*   \brief   PrintComplexNumber() const
*/
void ComplexNumber::PrintComplexNumber(void)
{
	std::cout << "The complex number is: " << GetReal() << " + " << GetImaginary() <<"I" << std::endl;
}

