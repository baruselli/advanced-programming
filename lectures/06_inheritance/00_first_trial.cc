#include <iostream>
#include <ap_error.h>

// each animal should implement
// void info()
// void speak()

struct Animal {
  unsigned int age;
  double weight;
  void info() const {
    std::cout << "age: " << age << std::endl
              << "weight: " << weight << std::endl;
  }
};

struct Dog {
  Animal _animal;
  void speak() const noexcept { std::cout << "Bau\n"; }
  void info() { _animal.info(); }
  Dog() : _animal{} {}
  Dog(const unsigned int a, const double d) : _animal{a, d} {}
};

struct Snake {
  Animal _animal;
  bool dangerous;
  Snake(const unsigned int a, const double w, const bool b)
      : _animal{a, w}, dangerous{b} {}
  Snake(const bool b) : _animal{}, dangerous{b} {}
  void info() const noexcept {
    _animal.info();
    std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
  }
  void speak() const noexcept { std::cout << "ssss\n"; }
};

inline void newline() noexcept {
  std::cout << std::endl;
}

template <typename AT>
void print_animal(const AT& a) noexcept {
  std::cout << "through ref\n";
  a.info();
  a.speak();
}

int main() {
  try {
    Dog d;
    d.info();
    d.speak();

    newline();

    Dog d1{0, 0.6};
    d1.info();
    d1.speak();

    newline();

    Snake s{true};
    s.info();
    s.speak();

    newline();

    Snake* p = new Snake{1, 2.3, false};
    std::cout << "through pointer\n";
    p->info();
    p->speak();

    delete p;

    newline();

    print_animal(s);

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
