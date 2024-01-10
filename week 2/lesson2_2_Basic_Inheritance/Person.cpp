//----------------------------------------------------------------------------------------------
/*! \file person.cpp
    \brief A Implentation files for classes in person

    \details
*/
//-----------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include files
#include "Person.h"

using namespace OOP;

//------------------------------------------------------------------------------
/*! \fn double CalculateBMI(void) 
*   \brief  calculates BMI from Weight and height
*/
double Person::CalculateBMI(void) 
	return (weight_kg / (height_m * height_m));
}