 // Shows how to use conditional statements
 #include <iostream>
 using namespace std;

 int main() {
 
   int x = 5;
   if(x == 5){
     std::cout << "The value of x is equal to 5.";
   }
   x = 10;
   if (x > 5){
     std::cout << "The value of x is greater than 5.";
   }
   
   if (x >= 10){
     std::cout << "\nThe value of x is greater than or equal to 10.";
   }
   
   if (x != 20){
     std::cout << "\nThe value of x is not equal to 20.";
   }
   
   if (x == 20){
     std::cout << "\nThe value of x is equal to 20.";
   }
     int grade = 85;

     if (grade < 60) {
       cout<<'F'<< endl;
     }
     else {      /* if, elif, and else statement can be used
                     inside of themselves to allow for sub options */
         if (grade < 70) {
             cout<<'D'<< endl;
         }
         else {
             if (grade < 80) {
                 cout<<'C'<< endl;
             }
             else {
                 if (grade < 90) {
                     cout<<'B'<< endl;
                 }
                 else {
                     cout<<'A'<< endl;
                 }
             }
         }
     }
	 
	 
     return 0;
 }
