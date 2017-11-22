#include "include/linked_list.h"
#include "include/double_linked_list.h"

int main()
{
    
try{
    {List<int> l;          //doubly linked
//List<int> l;          //singly linked
int res=0;
l.print();
l.insert(3,Insertion_method::push_back);
l.print();}

    {D_List<int> m;          //doubly linked
//List<int> l;          //singly linked
int res=0;
m.print();
m.insert(2,Insertion_method::push_back);
m.print();}


/*l.insert(2,Insertion_method::push_back);
l.print();
l.insert(6,Insertion_method::push_back);
l.print();
l.insert(8,Insertion_method::push_back);
l.print();
l.insert(4,Insertion_method::push_back);
l.print();
std::cout << l.get_at_index(0)<<l.get_at_index(1)<<l.get_at_index(2)<<l.get_at_index(3)<<l.get_at_index(4)<<std::endl;
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
l.print();*/




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