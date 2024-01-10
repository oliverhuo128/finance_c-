// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
 // Shows how to use conditional statements
// Shows a Switch statement.
#include <iostream>
// function name: "isodd"
// parameter list one parameter, with name "n" and type int
// return type is bool
bool isodd(int n)
{                      // the body of the function begins
    return n % 2;
}


int main() {
    for (int arg : {-3, -2, -1, 0, 1, 2, 3})
        std::cout << isodd(arg) << ' '; // isodd called 7 times, each
                                        // time n is copy-initialized from arg
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
