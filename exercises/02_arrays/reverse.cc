#include <cstring>
#include <iostream>

template <typename num>
num* init_vector(int len) {
    num* v = new num[len];
<<<<<<< 21ca5f883dd0e765155f1b2212c850211494eb7f

    for (int i =len-1; i > -1; --i)
        v[i]=0;
//    return v;
=======
    for (int i =len-1; i > -1; --i)
        v[i]=0;
>>>>>>> ex2b
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

    
    double* v= init_vector<int>(len);
 
    for (int i=0; i < len; ++i)
    std::cin >> v[i];   
 
    print_vector_reverse<int>(v,len);
<<<<<<< 21ca5f883dd0e765155f1b2212c850211494eb7f
        
=======
    
    
>>>>>>> ex2b
    
    
     return 0;
}
