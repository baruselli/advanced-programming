#include <iostream>

int main() {
  double d = 9.9;
  double &ref = d;			//reference (alias) different name for the same object
  double *ptr = &d;			//pointer (it is an object by itself)
  int i=2;
  int *ptri = &i;
  std::cout << "content of   d: " << d << std::endl;
  std::cout << "content of ref: " << ref << std::endl;
  std::cout << "content of ptr: " << ptr << std::endl << std::endl;
  std::cout << "address of   d: " << &d << std::endl;
  std::cout << "address of ref: " << &ref << std::endl;
  std::cout << "address of ptr: " << &ptr << std::endl;
  std::cout << "size of d: " << sizeof(d) << std::endl;
  std::cout << "size of ref: " << sizeof(ref) << std::endl;
  std::cout << "size of ptr: " << sizeof(ptr) << std::endl;
std::cout << "size of i: " << sizeof(i) << std::endl;
  std::cout << "size of ptri: " << sizeof(ptri) << " (always 8 for 64 bit)"<< std::endl;
}
