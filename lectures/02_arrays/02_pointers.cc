#include <iostream>

int main() {
  int a{5};
  int* pi{&a};
  *pi = 9;
  std::cout << "a is now " << a << std::endl;

    int aa[3]{5};
  int* paa=aa;
  *(++paa)=7;
  std::cout <<  aa[0]<<aa[1]<<aa[2] << std::endl;
  std::cout <<  paa[0]<<paa[1]<<paa[2] << std::endl;
  //std::cout << aa <<" " << paa << std::endl;
  
  
  char** ppc;

  int* ap[7];       //array of pointers

  int (*fp)(char*); //pointer to an integer function that accepts a char*

  int* f(char*);       // function that returns a pointer to an int

  void* pv{pi};         //function that can point to everything, and does not know the size to what it is pointing to
  // *pv; // we cannot dereference void*
  // ++pv; // we cannot increment. Why? (should go to the next location, but i do not know how much to jump (4B, 8B...)
  int* pi2 = static_cast<int*>(pv);

  pi = nullptr;
  ppc = nullptr;
  // ap = nullptr;			// error, why?
  fp = nullptr;
  pv = nullptr;
  pi2 = 0;  // older codes. gets the nullptr

  const int* pc = &a;
  // *pc = 7; 			// error: cannot change a via pointer because it is const
  a = 15;  // I can obviously change a

  int* const cp = &a;
  int b = 8;
  a = b;
  // cp = &b			// error

  const int* const cpc = &a;  // points to a fixed memory location
  // and cannot change it
  a = 99;

  return 0;
}
