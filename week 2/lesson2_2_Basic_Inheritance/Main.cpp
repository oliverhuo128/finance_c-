//------------------------------------------------------------------------------
//
// Basic Classes
// main.cpp
// Start OOP concept of classes and objects. 
// with class for a person that contains data for the person
// and a class for students
//------------------------------------------------------------------------------
 

//------------------------------------------------------------------------------
// include files  
#include <iostream>
#include "Student.h"


int main(void)
{
	// We now declare an object of the class Student
	Student aStudent;
	// Since strName is a public member of Person, and Student inherits from Person, we can access myName in the same way as if we had declared aStudent to be an object of type Person
	aStudent.strName = "John";

	// Likewise, we can access the other member variables and also the member function CalculateBMI()
	aStudent.weight_kg = 50.;
	aStudent.height_m = 1.75;
	std::cout << "BMI is: " << aStudent.CalculateBMI() << std::endl;

	// But a Student is "more" than a person. A student has, for instance, a University
	aStudent.strUniversity = "University of Birmingham";
	
	// What happens if we try to access uninitialised member data?
	std::cout << "Age is: " << aStudent.iAge << std::endl;

	// We now call the new function that assigns sports modules
	aStudent.SportsAssignment();

	// We check that the correct module was entered into the list of modules
	for (int i = 0; i < aStudent.Modules.size(); ++i) {
		std::cout << aStudent.strName << " is enrolled to " << aStudent.Modules.at(i) << std::endl;
	}
	
	return 0;
}