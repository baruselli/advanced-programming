//private: only memeber & friends
//protected: also children can see data
#include <iostream>
#include <ap_error.h>

class Animal {
  unsigned int age;
  double weight;

 public:
  Animal(const unsigned int a, const double w) : age{a}, weight{w} {
    if (weight < 0)
      AP_error("invalid weight:", w);
  }
 // Animal() : default {std::cout << "default constructor animal"<<std::endl;}  // delegating constructor
  
  Animal() : Animal{0, 0} {std::cout << "delegating constructor animal"<<std::endl;}  // delegating constructor

  Animal(const Animal& a): age{a.age},weight{a.weight}{std::cout << "copy constructor animal a"<<std::endl;}
  //Animal() = default; //{std::cout<<"default constructor Animal"<<std::endl;};
  
  virtual void speak() const = 0;
  virtual void info() const noexcept {
    std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
  }

  virtual ~Animal() {}
};

class Dog : public Animal {
 public:
  void speak() const noexcept override { std::cout << "Bau\n"; }
  Dog() = default;
  Dog(const unsigned int a, const double d) : Animal{a, d} {}
};

class Snake : public Animal {
  bool dangerous;

 public:
  Snake(const unsigned int a, const double w, const bool b)
      : Animal{a, w}, dangerous{b} {{std::cout << "custom constructor snake awb"<<std::endl;}}
  Snake(const bool b) : Animal{}, dangerous{b} {{std::cout << "custom constructor snake b"<<std::endl;}}
  void info() const noexcept override {
    Animal::info();
    std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
  }
  Snake(const Snake& s): Animal{s}, dangerous{s.dangerous}{std::cout << "copy constructor snake"<<std::endl;}           
  //runtime polimorfism for Animal, because s is an animal
  //implement the move ctor, which is similar to copy
  
  Snake& operator=(const Snake& s){
      {std::cout << "copy assignment snake"<<std::endl;}
      
    Animal::operator= (s);              //s1=s2 <-> s1.operator=(s2)        this->age to enforce polimorphism <-> Animal::age
   // this->Animal::operator= (s);      
    
    dangerous=s.dangerous;
    return *this;                       //only needed for chained assignments s1=s2=s3; I could return void and s1=s2 still works
  }
  
  void speak() const noexcept override { std::cout << "ssss\n"; }
};

inline void newline() noexcept {
  std::cout << std::endl;
}

void print_animal(const Animal& a) noexcept {
  a.info();
  a.speak();
  std::cout << "\n\n";
}

int main() {
  try {
    Snake s{1, 2.3, true};
    Snake s1{9,9,false};
    Snake s3{2,5,false};

    s1=s=s3;
//    Snake s1{s};
    print_animal(s);
    print_animal(s1);
    print_animal(s3);

    
   Snake s2{std::move(s)};

  //  print_animal(s2);

    s = s1;

  //  print_animal(s);

    s2 = std::move(s1);

  //  print_animal(s2);

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
