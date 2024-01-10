#include <cmath>
#include <random>
#include <iostream>
#include "EuropeanCall.h"

using namespace OOP;

EuropeanCall::EuropeanCall(){
}

EuropeanCall::EuropeanCall(
	float sharePrice,
	float expiryTime,
	float strike,
	float volatility,
	float interestRate
) :
	EuropeanOption(sharePrice, expiryTime, strike, volatility, interestRate){
}


EuropeanCall::~EuropeanCall(){
}

float EuropeanCall::PriceOptionAnalytically(void) {
	std::cout << "EuropeanCall::PriceOptionAnalytically" << std::endl;
    return 1.0;
}


float EuropeanCall::Payoff(float S){
	//std::cout << "EuropeanCall::Payoff" << std::endl;
	//if (S <= myStrike){
	//	return 0.0;
	//}	else	{
	//	return (S - myStrike);
	//}
	//return std::max( S - myStrike, 0.0);
	
	if (S - myStrike < 0) {
		return 0;
	}
	else {
		return S - myStrike;
	}
}
