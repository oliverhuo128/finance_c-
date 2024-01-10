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
using namespace OOP;

int main(void)
{ 
	char letter = 's';	                            // Variable declaration Makes a new object. The new object is to be an char
	char*  pletter;                                 // Pointer declaration for a pointer to char could have any value at all. The new object is to be an char-pointer   
	pletter = &letter;

	int number = 30;     	                           // Variable declaration   Makes a new object. The new object is to be an int.               
	int* p;                                          //  Make a new object. The new object is to be an int-pointer  
	p = &number;                                     // stores the address of number variable    
	std::cout << "Address of letter variable is:" << &letter << std::endl;
	std::cout << "Address of pletter variable is:" << pletter << std::endl;
	std::cout << "Value of p variable is:" << *p << std::endl;
	std::cout << "Address of number variable is:" << &number << std::endl;
	std::cout << "Address of p variable is:" << p << std::endl;
	std::cout << "Value of p variable is:" << *p << std::endl;
	//
	//int var{100}, * varPoint;

	//// Wrong! 
	//// varPoint is an address but var is not
	//varPoint = var;

	//// Wrong!
	//// &var is an address
	//// *varPoint is the value stored in &var
	//*varPoint = &var;

	//// Correct! 
	//// varPoint is an address and so is &var
	//varPoint = &var;

	//// Correct!
 //// both *varPoint and var are values
	//*varPoint = var;


	// We declare objects as before
	Student aStudent;                                // Variable declaration 
	Student* ptoaStudent;                            // Pointer declaration for a pointer to Student  
	ptoaStudent = &aStudent; 
	aStudent.SetName("John"); 
	aStudent.SetWeight(50.0);
	ptoaStudent->SetHeight(1.9);                     // call using the pointer 
	aStudent.SetUniversity("University of Birmingham"); 
 

	std::cout << "Address of aStudent variable is:" << &aStudent << std::endl;
	std::cout << "Address of ptoaStudent variable is:" << ptoaStudent << std::endl;
	std::cout << "Value of ptoaStudent  Name variable is:" << ptoaStudent->GetName() << std::endl;

	return 0;
}


