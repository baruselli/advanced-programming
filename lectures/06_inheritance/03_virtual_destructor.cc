#include <iostream>

struct Base {
  Base() { std::cout << "Base\n"; }
//  virtual ~Base() { std::cout << "~Base\n"; }
   ~Base() { std::cout << "~Base\n"; }
};

struct Derived : public Base {
  Derived():  p{new int[3]} {std::cout << "Derived\n"; }
  ~Derived() { delete[] p;std::cout << "~Derived\n"; }
  int *p;                                                       //also for this I need virtual
};

int main() {
  { Derived d; }            //this is a scope: d is immediately destroyed

  std::cout << "\n\npointers\n";
  Base* p = new Derived;
  delete p;

  return 0;
}


//ctor parent ->ctor child -> destr child -> destr  parent      with    virtual destructor
//ctor parent ->ctor child ->             -> destr  parent      without virtual destructor