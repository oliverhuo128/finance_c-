// demonstrates the difference between pass-by-value
// and pass-by-reference functions.
#include<iostream>  
using namespace std;    

void swap(int *x, int *y){  
 int swap;  
 swap=*x;  
 *x=*y;  
 *y=swap;  
}  

void func1(int var1, int var2){
    int temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

void func2(int &var1, int &var2){
    int temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

int main(){ 
  int x=500, y=100;    

  func1(x, y);
  cout << "results of func1:" << endl;
  cout << "x: " << x << ", y: " << y << endl;
  func2(x, y);
  cout << "results of func2:" << endl;
  cout << "x: " << y << ", y: " << y << endl;
 
    
  swap(&x, &y);  // passing value to function  
  cout << "results of swap:" << endl;
  cout << "x: " << y << ", y: " << y << endl;

  return 0;  
}    