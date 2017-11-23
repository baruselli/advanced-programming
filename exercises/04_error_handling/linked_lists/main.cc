#include "include/linked_list.h"
#include "include/double_linked_list.h"

int main()
{
    
try{

int res=0;

D_List<int>l;
l.insert(2,Insertion_method::push_back);
l.print();
l.insert(6,Insertion_method::push_back);
l.print();
l.insert(8,Insertion_method::push_back);
l.print();
l.insert(4,Insertion_method::push_back);
l.print();
std::cout << l.get_at_index(0)<<l.get_at_index(1)<<l.get_at_index(2)<<l.get_at_index(3)<<l.get_at_index(0)<<std::endl;
std::cout <<l.find_value(8)<<std::endl;
std::cout <<l.find_value(12)<<std::endl;
std::cout <<"maximum is " << l.maximum()<<std::endl;
std::cout <<"minimum is " << l.minimum()<<std::endl;
//std::cout << l.get_at_index(5)<<std::endl;


l.prune_node(res,Insertion_method::push_back);
l.print();
l.prune_node(res,Insertion_method::push_back);
l.print();
l.prune_node(res,Insertion_method::push_back);
l.print();
l.prune_node(res,Insertion_method::push_back);
l.print();
l.prune_node(res,Insertion_method::push_back);
l.print();
l.prune_node(res,Insertion_method::push_back);
l.print();
l.insert(2,Insertion_method::push_back);
l.insert(6,Insertion_method::push_back);
l.insert(3,Insertion_method::push_back);
l.insert(7,Insertion_method::push_back);
l.print();
l.prune_node(res,Insertion_method::push_front);
l.print();
l.prune_node(res,Insertion_method::push_front);
l.print();
l.insert(8,Insertion_method::push_front);
l.insert(9,Insertion_method::push_front);
l.print();
l.prune_node(res,Insertion_method::push_front);
l.print();
l.prune_node(res,Insertion_method::push_front);
l.print();
l.reset();
l.prune_node(res,Insertion_method::push_front);
l.print();
l.prune_node(res,Insertion_method::push_front);
l.print();
l.prune_node(res,Insertion_method::push_front);
l.print();
l.prune_node(res,Insertion_method::push_front);
l.print();
l.insert(11,Insertion_method::push_back);
l.insert(12,Insertion_method::push_back);
l.insert(13,Insertion_method::push_back);
l.insert(14,Insertion_method::push_back);
l.print();
std::cout <<"maximum is " << l.maximum()<<std::endl;
std::cout <<"minimum is " << l.minimum()<<std::endl;
std::cout << l.get_at_index(0)<<l.get_at_index(1)<<l.get_at_index(2)<<l.get_at_index(3)<<std::endl;
std::cout <<l.find_value(8)<<std::endl;
std::cout <<l.find_value(14)<<std::endl;
l.prune_node(res,Insertion_method::push_back);
l.print();
l.prune_node(res,Insertion_method::push_front);
l.print();
//l.reset();
//m.reset();

std::cout<<"test copy"<<std::endl;
List<int> l1;          
l1.insert(3,Insertion_method::push_back);
l1.insert(4,Insertion_method::push_back);
l1.insert(5,Insertion_method::push_back);
l1.print("l1");

List<int> l2{l1,false};
List<int> l3{l1,true};
l2.print("l2 shallow copy of l1");
l3.print("l3 deep copy of l1");
l1.insert(6,Insertion_method::push_back);
l1.insert(7,Insertion_method::push_back);
l2.print("l2 after inserting in l1: is the same as l1 but size is not updated");
l3.print("l3 after inserting in l1");
l1.print("l1 after inserting in l1");

List<int> l4;
l4=std::move(l1);
l1.print("l1 after moving l1 to l4 (undefined behavior)");
l4.print("l4 after moving l1 to l4");
l2.print("l2, shallow copy of l1,  after moving l1 to l4");

List<int> l5;
l5=l4;
l5.print("l5 deep copy of  l4");

List<int> l6;
List<int> l7{l6};
l6.insert(6,Insertion_method::push_back);
l6.insert(7,Insertion_method::push_back);
l6.print("l6");
l7.print("l7 shallow copy of l6 when it was empty (remains null because then I cannot copy the pointer to head)");

D_List<int> d1;          
d1.insert(3,Insertion_method::push_back);
d1.insert(4,Insertion_method::push_back);
d1.insert(5,Insertion_method::push_back);
d1.print("d1");

std::cout<< "building d2"<<std::endl;
//D_List<int> d2{std::move(d1)};
//D_List<int> d2;
//d2=std::move(d1);                      
D_List<int> d2{d1};
d2=d1;
//d2=d1;

d1.print("d1");
d2.print("d2");
D_List<int> d3{d2};
d3.print("d3, deep copy of d2");

/*
std::cout << "------------------------------double linked list----------------------------" <<std::endl;
D_List<int> m;
m.insert(12,Insertion_method::push_back);
m.print();
m.insert(13,Insertion_method::push_front);
m.print();
m.insert(14,Insertion_method::push_back);
m.print();
std::cout <<"maximum is " << m.maximum()<<std::endl;
std::cout <<"minimum is " << m.minimum()<<std::endl;
std::cout <<m.find_value(8)<<std::endl;
std::cout <<m.find_value(12)<<std::endl;

std::cout << m.get_at_index(0)<<m.get_at_index(1)<<m.get_at_index(2)<<m.get_at_index(3)<<m.get_at_index(4)<<std::endl;
*/

//m.prune_node(res,Insertion_method::push_front);
//m.print();
}
//catch(const index_error& s) {std::cerr << s.message << std::endl;}
catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

}