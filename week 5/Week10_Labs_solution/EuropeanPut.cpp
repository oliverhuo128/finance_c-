#include "EuropeanPut.h"
#include <cmath>
#include <random>
#include <iostream>
using namespace OOP;

EuropeanPut::EuropeanPut(){
}

EuropeanPut::EuropeanPut(
	float sharePrice,
	float expiryTime,
	float strike,
	float volatility,
	float interestRate
	) :
	EuropeanOption(sharePrice,  expiryTime, strike, volatility, interestRate){
}

EuropeanPut::~EuropeanPut(){
}

float EuropeanPut::PriceOptionAnalytically(void){
	std::cout << "EuropeanPut::PriceOptionAnalytically" << std::endl;
    return 1.0;
}



float EuropeanPut::Payoff(float S){
	//std::cout << "EuropeanPut::Payoff" << std::endl;
	//if (S >= myStrike){
	//	return 0.0;
	//}	else	{
	//	return (myStrike - S);
	//}
	//return std::max(myStrike - S, 0.0);

	if (myStrike - S < 0) {
		return 0;
	}
	else {
		return myStrike - S;
	}
} 
