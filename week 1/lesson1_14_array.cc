#include <iostream>
#include <array>

using namespace std;

int main()
{
  int array1[3] = {10,20,30};
  cout << "array1[2]"<<array1[2] << '\n'; 
 
  array<int,3> array2 {10,20,30}; 
  cout << "array2[2]"<<array2[2] << '\n';
}
