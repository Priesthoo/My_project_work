#include<iostream>
#include<initializer_list>
using namespace std;
template<class T>
struct Node{
  T value;
  Node<T>* next;
  Node<T>* prev;
  Node():value{},next{nullptr},prev{nullptr}{}
  };
  template<class T>
  void add_at_begin(Node<T>*node,const T& val){
           node=new Node<T>;
           node->value=val;
           node->next=nullptr;
          node->prev=nullptr;
     
  }
  template<class T>
  void create_node(Node<T>* node,const T& val){
      if(node->next==nullptr){
          node->next=new Node<T>;
          node->next->value=val;
          node->next->next=nullptr;
          node->next->prev=node;
      }
      else{
          create_node(node->next,val);
      }
  }
// Tranversal..
template<class T>
size_t get_node_length(Node<T>* node){
    Node<T>*iter=node;
    size_t y=0;
    while(iter!=nullptr){
        ++y;
        iter=iter->next;
    }
    return y;
}
template<class T>
Node<T>* get_last_pos(Node<T>*node){
       Node<T>*iter=nullptr;
       if(node->next==nullptr){
          iter=node;
       }
   return iter;
}
template<class T>
Node<T>* get_last_iter(Node<T>* node){
    Node<T>* iter,*iter1;
    iter=node;
    while(iter!=nullptr){
        iter1=get_last_pos<T>(iter);
        iter=iter->next;
    }
    return iter1;
}
template<class T>
class Iterator{
    private:
    Node<T>* iter;
    public:
    Iterator():iter{}{}
    Iterator(const Iterator& iter1 ){
        iter=iter1.iter;
    }
    Iterator(Node<T>* node){
        iter=node;
    }
    Iterator& operator++(){
        iter=iter->next;
        return *this;
    }
    const Iterator operator++(int){
        Iterator cpy=*this;
        ++cpy;
        return *this;
    }
    Iterator& operator=(const Iterator& iter1){
        *this={iter1};
        return *this;
    }
    Iterator& operator=(Node<T>*iter){
        *this={iter};
        return *this;
    }
    Iterator& operator--(){
        iter=iter->prev;
        return *this;
    }
    Iterator& operator--(int){
        Iterator cpy=*this;
         --cpy;
         return *this;
    }
    Node<T>* get_head(){
        return iter;
    }
    Node<T>& get(){
        return *iter;
    }
};
//a pointer can either  store address or a pointer to an allocated memory 
template<class T>
class Dlist{
    private:
    Node<T>* head;
    public:
    Dlist(){
        head=new Node<T>;
        head->value=0;
        head->next=nullptr;
        head->prev=nullptr;
    }
    Dlist(const initializer_list<T>& list){
        auto key=list.begin();
        head=new Node<T>;
        head->value=key[0];
        head->next=nullptr;
        head->prev=nullptr;
        for(int i=1;i<list.size();i++){
            create_node(head,key[i]);
        }
    }
    Dlist(Iterator<T> iter1,Iterator<T> iter2){
        head=iter1.get_head();
        iter2.get()->next=nullptr;
    }
    T& operator[ ](const int& idx){
        Node<T>* iter=this->head;
        size_t y=0;
        while(iter!=nullptr){
            if(y==idx){
                return iter->value;
            }
            ++y;
            iter=iter->next;
        }
        T value1={};
        return value1;
    }
 }