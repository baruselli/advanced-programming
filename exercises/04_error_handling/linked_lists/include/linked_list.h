#ifndef _linked_list
#define _linked_list


#include <iostream>
#include <memory>
#include <string>

/** index error*/
struct index_error{ std::string message; };

/**node structure*/
template <typename value_type>
  class node {
  public:
    value_type val;
    std::unique_ptr<node> next;
    std::unique_ptr<node> previous;

    node(value_type v, node *ptr, node *ptr2): val{v}, next{ptr},previous{ptr2} {};
    node(value_type v, node *ptr):             val{v}, next{ptr},previous{nullptr} {};
    node(value_type v):                        val{v}, next{nullptr},previous{nullptr} {};
  };

/** insertion methods*/
enum class Insertion_method { push_back, push_front };

template <typename value_type>
class List {
 public:
  /** std ctor */   
  List();
  virtual ~List() {std::cout<< "list dtor"<<std::endl;};
 
  /**copy ctor: false:this is just an alias, but with problems, hence to avoid; true: deep copy*/
  List(const List& m, bool deep);
  /**by default, I use the deep copy*/
  List(const List& m): List(m,true) {};
  /** move ctor*/
  List(List&& m) noexcept : _size{std::move(m._size)}, head{std::move(m.head)} {std::cout << "move ctor\n"; };

  /** deep copy assignment*/
  List& operator=(const List& m);
  /** move assignment*/
  List& operator=(List&& m) noexcept {std::cout<<"move ass.\n";_size = std::move(m._size);head=std::move(m.head);return *this;};
  
  /**inserts a value*/  
  void insert(const value_type& v, const Insertion_method m);

  /** print the values of the nodes*/
  virtual void print(std::string s);
  virtual void print() {print(std::string(""));};

  /** return the size of the list*/
  unsigned int size(){return _size;};

  /** delete all the nodes of the list*/
  virtual void reset() {std::cout<< "resetting list...";_size=0; head.release();std::cout<< "ok"<<std::endl;};

  /** prune node storing the value v*/
  void prune_node(value_type v, Insertion_method m);

  /** gets value at index i */
  value_type get_at_index(unsigned int i);
  
  /** finds value v */
  int find_value(value_type v);

  /** maximum*/
  value_type maximum();
  
  /** minimum */
  value_type minimum();
  

  
 protected: //must be used by child
 
  unsigned int _size;
  std::unique_ptr<node<value_type>> head;
  node<value_type>* ptr;                        //used everywhere to traverse the list
  
  
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