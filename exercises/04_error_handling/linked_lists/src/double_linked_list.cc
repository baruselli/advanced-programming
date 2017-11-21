#include <iostream>
#include <memory>
#include "double_linked_list.h"

template <typename value_type>
  D_List<value_type>::D_List() : List<value_type>::List() { std::cout<< "dlist ctor"<<std::endl;}

// print the values of the nodes,in both directions
template <typename value_type>
  void D_List<value_type>::print() {
    List<value_type>::print();
    
    List<value_type>::ptr=List<value_type>::tail.get();
    if(List<value_type>::ptr==nullptr)  std::cout<<"tail is null "<<std::endl;
    int counter=1;
    while(List<value_type>::ptr !=nullptr){
        std::cout<<"node -"<< counter++<< " at "<<List<value_type>::ptr<< " with value "<< 
            List<value_type>::ptr->val<<" and previous at "<< List<value_type>::ptr->previous.get()<< std::endl; 
        List<value_type>::ptr=List<value_type>::ptr->previous.get();
    }
      std::cout << "-----"<<std::endl;
  }



template <typename value_type>
  void D_List<value_type>::reset()  {List<value_type>::reset(); List<value_type>::tail.release();}


  
///////////////////////////////////////////////////////////////////
// append the newly created node at the beginning of the list
template <typename value_type>
  void D_List<value_type>::push_front(const value_type& v)
    {    
        List<value_type>::_size++;
        std::cout<<"Inserting "<< v << " with push_front from d_list"<<std::endl;
 //       std::cout<<"size " <<List<value_type>::_size<<std::endl;
       if (List<value_type>::_size==1) {
//            std::cout<<"head was at " <<head.get()<<std::endl;
            List<value_type>::ptr=new typename List<value_type>::node{v,nullptr,nullptr};
            List<value_type>::head.reset(List<value_type>::ptr);
            List<value_type>::tail.reset(List<value_type>::ptr);
            //tail=head;
        }
        else{
//            std::cout<<"head was at " <<head.get()<<" followed by " << head->next.get() <<std::endl;
            List<value_type>::ptr=new typename List<value_type>::node{v,List<value_type>::head.release(),nullptr};   //the new node has null before, and the former head after
            List<value_type>::head.reset(List<value_type>::ptr);      //the new node is set as the head
//           head->previous=head;  //the former head gets the new node as previous; must use = so shared pointers know they share ptr
           List<value_type>::head->next->previous.reset(List<value_type>::ptr);  //the former head gets the new node as previous
        }
 //    std::cout<<" head is at "<< head.get() << " with value " << head->val <<" and next at " << head->next.get() << std::endl; 
    }

// insert the newly created node at the end of the list
template <typename value_type>
  void D_List<value_type>::push_back(const value_type& v)    {
        std::cout<<"Inserting " <<v<< " with push_back from d_list"<<std::endl;
        List<value_type>::_size++;
        if (List<value_type>::_size==1) {
 //           std::cout<<"tail was at " <<tail.get()<<std::endl;
            List<value_type>::ptr=new typename List<value_type>::node{v,nullptr,nullptr};
            List<value_type>::tail.reset(List<value_type>::ptr);
            List<value_type>::head.reset(List<value_type>::ptr); //=tail;
        }
        else{
//            std::cout<<"tail was at " <<tail.get()<<" preceded by " << tail->previous.get() <<std::endl;
            List<value_type>::ptr=new typename List<value_type>::node{v,nullptr,List<value_type>::tail.release()};   //the new node has null after, and the former tail before
            List<value_type>::tail.reset(List<value_type>::ptr);            //the new node is set as the tail
            List<value_type>::tail->previous->next.reset(List<value_type>::ptr);      //the former tail gets the new node as next
        }
        
 //       std::cout<<" tail is at "<< tail.get() << " with value " << tail->val <<" and previous at " << tail->previous.get() << std::endl; 
  }

/////////////////////////////////////////////////////////
// removes value at the beginning of the list
template <typename value_type>
  const value_type D_List<value_type>::pull_front()
    {
        List<value_type>::_size--;
        std::cout<<"Removing with pull_front... ";
        value_type v = List<value_type>::head->val;
        if(List<value_type>::_size>0)List<value_type>::head.reset(List<value_type>::head->next.release());
        if(List<value_type>::_size>0)List<value_type>::head->previous.release();
    //    head->previous.reset(nullptr);
        if(List<value_type>::_size==0) List<value_type>::head.release();
        if(List<value_type>::_size==0) List<value_type>::tail.release();
        return v;
    }

// removes value at the end of the list
template <typename value_type>
  const value_type D_List<value_type>::pull_back()
    {
        List<value_type>::_size--;
        std::cout<<"Removing with pull_back... ";
//        std::cout<<" tail is at "<< tail.get() << " with value " << tail->val <<" and previous at " << tail->previous.get() << "and next at "<< tail->next.get()<<std::endl;
        value_type v = List<value_type>::tail->val;
        if(List<value_type>::_size==0) List<value_type>::head.release();
        if(List<value_type>::_size==0) List<value_type>::tail.release();
        if(List<value_type>::_size>0)List<value_type>::tail.reset(List<value_type>::tail->previous.release());
        if(List<value_type>::_size>0)List<value_type>::tail->next.release();
//        std::cout<<" tail is at "<< tail.get() << " with value " << tail->val <<" and previous at " << tail->previous.get() << "and next at "<< tail->next.get()<<std::endl;
        return v;
    }
        
    

 




  template class D_List<int>;
  template class D_List<double>;
