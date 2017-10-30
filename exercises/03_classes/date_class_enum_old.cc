//HOW DO I PRINT month_name from enum?
//how do I print the object inside a method definition using the new defined << Date << ? I do not have the object's name there!

#include <iostream>
#include <string>

enum class month_name_enum {jan=1,feb=2,mar=3,apr=4,may=5,jun=6,jul=7,aug=8,sep=9,oct=10,nov=11,dec=12};



class Date{
public:

    Date(const unsigned int day_in, const unsigned int month_in, const int year_in):
        _day{day_in},_month{month_in},_year{year_in} {} 
    Date(const unsigned int day_in, month_name_enum month_name_in, const int year_in):
        _day{day_in},_month_name{month_name_in},_year{year_in},_month{(unsigned int) month_name_in} {} 
    ~Date() {}

    //inline
    unsigned int day() const {return _day;} 
    unsigned int month() const{ return _month;} 
    month_name_enum month_name() const { return _month_name;} 
    int year() const{ return _year;}
    //I put is_leap inside the class because I need it for the days_in_month() method
    bool is_leap(const int y){return (((y%4==0) && (y%100!=0)) || ((y%100==0) && (y%400==0))) ; }
    
    //void print_date(Date d){std::cout << d << std::endl;} //??????????????????
    void print_date(){std::cout << this << std::endl;} //??????????????????  
    //void print_date(){std::cout << (*this) << std::endl;} //??????????????????  
    
    //implemented outside
    void add_day(const unsigned int n);
    void add_one_day();
    int days_in_month(int m,bool leap);

 

private:
    unsigned int _day;
    unsigned int _month;
    int _year;
    month_name_enum _month_name;


    
}; // note the ; at the end of class definition

void Date::add_one_day(){
if (days_in_month(_month, is_leap(_year))==_day && _month<12){
    _day=1;
    _month++;}
else if (days_in_month(_month, is_leap(_year))==_day && _month==12){
    _day=1;
    _month=1;
    _year++;
}
else if (days_in_month(_month, is_leap(_year))!=_day){
    _day++;
}    
else{
 std::cout<<"error in add_one_day" <<day()<<month()<<year()<<std::endl;   
}
}

void Date::add_day(const unsigned int n){
for (int m=0;m<n;m++) add_one_day();
}

int Date::days_in_month(int m,bool leap){
    
    int list_days_in_month[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (m!=2) return list_days_in_month[m-1];
    if (m==2){
     if(leap) return 29;
     if(!leap) return 28;
    }
}

bool operator==(const Date& lhs, const Date& rhs){
 return ((lhs.day()==rhs.day())&& (lhs.month()==rhs.month())&& (lhs.year()==rhs.year()))  ;  
}

bool operator!=(const Date& lhs, const Date& rhs){ return !(lhs==rhs)  ;}

std::ostream& operator<<(std::ostream& os, const Date& d){ return os << d.day() << "/"<< d.month()<< "/" << d.year() ;}



int main() {
    
    
Date d{30,3,1984};
Date d2{30,3,1984};
Date d3{31,3,1984};

 std::cout << d<< std::endl;
 std::cout << d2<< std::endl;
 std::cout << d3<< std::endl;
 std::cout << (d==d2)<< (d!=d2)<< std::endl;
 std::cout << (d==d3)<< (d!=d3)<<std::endl;


std::cout << d<< std::endl;
for (int i =1; i<400; i++){
d.add_day(1);
std::cout <<i<<" "<< d<< std::endl;
}


//leap
Date d4{25,2,1984};
for (int i =1; i<10; i++){
d4.add_day(1);
std::cout <<i<<" "<< d4<< std::endl;
}
 
//not leap
Date d5{25,2,1900};
for (int i =1; i<10; i++){
d5.add_day(1);
std::cout <<i<<" "<< d5<< std::endl;
}
//leap
Date d6{25,2,2000};
for (int i =1; i<10; i++){
d6.add_day(1);
std::cout <<i<<" "<< d6<< std::endl;
}
 
Date d7{25,2,2000};
std::cout << d7<< std::endl;
d7.add_day(365);
std::cout << d7<< std::endl;
Date d8{25,2,2001};
std::cout << d8<< std::endl; 
d8.add_day(365);
std::cout << d8<< std::endl; 


std::cout << d.is_leap(1984)<< d.is_leap(1985)<<d.is_leap(1900)<<d.is_leap(2000)<<std::endl;


/////////////////////
std::cout << "testing enum" <<std::endl;    
    
Date d10{30,month_name_enum::mar,1984};
std::cout << d10 <<std::endl;
d10.add_day(365);
std::cout << d10 <<std::endl;
std::cout <<(int) d10.month_name() <<std::endl; 
//std::cout <<d10.month_name() <<std::endl; 
//HOW DO I PRINT "mar"?
d10.print_date();

  return 0;
}