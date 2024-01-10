//Solution to Problem sheet 1 question 2
//by Zhenting Oliver Huo


#include <iostream>
//iostream is for cin and cout
#include <cmath> 
//cmath declares a set of functions to compute common mathematical operations and transformations
using namespace std;
// do not need to write std:: every time

double EPSILON = 0.05; //predefine EPSILON to equal to 0.05
//defining the bool function almost_equal
bool almost_equal(double a, double b, double c) {

    if (abs(a - b) < abs(c)) {

        //checking if the absolute value of a minus b is less than c
        return true;
        //return true if the absolute value of a minus b is less than c
    }
    else
    {
        return false;
        //return true if the absolute value of a minus b is greater than c
    }
}

//defining the void clamp function. the void type is a special type to represent the absence of a value
void clamp(const double a, const double b, double& c) {
    if (c<=a || almost_equal(c,a,EPSILON)) { //if c is less than or equal to a, OR if c is within epsilon of a
        c = a;                               //then set c=a
    }
    else {
        if (c>=b || almost_equal(c, b, EPSILON)) {//if c is greater than or equal to b, OR if c is within epsilon of b
            c = b;                                //then set c=b
        }
        else{
            c = c;//otherwise c is between a and b we therefore just let it equal itself.
        }
    }
}


int main()
{   double a; //intialise a, b and c as double values
    double b;
    double c;
    int d;  //initialise d as an int value
    gobackhere: //placemarker and label for the goto statement used later on.
    cout << " Type \"1\" and press enter, to input three doubles and then clamp the first value between the last two." << endl ;
    cout << " Type \"2\" and press enter, to run a series of tests, with explanation of what test is running and what it checks for with the clamp function." << endl ; //cout outputs the quotation marks to a console for the user
    cin >> d; //let d be the value that the user types
    if (d == 1) {//if the value for d entered by the user is 1 then we run the following
        cout << "Please enter a value you wish to clamp: ";
        cin >> a; //allow user to input value they wish to clamp
        cout << "Please enter the lower bound of your clamp: ";
        cin >> b; //allow user to input value (lower bound)
        cout << "Please enter the upper bound of you: ";
        cin >> c; //allow user to input value (upper bound)
        clamp(b, c, a); //we now use the clamp function on the values that were just inputted
        cout << "the clamp function outputs our new value " << a; //new value for the input value that went through the clamp function is outputted
    }
    else {
        if(d == 2) {//if the value for d entered by the user is 2 then we run the following 9 tests
            cout << " " << endl; //output just a space and start a new line, just for better aesthetic.
            cout << "TEST 1" << endl;
            cout << "A test for when c < a" << endl;
            cout << "Let a=10 b=20 and c=5" << endl;
            a = 10; //we change the values for a b and c to as such.
            b = 20;
            c = 5;
            clamp(a, b, c); //run the clamp function which only changes the value for c
            cout << "The clamp function outputs our new value for c= " << c << endl;
            cout << "This is a test to show that when c is less than the lower bound (a) then it is set to equal the lower bound." << endl;
            cout << " " << endl;


            cout << "TEST 2" << endl;
            cout << "A test for when c < a and c is within epsilon of \"a\", we have set epsilon arbitrarily to equal 0.05" << endl;
            cout << "Let a=10 b=20 and c=9.999" << endl;
            a = 10; //we change the values for a b and c to as such.
            b = 20;
            c = 9.999;
            clamp(a, b, c); //run the clamp function which only changes the value for c
            cout << "The clamp function outputs our new value for c= " << c << endl;
            cout << "This is a test to show that when c is less than the lower bound (a) then it is set to equal the lower bound and when it also within EPSILON of (a)." << endl;
            cout << " " << endl;


            cout << "TEST 3" << endl;
            cout << "A test for when c = a" << endl;
            cout << "Let a=10 b=20 and c=10" << endl;
            a = 10; //we change the values for a b and c to as such.
            b = 20;
            c = 10;
            clamp(a, b, c); //run the clamp function which only changes the value for c
            cout << "The clamp function outputs our new value for c= " << c << endl;
            cout << "This is a test to show that when c is equal to a it is then set to the same value as a" << endl;
            cout << " " << endl;


            cout << "TEST 4" << endl;
            cout << "A test for when c > a and c is within epsilon of \"a\", we have set epsilon arbitrarily to equal 0.05" << endl;
            cout << "Let a=10 b=20 and c=10.001" << endl;
            a = 10; //we change the values for a b and c to as such.
            b = 20;
            c = 10.001;
            clamp(a, b, c); //run the clamp function which only changes the value for c
            cout << "The clamp function outputs our new value for c= " << c << endl;
            cout << "This is a test to show that when c within EPSILON of (a) it is set to equal to (a)." << endl;
            cout << " " << endl;


            cout << "TEST 5" << endl;
            cout << "A test for when a < c < b" << endl;
            cout << "Let a=10 b=20 and c=15" << endl;
            a = 10; //we change the values for a b and c to as such.
            b = 20;
            c = 15;
            clamp(a, b, c); //run the clamp function which only changes the value for c
            cout << "The clamp function outputs our new value for c= " << c << endl;
            cout << "This is a test to show that when c is between a and b it keeps its original value" << endl;
            cout << " " << endl;

            cout << "TEST 6" << endl;
            cout << "A test for when c < b and c is within epsilon of \"b\", we have set epsilon arbitrarily to equal 0.05" << endl;
            cout << "Let a=10 b=20 and c=19.999" << endl;
            a = 10; //we change the values for a b and c to as such.
            b = 20;
            c = 19.999;
            clamp(a, b, c); //run the clamp function which only changes the value for c
            cout << "The clamp function outputs our new value for c= " << c << endl;
            cout << "This is a test to show that when c within EPSILON of (b) it is set to equal to (b)." << endl;
            cout << " " << endl;


            cout << "TEST 7" << endl;
            cout << "A test for when c = b" << endl;
            cout << "Let a=10 b=20 and c=20" << endl;
            a = 10; //we change the values for a b and c to as such.
            b = 20;
            c = 20;
            clamp(a, b, c); //run the clamp function which only changes the value for c
            cout << "The clamp function outputs our new value for c= " << c << endl;
            cout << "This is a test to show that when c is equal to b it is then set to the same value as b" << endl;
            cout << " " << endl;


            cout << "TEST 8" << endl;
            cout << "A test for when c > b and c is within epsilon of \"b\", we have set epsilon arbitrarily to equal 0.05" << endl;
            cout << "Let a=10 b=20 and c=20.001" << endl;
            a = 10; //we change the values for a b and c to as such.
            b = 20;
            c = 20.001;
            clamp(a, b, c); //run the clamp function which only changes the value for c
            cout << "The clamp function outputs our new value for c= " << c << endl;
            cout << "This is a test to show that when c is greater than the upper bound (b) then it is set to equal the upper bound and when it also within EPSILON of (b)." << endl;
            cout << " " << endl;



            cout << "TEST 9" << endl;
            cout << "A test for when c > b" << endl;
            cout << "Let a=10 b=20 and c=25" << endl;
            a = 10; //we change the values for a b and c to as such.
            b = 20;
            c = 25;
            clamp(a, b, c); //run the clamp function which only changes the value for c
            cout << "The clamp function outputs our new value for c= " << c << endl;
            cout << "This is a test to show that when c is greater than the upper bound (a) then it is set to equal the upper bound." << endl;
            cout << " " << endl;
        
        }
        else {
            cout << "error!" << endl; //if the user enters something else for d that is not 1 or 2 we output "error!"
            goto gobackhere; //then we move the user back to gobackhere:
        }
    }
    return 0;
}
