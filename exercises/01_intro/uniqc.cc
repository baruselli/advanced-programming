#include <iostream>			//declarations
#include <string>

int main(){

std::string line_in;
std::string line_old="";
int n=0;
bool beginning=1;

while(std::getline(std::cin,line_in))
{
if (line_in == line_old)
 {n++;}
else  {
//  if (line_old != "") 
if (not beginning) std::cout << n << " "<< line_old << std::endl;
  line_old=line_in;
  n=1;
}
beginning=0;
}

  std::cout << n << " "<< line_old << std::endl;

 return 0;

}