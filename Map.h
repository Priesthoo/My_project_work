#include<iostream>
#include<string>
#include<initializer_list>


using namespace std;
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
    
};
template<class T,class M>
struct Node{
    Pair<T,M> value;
    Node<T,M> *next;
    Node():value{},next{nullptr}{}
    Node(Pair<T,M>value1){
          value1=value;
          next=nullptr;
          }
};
template<class T,class M>
Node<T,M>* get_last_pos(Node<T,M>*node){
       Node<T,M>*iter=nullptr;
       if(node->next==nullptr){
          iter=node;
       }
   return iter;
}
template<class T,class M>
Node<T,M>* get_last_iter(Node<T,M>* node){
    Node<T,M>* iter,*iter1;
    iter=node;
    while(iter!=nullptr){
        iter1=get_last_pos<T>(iter);
        iter=iter->next;
    }
    return iter1;
}
template<class T,class M>
void create_node(Node<T,M>* node,Pair<T,M>myvalue){
      if(node->next==nullptr){
        node->next=new Node<T,M>;
        node->next->value=myvalue;
        node->next->next=nullptr;
    }
    
    else{
        create_node(node->next,myvalue);
    }
}
template<class T,class M>
Node<T,M>* find_key(Node<T,M>* node,const T& key){
    Node<T,M>*iter=node;
    Node<T,M>*iter2=nullptr;
    while(iter!=nullptr){
        if(iter->value.first==key){
            iter2=iter;
        }
        iter=iter->next;
    }
    return iter2;
}
template<class T,class M>
void print_node(Node<T,M>* node){
    if(node!=nullptr){
        cout<<node->value.first<<":"<<node->value.second<<endl;
        print_node(node->next);
    }
}
template<class T,class M>
 size_t get_length(Node<T,M>* node) {
     Node<T,M>* iter=node;
     size_t y=0;
     while(iter!=nullptr){
         ++y;
         iter=iter->next;
     }
     return y;
 }

template<class T,class M>
class Iterator{
    public:
    Node<T,M>* iter;
    public:
    Iterator():iter{}{}
    Iterator(const Iterator& node){
        iter=new Node<T,M>;
        iter->value=node.iter->value;
        iter->next=node.iter->next;
    }
    Iterator(Node<T,M>* node){
        this->iter=new Node<T,M>;
       this->iter->value=node->value;
       this->iter->next=node->next;
     }
    Iterator& operator++(){
        this->iter=iter->next;
        return *this;
 }
 const Iterator operator++(int){
     Node<T,M>*cpy=this->iter;
     iter=iter->next;
     return cpy;
 }
 T get_key() const {
     return iter->value.first;
 }
  ~Iterator(){
     iter=nullptr;
 }
 M get_value() const {
     return iter->value[this->get_key()];
 }
 M& change_value(){
     return iter->value[this->get_key()];
 }
Iterator& operator=(const Iterator& iter){
    *this={iter};
    return *this;
}
Pair<T,M> get_pair() const {
    return iter->value;
}
Node<T,M> *get_iter() const{
    return iter;
}
void assign_iter(Node<T,M>* node){
    this->iter=node;
}
};
template<class T,class M>
void sort_key(Node<T,M>* node){
    Node<T,M>* iter=node;
    while(iter!=nullptr){
        if(iter->next!=nullptr){
            if(iter->value.first>iter->next->value.first){
                T obj={iter->value.first};
                M obj1={iter->value.second};
                iter->value.first=iter->next->value.first;
                iter->value.second=iter->next->value.second;
                iter->next->value.first=obj;
                iter->next->value.second=obj1;
            }
        }
        iter=iter->next;
    }
}
template<class T,class M>
bool node_is_sorted(Node<T,M>* node){
    Node<T,M>* iter=node;
    while(iter!=nullptr){
        if(iter->next!=nullptr){
                if(iter->value.first>iter->next->value.first){
            return false;
        }
        }
        iter=iter->next;
    }
    return true;
}
template<class T,class M>
void sort_node_until(Node<T,M>* node){
    Node<T,M>*iter=node;
    bool is_sorted=false;
      while(is_sorted!=true){
          sort_key(iter);
          is_sorted=node_is_sorted(node);
          iter=node;
      }
}
template<class T,class M> //remove 
bool is_equal(Node<T,M>* node){
    Node<T,M>*iter=node;
    while(iter!=nullptr){
        if(iter->next!=nullptr){
        if(iter->value.first==iter->next->value.first){
            return false;
        }
        }
       iter=iter->next; 
    }
    return true;
}
template<class T,class M>
void rem_duplicate(Node<T,M>*node){
    Node<T,M>* iter=node;
    while(iter!=nullptr){
        if(iter->next!=nullptr){
        if(iter->value.first==iter->next->value.first){
            iter->next=iter->next->next;
        }
        }
        iter=iter->next;
    }
}
template<class T,class M>
void rem_all(Node<T,M>*node){
    Node<T,M>* iter=node;
    bool is_all=false;
    while(is_all!=true){
        rem_duplicate(node);
        is_all=is_equal(node);
    }
}
template<class T,class M>
Node<T,M>* search_key(Node<T,M>* node,const T& key){
    Node<T,M>* iter=node;
    while(iter!=nullptr){
        if(iter->value.first==key){
            return iter;
        }
        iter=iter->next;
    }
    return nullptr;
}

template<class T,class M>
using Cmpfunc=void(*)(Node<T,M>*);

template<class T,class M,Cmpfunc<T,M> cmp=sort_node_until>
class Map{
    Node<T,M>* root;
    public:
     void add_at_begin(const Pair<T,M>& myvalue){
         root->value=myvalue;
         root->next=nullptr;
     }
      void add_pair(const Pair<T,M>& myvalue){
            create_node(this->root,myvalue);
            cmp(this->get_root());
            rem_all(this->get_root());
       }
     Map(){
         root=new Node<T,M>;
      }
      Map(const Map& map){
          this->root=map.root;
      }
   Map( initializer_list<Pair<T,M>> lst){
          root=new Node<T,M>;
          auto key=lst.begin();
          root->value=key[0];
          root->next=nullptr;
          for(int i=1;i<lst.size();i++){
              this->add_pair(key[i]);
          }
              cmp(this->get_root());
              rem_all(this->get_root());
         }
    Map(Iterator<T,M> iter1,Iterator<T,M> iter2){
        root=new Node<T,M>;
        this->add_at_begin(iter1.get_pair());
        ++ iter1;
        while(iter1.get_iter()!=iter2.get_iter()){
            this->add_pair(iter1.get_pair());
            ++iter1;
            }
            cmp(this->get_root());
            rem_all(this->get_root());
        }
 Iterator<T,M> begin_iter() {
     Iterator<T,M> iter;
     iter.assign_iter(this->get_root());
     return iter;
     }                                                   //each next refers to a new node.
 Iterator<T,M> end_iter()  {
         Iterator<T,M> iter1;
         iter1.iter=nullptr;
         return iter1;
     }       
 M& operator[ ](const T idx) const{
     Iterator<T,M> iter=this->begin_iter();
     Iterator<T,M> iter2;
     M obj;
     while(iter.iter!=nullptr)
     {
         if(iter.get_key()==idx){
             obj=iter.get_value();
             return obj;
         }
         ++iter;
     }
  }
  void assign_elem(Iterator<T,M> iter,Iterator<T,M> iter1){
      *this={iter,iter1};
  }
  void assign_elem(const initializer_list<Pair<T,M>>& lst){
      *this={lst};
  }
   Node<T,M>* get_root() const {
       return root;
       }
   Cmpfunc<T,M> get_cmp_func(){
       return cmp;
   }
   void print_map(){
       print_node(this->get_root());
   }
   //Insertion....
 Iterator<T,M> insert_after_pos(const Iterator<T,M>& pos,const Pair<T,M>& val)  {
     Node<T,M>*iter=pos.get_iter();
     Node<T,M>* nNode=new Node<T,M>;
     nNode->value=val;
     nNode->next=iter->next;
     iter->next=nNode;
     Iterator<T,M> iter1;
     iter1.assign_iter(nNode);
     cmp(this->get_root());
     rem_all(this->get_root());
     return iter1;
 }
 Iterator<T,M> insert_after_pos(const Iterator<T,M>& pos,const initializer_list<Pair<T,M>>& lst){
       Node<T,M>* nNode=new Node<T,M>;
       auto key=lst.begin();
       nNode->value=key[0];
       for(int i=1;i<lst.size();i++){
                create_node(nNode,key[i]);
           } 
      Node<T,M>* iter=get_last_iter(nNode);
      iter->next=pos.get_iter()->next;
      pos.get_iter()->next=nNode;
      Iterator<T,M> iter1;
      iter1.assign_iter(nNode);
      cmp(this->get_root());
      rem_all(this->get_root());
      return iter1;
}
Iterator<T,M> insert_after_pos(const Iterator<T,M>& pos,const Iterator<T,M>& iter1,const Iterator<T,M>& iter2){
    Node<T,M>* iter=pos.get_iter();
    Node<T,M>* iter0=iter1.get_iter();
    Node<T,M>* iter3=iter2.get_iter();
    if(iter3==nullptr){
        iter3=iter->next;
    }
    else{
        iter3->next=iter->next;
    }
   iter->next=iter0;
   cmp(this->get_root());
   rem_all(this->get_root());
   Iterator<T,M> iter4;
   iter4.assign_iter(iter0);
   return iter4;
}

Iterator<T,M> insert_after_head(const Pair<T,M>& pair){
    Node<T,M>*nNode=new Node<T,M>;
    nNode->value=pair;
    nNode->next=root;
    root=nNode;
    Iterator<T,M> iter2;
    cmp(root);
    rem_all(root);
    iter2.assign_iter(root);
    return iter2;
}
void push_back_elem(const Pair<T,M>& pair){
    Node<T,M>* nNode=new Node<T,M>;
    nNode->value=pair;
    Node<T,M>* iter=get_last_iter(this->root);
    iter->next=nNode;
    cmp(root);
    rem_all(root);
}
static size_t get_map_length(Map map){
    size_t sz=get_length(map.get_root());
    return sz;
}
void pop_front(){
    root=root->next;
}
void push_front(const Pair<T,M>& pair){
    Node<T,M>* nNode=new Node<T,M>;
    nNode->value=pair;
    nNode->next=nullptr;
    nNode->next=root;
    root=nNode;
    cmp(root);
    rem_all(root);
}

void clear(){
    root=nullptr;
}
void remove(const Pair<T,M>& pair){
    Node<T,M>* iter=this->get_root();
    Node<T,M>* node=new Node<T,M>;
    while(root!=nullptr){
        if(root->value.first!=pair.first and root->value.second!=pair.second){
            create_node(node,root->value);
            }
        root=root->next;
    }
    root=node->next;
}
void remove(const Iterator<T,M>& iter){
    Node<T,M>*node=iter.get_iter();
    node=node->next;
}
   
};
typedef Pair<int,int> Psi;


