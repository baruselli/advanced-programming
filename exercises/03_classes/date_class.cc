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


int main() {
 Date d{30,3,1984};
d.add_day(20);
 
 std::cout << d.day()<< std::endl;



  return 0;
}

