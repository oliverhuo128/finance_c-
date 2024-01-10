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
	i = static_cast<int>( favMathmatician);
	std::cout << "i:" << i << std::endl;
	std::cout << "sizeof(i):" << sizeof(i) << std::endl;

}
