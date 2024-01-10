#include "EuropeanPut.h"
#include <cmath>
#include <random>
#include <iostream>
using namespace OOP;

EuropeanPut::EuropeanPut(){
}

EuropeanPut::EuropeanPut(
	double sharePrice,
	double expiryTime,
	double strike,
	double volatility,
	double interestRate
	) :
	EuropeanOption(sharePrice,  expiryTime, strike, volatility, interestRate){
}

EuropeanPut::~EuropeanPut(){
}

double EuropeanPut::PriceOptionAnalytically(void){
	std::cout << "EuropeanPut::PriceOptionAnalytically" << std::endl;
	return 2.0;
}



double EuropeanPut::Payoff(double S){
	std::cout << "EuropeanPut::Payoff" << std::endl;
		return 0.0;
}
