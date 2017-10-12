#include <iostream>

int main() {
  std::cout << "Please insert array length: ";
  int n;
  std::cin >> n;
  int* da = new int[n];  // allocated on the HEAP, or free-store

  for (int i = 0; i < n; ++i)
    da[i] = i * 10;

  for (int i = 0; i < n; ++i)
    std::cout << "da[" << i << "] = " << da[i] << std::endl;

  delete[] da;      //deletes the whole arry, not just the first member
  da=nullptr;
  return 0;
}
