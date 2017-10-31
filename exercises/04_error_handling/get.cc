#include <iostream>			//declarations
#include <string>


int get_int(std::string line_in)
{
int n;

n=atoi(line_in);
//if (stdline_in
//std::cin.clear();
//std::cin.ignore();

return n;
}

}

double get_double()
{
} 

int main(){

std::string line_in;



while(std::getline(std::cin,line_in))
 get_int(line_in);

 return 0;

}
