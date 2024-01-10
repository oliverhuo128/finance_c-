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
		 *  \brief This is the class for a person with name height and weight.
		 */
	class Person {
	public:
		// The default constructor
		Person();
		// A second constructor that takes arguments used to initialise the member variables
		Person(std::string name, double height, double weight, int age);
		// Destructors are typically best declared with the virtual keyword that we will discuss lateer
		virtual ~Person();

		double GetHeight(void) {
			return height_m;
		};

		void SetHeight(double height) {
			height_m = height;
		};

		double GetWeight(void) {
			return weight_kg;
		};

		void SetWeight(double weight) {
			weight_kg = weight;
		};

		double GetAge(void) {
			return iAge;
		};

		void SetAge(int age) {
			iAge = age;
		};

		std::string GetName(void) {
			return strName;
		};

		void SetName(std::string name) {
			strName = name;
		};

		// This functions works as before
		double CalculateBMI(void);

	private:
		double weight_kg;
		double height_m;
		std::string strName;
		int iAge;
	};	// class Person

} // namespace OOP

#endif	// OOP_PERSON_H

//------------------------------------------------------------------------------

