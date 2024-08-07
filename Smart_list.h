#include<memory>
#include<iostream>
using namespace std;
#ifndef INIT_LIST
#define INIT_LIST 10
#include<initializer_list>
#endif

#ifndef SMART_NODE
#define SMART_NODE 12
template<class T>
struct Node{
    T value;
    shared_ptr<Node<T>> next; // each next is a shared pointer...
 };
 template<class T>
void add_element(shared_ptr<Node<T>>&ptr,const T& value1){
    if(ptr.get()==nullptr){
        ptr.reset(new Node<T>);
        ptr.get()->value=value1;
        return;
    }
    add_element(ptr.get()->next,value1);
    }
    
template<class T>
void print_out_node(const shared_ptr<Node<T>>& ptr){
    shared_ptr<Node<T>> ptr1={ptr};
    while(ptr1.get()!=nullptr){
        if(ptr1.get()->next.get()!=nullptr){
                cout<<ptr1.get()->value<<",";
        }
        else{
            cout<<ptr1.get()->value<<endl;
        }
        ptr1=ptr1.get()->next;
    }
}

#endif
#ifndef SMART_LIST
#define SMART_LIST
template<class T>
class Smart_list{//size of smart list is still the same as the size of the shared_ptr type..
    private:
    shared_ptr<Node<T>> ptr;
    public:
    Smart_list():ptr{}{}
    void Insert(const T& value1){
        add_element(ptr,value1);
    }
  Smart_list(const initializer_list<T>& list){
      auto key=list.begin();
      for(int i=0;i<list.size();i++){
          this->Insert(key[i]);
      }
  }
  shared_ptr<Node<T>> get_head() const{
      return this->ptr;
  }
  void clear(){
     ptr.reset();
  }
  const char* check_null(){
      if(ptr.get()==nullptr){
          const char*g={"it is null"};
          return g;
      }
      const char*h={"it is not null"};
      return h;
  }
  shared_ptr<Node<T>> get_begin(){
      return this->ptr;
  }
  shared_ptr<Node<T>> get_end(){
      shared_ptr<Node<T>> ptr1;
      if(ptr1.get()==nullptr){
          return ptr1;
      }
  }
};
#endif
template<class T>
ostream& operator<<(ostream& os,const Smart_list<T>& ptr){
    shared_ptr<Node<T>> ptr1={ptr.get_head()};
    while(ptr1.get()!=nullptr){
        if(ptr1.get()->next.get()!=nullptr){
                os<<ptr1.get()->value<<",";
        }
        else{
            os<<ptr1.get()->value<<endl;
        }
        ptr1=ptr1.get()->next;
    }
    return os;
}
#ifndef SMART_ITERATOR
#define SMART_ITERATOR
template<class T>
class Smart_iterator{
    public:
    shared_ptr<Node<T>>iter;
    public:
    Smart_iterator():iter{}{}
    Smart_iterator(const shared_ptr<Node<T>>& sptr){
        iter=sptr;
    }
    Smart_iterator& operator=(const shared_ptr<Node<T>>& sptr){
        *this={sptr};
        return *this;
    }
 Smart_iterator& operator++(){
     iter=iter.get()->next;
     return *this;
 }
 const Smart_iterator operator++(int){
     shared_ptr<Node<T>> ptr={iter};
     iter=iter.get()->next;
     return ptr;
 }
        
};
#endif
template<class T>
ostream& operator<<(ostream& os,const Smart_iterator<T>& iter1){
    os<<iter1.iter.get()->value<<endl;
    return os;
}
