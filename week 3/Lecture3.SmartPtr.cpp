#include <iostream>
using namespace std;

int main() { 

  // When using the std::unique_ptr smart pointer,
  // you can only assign one owner for the pointer behind the wrapper.
  // The object the std::unique_ptr points to is deleted automatically when the smart pointer leaves the scope.
  unique_ptr<int> p1(new int(365));
  //unique_ptr<int> p2 = p1;  // error E1776


  // Using the std::shared_ptr smart pointer means 
  // you can apply multiple owners to a single raw pointer.
  // All of the owners must also leave the scope for it to be deleted.
  shared_ptr<int> p3(new int);
  //shared_ptr smart pointer can also be used for reference counting.
  // It contains an internal counter which tracks the amount of owners not yet destroyed.
  // To check how many pointers lead to the same address, use the use_count() method:
  cout << p3.use_count() << endl; 
  


  // here is a type of C++ memory leak called the circular reference, also known as a cycle.
  // It happens when C++ smart pointers form a referential loop by the 
  // last object in the reference chain points to the first one 
  // (e.g., X points to Y, Y points to Z, and Z points to X): X->Y->Z->X

  std::shared_ptr<char> p_shared = std::make_shared<char>(15);
  std::weak_ptr<char> p_weak1(p_shared);
  std::weak_ptr<char> p_weak2(p_weak1);
  // Both std::weak_ptr and std::shared_ptr smart pointers will point to the same data.
  // However, the std::weak_ptr will not change the value of the internal counter
  // and hence take part in reference counting.It is also not considered as an owner.
   

  //  One more reason to use std::weak_ptr for C++ memory management is that it helps 
  // with dangling pointers(those that point to deleted data).
  // You can check if a particular piece of data is valid by using lock() or expired() :

  if (auto tmp = p_weak1.lock())
    std::cout << *tmp << '\n';
  else
    std::cout << "Sorry, weak1 is no longer valid!\n";

  if (auto tmp = p_weak2.lock())
    std::cout << *tmp << '\n';
  else
    std::cout << "Sorry, weak2 is is no longer valid!\n";

  return 0;
}
