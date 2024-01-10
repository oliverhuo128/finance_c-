 
//------------------------------------------------------------------------------
//
// library OOP
// Student.h
// Declares a class Student that inherits from Person and has some additional member 
// variables and member functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include guard
#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H 

//------------------------------------------------------------------------------
// include files
#include <string>
#include <iostream>
#include <vector>
// We need to include "Person.h" since otherwise we cannot inherit from the Person class
#include "Person.h"

//------------------------------------------------------------------------------
// namespace definition
namespace OOP {

	//------------------------------------------------------------------------------
	/*! \class Student in Student.h
   *   \brief This is the class for a Student with modules.
   */
	class Student:	public Person {
	public:
		// SportsAssigment assigns Students to different modules depending on height
		void SportsAssignment(void);
		
		std::string strUniversity;
        std::string strSubject; 
        std::vector <std::string> Modules; 

	};	// class Student

} // namespace OOP

#endif	// OOP_STUDENT_H

//------------------------------------------------------------------------------



