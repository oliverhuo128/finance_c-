// Multilevel Inheritance

// Base class (parent)
class BaseClassA {
  public:
    void BaseClassAFunction() {
      cout << "Some content in parent class." ;
    }
};

// Derived class (child)
class Child_A: public BaseClassA {
};

// Derived class (grandchild)
class GrandChild_A: public Child_A {
};

int main() {
  GrandChild_A instanceObj;
  instanceObj.BaseClassAFunction();
  return 0;
}