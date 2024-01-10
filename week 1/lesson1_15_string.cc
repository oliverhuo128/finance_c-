#include <iostream>
#include <string>
int main(){

  std::string s = "Hello";
  char c = '!';
  s += c;
  std::cout << s;
  std::string s1 = "Hello ";
  std::string s2 = "World.";
  std::string s3 = s1 + s2;
  std::cout << s3;
  char c1 = s3[0]; // 'H' 
  char c2 = s3.at(0); // 'H';
  char c3 = s3[6]; // 'W'
  char c4 = s3.at(6); // 'W';
  std::cout << "First character: " << c1 << ", sixth character: " << c3;

}




#include <iostream>
#include <string>

std::string s;
std::string reverse(s) {

}




int main()
{
    {
        std::string s;
        double a;
        double b;
        double c;
        cout << "Please enter a value you wish to clamp: ";
        cin >> a;
        cout << "Please enter the lower bound of your clamp: ";
        cin >> b;
        cout << "Please enter the upper bound of you: ";
        cin >> c;
        clamp(b, c, a);
        cout << "the clamp function outputs our new value " << a;
        return 0;
    }

}