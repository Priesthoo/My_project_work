#include<iostream>
#include<initializer_list>
/*
    My aim:
    1).Insert_at_pos(),insert_after_pos(),insert_before_pos()
    parameters to be passed:
    1).value.
    2).initializer_list.
    3).iterators.
*/
enum OPERATOR{
    LESS_THAN,// less than(<)...
    GREATER_THAN,  // >
    LESS_THAN_OR_EQUAL_TO,// <=
    GREATER_THAN_OR_EQUAL_TO,//>=
    IS_EQUAL_TO,//==
    IS_NOT_EQUAL_TO//!=
};
enum SORT{
    ASCEND,// <
    DESCEND//>
};
enum PRINT{
    FORWARD,
    REVERSE
};
template<class T, class M>
struct  Pair{
    T first;
    M second;
    Pair()=default;
    Pair(T f, M sec){
        first=f;
        second=sec;
    }
 
M& operator[ ](const T key) const{
    if(key==first){
        return second;
    }
 }
 M& operator[ ](const T key){
     if(key==first){
         return second;
     }
 }
Pair& operator=(const Pair<T,M>& val){
    first=val.first;
    second=val.second;
    return *this;
}
bool operator==(const Pair<T,M>& pair){
    if(this->first ==pair.first and this->second ==pair.second){
        return true;
    }
    return false;
}
bool operator!=(const Pair<T,M>& pair){
    if(this->first!=pair.first and this->second !=pair.second){
        return true;
    }
    return false;
}
bool operator<(const Pair<T,M>& pair){
    if(this->first<pair.first and this->second<pair.second ){
        return true;
    }
    return false;
}
bool operator>(const Pair<T,M>& pair){
    if(this->first>pair.first and this->second >pair.second){
        return true;
    }
    return false;
    }
bool operator>=(const Pair<T,M>& pair){
    if(this->first>=pair.first and this->second>=pair.second){
        return true;
    }
    return false;
    }
bool operator<=(const Pair<T,M>& pair){
    if(this->first<=pair.first and this->first <=pair.second){
        return true;
    }
    return false;
    }   
};
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
bool is_sorted(Node<T>*node,OPERATOR state){
    if(state==LESS_THAN){
        Node<T>* iter=node;
        while(iter!=nullptr){
            if(iter->next!=nullptr){
            if(iter->value>iter->next->value){
                return false;
            }
            }
            iter=iter->next;
        }
        
        return true;
    }
    else if(state==GREATER_THAN){
        Node<T>*iter=node;
        while(iter!=nullptr){
            if(iter->next!=nullptr){
            if(iter->value<=iter->next->value){
                return false;
            }
            }
            iter=iter->next;
        }
        return true;
    }
    else if(state==LESS_THAN_OR_EQUAL_TO){
        Node<T>*iter=node;
        while(iter!=nullptr){
            if(iter->next!=nullptr){
            if(iter->value>iter->next->value){
                return false;
            }
            }
            iter=iter->next;
        }
        return true;
    }
    else if(state==GREATER_THAN_OR_EQUAL_TO){
        Node<T>*iter=node;
        while(iter!=nullptr){
            if(iter->next!=nullptr){
            if(iter->value<iter->next->value){
                return false;
            }
            }
            iter=iter->next;
        }
        return true;
    }
    else if(state==IS_EQUAL_TO){
        Node<T>*iter=node;
        while(iter!=nullptr){
            if(iter->next!=nullptr){
            if(iter->value!=iter->next->value){
                return false;
            }
            }
            iter=iter->next;
        }
        return true;
    }
    else if(state==IS_NOT_EQUAL_TO){
        Node<T>*iter=node;
        while(iter!=nullptr){
            if(iter->next!=nullptr){
            if(iter->value==iter->next->value){
                return false;
            }
            }
            iter=iter->next;
        }
        return true;
    }
}
template<class T>
void sort_nodes(Node<T>* node,SORT sort){
    if(sort==ASCEND){
    Node<T>*iter=node;
    while(iter!=nullptr){
        if(iter->next!=nullptr){
            if(iter->value>iter->next->value){
                T value1=iter->value;
                iter->value=iter->next->value;
                iter->next->value=value1;
            }
        }
        iter=iter->next;
    }
    }
    if(sort==DESCEND){
    Node<T>*iter=node;
    while(iter!=nullptr){
        if(iter->next!=nullptr){
            if(iter->value<iter->next->value){
                T value1=iter->value;
                iter->value=iter->next->value;
                iter->next->value=value1;
            }
        }
        iter=iter->next;
    }
}
}
// NB: sort must be equal to state..
template<class T>
void sort_nodes_until(Node<T>*node,SORT sort,OPERATOR state){
    bool is_sorting=false;
     while(is_sorting!=true){
         sort_nodes(node,sort);
         is_sorting=is_sorted(node,state);
     }
}
template<class T> 
void print_nodes(Node<T>* node,PRINT print){
    Node<T>* iter=nullptr;
    Node<T>*iter1=nullptr;
    iter=node;
    iter1=get_last_iter(node);
    if(print==FORWARD){
        while(iter!=nullptr){
            cout<<iter->value<<endl;
          iter=iter->next;
        }
    }
    else if(print==REVERSE){
        while(iter1!=nullptr){
            cout<<iter1->value<<endl;
             iter1=iter1->prev;
        }
    }
        
}
template<class T,class M=Node<T>*>//returns the first element that has value equal to val...
Node<T>* return_pos_by_val(Node<T>*node,const T& val){
    Pair<T,M>pair;
    Node<T>*iter=node;
    while(iter!=nullptr){
        if(iter->value==val){
            pair.second=iter;
            return pair.second;
        }
        iter=iter->next;
    }
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
   T get_value() const{
       return iter->value;
   }
   T& get_value(){
       return iter->value;
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
    Node<T>* begin(){
        return head;
    }
    Node<T>* end() {
        return nullptr;
    }
    Node<T>* begin() const{
        return head;
    }
    Node<T>* end()const{
        return nullptr;
    }
    
    Node<T>* at_pos(const int& idx){
        Node<T>* iter=this->head;
        size_t y=0;
        while(iter!=nullptr){
            if(y==idx){
                return iter;
            }
            ++y;
            iter=iter->next;
        }
        return nullptr;
    }
    Node<T>* get_head(){
        return head;
    }
    //this is the variants of Insert,for value,initializer_list,iterators......
    Node<T>*insert_after_pos(Node<T>*iter1,const T& value1){
       Node<T>*nNode=new Node<T>;
       nNode->value=value1;
       nNode->next=iter1->next;
       nNode->prev=iter1->next->prev;
       iter1->next->prev=nNode;
       iter1->next=nNode;
       return nNode;
     }
     Node<T>*insert_at_pos(Node<T>*iter,const T& value1){
        Node<T>*nNode=new Node<T>;
        nNode->value=value1;
        nNode->next=iter->next;
        nNode->prev=iter->prev;
        iter->prev->next=nNode;
        return nNode;
     }
     Node<T>*insert_before_pos(Node<T>*iter,const T& value1){
         Node<T>* nNode=new Node<T>;
         nNode->value=value1;
         nNode->next=iter;
         nNode->prev=iter->prev;
         iter->prev->next=nNode;
         return nNode;
      }
  Node<T>* insert_after_pos(Node<T>*iter,const initializer_list<int>& lst){
      auto key=lst.begin();
      Node<T>*nNode=new Node<T>;
      nNode->value=key[0];
      nNode->next=nullptr;
      nNode->prev=nullptr;
      for(int i=1;i<lst.size();i++){
          create_node(nNode,key[i]);
      }
      nNode->prev=iter;
      Node<T>*iter1=get_last_iter(nNode);
      iter1->next=iter->next;
      iter->next=nNode;
      return nNode;
  }
  Node<T>* insert_at_pos(Node<T>*iter,const initializer_list<int>& lst){
      auto key=lst.begin();
      Node<T>*nNode=new Node<T>;
      nNode->value=key[0];
      nNode->next=nullptr;
      nNode->prev=nullptr;
      for(int i=1;i<lst.size();i++){
          create_node(nNode,key[i]);
      }
      nNode->prev=iter->prev;
      Node<T>*iter1=get_last_iter(nNode);
      iter1->next=iter->next;
      iter->prev->next=nNode;
      return nNode;
}
Node<T>*insert_before_pos(Node<T>*iter,const initializer_list<int>& lst){
    auto key=lst.begin();
      Node<T>*nNode=new Node<T>;
      nNode->value=key[0];
      nNode->next=nullptr;
      nNode->prev=nullptr;
      for(int i=1;i<lst.size();i++){
          create_node(nNode,key[i]);
      }
      nNode->prev=iter->prev;
      Node<T>*iter1=get_last_iter(nNode);
      iter1->next=iter;
      iter->prev->next=nNode;
      return nNode;
      }
Node<T>*insert_after_pos(Node<T>*iter,Node<T>*iter1,Node<T>*iter2){
    Node<T>*iter4=new Node<T>;
    iter4->value=iter1->value;
    iter4->next=nullptr;
    iter4->prev=nullptr;
    iter1=iter1->next;
    while(iter1!=iter2){
        create_node(iter4,iter1->value);
        iter1=iter1->next;
    }
    iter4->prev=iter;
    Node<T>*iter5=get_last_iter(iter4);
    iter5->next=iter->next;
    iter->next=iter4;
    return iter4;
}
Node<T>*insert_at_pos(Node<T>*iter,Node<T>*iter1,Node<T>*iter2){
    Node<T>*iter4=new Node<T>;
    iter4->value=iter1->value;
    iter4->next=nullptr;
    iter4->prev=nullptr;
    iter1=iter1->next;
    while(iter1!=iter2){
        create_node(iter4,iter1->value);
        iter1=iter1->next;
    }
    iter4->prev=iter->prev;
    Node<T>*iter5=get_last_iter(iter4);
    iter5->next=iter->next;
    iter=iter4;
    return iter4;
}
Node<T>*insert_before_pos(Node<T>*iter,Node<T>*iter1,Node<T>*iter2){
    Node<T>*iter4=new Node<T>;
    iter4->value=iter1->value;
    iter4->next=nullptr;
    iter4->prev=nullptr;
    iter1=iter1->next;
    while(iter1!=iter2){
        create_node(iter4,iter1->value);
        iter1=iter1->next;
    }
    iter4->prev=iter->prev;
    Node<T>*iter5=get_last_iter(iter4);
    iter5->next=iter;
    iter->prev->next=iter4;
    return iter4;
}
};
