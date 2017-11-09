#include <iostream>

template <typename num>
class Vector {
  std::size_t _size;
  num* elem;

 public:
  explicit Vector(const std::size_t length)  //custom ctor--> no default ctor
      : _size{length}, elem{new num[length]{}} {}

  Vector()=default;
  ~Vector() { delete[] elem; }

  const num& operator[](const std::size_t& i) const noexcept { return elem[i]; }
  num& operator[](const std::size_t& i) noexcept { return elem[i]; }

  std::size_t size() const noexcept { return _size; }

  // range-for
  const num* begin() const noexcept { return elem; }
  num* begin() noexcept { return elem; }

  const num* end() const noexcept { return elem + _size; }
  num* end() noexcept { return elem + _size; }
};

int main() {
    Vector<int> v0;
  Vector<double> v1{7};
 // Vector<double> v2{v1};  // default copy constructor: 
                            //it fails because it copies the pointer: the pointers point to the same address
                          // it is shallow copy: a deep copy would copy also the allocated memory
                          // copy on write (cow)
                          //once the objects are destroyed, it tries to deallocate the memory twice
//Vector<double> v2{std::move(v1)};
//Vector<double> v2{std::copy(v1)};  //does not work why?
Vector<double> v2;
v2=std::move(v1);
  return 0;
}
