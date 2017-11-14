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
    if(      m==Insertion_method::push_front)       push_front(v);
    else if (m==Insertion_method::push_back)        push_back(v); 
    else std::cout << "smthing wrong in insert"<<std::endl;   
  }

  // print the values of the nodes,in both directions
  void print(){
    std::cout << "-----"<<std::endl;
    std::cout << "size= "<<size()<<std::endl;
    
    node *ptr;
    ptr=head.get();
    if(ptr==nullptr)  std::cout<<"head is null "<<std::endl;
    int counter=1;
    while(ptr !=nullptr){
        std::cout<<"node "<< counter++<< " at "<<ptr<< " with value "<< ptr->val<<" and next at "<< ptr->next.get()<< std::endl; 
        ptr=ptr->next.get();
    }
      
    ptr=tail.get();
    if(ptr==nullptr)  std::cout<<"tail is null "<<std::endl;
    counter=1;
    while(ptr !=nullptr){
        std::cout<<"node -"<< counter++<< " at "<<ptr<< " with value "<< ptr->val<<" and previous at "<< ptr->previous.get()<< std::endl; 
        ptr=ptr->previous.get();
    }

      
      std::cout << "-----"<<std::endl;
  }

  // return the size of the list
  unsigned int size(){return _size;}

  // delete all the nodes of the list
  void reset() {_size=0; head=nullptr; tail=nullptr;}

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
//    std::shared_ptr<node> next;
//    std::shared_ptr<node> previous;
    std::unique_ptr<node> next;
    std::unique_ptr<node> previous;

    node(value_type v, node *ptr,node *ptr2): val{v}, next{ptr}, previous{ptr2} {};
  };

  unsigned int _size;
//  std::shared_ptr<node> head;
//  std::shared_ptr<node> tail;
  std::unique_ptr<node> head;
  std::unique_ptr<node> tail;
  
///////////////////////////////////////////////////////////////////
// append the newly created node at the beginning of the list
  void push_front(const value_type& v)
    {
        std::cout<<"Inserting "<< v << " with push_front "<<std::endl;
       if (_size==1) {
 //           std::cout<<"head was at " <<head.get()<<std::endl;
            node *ptr=new node{v,nullptr,nullptr};
            head.reset(ptr);
            tail.reset(ptr);
            //tail=head;
        }
        else{
//            std::cout<<"head was at " <<head.get()<<" followed by " << head->next.get() <<std::endl;
            node *ptr=new node{v,head.release(),nullptr};   //the new node has null before, and the former head after
            head.reset(ptr);      //the new node is set as the head
//           head->previous=head;  //the former head gets the new node as previous; must use = so shared pointers know they share ptr
           head->next->previous.reset(ptr);  //the former head gets the new node as previous
        }
 //    std::cout<<" head is at "<< head.get() << " with value " << head->val <<" and next at " << head->next.get() << std::endl; 
    }

// insert the newly created node at the end of the list
  void push_back(const value_type& v)    {
        std::cout<<"Inserting " <<v<< " with push_back "<<std::endl;
        if (_size==1) {
 //           std::cout<<"tail was at " <<tail.get()<<std::endl;
            node *ptr=new node{v,nullptr,nullptr};
            tail.reset(ptr);
            head.reset(ptr); //=tail;
        }
        else{
//            std::cout<<"tail was at " <<tail.get()<<" preceded by " << tail->previous.get() <<std::endl;
            node *ptr=new node{v,nullptr,tail.release()};   //the new node has null after, and the former tail before
            tail.reset(ptr);            //the new node is set as the tail
            tail->previous->next.reset(ptr);      //the former tail gets the new node as next
        }
        
 //       std::cout<<" tail is at "<< tail.get() << " with value " << tail->val <<" and previous at " << tail->previous.get() << std::endl; 
  }

/////////////////////////////////////////////////////////
// removes value at the beginning of the list
  const value_type pull_front()
    {
        _size--;
        std::cout<<"Removing with pull_front... ";
        value_type v = head->val;
        if(_size>0)head.reset(head->next.release());
        if(_size>0)head->previous.release();
    //    head->previous.reset(nullptr);
        if(_size==0) head.release();
        if(_size==0) tail.release();
        return v;
    }

// removes value at the end of the list
  const value_type pull_back()
    {
        _size--;
        std::cout<<"Removing with pull_back... ";
//        std::cout<<" tail is at "<< tail.get() << " with value " << tail->val <<" and previous at " << tail->previous.get() << "and next at "<< tail->next.get()<<std::endl;
        value_type v = tail->val;
        if(_size==0) head.release();
        if(_size==0) tail.release();
        if(_size>0)tail.reset(tail->previous.release());
        if(_size>0)tail->next.release();
//        std::cout<<" tail is at "<< tail.get() << " with value " << tail->val <<" and previous at " << tail->previous.get() << "and next at "<< tail->next.get()<<std::endl;
        return v;
    }
        
    

    
};



int main()
{
    
//try{
List<int> l;
int res=0;
l.print();
l.insert(3,Insertion_method::push_front);
l.print();
l.insert(2,Insertion_method::push_front);
l.print();
l.insert(6,Insertion_method::push_front);
l.print();
l.insert(8,Insertion_method::push_back);
l.print();
l.insert(4,Insertion_method::push_back);
l.print();
l.prune_node(res,Insertion_method::push_back);
l.print();
l.prune_node(res,Insertion_method::push_back);
l.print();
l.prune_node(res,Insertion_method::push_front);
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
//}

//catch(std::exception &e){
//std::cout <<std::endl;

//}

}