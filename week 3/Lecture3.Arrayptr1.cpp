
// Array pointers
#include <iostream>
using namespace std;

double getAverage(int arr[], int size) {
  int i, sum = 0;
  double avg;

  for (i = 0; i < size; ++i) {
    sum += arr[i];
  }
  avg = double(sum) / size;

  return avg;
}

double getAverage1(int arr[5]) {
  int i, sum = 0;
  double avg;

  for (i = 0; i < 5; ++i) {
    sum += arr[i];
  }
  avg = double(sum) / 5;

  return avg;
}

double getAverage2(int *arr, int size) {
  int i, sum = 0;
  double avg;

  for (i = 0; i < size; ++i) {
    sum += arr[i];
  }
  avg = double(sum) / size;

  return avg;
}

int main()
{
  int iNumbers[5];
  int* p;
  p = iNumbers;                  // assign p the address of iNumbers
  *p = 10;                       // deref and assign iNumbers[0]=10
  p++;                           // move to next iNumbers[1]
  *p = 20;                       //  iNumbers[1]=20
  p = &iNumbers[2];              // assign address iNumbers[2] to p 
  *p = 30;                       // deref and assign value 30
  p = iNumbers + 3;              // Use arithmetic to find get memory address iNumbers[3]
  *p = 40;
  p = iNumbers;  
  *(p + 4) = 50;
  for (int n = 0; n < 5; n++)
    cout << iNumbers[n] << ", ";    // output : 10 20 30 40 50
  cout << "\n";
  cout << getAverage(iNumbers, 5)  << "  getAverage(int arr[], int size)  \n";    
  cout << getAverage1(iNumbers)    << "  getAverage1(int arr[5]) \n";    // 
  cout << getAverage2(iNumbers, 5) << "  getAverage2(int *arr, int size) \n";    // 

  return 0;
}

