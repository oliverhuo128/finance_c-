#include <iostream>  
#include <fstream>  
using namespace std;  
int main () {  
  ofstream filestream("testout.txt");  
  if (filestream.is_open()){   
    filestream << "C++ Tutorial.\n";  
    filestream.close();  
  }  
  else{
	  cout <<"File opening has failed";  
  }
  return 0;  
}  