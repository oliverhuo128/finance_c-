#include <string>

int main()
{
   int a = 42;
   a = 15;

   // Error cannot convert a string to an integer
   a = "Hello World";

   //Error as we cannot declare 'a' twice
   std::string a = "Hello World";

   return 0;
}