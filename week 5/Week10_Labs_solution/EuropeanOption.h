//------------------------------------------------------------------------------
//
// OOP
// EuropeanOption.h
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include guard
#ifndef OOP_EUROPEANOPTION_H
#define OOP_EUROPEANOPTION_H

//------------------------------------------------------------------------------
// include files
#include <string>
#include <cmath>
#include "EuropeanOption.h"
//------------------------------------------------------------------------------
// namespace definition
namespace OOP {

	//------------------------------------------------------------------------------
	/*! \class EuropeanOption in EuropeanOption.h
	 *  \brief This is the class for a EuropeanCall with sharePrice, expiryTime, strike, volatility, interestRate
	 */
	class EuropeanOption {
	public:
		// Default Constructor
		EuropeanOption();
		// Constructor initialising member data with the given input
		EuropeanOption(
			float sharePrice,
			float expiryTime,
			float strike,
			float volatility,
			float interestRate
		);

		~EuropeanOption();

		// I did not write the accessor functions as for the present problem one does not need them

		// These two functions need to be implemented by the derived classes. Here, compared to the first version of the MC version of this class, we ask for the implementation of a payoff function
		virtual	float PriceOptionAnalytically(void) = 0;
		virtual float Payoff(float S) = 0;
		virtual bool is_in_the_money(float S) const = 0;

		// Now the actual MC pricer is general for every European Option and just depends on the payoff function
		float PriceOptionMC(int numberOfRuns);
	protected:
		// The member data consists of the standard parameters used to price options with the Black-Scholes formula
		float mySharePrice;
		float myExpiryTime;
		float myStrike;
		float myVolatility;
		float myInterestRate;

		// We also declare the Gaussian cumulative distribution function
		// here as a protected member function, so derived classes can use it
		float CDF_normal(float x);

	};	// class EuropeanOption

} // namespace OOP

#endif	// OOP_EUROPEANOPTION_H

//------------------------------------------------------------------------------



