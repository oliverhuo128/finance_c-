//Solution to Problem sheet 1 question 3
//by Zhenting Oliver Huo


#include <iostream>
//iostream cin and cout
#include <string>
//include string type so no need to write std::string everytime
using namespace std;
// do not need to write std:: every time

//first we define the swap function
void swap(int* x, int* y) {
    int swap; //define variable swap as an integer type
    swap = *x; //let the value of swap be equal to the pointer towards x
    *x = *y; //let the value of x now equal y
    *y = swap; //let the new value of y be equal to the value of swap, which we set before.
}


//we define the reverse function that has type std::string, we don't really need std:: as we had include string.
std::string reverse(string s) {
    int n = s.length(); //let the value of n be the length of the string s/

    for (int x = 0; x < n / 2; x++){     //x starts from 0, it increases by 1 after each iteration until it is no longer less than n divided by 2.
        swap(&s.at(x), &s.at(n - 1 - x)) ;  // swap the digit of the string at x with the digit of the string at n-1-x
    }
    return s; //return the new value for s which is the reverse of the original s.
}


//the bool function which examines two strings s and t to see if one of these the the reverse of the other. 
bool reverse(string s, string t) {
    if (s == reverse(t)) { //does s requal to the reverse of t
        return true;  //return true if it does
    }
    else {
        return false;  //otherwise return false if s does not equal to the reverse of t.
    }
}





int main()
{
    {
        std::string s; //intialise string s
        std::string t; //initialise string t
        int option;   //initialise the variable called option as an integer variable.
        cout << "Please enter a string s ";
        cin >> s; //user inputs a string value for s
        cout << "Please enter a string t ";
        cin >> t;  //user inputs a string value for t
        gobackhere:  //placemarker and label for the goto statement used later on.
        cout << "Type /"1/" and hit Enter if you wish to make the second string t the reverse of the first."<< endl;
        cout << "Type /"2/" and hit Enter if you wish to test if the first string s is the reverse of the second t." << endl;
        cin >> option;  //user inputs a inter value for option
        if (option == 1) { //if option is equal to 1 then....
            t = reverse(s); //t is now equal to the reverse of string s through the function reverse which we defined above.
            cout << "s=" << s << endl;  //output original s value
            cout << "t=" << t << endl;  //output new t value which is the reverse of the s value
        }
        else {
            if (option == 2) {//if user chooses option 2 and types 2 then....
                if (reverse(s, t) == true) { //we run the bool function reverse(s, t) which we defined above. to see if the s is indeed the reverse of t. 
                    cout << "s is equal to the reverse of t."; 

                }
                else {
                    cout << "s is not equal to the reverse of t.";
                }

            }
            else {
                cout << "error!" << endl;  //if user input something else other than 1 or 2 for the variable option then an "error!" is outputted
                goto gobackhere; //after the error output the goto statement takes us back to the lable gobackhere:
            }
        
        }

  
        return 0;
    }

}