#include <iostream>     // std::cout

int main(){

  char arr[5];
  int arr1[5];
  arr[0] = 100;   // change the value of the first array element
  arr1[4] = 500;  // change the value of the last array element

  int arr2[5] = { 10, 20, 30, 40, 50 };  //initialiser list  
  double S[5763];
  S [0] = 32.4;  
  S [1] = 43.7;
  S [5762] = 63.2;
  arr[0] = 'H';
  arr[1] = 'E';
  arr[2] = 'L';
  arr[3] = 'L';
  arr[4] = 'O';
  std::cout << "The first array element is: " << arr[0] << '\n';
  std::cout << "The last array element is: " << arr[4] << '\n';
  	
  int matrix [3][5];

 
  int matrix1[2][2] = { { 0, 1 }, { 2, 3 } };
  matrix1[0][0] = 0;
  matrix1[0][1] = 1;  
  // to reference the second element vertically 
  // and fourth horizontally in an expression would be:
  std::cout << "matrix[1][0]"<<matrix[1][0]<< '\n';
  // Multidimensional arrays are not limited to two indices 
  //(i.e., two dimensions). They can contain as many indices as needed.
  //  the amount of memory needed for an array increases exponentially with each dimension
  // char century [100][365][24][60][60];
  // declares an array with an element of type char for each second in a century. This amounts to more than 3 billion char! So this declaration would consume more than 3 gigabytes of memory!
  return 0;  
}