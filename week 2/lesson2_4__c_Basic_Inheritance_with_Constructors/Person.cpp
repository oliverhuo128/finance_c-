//----------------------------------------------------------------------------------------------
/*! \file person.cpp
		\brief A Implentation files for classes in person

		\details
*/
//-----------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include files
#include "Person.h" 
#include <iostream>

using namespace OOP;

//------------------------------------------------------------------------------
/*! \fn double CalculateBMI(void)
*   \brief  calculates BMI from Weight and height
*/
double Person::CalculateBMI(void){
   return (weight_kg / (height_m * height_m));
}

// The default constructor creates a default person with reasonable values
Person::Person() :
	height_m(1.5), weight_kg(50), iAge(18) // The best way to initialise member variables
{
	// The following works also to initialise member variables, but is not the preferred way for many reasons
	// Especially if some of our member data consists of other complex data types (e.g. other classes), we would first create an object of that class here and then assign it. It is safer and more efficient to initilise all member data 
	// Further, what if you have a data strucure with a fixed length, such as a C-style array or a std::array? Try to initialize this here within this block of code
	strName = "Test Person";

	std::cout << "Default constructor of Person called with no given input. It constructs a test person. " << std::endl;
}

Person::Person(std::string name, double height, double weight, int age) :
	strName(name), height_m(height), weight_kg(weight), iAge(age) // The best way to initialise member variables
{
	std::cout << "Constructor of Person called with given member variables. " << std::endl;
}

// The default destructor
Person::~Person() {
	std::cout << "Destructor of class Person called. " << std::endl;
}
