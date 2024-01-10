
//------------------------------------------------------------------------------
// include guard
#ifndef OOP_TEACHER_H
#define OOP_TEACHER_H 

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
class Teacher : public Person {
public:
	//Constructors and Destructors
	Teacher() {};

	std::string classes;
};	// class Teacher

} // namespace OOP

#endif	// OOP_TEACHER_H
