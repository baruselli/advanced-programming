#include <iostream>
#include <string>

int main() {
  std::cout << "Insert your name and age:\n";
  //"Insert your name and age:\n" >> std::cout; does not work
  std::string name;
  unsigned int age;
  std::cin >> name >> age;
  std::cout << "Hello, " << name << " [" << age << "]\n";
  return 0;
}
