
#include <iostream>     // std::cout
int main()
{
  int x = 123;
  int* p = &x;
  std::cout << "The value of the dereferenced pointer is: " << *p;
  
  *p = 456; // change the value of pointed-to object
  std::cout << "The value of x is: " << x;
  
  char* q = nullptr; //It is said that p is now a null pointer.
  // references
  int& y = x;
  x = 456;
  // both x and y now hold the value of 456
  y = 789;
  // both x and y now hold the value of 789

  return 0;

}