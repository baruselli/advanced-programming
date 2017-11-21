#include <linked_list.h>

////
  template <typename value_type>
//  List<value_type>::List(): _size{0}, head{nullptr},tail{nullptr} { {std::cout<< "list ctor"<<std::endl;}}
  List<value_type>::List(): _size{0}, head{nullptr} { {std::cout<< "list ctor"<<std::endl;}}
  
////     
  template <typename value_type>
  void List<value_type>::insert(const value_type& v, const Insertion_method m)
  {
    if(_size==0 || m==Insertion_method::push_front) push_front(v);
    else if (m==Insertion_method::push_back)        push_back(v); 
    else std::cout << "smthing wrong in insert"<<std::endl;   
  }

////
  template <typename value_type>
  void List<value_type>::print(){
    std::cout << "-----"<<std::endl;
    std::cout << "size= "<<size()<<std::endl;
    
    ptr=head.get();
    if(ptr==nullptr)  std::cout<<"head is null "<<std::endl;
    int counter=1;
    while(ptr !=nullptr){
        std::cout<<"node "<< counter++<< " at "<<ptr<< " with value "<< ptr->val<<" and next at "<< ptr->next.get()<< std::endl; 
        ptr=ptr->next.get();
    }
      
    std::cout << "-----"<<std::endl;
  }

/////
  template <typename value_type>
  void List<value_type>::prune_node(value_type v, Insertion_method m){
    if(_size<=0) std::cout<< "Cannot prune, list is empty"   << std::endl;
    else if(m==Insertion_method::push_front) {v=pull_front();    std::cout << "I got " << v << std::endl;}
    else if (m==Insertion_method::push_back) {v=pull_back();     std::cout << "I got " << v << std::endl;}
    else std::cout << "smthing wrong in insert"<<std::endl;   
  }

/////
  template <typename value_type>
  value_type List<value_type>::get_at_index(unsigned int i){
  if (i>=_size){
 throw(index_error{"index i out of bound " + std::to_string(i)});
  }
  else{
  ptr=head.get();
  for (unsigned int j=0;j<i;j++)  ptr=ptr->next.get();
  return ptr->val;
  }
  }
  
/////
  template <typename value_type>
  int List<value_type>::find_value(value_type v){
  ptr=head.get();
  unsigned int counter=0;
  while (ptr !=nullptr){
      if (v==ptr->val) return counter; 
      ptr=ptr->next.get();
      counter++;
  }
  return -1;
  }

/////
  template <typename value_type>
  value_type List<value_type>::maximum(){
  if(_size<=0) { throw(index_error{"list is empty, cannot max"});}
  else{
    ptr=head.get();
    value_type maxi=ptr->val;
    while(ptr !=nullptr){
      if (ptr->val>maxi) maxi=ptr->val;
      ptr=ptr->next.get();
  }

      return maxi;
}
  }  
  
/////
  template <typename value_type>
  value_type List<value_type>::minimum(){
  if(_size<=0) { throw(index_error{"list is empty, cannot min"});}
  else{
    ptr=head.get();
    value_type mini=ptr->val;
    while(ptr !=nullptr){
      if (ptr->val<mini) mini=ptr->val;
      ptr=ptr->next.get();
  }

      return mini;
}
  }  

/////
/*  void sort(){
  if(_size<=1) { return;}
  else{
    value_type mini=minimum();
    value_type maxi=maximum();
    node *ptr=head.get();
    while(ptr !=nullptr){
      if (ptr->val<mini) mini=ptr->val;
      ptr=ptr->next.get();
  }

      return mini;
}
  }  
*/  
  
  template <typename value_type>
  void List<value_type>::push_front(const value_type& v)
    {
        _size++;
        std::cout<<"Inserting "<< v << " with push_front "<<std::endl;
 //       std::cout<<"head was at " <<head.get()<<std::endl;
        head.reset(new node<value_type>{v,head.release()});
//        std::cout<<" head is at "<< head.get() << " with value " << head->val <<" and next at " << head->next.get() << std::endl; 
    }

    //
  template <typename value_type>
  void List<value_type>::push_back(const value_type& v)    {
        std::cout<<"Inserting " <<v<< " with push_back "<<std::endl;
        _size++;
        ptr=head.get();
        while(ptr !=nullptr){                   //I traverse the list with ptr
            if( ptr->next.get()==nullptr) {
                ptr->next.reset(new node<value_type>{v,nullptr});
                break;}
            ptr=ptr->next.get();}
    }    

////
 template <typename value_type>
 const value_type List<value_type>::pull_front()
    {
        _size--;
        std::cout<<"Removing with pull_front... ";
 //       std::cout<<"head was at " <<head.get()<<std::endl;
        value_type v = head->val;
        head.reset(head->next.release());
//     std::cout<<" head is at "<<head.get()<<" with value "<<head->val<<" and next at "<<head->next.get()<< std::endl; 
        return v;
    }

////
  template <typename value_type>
  const value_type List<value_type>::pull_back()
    {
        _size--;
        value_type v;
        std::cout<<"Removing with pull_back... ";
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
        
    

 

  template class List<int>;
  template class List<double>;