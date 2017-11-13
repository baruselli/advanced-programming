#include <iostream>
#include <memory>

enum class Insertion_method { push_back, push_front };

template <typename value_type>
class List {
 public:
  List(): _size{0}, head{nullptr}, tail{nullptr} {}
     
  void insert(const value_type& v, const Insertion_method m)
  {
    _size++;
    node *ptr;
    if(_size==1 || m==Insertion_method::push_front){
        node a{v,head.get()};      //the new node points to the old head; when _size==0->1  head=nullptr
        ptr=&a;
        head.reset(ptr);               //the new node is now the head
        if(_size==1)   tail.reset(ptr);             //if the list was empty,the new node is also the tail
    }
    else if (m==Insertion_method::push_back)          //at the end of the list
    {
        node a=node{v,nullptr};     //the new node points to null, since it is the tail
        ptr=&a;
        tail->next.reset(ptr);          //the former tail gets a pointer to the new tail
        tail.reset(ptr);                 //and the tail is reset to the new node
    }    
    else{
     std::cout << "smthing wrong in insert"<<std::endl;   
    }
 
    std::cout<<"new node at "<< ptr  << " with value " << ptr->val  <<" and next at " << ptr->next  << std::endl; 
    std::cout<<" head is at "<< head << " with value " << head->val <<" and next at " << head->next << std::endl; 
    std::cout<<" tail is at "<< tail << " with value " << tail->val <<" and next at " << tail->next << std::endl; 
    }

  // print the values of the nodes
  void print(){
    int counter=1;
    if(head.get()!=nullptr)  std::cout<<"head at "<< head.get() << " with value " << head.get()->val  <<" and next at " << head.get()->next  << std::endl;     
    if(tail.get()!=nullptr)  std::cout<<"tail at "<< tail.get() << " with value " << tail.get()->val  <<" and next at " << tail.get()->next  << std::endl; 
    
    node *ptr=head.get();
    while(ptr !=nullptr){
        std::cout<<"node " << counter << " at "<< ptr  << " with value " << ptr->val  <<" and next at " << ptr->next.get()  << std::endl; 
        ptr=ptr->next.get();
    }
      
      
      
  }

  // return the size of the list
  unsigned int size(){return _size;}

  // delete all the nodes of the list
  void reset() {_size=0;}

  // prune node storing the value v
  void prune_node(const value_type v);



 private:
 
  struct node {
    value_type val;
    std::shared_ptr<node> next;

    node(value_type v, node *ptr): val{v}, next{ptr} {};
  };

  
//  std::unique_ptr<node> head;
//  std::unique_ptr<node> tail;
  unsigned int _size;
  std::shared_ptr<node> head;
  std::shared_ptr<node> tail;
 
  // append the newly created node at the end of the list
 // void push_back(const value_type& v) {}

  // insert the newly created node in front of the list
 // void push_front(const value_type& v);

};



int main()
{
    
try{
List<int> l;
std::cout<< "size: "<< l.size()<<std::endl;
l.print();
l.insert(3,Insertion_method::push_front);
//std::cout<< "size: "<< l.size()<<std::endl;
//l.print();
//l.insert(2,Insertion_method::push_front);
//std::cout<< l.size()<<std::endl;    
}

catch(std::runtime_error &e){
std::cout <<std::endl;

}

}