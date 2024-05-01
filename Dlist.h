#include<iostream>
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

