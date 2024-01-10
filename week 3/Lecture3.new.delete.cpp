
#include <iostream> 
using namespace std; 

int main() {
  // declare an int pointer
  int* pointVar;

  // declare a float pointer
  float* pointFloat;

  // dynamically allocate memory
  // using the new keyword  
  // Notice that we have used the pointer pointVar to allocate the memory dynamically.
  // This is because the new operator returns the address of the memory location.
  pointVar = new int;
  pointFloat = new float;

  // assigning value to the memory
  *pointVar = 45;
  *pointFloat = 45.45f;

  cout << *pointVar << endl;
  cout << *pointFloat << endl;
   
  // Once we no longer need to use a variable that we have declared dynamically, 
  // we can deallocate the memory occupied by the variable.
  // For this, the delete operator is used.It returns the memory to the operating system.
  // This is known as memory deallocation.
  delete pointVar;  
  delete pointFloat;

  int num;
  cout << "Enter total number of students: ";
  cin >> num;
  float* ptr;

  // memory allocation of num number of floats
  ptr = new float[num];

  cout << "Enter Score of students." << endl;
  for (int i = 0; i < num; ++i) {
    cout << "Student" << i + 1 << ": ";
    cin >> *(ptr + i);
  }

  cout << "\nDisplaying score of students." << endl;
  for (int i = 0; i < num; ++i) {
    cout << "Student" << i + 1 << " :" << *(ptr + i) << endl;
  }

  // ptr memory is released
  delete[] ptr;

  return 0;

}