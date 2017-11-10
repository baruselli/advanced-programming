#include <iostream>
#include <memory>
#include "../../lectures/04_error_handling/ap_error.h"

template <typename num>
class Matrix{

  
public:
  explicit Matrix(const unsigned int s1, const unsigned int s2) : _size{s1*s2}, elems{new num[_size]}, rows{s1}, columns{s2} {}; 
//copy ctor 
  Matrix(const Matrix& m):rows{m.rows},columns{m.columns},_size{m._size},elems{new num[_size]}
  {
   for (auto i=0,i<_size;i++)
       elems[i]=new(&elem[i]) num{m.elems[i]};       //??? use std_uninitialized
  }
  
  
  unsigned int size() const noexcept {return _size;}
  unsigned int row() const noexcept {return rows;}
  unsigned int col() const noexcept {return columns;}
 
 //num& operator[](const unsigned int i) noexcept    {return elems[i];}
 // const num& operator[](const unsigned int i) const noexcept   {return elems[i];}   
  
  num* operator[] (const int i) noexcept {return &elems[i*columns];}
  const  num* operator[] (const int i) const noexcept {return &elems[i*columns];}
  
 num& at(const int i, const int j){range_check(i,j);return (*this)[i][j];return elems[i*cols+j];}
  const num& at const (const int i, const int j){range_check(i,j);return (*this)[i][j];}
 
  num& operator ()(const int i, const int j){
#ifndef NDEBUG
    return at(i,j);
#else
    return (*this)[i][j];
#endif
  }
 

  
const num& operator ()(const int i, const int j) const {
#ifndef NDEBUG
    return at(i,j);
#else
    return (*this)[i][j];
#endif
  }
 
private:
  unsigned int rows=0;
  unsigned int columns=0;
  unsigned int _size=0;
  std::unique_ptr<num[]> elems;
  void range_check(const int i, const int j) const;
};


template <class num>
void Matrix<num>::range_check(const int i, const int j) const{
  
  if(i>=rows() || j>= columns())
    AP_error("out of bounds",i,j,rows,columns)
  
  
}


template <class num>
std::ostream& operator<<(std::ostream& os, const Matrix<num>& m)
{
  for (auto i=0; i<m.row(); i++){
  for (auto j=0; j<m.col(); j++){
   std::cout<<m[i][j]<< "\t" ;
   std::cout<<m(i,j)<< "\t" ;
  }
    std::cout<<std::endl; 
  }
    
  return os;
}

  
  
  
  int main()
{
try{
  
  Matrix<int> a{3,4};
    
    int c=0;
  for (auto i=0; i<a.row(); i++){
  for (auto j=0; j<a.col(); j++){
    a[i][j]=c++;}}
    
    std::cout<<a.size()<<std::endl;
    std::cout<<a<<std::endl;
}

catch(std::runtime_error &e){
std::cout <<std::endl;

}


}

