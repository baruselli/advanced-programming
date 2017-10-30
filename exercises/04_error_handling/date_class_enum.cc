#include <iostream>
#include <string>

enum class month_name_enum {jan=1,feb=2,mar=3,apr=4,may=5,jun=6,jul=7,aug=8,sep=9,oct=10,nov=11,dec=12};
const char* const  list_month_names[12]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};

struct Wrong_date {
  std::string message;
};


class Date{
public:
    
    //Constructor with int for month
    Date(const unsigned int day_in, const unsigned int month_in, const int year_in):
        Date {day_in, get_enum_from_int(month_in), year_in} {}
    //    _day{day_in},_month_enum{get_enum_from_int(month_in)},_year{year_in} {} 
    
    //Constructor with enum for month
    Date(const unsigned int day_in, month_name_enum month_name_in, const int year_in)
        {
        if(day_in>0 && day_in<32) _day=day_in;
        else throw(Wrong_date{"The day must be between 1 and 31. You gave me " + std::to_string(day_in)});
        _month_enum=month_name_in;
        
        if(year_in>0) _year=year_in;
        else throw(Wrong_date{"The year must be between positive. You gave me " + std::to_string(year_in)});
        
        if (!is_date_valid()) {
            print_date();
            throw(Wrong_date{"The given date is invalid (day in month not correct)."});
            }
        }
        
    //Destructor
    ~Date() {}

    //inline
    unsigned int day() const {return _day;} 
    unsigned int month() const{ return (int)_month_enum;} 
    std::string month_name() const { return list_month_names[month()-1];} 
    month_name_enum month_enum() const { return _month_enum;} //this returns the enum
    int year() const{ return _year;}
    //I put is_leap inside the class because I need it for the days_in_month() method
    bool is_leap(const int y){return (((y%4==0) && (y%100!=0)) || ((y%100==0) && (y%400==0))) ; }
    void print_date(){std::cout << day()<< " " << month_name() <<" "<< year() << " ";} 
    bool is_date_valid(){return (day()<=days_in_month(month(), is_leap(year())));}  //all the other checks have been already done 
    
    //implemented outside
    void add_day(const unsigned int n);
    void add_one_day();
    int days_in_month(int m,bool leap);
    month_name_enum get_enum_from_int (int n);

private:
    unsigned int _day;
    int _year;
    month_name_enum _month_enum;
    
}; 



void Date::add_one_day(){
if (days_in_month(month(), is_leap(_year))==_day && month()<12){
    _day=1;
    _month_enum=get_enum_from_int(month()+1);}
else if (days_in_month(month(), is_leap(_year))==_day && month()==12){
    _day=1;
    _month_enum=get_enum_from_int(1);   //=month_name_enum::jan
    _year++;
}
else if (days_in_month(month(), is_leap(_year))!=_day){
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

month_name_enum Date::get_enum_from_int (int n){
    switch(n) {
        case 1 :  return month_name_enum::jan;
        case 2 :  return month_name_enum::feb;
        case 3 :  return month_name_enum::mar;
        case 4 :  return month_name_enum::apr;
        case 5 :  return month_name_enum::may;
        case 6 :  return month_name_enum::jun;
        case 7 :  return month_name_enum::jul;
        case 8 :  return month_name_enum::aug;
        case 9 :  return month_name_enum::sep;
        case 10 :  return month_name_enum::oct;
        case 11 :  return month_name_enum::nov;
        case 12 :  return month_name_enum::dec;
        default: throw(Wrong_date{ "The month must be between 1 and 12. You gave me " + std::to_string(n)});
    }    
}




bool operator==(const Date& lhs, const Date& rhs){
 return ((lhs.day()==rhs.day())&& (lhs.month()==rhs.month())&& (lhs.year()==rhs.year()))  ;  
}

bool operator!=(const Date& lhs, const Date& rhs){ return !(lhs==rhs)  ;}

std::ostream& operator<<(std::ostream& os, const Date& d){ return os << d.day() << "/"<< d.month()<< "/" << d.year() ;}

std::ostream& operator<<(std::ostream& os, const month_name_enum m){return os << list_month_names[int(m)-1];} 

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
std::cout <<d10.month_name() <<std::endl; 
d10.print_date();
//here I print the enum directly
std::cout <<d10.month_enum() <<std::endl; 

/////////////////////
std::cout << "testing exceptions" <<std::endl; 

//I would like smthng like this:
//for tuple in ((1,1,2017),(29,2,2000),(31,12,2017)),
//  try
//      print(date{tuple})
//  catch
//      "error message"


for (unsigned int day=0; day<40; day++){
    try {
        std::cout<< Date{day,2,1984} <<std::endl;
    } catch (const Wrong_date& s) {
        std::cerr << s.message << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception. Aborting.\n";
    }
}

for (unsigned int month=0; month<20; month++){
    try {
        std::cout<< Date{31,month,1984} <<std::endl;
    } catch (const Wrong_date& s) {
        std::cerr << s.message << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception. Aborting.\n";
    }
}


for (int year=1900; year<2017; year++){
    try {
        std::cout<< Date{29,2,year} <<std::endl;
    } catch (const Wrong_date& s) {
        std::cerr << s.message << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception. Aborting.\n";
    }
}


  return 0;
}