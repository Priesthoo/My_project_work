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
Node<T,M> *get_iter(){
    return iter;
}
};
template<class T,class M>
class Map{
    Node<T,M>* root;
    public:
     void add_at_begin(const Pair<T,M>& myvalue){
         root->value=myvalue;
         root->next=nullptr;
     }
      void add_pair(const Pair<T,M>& myvalue){
            create_node(this->root,myvalue);
      }
     
     Map(){
         root=new Node<T,M>;
      }
      Map(const Pair<T,M>& pair){
          root=new Node<T,M>;
          root->value=pair.value;
          root->next=nullptr;
      }
      Map(const initializer_list<Pair<T,M>>& lst){
          root=new Node<T,M>;
          auto key=lst.begin();
          this->add_at_begin(key[0]);
          for(int i=1;i<lst.size();i++){
              this->add_pair(key[i]);
          }
         }
    Map(Iterator<T,M> iter1,Iterator<T,M> iter2){
        root=new Node<T,M>;
        this->add_at_begin(iter1.get_pair());
        ++ iter1;
        while(iter1.get_iter()!=iter2.get_iter()){
            this->add_pair(iter1.get_pair());
            ++iter1;
            }    
        }
 Iterator<T,M> begin_iter() const{
     return root;
     }
 Iterator<T,M> end_iter() const {
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
  void assign();
    
};
