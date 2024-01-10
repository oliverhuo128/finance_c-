//----------------------------------------------------------------------------------------------
/*! \file Student.cpp
    \brief A Implentation files for classes in Student

    \details
*/
//-----------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include files 
#include "Student.h"


using namespace OOP;

//------------------------------------------------------------------------------
/*! \fn void SportsAssignment(void) 
*   \brief  calculatesthe  modules for the student
*/
void Student::SportsAssignment(void){
	// SportsAssignment can access Heightand strName from the base classs Person, because these variables are public
	if (height_m > 1.8) {
		Modules.push_back("Basketball");
		std::cout << "Student " << strName << " is assigned to the Basketball course" << std::endl;
	} else	{
		Modules.push_back("Football");
		std::cout << "Student " << strName << " is assigned to play Football" << std::endl;
	}
}
