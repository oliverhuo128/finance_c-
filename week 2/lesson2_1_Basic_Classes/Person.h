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
		// But here, this data is public
		double weight_kg;
		double height_m;
		int iAge;

		// strName is private so we can access and set it thorugh these accessors
		void SetName(std::string aString) {
			strName = aString;
		}

		std::string GetName(void) {
			return strName;
		}


		double CalculateBMI(void) {
			return (weight_kg / (height_m * height_m));
		}

		private:
			// myName is private, so you cannot directly access it in main
			// or outside of this class
			std::string strName;
	};	// class Person

} // namespace OOP

#endif	// OOP_PERSON_H

//------------------------------------------------------------------------------

