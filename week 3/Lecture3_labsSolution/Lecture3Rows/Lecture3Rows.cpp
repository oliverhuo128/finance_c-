// Lecture3Rows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "rows.h"
#include <iostream>

//namespace

using namespace OOP;

int main()
{
  std::cout << "start World!\n";
  row s, r(10, "r:");
  
  for (int j = 0; j < 10; ++j) {
    r.set_at(j, j+1);
  } 
  row t(r);
  s = r;
  s.set_label("s:");
  t.set_label("t:");
  r.printrow(); 
  s.printrow();
  t.printrow();

  std::cout << "end World!\n";
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
