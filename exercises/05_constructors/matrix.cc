#include <iostream>
#include <memory>
#include "../../lectures/04_error_handling/ap_error.h"

template <typename num>
class Matrix{
public:
//ctors
  
  Matrix() { std::cout << "default ctor"<<std::endl;}

  //custom ctor
  explicit Matrix(const unsigned int s1, const unsigned int s2) : _size{s1*s2}, elems{new num[_size]}, rows{s1}, columns{s2} 
  { std::cout << "custom ctor"<<std::endl;} 

  //copy ctor 
  Matrix(const Matrix& m):rows{m.rows},columns{m.columns},_size{m._size},elems{new num[_size]}
  {std::cout << "copy ctor"<<std::endl;
   for (auto i=0;i<_size;i++)
       elems[i]=m.elems[i];       //use std_uninitialized for non-builtin types (?)
  }

  // move ctor
  Matrix(Matrix&& m) noexcept
      : _size{std::move(m._size)}, elems{std::move(m.elems)},columns{std::move(m.columns)},rows{std::move(m.rows)} {
    std::cout << "move ctor\n";
  }

///////////////
// copy assignment
  Matrix& operator=(const Matrix& m) {
    std::cout << "copy assignment\n";
    _size = m._size;
    columns = m.col();
    rows = m.row();
    elems.reset(new num[_size]);

    for (std::size_t i = 0; i <m.row(); ++i)
    for (std::size_t j = 0; j <m.col(); ++j)
      elems[i*columns+j] = m(i,j);
    return *this;
  }
  
  // move assignment
  Matrix& operator=(Matrix&& m) noexcept {
    std::cout << "move assignment\n";
    _size = std::move(m._size);
    columns = std::move(m.columns);
    rows = std::move(m.rows);
    elems = std::move(m.elems);
    return *this;
  }
  
////////////////////////  
// size row col 
  unsigned int size() const noexcept {return _size;}
  unsigned int row()  const noexcept {return rows;}
  unsigned int col()  const noexcept {return columns;}

//  []
         num* operator[] (const int i)       noexcept {return &elems[i*columns];}
  const  num* operator[] (const int i) const noexcept {return &elems[i*columns];}
 
// at
        num& at (const int i, const int j)      {range_check(i,j);return (*this)[i][j];}
  const num& at (const int i, const int j)const {range_check(i,j);return (*this)[i][j];}

// ()
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
  
//////////

private:
  unsigned int rows=0;
  unsigned int columns=0;
  unsigned int _size=0;
  std::unique_ptr<num[]> elems;
  void range_check(const int i, const int j) const{ if(i>=row() || j>= col()) AP_error("out of bounds",i,j,rows,columns); }
};

//////////////////////////////////////
//// operators
//<<
template <class num>
std::ostream& operator<<(std::ostream& os, const Matrix<num>& m)
{ std::cout<<"(" ;
  for (auto i=0; i<m.row(); i++){
  for (auto j=0; j<m.col(); j++){
//   std::cout<<m[i][j]<< "\t" ;
   std::cout<<m(i,j)<< "\t" ;
  }
  if(i==m.row()-1)  std::cout<<" )" ;
  std::cout<<std::endl; 
  }
  return os;
}

// +
template <class num>
Matrix<num> operator+(const Matrix<num>& m1, const Matrix<num>& m2)
{
//  AP_assert(m1.col()==m2.col() && m1.row()==m2.row(), "Size mismatch in +");
  assert(m1.col()==m2.col() && m1.row()==m2.row());
  Matrix<num> res{m1.row(),m1.col()};
  for (auto i=0; i<res.row(); i++)
    for (auto j=0; j<res.col(); j++)
      res(i,j)=m1(i,j)+m2(i,j);
  
  return res;
}

// *
template <class num>
Matrix<num> operator*(const Matrix<num>& m1, const Matrix<num>& m2)
{
//  AP_assert(m1.col()==m2.row(), "Size mismatch in *");
  assert(m1.col()==m2.row());
  Matrix<num> res{m1.row(),m2.col()};
  
  for (auto i=0; i<res.row(); i++){
    for (auto j=0; j<res.col(); j++){
      res(i,j)=0;
      for (auto k=0; k<m1.col(); k++){
        res(i,j)+=m1(i,k)*m2(k,j);
      }}}
  return res;
}



  
////////////////////////////////////////////////////////
  
  int main()
{
try{
  
  Matrix<int> a0{};
  std::cout<<"a0 " << a0.col()<<" " <<a0.row()<<std::endl;
  //  std::cout<<a0<<std::endl;       //this segfaults because pointer is not initialized
//
  Matrix<int> a{3,4};
  int c=0;
  for (auto i=0; i<a.row(); i++){
  for (auto j=0; j<a.col(); j++){
    a[i][j]=c++;}}
    std::cout<<"a "<<a.row() <<" " <<a.col() <<std::endl;
    std::cout<<a<<std::endl;
    
  Matrix<int> b{3,4};
  for (auto i=0; i<b.row(); i++){
  for (auto j=0; j<b.col(); j++){
    b[i][j]=c++;}}
  std::cout<<"b "<<b.row()<<" "<<b.col()<<std::endl;
  std::cout<<b<<std::endl;

//  
   Matrix<int> a1{a};
  std::cout<<"a1 " << a1.col()<<" " <<a1.row()<<std::endl;
   std::cout<<a1<<std::endl;
   Matrix<int> a2{Matrix<int>{1,2}};
  std::cout<<"a2 " << a2.col()<<" " <<a2.row()<<std::endl;
   std::cout<<a2<<std::endl;
 
//=
  a0=a;
  std::cout<<"a0 " << a0.col()<<" " <<a0.row()<<std::endl;
  std::cout<<a0<<std::endl;

//+    
  std::cout<<"test a+b"<<std::endl;
    
  Matrix<int> res{a+b};
  std::cout<<"res " << res.col()<<" " <<res.row()<<std::endl;
  std::cout<<res<<std::endl;
  std::cout<<a+b<<std::endl;

  a0=res+a;
  std::cout<<"a0 " << a0.col()<<" " <<a0.row()<<std::endl;
  std::cout<<a0<<std::endl;
  

  
// * 
  Matrix<int> m1{2,3};
  m1(0,0)=3;
  m1(0,1)=5;
  m1(1,2)=7;
  std::cout<<"m1 " << m1.col()<<" " <<m1.row()<<std::endl;
  std::cout<<m1<<std::endl;
  Matrix<int> m2{3,2};
  m2(0,0)=3;
  m2(1,0)=5;
  m2(2,1)=7;
  std::cout<<"m2 " << m2.col()<<" " <<m2.row()<<std::endl;
  std::cout<<m2<<std::endl;
  
  std::cout<<"test m1*m2"<<std::endl;
  Matrix<int> res2;
  res2=m1*m2;
  std::cout<<"res2 " << res2.col()<<" " <<res2.row()<<std::endl;
  std::cout<<res2<<std::endl;
  std::cout<<m1*m2<<std::endl;

  Matrix<int> res3{m1*m2};
  std::cout<<"res3 " << res3.col()<<" " <<res3.row()<<std::endl;
  std::cout<<res3<<std::endl;

}

catch(std::runtime_error &e){
std::cout <<std::endl;

}


}

