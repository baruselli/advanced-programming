#include <iostream>

enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

using namespace std;

int main() {
  cout << nov << endl;
  cout << month::oct << endl;
  cout << std::oct << endl;
  //cout << oct << endl;
  return 0;
}
