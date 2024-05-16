#include<iostream>
#include<initializer_list>
using namespace std;
#ifndef null
#define null nullptr
#endif
/*
circular linked list is an extension of linked list in which the last node points to the beginning of the list, There is no null unlike linked_list.
There will be a lot of modification of the functions of linked list,The functions are listed below:
1).all insert functions.
2).all tranverse functions.
3).all deletion functions..
*/
template<class T>
struct Node{
    T value;
    Node* next;
    Node<T>& operator=(Node<T>* iter){
        *this=*iter;
        return *this;
    }
};
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
void create_node(Node<T>* node,const T& val){
    if(node->next==null){
        node->next=new Node<T>;
        node->next->value=val;
        node->next->next=null;
    }
    else{
        create_node(node->next,val);
    }
}
template<class T>
void init(Node<T>*node,const initializer_list<T>& list){
    Node<T>*iter=node;
    auto key=list.begin();
    iter->value=key[0];
    iter->next=null;
    for(int i=1;i<list.size();i++){
        create_node(iter,key[i]);
    }
    Node<T>*iter1=get_last_iter(node);
    iter1->next=node;
}
template<class T>
void init(Node<T>*node,Node<T>*iter1,Node<T>*iter2){
    Node<T>*iter=node;
    iter=iter1;
    iter2->next=iter1;
}
template<class T>
Node<T>* get_at_pos(Node<T>*node,const size_t&  idx){
    Node<T>* iter=node;
    size_t y=0;
    while(iter!=null){
        if(y==idx){
            return iter;
        }
        ++y;
        iter=iter->next;
    }
    return null;
}
template<class T>
T& change_value(Node<T>*iter){
    return iter->value;
}
template<class T>
Node<T>& change_node(Node<T>* iter){
    return *iter;
}
template<class T>
void print_node(Node<T>*node){
    if(node!=null){
    cout<<node->value<<" ";
    Node<T>*iter=node->next;
    while(iter!=null){
        if(iter==node){ break;}
        cout<<iter->value<<" ";
        iter=iter->next;
    }
    cout<<endl;
    }
}
//to get the length of the node.
template<class T>
size_t get_length(Node<T>*head)  {
       Node<T>*iter=head->next;
       size_t y=1;
       while(iter!=head){
           ++y;
           iter=iter->next;
       }
       return y;
   }
//to get a node at a particular position..
template<class T>
 Node<T>*get_pos_for_clist(Node<T>*head,const int& idx)  {
       if(idx==0){
           return head;
       }
       if(idx>=get_length(head)){
           return null;
       }
       Node<T>*iter=head->next;
       size_t y=1;
       while(iter!=head){
           if(idx==y){
               return iter;
           }
           ++y;
           iter=iter->next;
       }
   }
   /*
     insertion: I will create four insertion, and they are:
     1).insert_at_pos()->iterators,value,initializer_list.
     2).insert_after_pos()->iterators,value,initializer_list.
     3).push_back()->iterators,value,initializer_list.
     4).push_front()->iterators,value,initializer_list;
     5).insert_at_Nth_node().
   */
   /*
    Deletion:i can delete nodes in four ways:
    1).clear(): it points the head to null;
    2).erase(): also does the same as clear()
    3).erase_Nth_node():N must be within get_length();
    4).erase():it accepts iterators as arguments, the iterators must form a range that is a subset of the called object.
    
   */
   //starting with idx...
template<class T>
 Node<T>*insert_at_pos(Node<T>*pos,const T& value) {
      change_value(pos)=value;
  }
template<class T>
Node<T>* get_last_head(Node<T>*head){
       Node<T>*iter=head->next;
       while(iter!=null){
           if(iter==head){
               return iter;
           }
           iter=iter->next;
       }
   }
template<class T>
Node<T>*get_before_last_head(Node<T>*node){
    Node<T>*iter=node->next;
    while(iter!=null){
        if(iter->next==node){
            return iter;
        }
        iter=iter->next;
    }
}
  template<class T>
   Node<T>*insert_at_pos(Node<T>*pos,const initializer_list<T>&list){
      auto key=list.begin();
      Node<T>*iter2=pos;
       Node<T>* nNode=new Node<T>;
        nNode->value=key[0];
        nNode->next=null;
        for(int i=1;i<list.size();i++){
            create_node(nNode,key[i]);
        }
        Node<T>*iter=get_last_iter(nNode);
        iter->next=iter2->next;
        change_node(iter2)=*nNode;
        return nNode;
  }

  //insert_after_pos
  template<class T>
  Node<T>*insert_after_pos(Node<T>*pos,const T& value){
       Node<T>*nNode=new Node<T>;
       nNode->value=value;
       nNode->next=pos->next;
       pos->next=nNode;
       return nNode;
  }
  template<class T>
  Node<T>*insert_after_pos(Node<T>*pos,const initializer_list<T>& list){
      auto key=list.begin();
      Node<T>*iter2=pos;
       Node<T>* nNode=new Node<T>;
        nNode->value=key[0];
        nNode->next=null;
        for(int i=1;i<list.size();i++){
            create_node(nNode,key[i]);
        }
        Node<T>*iter=get_last_iter(nNode);
        iter->next=pos->next;
        pos->next=nNode;
        return nNode;
  }
 template<class T>
void  push_back(Node<T>*node,const T& value){
    Node<T>*iter=get_before_last_head(node);
    Node<T>*nNode=new Node<T>;
    nNode->value=value;
    nNode->next=iter->next;
    iter->next=nNode;
}
template<class T>
void push_back(Node<T>*node,const initializer_list<T>& list){
       auto key=list.begin();
       Node<T>* nNode=new Node<T>;
        nNode->value=key[0];
        nNode->next=null;
        for(int i=1;i<list.size();i++){
            create_node(nNode,key[i]);
        }
        Node<T>*iter=get_last_iter(nNode);
        Node<T>*iter1=get_before_last_head(node);
        iter->next=iter1->next;
        iter1->next=nNode;
}
template<class T>
void push_front(Node<T>*node,const int& val){
     Node<T>*nNode=new Node<T>;
    nNode->value=val;
    nNode->next=node->next;
    node->next=nNode;
  }
 template<class T>
 void push_front(Node<T>*node,const initializer_list<int>& list){
       auto key=list.begin();
       Node<T>* nNode=new Node<T>;
        nNode->value=key[0];
        nNode->next=null;
        for(int i=1;i<list.size();i++){
            create_node(nNode,key[i]);
        }
        Node<T>*iter=get_last_iter(nNode);
        iter->next=node->next;
        node->next=nNode;
 }


/*
For the constructors, it accepts an initializer list,iterators...
*/
template<class T>
class Circular_list{
    private:
    Node<T>*head;
    public:
    Circular_list():head{null}{}
    Circular_list(const initializer_list<int>& list){
        auto key=list.begin();
        head=new Node<T>;
        head->value=key[0];
        head->next=null;
        for(int i=1;i<list.size();i++){
            create_node(head,key[i]);
        }
        Node<T>*iter=get_last_iter(head);
        iter->next=head;
    }
    Node<T>* get_last_node_head_for_clist(){
        Node<T>*iter=head->next;
        while(iter!=null){
            if(iter==head){
                return iter;
                
            }
            iter=iter->next;
        }
    }
    Circular_list(Node<T>*iter1,Node<T>*iter2){
        head=iter1;
        iter2->next=head;
    }
    Circular_list(Node<T>*root){
        head=root;
    }
    Node<T>* begin() const {
       return head;
    }
    Node<T>* end() const{
        return null;
    }
   const Node<T>* cbegin() const {
       return head;
   }
   const Node<T>* cend() const{
       return null;
   }
   /*
   Taking into account, the head, i implemented my get_length() to return the lenght of node.
   */
   
   size_t get_length() const {
       Node<T>*iter=head->next;
       size_t y=1;
       while(iter!=head){
           ++y;
           iter=iter->next;
       }
       return y;
   }
   /*
   i implemented get_pos_for_clist() to return by index the Node.
   
   */

   /*
    To return value at index idx.
   
   
   */
   T& operator[ ](const int&  idx){
       if(idx>=get_length()){
           T value={};
           return value;
       }
       Node<T>*iter=get_pos_for_clist(head,idx);
       return iter->value;
   }
   T operator[ ](const int&  idx) const{
       if(idx>=get_length()){
           T value={};
           return value;
       }
       Node<T>*iter=get_pos_for_clist(head,idx);
       return iter->value;
   }

   void print_clist(){
       print_node(head);
   }
}