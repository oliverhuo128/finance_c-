// startClassTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
using namespace OOP;  

int main(void) {


	// Now we initialize a Person directly with our new constructor
	// Note the syntax. The argumentss in the brackets behind the name of the object indicate which consstrcutor is called
	Person aReasonablyInitilisedPerson("Elizabeth", 1.7, 67, 29);

	std::cout << "BMI of " << aReasonablyInitilisedPerson.GetName() << " is: " << aReasonablyInitilisedPerson.CalculateBMI() << std::endl;

	std::cout << "Her age is " << aReasonablyInitilisedPerson.GetAge() << std::endl;
 
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

	Person& aRefToAPerson = aReasonablyInitilisedPerson;
	std::cout << " Name is: " << aRefToAPerson.GetName();
	Student * aPointerToAStudent = &aReasonablyInitialisedDefaultStudent;
	std::cout << " Name is " << (*aPointerToAStudent).GetName();
	 
	Person& anotherReference = aReasonablyInitialisedDefaultStudent;
	Person* aPersonPointerToAStudent = &aReasonablyInitialisedDefaultStudent;
	std::cout << " Name is " << (*aPointerToAStudent).GetName();

	aPersonPointerToAStudent;
	return 0;
}