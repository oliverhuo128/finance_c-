// pointer to function example
#include <iostream>
using namespace std;

// Addition function
int addition (int a, int b){ 
 return (a+b); 
}

// Subtraction
int subtraction (int a, int b){ 
 return (a-b); 
}

// function operation calls the function
int operation (int x, int y, int (*functocall)(int,int)){
  int g;
  g = (*functocall)(x,y);
  return (g);
}

int main (){
  int m,n;
  int (*minus)(int,int) = subtraction;

  m = operation (7, 5, addition);      // use the function name
  n = operation (20, m, minus);        // pass a function ptr
  cout << n;
  return 0;
}