#ifndef _linked_list
#define _linked_list


#include <iostream>
#include <memory>
#include <string>

/** index error*/
struct index_error{ std::string message; };

/** insertion methods*/
enum class Insertion_method { push_back, push_front };

template <typename value_type>
class List {
 public:
  /** std ctor */   
  List();
    
  /**inserts a value*/  
  void insert(const value_type& v, const Insertion_method m);

  /** print the values of the nodes*/
  virtual void print();

  /** return the size of the list*/
  unsigned int size(){return _size;};

  /** delete all the nodes of the list*/
  virtual void reset() {_size=0; head.release();};

  /** prune node storing the value v*/
  virtual void prune_node(value_type v, Insertion_method m);

  /** gets value at index i */
  value_type get_at_index(unsigned int i);
  
  /** finds value v */
  int find_value(value_type v);

  /** maximum*/
  value_type maximum();
  
  /** minimum */
  value_type minimum();
  

  
// private:
 
  struct node {
    value_type val;
    std::unique_ptr<node> next;
    std::unique_ptr<node> previous;

    node(value_type v, node *ptr, node *ptr2): val{v}, next{ptr},previous{ptr2} {};
    node(value_type v, node *ptr): val{v}, next{ptr},previous{nullptr} {};
  };

    unsigned int _size;
  std::unique_ptr<node> head;
  std::unique_ptr<node> tail;
  
/** append a node at the beginning of the list*/
  virtual void push_front(const value_type& v);

/** insert a node at the end of the list*/
  virtual void push_back(const value_type& v) ;

/** removes value at the beginning of the list*/
  virtual const value_type pull_front();

/** removes value at the end of the list*/
  virtual const value_type pull_back() ;
    
};



#endif