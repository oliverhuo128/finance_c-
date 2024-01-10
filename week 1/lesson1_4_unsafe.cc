#include <iostream>   
int main() 
{ 
  // set up the initial values 
  int a = 42; 
  float b = 3.141; 
  double c = 1.0e45; // 1 * 10^45  
  
  std::cout << “Initial values" << std::endl; 
  std::cout << a << " " << b << " " << c << std::endl;

   // safe conversions as before
  float a1 = a; 
  double b1 = b;   

  std::cout << "Safe conversions" << std::endl; 
  std::cout << a1 << " " << b1 << " " << c << std::endl;   

  // unsafe conversions - potential loss of data 
  // as converting to a type that supports a narrower 
  // range of values 
  int b2 = b; 
  float c2 = c;   
  std::cout << "Unsafe conversions" << std::endl; 
  std::cout << a << " " << b2 << " " << c2 << std::endl;   

  return 0; 
} 
