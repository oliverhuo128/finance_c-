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
*   \brief  calculates the  modules for the student
*/
void Student::SportsAssignment(void){
	// Since member data in Person is private, we can only access myName and myHeight through the accessor functions
	if (GetHeight() > 1.8) {	
		Modules.push_back("Basketball");
		std::cout << "Student " << GetName() << " is assigned to the Basketball course" << std::endl;
	} else	{
	    Modules.push_back("Football");
		std::cout << "Student " << GetName() << " is assigned to play Football" << std::endl;
	}
}
