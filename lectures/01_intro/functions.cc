#include <iostream>

void buggy_swap(int a, int b);	//fct. prototype
void swap_c(int *a, int *b);		//with pointers	pointers can have new values, references cannot
void swap_cxx(int &a, int &b); // can we do better?		//with references

int main() {
  int a = 3;
  int b = {7};
  buggy_swap(a, b);			
  std::cout << "expected 7 3 --> " << a << " " << b << "\n";

  a = 3;
  b = 7;
  swap_c(&a, &b);
  std::cout << "expected 7 3 --> " << a << " " << b << "\n";

  a = 3;
  b = 7;
  swap_cxx(a, b);
  std::cout << "expected 7 3 --> " << a << " " << b << "\n";
}

void buggy_swap(int a, int b) {		//arguments are passed by value (a new variable is created)
  int tmp = b;				//here I have 3 new variables
  b = a;
  a = tmp;
}

void swap_c(int *a, int *b) {
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

void swap_cxx(int &a, int &b) {
  int tmp = b;
  b = a;
  a = tmp;
}
