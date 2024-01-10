 

//------------------------------------------------------------------------------
// include guard

#ifndef PRINTHEADER_H
#define PRINTHEADER_H

//------------------------------------------------------------------------------
// include files
#include <iostream>


int print(std::string s);						 // Print a string.
int print(double dvalue);						 // Print a double.
int print(double dvalue, int prec);	 // Print a double with a
																		 //  given precision.
#endif	// PRINTHEADER_H