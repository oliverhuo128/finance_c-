
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
	class Student : public Person {
	public:
		//Constructors and Destructors
		Student();
		Student(std::string name, double height, double weight, int age, std::string university, std::string subject, std::vector<std::string> modules);
		~Student();

		// Accessor functions
		std::string GetUniversity(void) {
			return strUniversity;
		};

		void SetUniversity(std::string university) {
			strUniversity = university;
		};

		std::string GetSubject(void)
		{
			return strSubject;
		};

		void SetSubject(std::string subject) {
			strSubject = subject;
		};

		std::vector<std::string> GetModules(void) {
			return Modules;
		};

		void SetModules(std::vector<std::string>& modules) {
			Modules = modules;
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


