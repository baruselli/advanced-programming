//private: only member & friends
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
  Animal() : Animal{0, 0} {std::cout << "delegating constructor animal"<<std::endl;}  // delegating constructor
  Animal(const Animal& a): age{a.age},weight{a.weight}{std::cout << "copy constructor animal a"<<std::endl;}
  Animal(Animal&& a) noexcept  : age{std::move(a.age)}, weight{std::move(a.weight)} { std::cout << "move ctor animal a\n";  }

  virtual void speak() const = 0;
  virtual void info() const noexcept {
    std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
  }

  virtual ~Animal() {}

//copy assignment
   Animal& operator=(const Animal& a) {
    std::cout << "copy assignment animal\n";
    age = a.age;
    weight = a.age;
    return *this;
  }
  
  // move assignment
  Animal& operator=(Animal&& a) noexcept {
    std::cout << "move assignment animal \n";
    age = std::move(a.age);
    weight = std::move(a.weight);
    return *this;
  }
};

 
////////////////////////////////////////////////////////////////////////////////
class Dog : public Animal {
 public:
  void speak() const noexcept override { std::cout << "Bau\n"; }
  Dog() = default;
  Dog(const unsigned int a, const double d) : Animal{a, d} {std::cout <<"custom ctor dog a d"<<std::endl;}
  Dog(const Dog& d): Animal{d} {std::cout << "copy constructor dog"<<std::endl;}
  Dog(Dog && d) noexcept  : Animal{std::move(d)} { std::cout << "move ctor dog\n";  }
//copy assignment
  Dog& operator=(const Dog& d){
      {std::cout << "copy assignment dog"<<std::endl;}
    Animal::operator= (d);              //s1=s2 <-> s1.operator=(s2)        this->age to enforce polimorphism <-> Animal::age
    return *this;                       //only needed for chained assignments s1=s2=s3; I could return void and s1=s2 still works
  }

   // move assignment
  Dog& operator=(Dog&& d) noexcept {
    std::cout << "move assignment dog\n";
    Animal::operator= (d);   
    return *this;
  }

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
  Snake(Snake && s) noexcept  : Animal{std::move(s)}, dangerous{std::move(s.dangerous)} { std::cout << "move ctor snake a\n";  }

//copy assignment
  Snake& operator=(const Snake& s){
      {std::cout << "copy assignment snake"<<std::endl;}

    Animal::operator= (s);              //s1=s2 <-> s1.operator=(s2)        this->age to enforce polimorphism <-> Animal::age
   // this->Animal::operator= (s);

    dangerous=s.dangerous;
    return *this;                       //only needed for chained assignments s1=s2=s3; I could return void and s1=s2 still works
  }

   // move assignment
  Snake& operator=(Snake&& s) noexcept {
    std::cout << "move assignment snake\n";
    Animal::operator= (s);   
    dangerous=std::move(s.dangerous);

    return *this;
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
    Snake s1{1, 2.3, true};
    Snake s2{9,9,false};
    Snake s3{s2};

    s1=s2=s3;
//    Snake s1{s};
    print_animal(s1);
    print_animal(s2);
    print_animal(s3);

std::cout<<"Snake s4{std::move(s1)}; "<<std::endl;
   Snake s4{std::move(s1)};

  //  print_animal(s2);

    s2 = s3;

  //  print_animal(s);

    s2 = std::move(s1);

  //  print_animal(s2);
std::cout<<"Dogs "<<std::endl;

    Dog d1;
    Dog d2{d1};
    print_animal(d2);

    Dog d3;
    d3.Animal::operator=(s1);  //here I assign the common animal features of snake to dog (?)
    print_animal(d3);
    print_animal(s1);
    
    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
