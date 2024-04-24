#include<iostream>
#include"Vector.h"
using namespace std;
template<class T>
struct Node{
    public:    // it is no t actually necessary,since by default it is public
    T data;
    Node* next;
    Node():data{},next{nullptr}{}
    Node& operator=(const Node<T>& node){
        data=node.data;
        next=node.next;
        return *this;
    }
};
template<class T>
    void print_node(Node<T>* node){
        if(node!=nullptr){
            cout<<node->data<<",";
            print_node(node->next);
        }
     }
template<class T>
void add_value1(Node<T>* node,T val){
    if(node->next==nullptr){
        node->next=new Node<T>;
        node->next->data=val;
        node->next->next=nullptr;
    }
    else{
        add_value1(node->next,val);
    }
}

 template<class T>
 Node<T>* add_new_node(Node<T>* node,T value) {
    Node<T>* nNode=new Node<T>;
    nNode->data=value;
    nNode->next=node->next;
    node->next=nNode;
    return nNode;
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
class My_list{
    private:
    Node<T>* head;
    public:
    class Iterator{
    public:
    Node<T>* iter;
    public:
    Iterator(){
        iter=new Node<T>;
    }
    Iterator(const Iterator& iter1){
        this->iter=new Node<T>;
        this->iter->data=iter1.iter->data;
        this->iter->next=iter1.iter->next;
    }
    Iterator(Node<T>* node){
        this->iter=new Node<T>;
       this->iter->data=node->data;
       this->iter->next=node->next;
     }
    Iterator& operator++(){
        this->iter=iter->next;
        return *this;
 }
 const Iterator operator++(int){
     Node<T>*cpy=this->iter;
     iter=iter->next;
     return cpy;
 }

 T get_value() {
     return iter->data;
 }
 T get_value() const {
     return iter->data;
 }
 
 Iterator& operator=(const Iterator& iter2){
     *this={iter2};
     return *this;
 }
 Iterator& operator=(Node<T>* node){
     *this={node};
     return *this;
 }
};
  My_list(){
        head=new Node<T>;
        head->next=NULL;
       
    }
    void add_value_at_beg(const T val){
         if(head!=NULL){
             head->data=val;
         }
      }
      
      void add_value(const T& val){
         add_value1(head,val);
 }
     void print_value(){
        cout<<head->data<<",";
         print_node<T>(head->next);  
        }
        My_list(initializer_list<T> lst){
              auto key=lst.begin();
            head=new Node<T>;
            head->data=key[0];
             head->next=nullptr;
            int y=lst.size();
            for(int i =1;i<y;i++){
                this->add_value(key[i]);
          }
        }
        My_list(size_t n,T elem){
            head=new Node<T>;
            head->next=nullptr;
            this->add_value_at_begin(elem);
            for(int i=1;i<n;i++ ){
                this->add_value(elem);
            }
        }
      template<class M>
      void add_Vector(M begin,M end){
          int y=Vector<T>::get_length_from_pos(begin,end);
          head=new Node<T>;
          head->data=begin[0];
            head->next=nullptr;
         for(int i=1;i<y;i++){
            this->add_value(begin[i]);
    }
  }
   void assign(const initializer_list<T> lst){
       *this={lst};
  }
  My_list& operator=(const My_list& mylist){
      this->head=mylist.head;
      return *this;
  }
  void swap(const My_list&  list){
      My_list list1;
      list1.head=head;
      head=list.head;
      list.head=list1.head;
  }
  Node<T>*  begin()  {
      Node<T>* iter2;
      iter2=this->head;
      return iter2;
  }
  Node<T>* end() {
      Node<T>*  iter2;
      iter2=nullptr;
      return iter2;
  }
  const Node<T>* cbegin() const{
      Node<T>* iter2;
      iter2=this->head;
      return iter2;
      
  }
 const Node<T>* cend() const {
     Node<T>*  iter2;
     iter2=nullptr;
     return iter2;
 }
 void clear(){
     head=nullptr;
 }
 void push_front(T elem){
  Node<T>* iter=new Node<T>;
  iter->data=elem;
  iter->next=this->head;
  this->head=iter;
 }
 void pop_front(){
     this->head=this->head->next;
 }
 static Node<T>* insert_after_pos(Node<T>* iter1,size_t n,T elem){
     Node<T>* nNode=new Node<T>;
     nNode->data=elem;
     nNode->next=nullptr;
     for(int i=1;i<n;i++){
         add_value1(nNode,elem);
 }
 Node<T>* iter=get_last_iter<int>(nNode);
 iter->next=iter1->next;
 iter1->next=nNode;
 return nNode;
 }
 static Node<T>*insert_after_pos(Node<T>* pos,Node<T>* beg,Node<T>* end){
     if(end==nullptr){
         end=new Node<T>;
     }
     end=pos->next;
     pos->next=beg;
     return beg;
 }
};
