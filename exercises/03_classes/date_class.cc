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
void add_one_day();
int days_in_month[12]{30,28,31,30,31,30,30,31,30,31,30,31};
=======
>>>>>>> ex03

private:
    unsigned int _day;
    unsigned int _month;
    int _year;
   
    
}; // note the ; at the end of class definition

void Date::add_one_day(){

if (days_in_month[_month-1]==_day && _month<12){
    _day=1;
    _month++;}
else if (days_in_month[_month-1]==_day && _month==12){
    _day=1;
    _month=1;
    _year++;
}
else if (days_in_month[_month-1]!=_day){
    _day++;
}    
else{
 std::cout<<day()<<std::endl;   
    
}
}

void Date::add_day(const unsigned int n){
 
for (int m=0;m<n;m++) add_one_day();
 
     
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

bool is_leap(const int y){
return (((y%4==0) && (y%100!=0)) || ((y%100==0) && (y%400==0))) ;  
=======
    int days_in_month[12]{30,28,31,30,31,30,30,31,30,31,30,31};
    
}; // note the ; at the end of class definition


void Date::add_day(const unsigned int n){
    
 _day=_day+n;       
    
>>>>>>> ex03
}


int main() {
Date d{30,3,1984};
Date d2{30,3,1984};
Date d3{31,3,1984};

d.add_day(10);
std::cout << d<< std::endl;
d.add_day(45);
std::cout << d<< std::endl;

  std::cout << d2<< std::endl;
   std::cout << d3<< std::endl;
 
 std::cout << (d==d2)<< (d!=d2)<< std::endl;
 std::cout << (d==d3)<< (d!=d3)<<std::endl;

 

std::cout << is_leap(1984)<< is_leap(1985)<<is_leap(1900)<<is_leap(2000)<<std::endl;
=======
 Date d{30,3,1984};
d.add_day(20);
 
 std::cout << d.day()<< std::endl;


>>>>>>> ex03

  return 0;
}

