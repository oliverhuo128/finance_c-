//Solution to Problem sheet 1 question 1
//by Zhenting Oliver Huo


#include <iostream>
//iostream cin and cout
#include <cmath> 
//for common mathematical operations in this case abs()
using namespace std;
// do not need to write std:: every time

//defining the bool function almost_equal
bool almost_equal (double a, double b, double EPSILON) {
    
    if (abs(a-b)<abs(EPSILON))  {
        //checking if the absolute value of a minus b is less than EPSILON
        return true;
        //return true if the absolute value of a minus b is less than EPSILON
    }
    else
    {
        return false;
        //return true if the absolute value of a minus b is greater than EPSILON
    }
}
    

int main()
{
   //initialise the values for a b and c
   //the folowing is a test of a and b for small numbers near 0.
   double a = 0.00001;
   double b = 0.00002; //set a and b to be small numbers near 0.
   double EPSILON;
   cout << "Please input a value for EPSILON "; //cout outputs the text in speechmarks.
   cin >> EPSILON;
   //cin allows the user to input a value of their choice for EPSILON
   cout << "Test for small numbers near 0, a=" << a << ", b=" << b;
   cout << " where EPSILON is equal to " << EPSILON << ". a and b are ";
   if (almost_equal(a, b, EPSILON) == true) {
    //the if statement to run this test on the function
       cout << "within EPSILON" << "\n" << endl;
       //if the function outputs true then the above is outputted as text for the user
   }
   else {
       cout << "outside of EPSILON" << "\n" << endl;
       //if the function outputs false then the about is outputted as text for the user
   }


   //the following is a test for numbers between 1-2
   a = 1.5;
   b = 1.6; //we set values of a and b to arbitrary values between 1 and 2
   cout << "Test for numbers between 1 and 2, a=" << a << ", b=" << b;
   cout << " where EPSILON is equal to " << EPSILON << ". a and b are ";
   if (almost_equal(a, b, EPSILON) == true) { //the if statement to run this test on the function
       cout << "within EPSILON" << "\n" << endl;
       //if the function outputs true then the above is outputted as text for the user
   }
   else {
       cout << "outside of EPSILON" << "\n" << endl;
       //if the function outputs false then the about is outputted as text for the user
   }

   //the following is a test for large numbers against small numbers
   a = 10000000; //set a as a large number
   b = 0.00001;  //set b as a small number
   cout << "Test for larger number against small number, a="<< a <<", b=" <<b;
   cout << " where EPSILON is equal to " << EPSILON << ". a and b are ";
   if (almost_equal(a, b, EPSILON) == true) {//the if statement to run this test on the function
       cout << "within EPSILON" << "\n" << endl;
       //if the function outputs true then the above is outputted as text for the user
   }
   else {
       cout << "outside of EPSILON" << "\n" << endl;
       //if the function outputs false then the about is outputted as text for the user
   }

   //the following is a test for a large number against another large number
   a = 10000000; //set a as a large number
   b = 20000000; //set b as another large number
   cout << "Test for larger number against large number, a=" << a << ", b=" << b;
   cout << " where EPSILON is equal to " << EPSILON << ". a and b are ";
   if (almost_equal(a, b, EPSILON) == true) {//the if statement to run this test on the function
       cout << "within EPSILON" << "\n" << endl;
       //if the function outputs true then the above is outputted as text for the user
   }
   else {
       cout << "outside of EPSILON" << "\n" << endl;
       //if the function outputs false then the about is outputted as text for the user
   }


   //the folowing is a test of the function almost_equal for a and b as a negative number and a postive number
   a = -1; //setting a as a negative number
   b = 1; //setting b as a postive number
   cout << "Test for negative number against positive number, a=" << a << ", b=" << b;
   cout << " where EPSILON is equal to " << EPSILON << ". a and b are ";
   if (almost_equal(a, b, EPSILON) == true) {//the if statement to run this test on the function
       cout << "within EPSILON" << "\n" << endl;
       //if the function outputs true then the above is outputted as text for the user
   }
   else {
       cout << "outside of EPSILON" << "\n" << endl;
       //if the function outputs false then the about is outputted as text for the user
   }


   



    return 0;
}
