#include <iostream>

struct Point_s {
  double x;
  double y;
};

class Point_c {
//public:
  double x;
  double y;
};

int main() {
  Point_s ps;
  ps.x = 9.9;
  ps.y = 3. / 7;

  Point_c pc;
  // pc.x =7.6; // error
  std::cout << pc.x  << std::endl;    //error

  Point_s* p = &ps; //pointer to struct

  p->x = 0.1;

  std::cout << p->x << " "<<    p->y << std::endl;

  return 0;
}
