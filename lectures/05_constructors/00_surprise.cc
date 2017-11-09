#include <iostream>

struct X {
  char member;          //builtin types are not initialized by default (it keeps what is in the RAM)
};

int main() {
  X x1{'r'};                 // default ctor
  std::cout << x1.member << std::endl;
  std::cout << "---------" << std::endl;
  X x2{x1};             // copy ctor
  std::cout << x1.member << std::endl;
  std::cout << x2.member << std::endl;
  std::cout << "---------" << std::endl;
  X x3{std::move(x2)};  // move ctor
  std::cout << x1.member << std::endl;
  std::cout << x2.member << std::endl;
  std::cout << x3.member << std::endl;
  std::cout << "---------" << std::endl;
  X x4{};               // default ctor calling {} to each member
  x4 = x3;              // copy assignment
  std::cout << x1.member << std::endl;
  std::cout << x2.member << std::endl;
  std::cout << x3.member << std::endl;
  std::cout << x4.member << std::endl;
  std::cout << "---------" << std::endl;
  X x5;                 // default ctor
  x5 = std::move(x4);   // move assignment
  std::cout << x1.member << std::endl;
  std::cout << x2.member << std::endl;
  std::cout << x3.member << std::endl;
  std::cout << x4.member << std::endl;
  std::cout << x5.member << std::endl;  // what do you expect?? unpredictable
  std::cout << "---------" << std::endl;
  return 0;
}
