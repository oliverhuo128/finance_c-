#include <iostream>
using namespace std;
void oil_leak() { 
  // a function to allocate 8 memory from the heap for a pointer.If you are using a 64 - bit machine, this will use 8 bytes.
  double *pointer = new double(32.54); // allocate butwith new but not delete
}

int main() {
// 8 bytes doesnot seam like a big leak until...
 for(int j = 0; j < 150000; j++) {
   oil_leak();
 }
}