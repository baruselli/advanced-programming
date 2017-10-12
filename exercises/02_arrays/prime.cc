#include <cstring>
#include <iostream>
#include <math.h>


int main(int argc, char* argv[]) {
    int n_primes=0;
    const int dim_array=1000;
    int* primes= new int[dim_array];
    int n_max=atoi(argv[1]);
    bool isprime;
    primes[0]=2;
 
    for (int i=3; i < n_max; ++i){
        isprime=true;
           for (int j=2; j < i/2+1; ++j){
               if(i%j==0){
                   isprime=false;
                   break;
                   
            }}
                if (isprime) n_primes++;
                if (isprime) primes[n_primes]=i;
                if(n_primes>dim_array-2) {
                    std::cout<<"max dim reached, please increase dim_array" <<std::endl;
                    break;}
    }
 
   
    for (int i=0; i < n_primes; ++i)
        std::cout<<primes[i]<<std::endl;;
    
 delete[](primes);  
 primes=nullptr;
    
     return 0;
}
