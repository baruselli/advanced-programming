#include <cstring>
#include <iostream>

template <typename num>
num* init_vector(int len) {
    num* v = new num[len];
    //for (int i =len-1; i > -1; --i)
    //    v[i]=0;
    return v;
}


template <typename num>
void print_vector_reverse(const num* vec, const int n) {
for (int i =n-1; i > -1; --i)
    std::cout << vec[i] <<  " ";
std::cout << std::endl;
}


int main(int argc, char* argv[]) {
    int len;

    std::cin>>len;

    double* v_a= init_vector<double>(len);
    for (int i=0; i < len; ++i)
        std::cin >> v_a[i];   
    
  //  int* v= init_vector<int>(len);
 
  //  for (int i=0; i < len; ++i)
  //      v[i]=atoi(v_a[i]);   
 
    print_vector_reverse(v_a,len);
    
  delete[](v_a); 

    
    
     return 0;
}