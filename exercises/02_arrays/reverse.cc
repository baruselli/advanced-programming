#include <cstring>
#include <iostream>

template <typename num>
num* init_vector(int len) {
    num* v = new num[len];
    for (int i =len-1; i > -1; --i)
        v[i]=0;
    return v;
}


template <typename num>
void print_vector_reverse(const num* vec, const int n) {
for (int i =n-1; i > -1; --i)
    std::cout << vec[i] << std::endl;
}


int main(int argc, char* argv[]) {
    int len;
    std::cin>>len;

    
    int* v= init_vector<int>(len);
 
    for (int i=0; i < len; ++i)
    std::cin >> v[i];   
 
    print_vector_reverse<int>(v,len);
    
    
    
    
     return 0;
}
