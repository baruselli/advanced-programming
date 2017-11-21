#include <iostream>
#include <memory>
#include "double_linked_list.h"

template <typename value_type>
  D_List<value_type>::D_List() : List<value_type>::List() {}

// print the values of the nodes,in both directions
template <typename value_type>
  void D_List<value_type>::print() {
    List<value_type>::print();
    
    List<value_type>::node *ptr;
    
    ptr=tail.get();
    if(ptr==nullptr)  std::cout<<"tail is null "<<std::endl;
    int counter=1;
    while(ptr !=nullptr){
        std::cout<<"node -"<< counter++<< " at "<<ptr<< " with value "<< ptr->val<<" and previous at "<< ptr->previous.get()<< std::endl; 
        ptr=ptr->previous.get();
    }
      std::cout << "-----"<<std::endl;
  }



template <typename value_type>
  void D_List<value_type>::reset()  {List<value_type>::reset(); tail.release();}


  
///////////////////////////////////////////////////////////////////
// append the newly created node at the beginning of the list
template <typename value_type>
  void D_List<value_type>::push_front(const value_type& v)
    {    
        _size++;
        std::cout<<"Inserting "<< v << " with push_front from d_list"<<std::endl;
        std::cout<<"size " <<_size<<std::endl;
       if (_size==1) {
//            std::cout<<"head was at " <<head.get()<<std::endl;
//            node *ptr=new node{v,nullptr,nullptr};
//            head.reset(ptr);
//            tail.reset(ptr);
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
template <typename value_type>
  void D_List<value_type>::push_back(const value_type& v)    {
        std::cout<<"Inserting " <<v<< " with push_back from d_list"<<std::endl;
        _size++;
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
template <typename value_type>
  const value_type D_List<value_type>::pull_front()
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
template <typename value_type>
  const value_type D_List<value_type>::pull_back()
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
        
    

 




  template class D_List<int>;
  template class D_List<double>;
