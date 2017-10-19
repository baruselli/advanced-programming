#include <iostream>
#include <string>

class Date{
public:

  Date(const unsigned int day_in, const unsigned int month_in, const int year_in): _day{day_in}, _month{month_in}, _year{year_in} {} 

   ~Date() {}
    
unsigned int day() const {return _day;} 
unsigned int month() const{ return _month;} 
int year() const{ return _year;}
void add_day(const unsigned int n);

private:
    unsigned int _day;
    unsigned int _month;
    int _year;
    int days_in_month[12]{30,28,31,30,31,30,30,31,30,31,30,31};
    
}; // note the ; at the end of class definition


void Date::add_day(const unsigned int n){
 
  
    
 _day=_day+n;
 
     
}


bool operator==(const Date& lhs, const Date& rhs){
 return ((lhs.day()==rhs.day())&& (lhs.month()==rhs.month())&& (lhs.year()==rhs.year()))  ;  
}

bool operator!=(const Date& lhs, const Date& rhs){
 return !(lhs==rhs)  ;  
}


std::ostream& operator<<(std::ostream& os, const Date& d){
 return os << d.day() << "/"<< d.month()<< "/" << d.year() ;    
}

int main() {
 Date d{30,3,1984};
 Date d2{30,3,1984};
Date d3{31,3,1984};
d.add_day(0);
 
 std::cout << d<< std::endl;
 
 std::cout << (d==d2)<< (d!=d2)<< std::endl;
 std::cout << (d==d3)<< (d!=d3)<<std::endl;



  return 0;
}





