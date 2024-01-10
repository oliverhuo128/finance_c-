//------------------------------------------------------------------------------
//
// Complex Number Classes
// Main.cpp
// Start OOP concept of classes and objects. 
// tests Our Complex Number Class
//------------------------------------------------------------------------------
 

//------------------------------------------------------------------------------
// include files   
#include "ComplexNumbers.h"


int main(void){
	OOP::ComplexNumber a(1.0, 2.0);
	OOP::ComplexNumber b(1.0,2.0); 
	std::cout << "a :" << a << ": b: " << b << std::endl;
	std::cout << "a+b :" << a + b << std::endl;
	std::cout << "a - b :" << a - b << std::endl;
	std::cout << "a * b :" << a * b << std::endl;
	std::cout << "a / b :" << a / b << std::endl;
	std::cout << "a GetConjugate :" << a.GetConjugate()<< std::endl;
	
	return 0;
}