#include "EuropeanOption.h"
#include <cmath>
#include <random>
using namespace OOP;

EuropeanOption::EuropeanOption() {
	mySharePrice = 0.0;
	myExpiryTime = 0.0;
	myStrike = 0.0;
	myVolatility = 0.0;
	myInterestRate = 0.0;
}


EuropeanOption::EuropeanOption(
	float sharePrice,
	float expiryTime,
	float strike,
	float volatility,
	float interestRate
)  :
	mySharePrice(sharePrice),
	myExpiryTime(expiryTime),
	myStrike(strike),
	myVolatility(volatility),
	myInterestRate(interestRate){
		
}

EuropeanOption::~EuropeanOption(){
}

// Performs numberOfRuns MC simulations to estimate the price. Here this function works with any derived class at just depends on the payoff of the derived class
float EuropeanOption::PriceOptionMC(int numberOfRuns){

	// We use the same random number generator as before;
	std::random_device random_dev;
	std::mt19937 random_generator(random_dev());

	// For standard European options, we sample from a normal distribution 
	// which we later convert into the corresponding log-normal distribution.
	// Note that contrary to the call, we sample here from a normal with the right parameters,
	// instead of shifting the parameters later on
	std::normal_distribution <float> distribution(myInterestRate * myExpiryTime - 0.5 * myVolatility * myVolatility * myExpiryTime, myVolatility * sqrt(myExpiryTime));

	float price_at_expiry = 0.0;
	for (int i = 0; i < numberOfRuns; ++i){
		// We simply sum all the simulated payoffs. 
		// The payoff function called here will be the one implemented in the derived class
		price_at_expiry += Payoff(mySharePrice * exp(distribution(random_generator)));
	}

	// Th simulated price is simply the average payoff obtained from all of our simulations, 
	// discounted back to the present time (here assumed to be zero)
	return exp(-myInterestRate * myExpiryTime) * price_at_expiry / numberOfRuns;
}
  
// We define the Gaussian CDF here as a protected member function, so deriveed classes can use it
float EuropeanOption::CDF_normal(float x){
	//https://en.cppreference.com/w/cpp/numeric/math/erfc 
	return std::erfc(-x / std::sqrt(2)) / 2;
}

