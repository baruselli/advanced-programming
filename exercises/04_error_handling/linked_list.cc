enum class Insertion_method { push_back, push_front };

template <typename value_type>
class List {
 public:
   // implement suitable constructor(s) for List
  List(){_size=0;}
     
  // insert a new node with the value v according to the method m
  // this method should be used to fill the list
  void insert(const value_type& v, const Insertion_method m);

  // print the values of the nodes
  void print();

  // return the size of the list
  unsigned int size(){return _size;}

  // delete all the nodes of the list
  void reset() {_size=0;}

  // prune node storing the value v
  void prune_node(const value_type; v);



 private:
 
  // private struct node with the proper value_type
  struct node {
    value_type val;
    std::unique_ptr<node> next;

    // implement suitable constructor(s) for node
  };
  
  node(value_type val): val{val} {};

  // append the newly created node at the end of the list
  void push_back(const value_type& v) {next=nullptr;};

  // insert the newly created node in front of the list
  void push_front(const value_type& v);

  std::unique_ptr<node> head;
  unsigned int _size;
};