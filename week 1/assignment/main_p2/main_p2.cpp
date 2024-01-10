//Solution to Problem sheet 1 question 1
//by Zhenting Oliver Huo

#include <iostream>
#include <cmath> 
using namespace std;

bool almost_equal(double a, double b, double c) {

    if (abs(a - b) < abs(c)) {
        return true;
    }
    else
    {
        return false;
    }
}
