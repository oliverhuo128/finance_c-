//------------------------------------------------------------------------------
//
// Basic Classes
// main.cpp
// Start OOP concept of classes and objects. 
// with class for a person that contains data for the person
// and a class for students
// Introduces the use of constructors. 
// We should alwayss implement constructors to our classes 
// and use them to initialise our member variables in a safe way,
// such that the resulting objects are ready to be used
//------------------------------------------------------------------------------
 

//------------------------------------------------------------------------------
// include files
#include <iostream>
#include "Person.h"
#include "Student.h"

int main(void){


	// Now we initialize a Person directly with our new constructor
	// Note the syntax. The argumentss in the brackets behind the name of the object indicate which consstrcutor is called
	Person aReasonablyInitilisedPerson("Elizabeth", 1.7, 67, 29);

	std::cout << "BMI of "<< aReasonablyInitilisedPerson.GetName() << " is: " << aReasonablyInitilisedPerson.CalculateBMI() << std::endl;

	std::cout << "Her age is " << aReasonablyInitilisedPerson.GetAge() <<std::endl ;

	// Now we create a Student with the default constructor. No round brackets are used here
	Student aReasonablyInitialisedDefaultStudent;
	
	std::cout << "BMI of " << aReasonablyInitialisedDefaultStudent.GetName() << " is: " << aReasonablyInitialisedDefaultStudent.CalculateBMI() << std::endl;

	// We call the SportsAssignment 
	aReasonablyInitialisedDefaultStudent.SportsAssignment();
	// We check that the correct module was entered into the list of modules. Note that we can use the .size() after the accessor function in the same way as if we had accessed the myModules vector directly
	for (int i = 0; i < aReasonablyInitialisedDefaultStudent.GetModules().size(); ++i)
	{
		std::cout << aReasonablyInitialisedDefaultStudent.GetName() << " is enrolled to " << aReasonablyInitialisedDefaultStudent.GetModules().at(i) << std::endl;
	}



	return 0;
}