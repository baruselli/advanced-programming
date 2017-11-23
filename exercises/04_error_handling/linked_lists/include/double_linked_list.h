#ifndef _d_list
#define _d_list

#include <iostream>
#include <memory>
#include "linked_list.h"

/*
template <typename value_type>
  class d_node : public node<value_type> {
  public:
    std::unique_ptr<d_node> previous;

    d_node(value_type v, d_node *ptr, d_node *ptr2): node<value_type>{v,ptr},previous{ptr2} {};
    d_node(value_type v, d_node *ptr):               node<value_type>{v,ptr},previous{nullptr} {};
    d_node(value_type v):                            node<value_type>{v,nullptr},previous{nullptr} {};
  };
*/

template <typename value_type>
class D_List : public List<value_type> {
//class D_List {
 public:
  D_List(): List<value_type>::List(),tail{nullptr} { std::cout<< "dlist ctor"<<std::endl;};
  ~D_List() { std::cout<< "dlist dtor"<<std::endl;this->reset();};
  
  /**copy ctor: I use the single list ctor, which uses push_back from list-->does not work*/
  D_List(const D_List& m, bool deep) : List<value_type>{m,deep} {if (not deep) tail.reset(m.tail.get());};
  /**by default, I use the deep copy*/
  D_List(const D_List& m): D_List(m,true) {};
  /** move ctor works*/   
  D_List(D_List&& m) noexcept : List<value_type>{std::move(m)}, tail{std::move(m.tail)} {std::cout << "move ctor d_list\n"; };

  /** deep copy assignment: only copies the values; this works out of the box, using push_back from d_list*/
  D_List& operator=(const D_List& m){List<value_type>::operator=(m);return *this;};
  /** move assignment*/
 //this works:
 //D_List& operator=(D_List&& m) noexcept
    {List<value_type>::_size = std::move(m._size);List<value_type>::head=std::move(m.head);tail=std::move(m.tail);return *this;};
//this not:
//(does a deep copy???)
// D_List& operator=(D_List&& m) noexcept {List<value_type>::operator=(m);return *this;};
//where
// List& operator=(List&& m) noexcept {std::cout<<"move ass.\n";_size = std::move(m._size);head=std::move(m.head);return *this;};


  void print(std::string s) override ;
  void print() override {print(std::string(""));};

  void reset() override  {List<value_type>::reset(); tail.release();} 

 private:
 
    std::unique_ptr<node<value_type>> tail;

 /* struct node {
    value_type val;
    std::unique_ptr<node> next;
    std::unique_ptr<node> previous;

    node(value_type v, node *ptr, node *ptr2): val{v}, next{ptr},previous{ptr2} {};
  };

    unsigned int _size;
  std::unique_ptr<node> head;
  std::unique_ptr<node> tail;*/
 //std::unique_ptr<node> tail;
///////////////////////////////////////////////////////////////////
/** append the newly created node at the beginning of the list*/
  void push_front(const value_type& v) override;

/** insert the newly created node at the end of the list*/
  void push_back(const value_type& v) override;
        
/** removes value at the beginning of the list*/
  const value_type pull_front() override;
  
/** removes value at the end of the list*/
  const value_type pull_back() override;
};


#endif