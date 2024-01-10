#include <cstdlib>/* srand, rand */ 
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  int iSecret, iGuess;
  // initialize random seed: 
  srand((unsigned)time(0));

  // generate secret number between 1 and 10:  
  iSecret = (rand() % 10) + 1;

  do {
    cout << ("Guess the number (1 to 10): \n");
    cin >> iGuess;
    if (iSecret < iGuess) {
      cout << ("The secret number is lower \n");
    }
    else if (iSecret > iGuess) {
      cout << ("The secret number is higher \n");
    }
  } while (iSecret != iGuess);

  cout << "Congratulations!";
  return 0;
}
