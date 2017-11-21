#ifndef _d_list
#define _d_list

#include <iostream>
#include <memory>
#include "linked_list.h"


template <typename value_type>
  class d_node : public node<value_type> {
  public:
    std::unique_ptr<d_node> previous;

    d_node(value_type v, d_node *ptr, d_node *ptr2): node<value_type>{v,ptr},previous{ptr2} {};
    d_node(value_type v, d_node *ptr):               node<value_type>{v,ptr},previous{nullptr} {};
    d_node(value_type v):                            node<value_type>{v,nullptr},previous{nullptr} {};
  };


template <typename value_type>
class D_List : public List<value_type> {
//class D_List {
 public:
  D_List();
  ~D_List() { std::cout<< "dlist dtor"<<std::endl;};

// print the values of the nodes,in both directions
  void print() override;  //override;

  void reset() override; // override {List::reset(); tail.release();}

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