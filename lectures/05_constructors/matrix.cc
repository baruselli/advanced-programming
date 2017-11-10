#include <iostream>
#include <memory>

template <typename num>
class Matrix{
  unsigned int rows=0;
  unsigned int columns=0;
  unsigned int _size=0;
  std::unique_ptr<num[]> elems;
 
  
public:
  explicit Matrix(const unsigned int s1, const unsigned int s2) : _size{s1*s2}, elems{new num[_size]}, rows{s1}, columns{s2} {} 
  
  
  operator[](const std::size_t i) that throws no exceptions
  
  
  
  
}



template <typename num>
num& Matrix<num>::operator[](const std::size_t i){ return elems[i];}
const num& Matrix<num>::operator[](const std::size_t i){ return elems[i];}

  
  
  
  int main()
{
    Matrix<int> a{2,2};
    std::cout<<a[1]<<std::endl;

}

