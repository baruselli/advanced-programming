#include <iostream>
#include <memory>

struct error {
  std::string message;
};

template <typename num>
class Vector{
  unsigned int _size;
  std::unique_ptr<num[]> elems;
public:
  explicit Vector(const unsigned int s) : elems{new num[s]}, _size{s} {}            //explicit to avoid implicit conversion
                                                                                    //int-->Vector for a fct that takes a Vector and 
                                                                                    //is supplied an int
  // Vector(std::initializer_list<num> lst);
  ~Vector()  {}                                                                     //do I need a destructor? 
                                                                                    //do I need to put anything in it?

  unsigned int size() const noexcept {return _size;}

  num& operator[](const unsigned int i) noexcept    {return elems[i];}
  const num& operator[](const unsigned int i) const noexcept   {return elems[i];}   
  //why this second definition? for const and not const functions, must be both implemented and cannot call each other

  num& at(const unsigned int i);                                                    
  const num& at(const unsigned int i) const;

  num* begin() noexcept {return  &elems[0];}
  const num* begin() const noexcept {return  &elems[0];}
  
  const num* end() const {return &elems[_size];}
  num* end() noexcept {return &elems[_size];}
 // from 05lecture/04
   //const num* begin() const noexcept { return elem.get(); }
 // num* begin() noexcept { return elem.get(); }

  //const num* end() const noexcept { return elem.get() + _size; }
 // num* end() noexcept { return elem.get() + _size; }
 
  //elem.reset(new num[_size]);
 
  void resize(const Vector& v){resize(v._size);}
  void resize(const unsigned int s)
  {
      
      if (s>size()){
          int size_old=size();
          _size=s;
          num* temp=new num[s]; 
          for (int j = 0;j<size_old; j++) temp[j]=elems[j];
          for (int j = size_old;j<s; j++) temp[j]=0;
          elems.reset(temp);
     }
      else{
          _size=s;
      }
      
      

}            
          
      
}; //end of class


template <class num>
std::ostream& operator<<(std::ostream& os, const Vector<num>& v)
{
  for (const auto x : v)                                             //what is this notation? something like "for x in v" in python?
    os << x << " ";
  os << std::endl;
  return os;
}




template <typename num>
num& Vector<num>::at(const unsigned int i){                                                  
  if (i < _size) return elems[i];
  else throw(error{"Error in index. Index must be smaller than " + std::to_string(size())});
 }

template <typename num>
void print_vector(const char* s,const Vector<num>& v)
{
  std::cout <<"-----------------------------------\n"
	    << s << "\n"
	    << " size : "<< v.size() << "\n"
	    << "elems : " << v
	    <<"-----------------------------------\n";
}


int main()
{
    Vector<int> a{10};
    for (int i=0; i <a.size();i++) a[i]=i*i;
    
    print_vector("a",a);
    
    a.resize(5);
    print_vector("a",a);
    
    
    a.resize(15);
    print_vector("a",a);
    
    Vector<int> b{3};
    a.resize(b);
    print_vector("a",a);
    
try{
    std::cout << a.at(4) <<std::endl;
    std::cout << a.at(20) <<std::endl;
}
catch (const error& s) {
        std::cerr << s.message << std::endl;
}

}

