 
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
#include "Person.h"

//------------------------------------------------------------------------------
// namespace definition
namespace OOP {  

	class Student:	public Person{
		public:

		// Accessor functions
		std::string GetUniversity(void){
			return strUniversity;
		};
		
		void SetUniversity(std::string university){
			strUniversity = university;
		};
		
		std::string GetSubject(void){
			return strSubject;
		};
		
		void SetSubject(std::string university){
			strSubject = university;
		};
		
		std::vector<std::string> GetModules(void){
			return Modules;
		};
		
		void SetModules(std::vector<std::string>& university){
			Modules = university;
		};
		// SportsAssigment assigns Students to different modules depending on height
		void SportsAssignment(void);

	  private:
		
		std::string strUniversity;
        std::string strSubject; 
        std::vector <std::string> Modules;

	};	// class Student

} // namespace OOP

#endif	// OOP_STUDENT_H

//------------------------------------------------------------------------------


