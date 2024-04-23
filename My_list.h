#include<iostream>
#include"Vector.h"
using namespace std;
template<class T>
struct Node{
    public:    // it is no t actually necessary,since by default it is public
    T data;
    Node* next;
    Node():data{},next{nullptr}{}
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
class My_list{
    private:
    Node<T>* head;
    public:
    class Iterator{
    public:
    Node<T>* iter;
    public:
    Iterator():iter{nullptr}{}
    Iterator(const Iterator& iter1){
        this->iter=iter1.iter;
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
  Iterator begin()  {
      Iterator iter2;
      iter2.iter=this->head;
      return iter2;
  }
  Iterator end() {
      Iterator iter2;
      iter2.iter=nullptr;
      return iter2;
  }
  const Iterator  cbegin() const{
      Iterator iter2;
      iter2.iter=this->head;
      return iter2;
      
  }
 const Iterator cend() const {
     Iterator  iter2;
     iter2.iter=nullptr;
     return iter2;
 }
  
};
