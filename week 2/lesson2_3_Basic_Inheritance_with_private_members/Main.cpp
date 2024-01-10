//------------------------------------------------------------------------------
//
// Basic Classes
// main.cpp
// Start OOP concept of classes and objects. 
// with class for a person that contains data for the person
// and a class for students
// Here we construct an object of Student that has all member data private
//------------------------------------------------------------------------------
 

//------------------------------------------------------------------------------
// include files
#include <iostream>
#include "Student.h"


int main(void)
{
	// We declare objectss as before
	Student aStudent;
	// But now we cannot set the name by directly accessing the member variable myName. We have to use the accessor function
	aStudent.SetName("John");

	// Likewise with weight and height and university
	aStudent.SetWeight(50.0);
	aStudent.SetHeight(1.9);
	std::cout << "BMI is: " << aStudent.CalculateBMI() << std::endl;
	aStudent.SetUniversity("University of Birmingham");
	
	// We call the Sporrtsassignment 
	aStudent.SportsAssignment();
	// We check that the correct module was entered into the list of modules. Note that we can use the .size() after the accessor function in the same way as if we had accessed the myModules vector directly
	for (int i = 0; i < aStudent.GetModules().size(); ++i)	{
		std::cout << aStudent.GetName() << " is enrolled to " << aStudent.GetModules().at(i) << std::endl;
	}

	return 0;
}