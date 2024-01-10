// Base class
class BaseClassA {
  public:
    void BaseClassA_Function() {
      cout << "Some content in BaseClassA class." ;
    }
};

// Another base class
class BaseClassB {
  public:
    void BaseClassB_Function() {
      cout << "Some content in BaseClassB class." ;
    }
};

// Derived class
class ChildClassAB: public BaseClassA, public BaseClassB {
};

int main() {
  ChildClassAB child_ab;
  child_ab.BaseClassA_Function();
  child_ab.BaseClassB_Function();
  return 0;
}

