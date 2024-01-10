#include "FunctionUtils.h"
#include "cRational.h"

using namespace OOP;

void PrintcRational(const cRational& RationalNum)
{
	if (RationalNum.Numerator() == 0)
	{
		std::cout << 0;
	}
	else if (RationalNum.Denominator() == 1)
	{
		std::cout << RationalNum.Numerator();
	}
	else
	{
		std::cout << RationalNum.Numerator() << "/" << RationalNum.Denominator();
	}
}

void PrintMixedRational(const cRational& RationalNum)
{
	long long numerator = RationalNum.Numerator();
	long long denominator = RationalNum.Denominator();
	bool NegativeSign = false;

	if (numerator < 0)
	{
		NegativeSign = true;
		numerator = -numerator;
	}

	cRational RationalNumCopy{ numerator, denominator }; // create a copy of the RationalNum with sign changed.

	if (numerator == 0)
	{
		std::cout << 0;
	}
	else if (denominator == 1)
	{
		std::cout << numerator;
	}
	else
	{
		if (numerator < denominator) // Don't need to use <= as output will be 1 if num = den
		{
			std::cout << numerator << "/" << denominator;
		}
		else
		{
			long long integer_part = numerator / denominator;
			cRational integer_as_rational{ integer_part,1 };
			cRational rational_part = RationalNumCopy - integer_as_rational;

			if (NegativeSign == true) {
				std::cout << "-";
			}

			std::cout << integer_part << " " << rational_part.Numerator() << "/" << rational_part.Denominator();
		}
	}
}