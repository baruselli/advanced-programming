#include <iostream>			//declarations
#include <string>

int main(){

std::string line_in;
std::string line_old="";

while(std::getline(std::cin,line_in))
{
if (line_in != line_old) 
  std::cout << line_in << std::endl;
line_old=line_in;
}


 return 0;

}
