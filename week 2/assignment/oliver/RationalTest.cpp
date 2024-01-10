// Problem2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "cRational.h" 
#include <iostream>
#include <string>
using namespace OOP;
using namespace std;

int main()
{
	cRational a;
	std::cout << "Output of default constructor using getters:" << a.Numerator() << "/" << a.Denominator() << std::endl;
	std::cout << "Output of default constructor using friend function:" << a << std::endl;

	cRational b(1, 2);
	std::cout << "Output of complete constructor using friend function:" << b << std::endl;

	cRational c(b);
	std::cout << "Output of copy constructor using friend function:" << c << std::endl;

	cRational d(2, 2);

	d.Set(8);
	std::cout << "Testing the set function, Set(8) " << d << std::endl;

	cRational e;
	e.Set(12, 1000);
	std::cout << "testing the set function, Set(12,1000) " << e << std::endl;
	std::cout << "\n";
	std::cout << "Please input 2 fractions (a/b)\n";

	long long f;
	long long g;
	long long h;
	long long i;
	char s;

	std::cout << "input first fraction" << std::endl;
	
	std::cin >> f >> s >> g;
	
	cRational j(f,g);

	std::cout << "input second fraction" << std::endl;
	
	std::cin >> h >> s >> i;

	cRational k(h,i);

	j.canonicalform();
	k.canonicalform();

	std::cout << "Testing Canonical form" << " Fraction 1" << " = " << j << std::endl;
	std::cout << "Testing Canonical form" << " Fraction 2" << " = " << k << std::endl;

	std::cout << "Testing RealValue of" << " Fraction 1" << " = " << j.RealValue() << std::endl;
	std::cout << "Testing RealValue of" << " Fraction 2" << " = " << k.RealValue() << std::endl;

	std::cout << "Testing + operator " << j << " + " << k << " = " << j + k << std::endl;
	cRational l;
	std::cout << "Testing Add function " << j << " + " << k << " = " << l.Add(j,k) << std::endl;
	std::cout << "Testing - operator " << j << " - " << k << " = " << j - k << std::endl;
	std::cout << "Testing * operator " << j << " * " << k << " = " << j * k << std::endl;
	std::cout << "Testing / operator " << j << " / " << k << " = " << j / k << std::endl;

	string m;
	if ((j < k) == 1) {
		m = "true";
	}
	else {
		m = "false";
	}
	std::cout << "Testing < operator " << j << " < " << k << " = " << m << std::endl;

	string m1;
	if ((j > k) == 1) {
		m1 = "true";
	}
	else {
		m1 = "false";
	}
	std::cout << "Testing > operator " << j << " > " << k << " = " << m1 << std::endl;

	string m2;
	if ((j <= k) == 1) {
		m2 = "true";
	}
	else {
		m2 = "false";
	}
	std::cout << "Testing <= operator " << j << " <= " << k << " = " << m2 << std::endl;

	string m3;
	if ((j >= k) == 1) {
		m3 = "true";
	}
	else {
		m3 = "false";
	}
	std::cout << "Testing >= operator " << j << " >= " << k << " = " << m3 << std::endl;

	string m4;
	if ((j == k) == 1) {
		m4 = "true";
	}
	else {
		m4 = "false";
	}
	std::cout << "Testing == operator " << j << " == " << k << " = " << m4 << std::endl;

	string m5;
	if ((j != k) == 1) {
		m5 = "true";
	}
	else {
		m5 = "false";
	}
	std::cout << "Testing != operator " << j << " != " << k << " = " << m5 << std::endl;


	std::cout << "Testing oppoiste of " << " Fraction 1" << " = " << j.opposite() << std::endl;
	std::cout << "Testing oppoiste of " << " Fraction 2" << " = " << k.opposite() << std::endl;
	std::cout << "Testing reciprocal of " << " Fraction 1" << " = " << j.reciprocal() << std::endl;
	std::cout << "Testing reciprocal of " << " Fraction 2" << " = " << k.reciprocal() << std::endl;

	cRational y;
	cRational x;

	std::cout << "Testing gcd of " << " Fraction 1" << " = " << y.GCD(j.Numerator(), j.Denominator()) << std::endl;
	std::cout << "Testing gcd of " << " Fraction 2" << " = " << x.GCD(k.Numerator(), k.Denominator()) << std::endl;

	std::cout << "Testing exponent function: please enter integer exponent" << std::endl;
	int z;
	std::cin >> z ;
	std::cout << "Testing Fraction 1 to the power of " << z << " = " << j.exp(z) << std::endl;
	std::cout << "Testing Fraction 2 to the power of " << z << " = " << k.exp(z) << std::endl;

	std::cout << "Testing istream: first input numerator then input denominator " << std::endl;
	cRational input;
	std::cin >> input;
	std::cout << input << std::endl;

	std::cout << "final test: access the numerator [0] or denominator [1] " << std::endl;
	std::cout << "the numerator [1] is " << j[1] << std::endl;
	std::cout << "the denominator [0] is "<< j[0] << std::endl;




	



}

