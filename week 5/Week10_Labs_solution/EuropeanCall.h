//------------------------------------------------------------------------------
//
// OOP
// EuropeanCall.h
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include guard

#ifndef OOP_EUROPEANCALL_H
#define OOP_EUROPEANCALL_H

//------------------------------------------------------------------------------
// include files
#include <string>
#include <cmath>
#include "EuropeanOption.h"
//------------------------------------------------------------------------------
// namespace definition
namespace OOP {

	//------------------------------------------------------------------------------
	/*! \class EuropeanCall in EuropeanCall.h
	 *  \brief This is the class for a EuropeanCall with sharePrice, expiryTime, strike, volatility, interestRate
	 */
	class EuropeanCall : public EuropeanOption {
	public:
		EuropeanCall();
		EuropeanCall(
			float sharePrice,
			float expiryTime,
			float strike,
			float volatility,
			float interestRate
		);
		~EuropeanCall();

		// PriceOptionAnalytically return the option value from the analytic Black Scholes formula
		float PriceOptionAnalytically(void);
		bool is_in_the_money(float S) const { return (S > myStrike) ? true : false; }

		// We declare a payoff function giving the payoff for given share price at expiry
		float Payoff(float S);

	};	// class EuropeanCall

} // namespace OOP

#endif	// OOP_EUROPEANCALL_H

//------------------------------------------------------------------------------


