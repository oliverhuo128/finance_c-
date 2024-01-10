//------------------------------------------------------------------------------
//
// OOP
// Person.h
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include guard

#ifndef OOP_PERSON_H
#define OOP_PERSON_H

//------------------------------------------------------------------------------
// include files
#include <string>

//------------------------------------------------------------------------------
// namespace definition
namespace OOP {

	//------------------------------------------------------------------------------
	/*! \class Person in Person.h
   *   \brief This is the class for a person with name height and weight.
   */
	class Person {
	public:
		// Usually we make member variables private. 
		// But here, for illustration, this data is public
		double weight_kg;
		double height_m;
		std::string strName;
		int iAge; 
		double CalculateBMI(void);
	};	// class Person

} // namespace OOP

#endif	// OOP_PERSON_H

//------------------------------------------------------------------------------

