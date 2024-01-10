//------------------------------------------------------------------------------
//
// Basic Classes
// main.cpp
// Start OOP concept of classes and objects. 
// Our first example is a class for a person that contains data for the person
//------------------------------------------------------------------------------
 

//------------------------------------------------------------------------------
// include files  
#include <iostream>
#include "Person.h"


int main(void)
{
	Person aPerson;

	aPerson.iAge = 21;
	aPerson.weight_kg = 77.0;
	aPerson.height_m = 1.75;

	// strName cannot be set like: aPerson.strName = "Simon";
	// Because it is private, we use the accessor
	aPerson.SetName("Simon");

	std::cout << "BMI of " << aPerson.GetName() << ": " << aPerson.CalculateBMI() << std::endl;

	return 0;
}