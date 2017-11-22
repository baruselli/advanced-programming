#include <iostream>
#include <memory>
#include "double_linked_list.h"

template <typename value_type>
//  D_List<value_type>::D_List() : List<value_type>::List() { std::cout<< "dlist ctor"<<std::endl;}
  D_List<value_type>::D_List() : List<value_type>::List(),tail{nullptr} { std::cout<< "dlist ctor"<<std::endl;}

/** print the values of the nodes,in both directions*/
template <typename value_type>
  void D_List<value_type>::print() {
      
    List<value_type>::print();
    
    List<value_type>::ptr=tail.get();
    if(List<value_type>::ptr==nullptr)  std::cout<<"tail is null "<<std::endl;
    int counter=1;
    while(List<value_type>::ptr !=nullptr){
        std::cout<<"node -"<< counter++<< " at "<<List<value_type>::ptr<< " with value "<< 
            List<value_type>::ptr->val<<" and previous at "<< List<value_type>::ptr->previous.get()<< std::endl; 
        List<value_type>::ptr=List<value_type>::ptr->previous.get();
    }
      std::cout << "-----"<<std::endl;
  }

/** append a new node at the beginning of the d_list: calls the method from list, and correct for previous and tail*/
template <typename value_type>
  void D_List<value_type>::push_front(const value_type& v)
    {    
        std::cout<<"Inserting "<< v << " with push_front from d_list"<<std::endl;
        List<value_type>::push_front(v);
 
        if (List<value_type>::_size==1) tail.reset(List<value_type>::head.get());
        else     List<value_type>::head->next->previous.reset(List<value_type>::head.get());  
       //the former head, now head->next, gets the new node, now head, as previous
    }

/** insert a new node at the end of the d_list: cannot call the method from single list because it is slow*/
template <typename value_type>
  void D_List<value_type>::push_back(const value_type& v)    {
        std::cout<<"Inserting " <<v<< " with push_back from d_list"<<std::endl;
        List<value_type>::_size++;
        tail.reset(new node<value_type>{v,nullptr,tail.release()});
            
        if (List<value_type>::_size==1) List<value_type>::head.reset(tail.get());
        else                            tail->previous->next.reset(tail.get());      
        //the former tail, now tail->previous, gets the new node, now tail, as next

  }

/** removes value at the beginning of the list: calls List::pull_front, then fixes tail/previous*/
template <typename value_type>
  const value_type D_List<value_type>::pull_front()
    {
        std::cout<<"Removing with d_pull_front... ";
        
        value_type v=List<value_type>::pull_front();
        if(List<value_type>::_size>0)  List<value_type>::head->previous.release();
        if(List<value_type>::_size==0) tail.release();
        return v;
    }

/** removes value at the end of the list: cannot call method from single list, which is slow*/
template <typename value_type>
  const value_type D_List<value_type>::pull_back()
    {
        List<value_type>::_size--;
        std::cout<<"Removing with pull_back... ";
        value_type v = tail->val;
        tail.reset(tail->previous.release());
        if(List<value_type>::_size==0) List<value_type>::head.release();
        if(List<value_type>::_size>0)  tail->next.release();
        return v;
    }
        
 
  template class D_List<int>;
  template class D_List<double>;
