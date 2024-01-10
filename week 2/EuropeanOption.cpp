#include "EuropeanOption.h"
#include <cmath>
#include <random>
using namespace OOP;

EuropeanOption::EuropeanOption(){
}


EuropeanOption::EuropeanOption(
	double sharePrice,
	double expiryTime,
	double strike,
	double volatility,
	double interestRate
	):
	mySharePrice(sharePrice),
	myExpiryTime(expiryTime),
	myStrike(strike),
	myVolatility(volatility),
	myInterestRate(interestRate){

}

EuropeanOption::~EuropeanOption(){
}

// Performs numberOfRuns MC simulations to estimate the price. Here this function works with any derived class at just depends on the payoff of the derived class
double EuropeanOption::PriceOptionMC(int numberOfRuns){
	return 1.0;
}

// We defie the Gaussiand CDF here as a protected member function, so deriveed classes can use it
double EuropeanOption::CDF_normal(double x)
{
	return 0.5 * erfc(-x / sqrt(2));
}

