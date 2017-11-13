#include <iostream>
#include <memory>

enum class Insertion_method { push_back, push_front };

template <typename value_type>
class List {
 public:
  List(): _size{0}, head{nullptr} {}
     
  void insert(const value_type& v, const Insertion_method m)
  {
    _size++;
    if(_size==1 || m==Insertion_method::push_front){
        std::cout<<"Inserting "<< v << " with push_front "<<std::endl;
        node *old_head=head.get();
        std::cout<<"head was at " <<old_head<<std::endl;
 //       ptr=      //the new node points to the old head; when _size==0->1  head=nullptr
 //       std::cout<<"new node at "<< ptr  << " with value " << ptr->val  <<" and next at " << ptr->next.get()  << std::endl; 
        head.reset(new node{v,old_head});               //the new node is now the head
        std::cout<<" head is at "<< head.get() << " with value " << head->val <<" and next at " << head->next.get() << std::endl; 
    }
    else if (m==Insertion_method::push_back)          //at the end of the list
    {
        std::cout<<"Inserting " <<v<< " with push_back "<<std::endl;
//        std::cout<<"head was at " <<head.get()<<std::endl;
        node *ptr;
        ptr=head.get();
        while(ptr !=nullptr){                   //I traverse the list with ptr
            if( ptr->next.get()==nullptr) {
                ptr->next.reset(new node{v,nullptr});
                break;}
            ptr=ptr->next.get();}
        //std::cout<<" head is at "<< head.get()<< " with value "<< head->val<<" and next at "<< head->next.get()<< std::endl;
    }    
    else{
     std::cout << "smthing wrong in insert"<<std::endl;   
    }
 
    }

  // print the values of the nodes
  void print(){
    std::cout << "-----"<<std::endl;
    std::cout << "size= "<<size()<<std::endl;
    
    node *ptr=head.get();
    if(ptr==nullptr)  std::cout<<"head is null "<<std::endl;
    int counter=1;
    while(ptr !=nullptr){
        std::cout<<"node "<< counter++<< " at "<<ptr<< " with value "<< ptr->val<<" and next at "<< ptr->next.get()<< std::endl; 
        ptr=ptr->next.get();
    }
      
    std::cout << "-----"<<std::endl;
      
      
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
    std::unique_ptr<node> next;

    node(value_type v, node *ptr): val{v}, next{ptr} {};
  };

  
//  std::unique_ptr<node> head;
  unsigned int _size;
  std::unique_ptr<node> head;
 
  // append the newly created node at the end of the list
 // void push_back(const value_type& v) {}

  // insert the newly created node in front of the list
 // void push_front(const value_type& v);

};



int main()
{
    
try{
List<int> l;
l.print();
l.insert(3,Insertion_method::push_front);
l.print();
l.insert(2,Insertion_method::push_back);
l.print();
l.insert(6,Insertion_method::push_back);
l.print();
l.insert(8,Insertion_method::push_back);
l.print();
l.insert(4,Insertion_method::push_front);
l.print();
}

catch(std::runtime_error &e){
std::cout <<std::endl;

}

}