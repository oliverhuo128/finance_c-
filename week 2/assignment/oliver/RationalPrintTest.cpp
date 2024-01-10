
#include "cRational.h" 
#include <iostream>
#include <string>
#include "FunctionUtils.h"
using namespace OOP;
using namespace std;

int main(){
	long long f;
	long long g;
	char s;

	std::cout << "input fraction (a/b)" << std::endl;
	std::cin >> f >> s >> g;
	cRational j(f, g);

	std::cout << "Testing PrintcRational function: ";
	PrintcRational(j);
	std::cout << "" << std::endl;
	std::cout << "Testing PrintMixedRational function: ";
	PrintMixedRational(j);
	std::cout << "" << std::endl;

}