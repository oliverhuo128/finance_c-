// start_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum eDays { kMonday, kTuesday, kWednesday, kThursday, kFriday, kSaturday, kSunday };

enum  class eMathatician {
	kCauchy = 1789,
	kEuler = 1707,
	kFourier = 1768,
	kGauss = 1777,
	kHesse = 1811,
	kHilbert = 1862,
	kKronecker = 1823,
	kLaplace = 1749,
}; // numerical value == year of birth

enum eColor { red, green, blue };

int main()
{
	eDays today = eDays::kWednesday;
	eDays tomorrow;
	eMathatician favMathmatician = eMathatician::kHesse;
	std::cout << "enum today:" << today << std::endl;
	std::cout << "sizeof(today):" << sizeof(today) << std::endl;

	if (myday == Days::Monday)
	{
		etomorrow = Days::Friday;
	}

	std::cout << "enum favMathmatician:" << static_cast<int>(favMathmatician) << std::endl;   // enum class will not convert to int to cast is need
	std::cout << "sizeof(favMathmatician):" << sizeof(favMathmatician) << std::endl;

	int i = today;
	std::cout << "i:" << i << std::endl;
	std::cout << "sizeof(i):" << sizeof(i) << std::endl;
	i = static_cast<int>(favMathmatician);
	std::cout << "i:" << i << std::endl;
	std::cout << "sizeof(i):" << sizeof(i) << std::endl;

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
