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
    if(_size==1 || m==Insertion_method::push_front) push_front(v);
    else if (m==Insertion_method::push_back)        push_back(v); 
    else std::cout << "smthing wrong in insert"<<std::endl;   
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
  void reset() {_size=0; head=nullptr;}

  // prune node storing the value v
  void prune_node(value_type v, Insertion_method m){
    if(_size<=0) std::cout<< "Cannot prune, list is empty"   << std::endl;
    else if(m==Insertion_method::push_front) {v=pull_front();    std::cout << "I got " << v << std::endl;}
    else if (m==Insertion_method::push_back) {v=pull_back();     std::cout << "I got " << v << std::endl;}
    else std::cout << "smthing wrong in insert"<<std::endl;   
  }



 private:
 
  struct node {
    value_type val;
    std::unique_ptr<node> next;

    node(value_type v, node *ptr): val{v}, next{ptr} {};
  };

  unsigned int _size;
  std::unique_ptr<node> head;
  
///////////////////////////////////////////////////////////////////
// append the newly created node at the beginning of the list
  void push_front(const value_type& v)
    {
        std::cout<<"Inserting "<< v << " with push_front "<<std::endl;
 //       std::cout<<"head was at " <<head.get()<<std::endl;
        head.reset(new node{v,head.release()});
//        std::cout<<" head is at "<< head.get() << " with value " << head->val <<" and next at " << head->next.get() << std::endl; 
    }

// insert the newly created node at the end of the list
  void push_back(const value_type& v)    {
        std::cout<<"Inserting " <<v<< " with push_back "<<std::endl;
        node *ptr;
        ptr=head.get();
        while(ptr !=nullptr){                   //I traverse the list with ptr
            if( ptr->next.get()==nullptr) {
                ptr->next.reset(new node{v,nullptr});
                break;}
            ptr=ptr->next.get();}
    }    

/////////////////////////////////////////////////////////
// removes value at the beginning of the list
  const value_type pull_front()
    {
        _size--;
        std::cout<<"Removing with pull_front... ";
 //       std::cout<<"head was at " <<head.get()<<std::endl;
        value_type v = head->val;
        head.reset(head->next.release());
//     std::cout<<" head is at "<<head.get()<<" with value "<<head->val<<" and next at "<<head->next.get()<< std::endl; 
        return v;
    }

// removes value at the end of the list
  const value_type pull_back()
    {
        _size--;
        value_type v;
        std::cout<<"Removing with pull_back... ";
        node *ptr;
        ptr=head.get();
        while(ptr !=nullptr){                   //I traverse the list with ptr
            if( ptr->next.get()==nullptr) {
                v = ptr->val;
                break;}
            ptr=ptr->next.get();}
 
 //here I reset the pointer of the new tail
        if (_size==0) head.reset(nullptr);
        else{
          ptr=head.get();
          for (unsigned int i=0; i<_size-1; i++){
              ptr=ptr->next.get();}
          ptr->next.reset(nullptr);
        }
        
        return v;
    }
        
    

    
};



int main()
{
    
try{
List<int> l;
int res=0;
l.print();
l.insert(3,Insertion_method::push_back);
l.print();
l.insert(2,Insertion_method::push_back);
l.print();
l.insert(6,Insertion_method::push_back);
l.print();
l.insert(8,Insertion_method::push_back);
l.print();
l.insert(4,Insertion_method::push_back);
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
l.prune_node(res,Insertion_method::push_front);
l.print();
l.prune_node(res,Insertion_method::push_front);
l.print();
l.prune_node(res,Insertion_method::push_front);
l.print();
l.prune_node(res,Insertion_method::push_front);
l.print();

//l.insert(12,Insertion_method::push_back);
//l.print();
//l.prune_node(res,Insertion_method::push_front);
//l.print();
}

catch(std::runtime_error &e){
std::cout <<std::endl;

}

}