// Shows a Switch statement.

 #include <iostream>
 using namespace std;

 int main() {

     int grade = 85;

     int tempgrade = grade/10;
	 // switch cases allow for different options based on
     // the value of tempgrade similar to if statements
     switch(tempgrade) {  
       case 10:
       case 9:
         cout << " grade is A" << endl;
         break;
       case 8:
         cout << " grade is B" << endl;
         break;
       case 7:
         cout << " grade is C" << endl;
         break;
       case 6:
         cout << " grade is D" << endl;
         break;
       default:
         cout << " grade is F" << endl;
     }

     return 0;
 }