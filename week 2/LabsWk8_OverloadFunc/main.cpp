#include <string>
#include <iostream>     // std::cout
#include <iomanip>      // std::setprecision
#include"PrintHeader.h"
// Prototype three print functions.

using namespace std;


int main(int argc, char *argv[]) {
	const double d = 893094.2987;
	if (argc < 2) {
		// These calls to print invoke print( char *s ).
		print("Error: program requires one argument."); 
		print("digits of precision for the number printed");
		exit(0);
	} 
  // 	std::setprecision(17);
	// call print( double dvalue ).
	print(d);

	// call print( double dvalue, int prec ).
	print(d, atoi(argv[1]));
}
