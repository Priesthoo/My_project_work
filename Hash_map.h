#include<iostream>
using namespace std;
#define TABLE_SIZE 567
#ifndef null
#define null nullptr
#endif
#ifndef MOD
#define MOD %
#endif
#ifndef VECTOR
#define VECTOR
#endif
#ifdef VECTOR
#include<vector>
#endif
#define STRING
#ifdef STRING
#include<string>
#endif
#include<initializer_list>
//bucket interface
//Table interface.
//hash function,I use modulo operator 
/*
Firstly work with hash function that converts int key to int hash_value.
why do i need the hash node,Incase I encountered the same key 
load factor=number of filled slots/total number of slots..
i have to handle collision by seperate chaining.
*/
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
//Hash enumeration
enum HASH{
    INT_MOD,
    STRING_MOD
};
//nodes that will work for hash_table.
template<class T>
struct Hash_node{
    T value;
    Hash_node* next;
    Hash_node():value{},next{null}{}
};
template<class T>
Hash_node<T>* get_last_pos(Hash_node<T>*node){
       Hash_node<T>*iter=nullptr;
       if(node->next==nullptr){
          iter=node;
       }
   return iter;
}
template<class T>
Hash_node<T>* get_last_iter(Hash_node<T>* node){
    Hash_node<T>* iter,*iter1;
    iter=node;
    while(iter!=nullptr){
        iter1=get_last_pos<T>(iter);
        iter=iter->next;
    }
    return iter1;
}
template<class T>
void add_node(Hash_node<T>*node,const T& value){
    if(node->next==null){
        Hash_node<T>*nhNode=new Hash_node<T>;
        nhNode->value=value;
        nhNode->next=null;
        node->next=nhNode;
    }
    else if(node->next!=null){
        add_node(node->next,value);
    }
    
}
template<class T>
T& change_value(Hash_node<T>*node){
    return node->value;
}
template<class T>
void print_node(Hash_node<T>*node){
    Hash_node<T>*iter=node;
    while(iter!=null){
        if(iter->next!=null){
        cout<<iter->value<<"->";
     }
    else if(iter->next==null){
        cout<<iter->value<<endl;
    }
    iter=iter->next;
    }
}
template<class T,class M>
Hash_node<Pair<T,M>>* get_nth_node(Hash_node<Pair<T,M>>*node,const size_t& size){
    Hash_node<Pair<T,M>>*iter=node;
    size_t sz=1;
    while(iter!=null){
       if(size==sz){
           return sz;
       }
       ++sz;
       iter=iter->next;
    }
    return null;
}
template<class T,class M>
void print_nodes(Hash_node<Pair<T,M>>* node){
    Hash_node<Pair<T,M>>* iter=node;
    while(iter!=null){
        if(iter->next!=null){
        cout<<"["<<iter->value.first<<":"<<iter->value.second<<"]"<<"->";
     }
    else if(iter->next==null){
        cout<<"["<<iter->value.first<<":"<<iter->value.second<<"]"<<endl;
     }
     iter=iter->next;
    }
}
template<class T>
void add_value(Hash_node<T>*node,const T& val){
    if(node==null){
        node=new Hash_node<T>;
        change_value(node)=val;
        node->next=null;
    }
}
template<class T>
class Hash_entry{
    public:
    Hash_node<T>* head;
    public:
    Hash_entry():head{null}{}
    Hash_entry(Hash_node<T>* node){
        head=node;
    }
    
};
int Hash_function(int key,int Entry_size)
{
    int hash_value=key MOD Entry_size;
    return hash_value;
}
int Hash_string(const string key,int Entry_size){
    int Hash_value=0;
    for(auto ch:key){
        Hash_value+=(int)ch;
}
int result=Hash_value MOD Entry_size;
return result;
}
template<class T>
size_t get_no_of_element(Hash_node<T>*node){
    size_t sz=0;
    Hash_node<T>*iter=node;
    while(iter!=null){
        ++sz;
        iter=iter->next;
    }
    return sz;
}
template<class T>
class Hash_map{
    Hash_entry<T>*hash_entry;
    size_t size;
    public:
    Hash_map():hash_entry{null},size{0}{}
    Hash_map(Hash_entry<T>*entry,const size_t&  sz){
        size=sz;
        hash_entry=new Hash_entry<T>[size];
        for(int i=0;i<size;i++){
            hash_entry[i].head=null;
        }
    }
    void add_value(int key,const T&value){
        int hash_value=Hash_function(key,size);
        if(hash_entry[hash_value].head==null){
            hash_entry[hash_value].head=new Hash_node<T>;
            hash_entry[hash_value].head->value=value;
        }
        else if(hash_entry[hash_value].head!=null){
            add_node(hash_entry[hash_value].head,value);
        }
    }
     size_t get_size() const {
        return size;
    }
    void find_and_print(int key){
        int hash=Hash_function(key,size);
        print_node(hash_entry[hash].head);
    }
    void clear_head(const int&  key){
        int hash_value=Hash_function(key,size);
        hash_entry[hash_value].head=null;
    }
    void insert_value_by_key(int key,const T& value){
        add_value(key,value);
    }
    size_t get_used_entry() const {
        size_t z=0;
        for(int i=0;i<size;i++){
            if(hash_entry[i].head==null){
                continue;
            }
            ++z;
        }
        return z;
    }
    
 //returns set of indices that were used.
 vector<int> get_set_of_used_index() const {
     vector<int> get;
     for(int i=0;i<this->size;i++){
         if(hash_entry[i].head==null){
             continue;
         }
         get.push_back(i);
     }
     return get;
 }
  void insert(int key,Hash_node<T>*node){
     int Hash_value=Hash_function(key,size);
     hash_entry[Hash_value].head=node;
 }
};
template<class T>
bool is_less_than(Hash_node<T>*node){
    Hash_node<T>*iter=node;
    while(iter!=null){
        if(iter->next!=null){
        if(iter->value>iter->next->value){
            return false;
        }    
    }
    iter=iter->next;
    }
    return true;
}

template<class T>
void less_than(Hash_node<T>*node){
    Hash_node<T>*iter=node;
    while(iter!=null){
        if(iter->next!=null){
            if(iter->value>iter->next->value){
                T val=iter->value;
                change_value(iter)=iter->next->value;
                change_value(iter->next)=val;
            }
        }
        iter=iter->next;
    }
}
//it sorts nodes
template<class T>
void sort_node(Hash_node<T>*node){
    Hash_node<T>*iter=node;
    bool is_sorted=false;
    while(is_sorted!=true){
        less_than(iter);
        is_sorted=is_less_than(iter);
    }
    
}
 //Function pointers
typedef int(*hash_function)(int,int);

//it sorts according key.
template<class T,class M>
void sort_key(Hash_node<Pair<T,M>>* node){
    Hash_node<Pair<T,M>>* iter=node;
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
// it returns true if all values are in ascemding order
template<class T,class M>
bool node_is_sorted(Hash_node<Pair<T,M>>* node){
    Hash_node<Pair<T,M>>* iter=node;
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
//it sorts the values of node until they are in ascending order.
template<class T,class M>
void sort_node_until(Hash_node<Pair<T,M>>* node){
    Hash_node<Pair<T,M>>*iter=node;
    bool is_sorted=false;
      while(is_sorted!=true){
          sort_key(iter);
          is_sorted=node_is_sorted(node);
          iter=node;
      }
}


//insertion, delete, tranversal,
/*
Insertion at a particular node,insertion 
*/

template<class T,class M>
using Cmp=void(*)(Hash_node<Pair<T,M>>*);

template<class T,class M,Cmp<T,M> cmp=sort_node_until,   hash_function hash_func=Hash_function>
class Hash_table{
    public:
    Hash_entry<Pair<T,M>> *hash_entry;
    size_t size;
    public:
    Hash_table():hash_entry{null},size{}{}
    Hash_table(Hash_entry<Pair<T,M>>*hash_en,const size_t& sz){
        hash_entry=hash_en;
        size=sz;
    }
    //constructor that accepts a size parameter
    explicit Hash_table(const size_t& sz){
        size=sz;
        hash_entry=new Hash_entry<Pair<T,M>>[size];
        
    }
    //constructor that accepts initializer lais as an argument 
    Hash_table(const initializer_list<Pair<T,M>>& list){
        size=list.size();
        auto k=list.begin();
        hash_entry=new Hash_entry<Pair<T,M>>[size];
        for(int i=0;i<size;i++){
            int  hash_value=hash_func(k[i].first,size);
            if(hash_entry[hash_value].head==null){
                hash_entry[hash_value].head=new Hash_node<Pair<T,M>>;
                hash_entry[hash_value].head->value=k[i];
                hash_entry[hash_value].head->next=null;
           }
         else if(hash_entry[hash_value].head!=null){
             add_node(hash_entry[hash_value].head,k[i]);
         }
        }
        for(int i=0;i<size;i++){
            if(hash_entry[i].head==null){
                continue;
            }
            cmp(hash_entry[i].head);
        }
    }
    //it prints the table.
  void print_table(){
      for(int i=0;i<size;i++){
          if(hash_entry[i].head==null){
              cout<<"index "<<i<<":"<<"empty"<<endl;
          }
          else if(hash_entry[i].head!=null){
           cout<<"index "<<i<<":";
           print_nodes(hash_entry[i].head);
          }
      }
  }
  //copy constructor 
  Hash_table(const Hash_table& htable){
      size=htable.size;
      hash_entry=new Hash_entry<Pair<T,M>>[size];
      for(int i=0;i<size;i++){
          hash_entry[i].head=htable.hash_entry[i].head;
      }
  }
  //our assignment operator.
  Hash_table& operator=(const initializer_list<Pair<T,M>>& list){
      *this={list};
      return *this;
  }
  // our assignment operator(=).
  Hash_table& operator=(const Hash_table& htable){
      *this={htable};
      return *this;
  }
  //it changes the size of the table and rehashes all the element of the previous table to fit the new size of the table.
  void Rehash(const size_t& sz){
      Hash_table htable=*this;
      hash_entry=new Hash_entry<Pair<T,M>>[sz];
      for(int i=0;i<htable.size;i++){
      if(htable.hash_entry[i].head==null){
          continue;
      }
   else if(htable.hash_entry[i].head!=null){
           Hash_node<Pair<T,M>>*iter=htable.hash_entry[i].head;
           while(iter!=null){
            int hash_value=hash_func(iter->value.first,sz);
            if(hash_entry[hash_value].head==null){
                hash_entry[hash_value].head=new Hash_node<Pair<T,M>>;
                hash_entry[hash_value].head->value=iter->value;
                hash_entry[hash_value].head->next=null;
           }
         else if(hash_entry[hash_value].head!=null){
             add_node(hash_entry[hash_value].head,iter->value);
         }
           iter=iter->next;     
}
  }
 }
        size=sz;
       for(int i=0;i<size;i++){
            if(hash_entry[i].head==null){
                continue;
            }
            cmp(hash_entry[i].head);
        }
    }
  //works like Rehash function.
void Resize(const size_t& sz){
    Rehash(sz);
}
//it pushes the element at the head node or at the last node
 void push(const Pair<T,M>& pair){
     int hash_value=hash_func(pair.first,size);
     if(hash_entry[hash_value].head!=null){
         Hash_node<Pair<T,M>>*iter=get_last_iter(hash_entry[hash_value].head);
         iter->next=new Hash_node<Pair<T,M>>;
         iter->next->value=pair;
     }
     else if(hash_entry[hash_value].head==null){
      Hash_node<Pair<T,M>>*iter=null;
      iter=new Hash_node<Pair<T,M>>;
      iter->value=pair;
      hash_entry[hash_value].head=iter;
     }
    cmp(hash_entry[hash_value].head);
 }
 //it returns element in each entry.
 size_t get_count_of_element() const {
     size_t y=0;
     for(int i=0;i<size;i++){
         if(hash_entry[i].head==null){
             continue;
         }
         else if(hash_entry[i].head!=null){
             y+=get_no_of_element(hash_entry[i].head);
         }
     }
     return y;
 }
 //it returns the number of used index
 size_t get_used_entry() const {
        size_t z=0;
        for(int i=0;i<size;i++){
            if(hash_entry[i].head==null){
                continue;
            }
            ++z;
        }
        return z;
    }
    //it returns the load  factor 
 float load_balance()const {
    float s=(float)get_used_entry();
    float sz=(float)size;
    float load=(float)s/size;
    return load;
 }
 //it returns size
size_t get_size() const{
    return size;
}
//Hash_table interface
Hash_entry<Pair<T,M>>& operator[ ](const T& idx) const {
    int hash_value=hash_func(idx,size);
    return hash_entry[hash_value];
}
//it returns the compare function
Cmp<T,M> get_cmp() const{
    return cmp;
}
//it returns  the hash function in use.
hash_function get_hashfunc() const{
    return hash_func;
}
//it returns the node that has value as pair in the hash_table.
Hash_node<Pair<T,M>> find_value_by_key(const Pair<T,M>& pair){
    int hash_value=hash_func(pair.first,size);
    if(hash_entry[hash_value].head!=null){
        Hash_node<Pair<T,M>>*iter=hash_entry[hash_value].head;
        while(iter!=null){
            if(iter->value.first==pair.first and iter->value.second==pair.second){
                return iter;
            }
            iter=iter->next;
        }
    }
    return null;
}
//it returns the hash_index of the value.
size_t return_hash_index(const Pair<T,M>& pair){
    size_t hash_value=(size_t)hash_func(pair.first,size);
    return hash_value;
}
//it inserts pair of value into the internal state of the object.to which it is attached.
void insert_key_pair(const Pair<T,M>& pair){
    int hash_value=hash_func(pair.first,size);
    Hash_node<Pair<T,M>>*iter=null;
    if(hash_entry[hash_value].head==null){
        hash_entry[hash_value].head=new Hash_node<Pair<T,M>>;
        hash_entry[hash_value].head->value=pair;
    }
  else if(hash_entry[hash_value].head!=null){
      iter=get_last_iter(hash_entry[hash_value].head);
      iter->next=new Hash_node<Pair<T,M>>;
      iter->next->value=pair;
  }
}
// it inserts the initializer list into the internal structure of the object to which it is attached.
void insert_key_pairs(const initializer_list<Pair<T,M>>& list){
    auto key=list.begin();
    Hash_node<Pair<T,M>>*iter=null;
    for(int i=0;i<list.size();++i){
        int hash_value=hash_func(key[i].first,size);
        if(hash_entry[hash_value].head==null){
            hash_entry[hash_value].head=new Hash_node<Pair<T,M>>;
            hash_entry[hash_value].head->value=key[i];
         }
         else if(hash_entry[hash_value].head!=null){
             iter=get_last_iter(hash_entry[hash_value].head);
             iter->next=new Hash_node<Pair<T,M>>;
             iter->next->value=key[i];
         }
    }
    for(int i=0;i<size;i++){
            if(hash_entry[i].head==null){
                continue;
            }
            cmp(hash_entry[i].head);
        }
  }
  void print_nodes_attached_to_index(const T& idx){
      int hash_value=hash_func(idx,size);
      if(hash_entry[hash_value].head!=null){
      Hash_node<Pair<T,M>>*iter=hash_entry[hash_value].head;
      while(iter!=null){
          if(iter->next!=null){
          cout<<iter->value.second<<"->";
          }
          else {
              cout<<iter->value.second<<endl;
          }
          iter=iter->next;
      }
   }
  }
  void erase_by_index(const T& pair){
      int hash_value=hash_func(pair,size);
      hash_entry[hash_value].head=null;
  }
  void clear(){
      for(int i=0;i<size;i++){
          if(hash_entry[i].head==null){
              continue;
          }
          hash_entry[i].head=null;
      }
  }
  
//hash index operations.
Hash_node<Pair<T,M>> get_hash_index_head(const T& key){
    int hash_value=hash_func(key,size);
    return hash_entry[hash_value].head;
}
//it returns the no of element per head.
size_t get_no_of_element_per_head(const T& key){
    int hash_value=hash_func(key,size);
   Hash_node<Pair<T,M>>*iter=hash_entry[hash_value].head;
   size_t sz=get_no_of_element(iter);
   return sz;
}
  //it returns the nth node for a particular head.
  Hash_node<Pair<T,M>>*get_nth_node_for_head(const T& key, const size_t& sz){
      int hash_value=hash_func(key,size);
      Hash_node<Pair<T,M>>*iter=get_nth_node(hash_entry[hash_value].head,sz);
      return iter;
  }
};
typedef int(*String_hash)(const string,int);
template<class T,class M,Cmp<T,M> cmp=sort_node_until,String_hash hash_func=Hash_string>
class String_map{
    public:
    Hash_entry<Pair<T,M>>* hash_entry;
    size_t size;
    public:
    String_map():hash_entry{null},size{}{}
    String_map(Hash_entry<Pair<T,M>>*hash_en,const size_t& sz){
        hash_entry=hash_en;
        size=sz;
    }
    //constructor that accepts a size parameter
    explicit String_map(const size_t& sz){
        size=sz;
        hash_entry=new Hash_entry<Pair<T,M>>[size];
        
    }
    //constructor that accepts initializer lais as an argument 
    String_map(const initializer_list<Pair<T,M>>& list){
        size=list.size();
        auto k=list.begin();
        hash_entry=new Hash_entry<Pair<T,M>>[size];
        for(int i=0;i<size;i++){
            int  hash_value=hash_func(k[i].first,size);
            if(hash_entry[hash_value].head==null){
                hash_entry[hash_value].head=new Hash_node<Pair<T,M>>;
                hash_entry[hash_value].head->value=k[i];
                hash_entry[hash_value].head->next=null;
           }
         else if(hash_entry[hash_value].head!=null){
             add_node(hash_entry[hash_value].head,k[i]);
         }
        }
        for(int i=0;i<size;i++){
            if(hash_entry[i].head==null){
                continue;
            }
            cmp(hash_entry[i].head);
        }
    }
    //it prints the table.
  void print_table(){
      for(int i=0;i<size;i++){
          if(hash_entry[i].head==null){
              cout<<"index "<<i<<":"<<"empty"<<endl;
          }
          else if(hash_entry[i].head!=null){
           cout<<"index "<<i<<":";
           print_nodes(hash_entry[i].head);
          }
      }
  }
  //copy constructor 
  String_map(const String_map& htable){
      size=htable.size;
      hash_entry=new Hash_entry<Pair<T,M>>[size];
      for(int i=0;i<size;i++){
          hash_entry[i].head=htable.hash_entry[i].head;
      }
  }
  //our assignment operator.
  String_map& operator=(const initializer_list<Pair<T,M>>& list){
      *this={list};
      return *this;
  }
  // our assignment operator(=).
  String_map& operator=(const String_map& htable){
      *this={htable};
      return *this;
  }
  //it changes the size of the table and rehashes all the element of the previous table to fit the new size of the table.
  void Rehash(const size_t& sz){
      String_map htable=*this;
      hash_entry=new Hash_entry<Pair<T,M>>[sz];
      for(int i=0;i<htable.size;i++){
      if(htable.hash_entry[i].head==null){
          continue;
      }
   else if(htable.hash_entry[i].head!=null){
           Hash_node<Pair<T,M>>*iter=htable.hash_entry[i].head;
           while(iter!=null){
            int hash_value=hash_func(iter->value.first,sz);
            if(hash_entry[hash_value].head==null){
                hash_entry[hash_value].head=new Hash_node<Pair<T,M>>;
                hash_entry[hash_value].head->value=iter->value;
                hash_entry[hash_value].head->next=null;
           }
         else if(hash_entry[hash_value].head!=null){
             add_node(hash_entry[hash_value].head,iter->value);
         }
           iter=iter->next;     
}
  }
 }
        size=sz;
       for(int i=0;i<size;i++){
            if(hash_entry[i].head==null){
                continue;
            }
            cmp(hash_entry[i].head);
        }
    }
  //works like Rehash function.
void Resize(const size_t& sz){
    Rehash(sz);
}
//it pushes the element at the head node or at the last node
 void push(const Pair<T,M>& pair){
     int hash_value=hash_func(pair.first,size);
     if(hash_entry[hash_value].head!=null){
         Hash_node<Pair<T,M>>*iter=get_last_iter(hash_entry[hash_value].head);
         iter->next=new Hash_node<Pair<T,M>>;
         iter->next->value=pair;
     }
     else if(hash_entry[hash_value].head==null){
      Hash_node<Pair<T,M>>*iter=null;
      iter=new Hash_node<Pair<T,M>>;
      iter->value=pair;
      hash_entry[hash_value].head=iter;
     }
    cmp(hash_entry[hash_value].head);
 }
 //it returns element in each entry.
 size_t get_count_of_element() const {
     size_t y=0;
     for(int i=0;i<size;i++){
         if(hash_entry[i].head==null){
             continue;
         }
         else if(hash_entry[i].head!=null){
             y+=get_no_of_element(hash_entry[i].head);
         }
     }
     return y;
 }
 //it returns the number of used index
 size_t get_used_entry() const {
        size_t z=0;
        for(int i=0;i<size;i++){
            if(hash_entry[i].head==null){
                continue;
            }
            ++z;
        }
        return z;
    }
    //it returns the load  factor 
 float load_balance()const {
    float s=(float)get_used_entry();
    float sz=(float)size;
    float load=(float)s/size;
    return load;
 }
 //it returns size
size_t get_size() const{
    return size;
}
//Hash_table interface
Hash_entry<Pair<T,M>>& operator[ ](const T& idx) const {
    int hash_value=hash_func(idx,size);
    return hash_entry[hash_value];
}
//it returns the compare function
Cmp<T,M> get_cmp() const{
    return cmp;
}
String_hash get_hash_function(){
    String_hash hf=hash_func;
    return hf;
}

//it returns the node that has value as pair in the hash_table.
Hash_node<Pair<T,M>> find_value_by_key(const Pair<T,M>& pair){
    int hash_value=hash_func(pair.first,size);
    if(hash_entry[hash_value].head!=null){
        Hash_node<Pair<T,M>>*iter=hash_entry[hash_value].head;
        while(iter!=null){
            if(iter->value.first==pair.first and iter->value.second==pair.second){
                return iter;
            }
            iter=iter->next;
        }
    }
    return null;
}
//it returns the hash_index of the value.
int return_hash_index(const Pair<T,M>& pair){
    int hash_value=hash_func(pair.first,size);
    return hash_value;
}
//it inserts pair of value into the internal state of the object.to which it is attached.
void insert_key_pair(const Pair<T,M>& pair){
    int hash_value=hash_func(pair.first,size);
    Hash_node<Pair<T,M>>*iter=null;
    if(hash_entry[hash_value].head==null){
        hash_entry[hash_value].head=new Hash_node<Pair<T,M>>;
        hash_entry[hash_value].head->value=pair;
    }
  else if(hash_entry[hash_value].head!=null){
      iter=get_last_iter(hash_entry[hash_value].head);
      iter->next=new Hash_node<Pair<T,M>>;
      iter->next->value=pair;
  }
}
// it inserts the initializer list into the internal structure of the object to which it is attached.
void insert_key_pairs(const initializer_list<Pair<T,M>>& list){
    auto key=list.begin();
    Hash_node<Pair<T,M>>*iter=null;
    for(int i=0;i<list.size();++i){
        int hash_value=hash_func(key[i].first,size);
        if(hash_entry[hash_value].head==null){
            hash_entry[hash_value].head=new Hash_node<Pair<T,M>>;
            hash_entry[hash_value].head->value=key[i];
         }
         else if(hash_entry[hash_value].head!=null){
             iter=get_last_iter(hash_entry[hash_value].head);
             iter->next=new Hash_node<Pair<T,M>>;
             iter->next->value=key[i];
         }
    }
    for(int i=0;i<size;i++){
            if(hash_entry[i].head==null){
                continue;
            }
            cmp(hash_entry[i].head);
        }
  }
  //it prints nodes associated with hashindex.
  void print_nodes_attached_to_index(const T& idx){
      int hash_value=hash_func(idx,size);
      if(hash_entry[hash_value].head!=null){
      Hash_node<Pair<T,M>>*iter=hash_entry[hash_value].head;
      while(iter!=null){
          if(iter->next!=null){
          cout<<iter->value.second<<"->";
          }
          else {
              cout<<iter->value.second<<endl;
          }
          iter=iter->next;
      }
   }
  }
  //it erases the element by key
  void erase_by_index(const T& pair){
      int hash_value=hash_func(pair,size);
      hash_entry[hash_value].head=null;
  }
  //,it clears  all elements of the array of linked lis
  void clear(){
      for(int i=0;i<size;i++){
          if(hash_entry[i].head==null){
              continue;
          }
          hash_entry[i].head=null;
      }
  }
//hash index operations.
Hash_node<Pair<T,M>> get_hash_index_head(const T& key){
    int hash_value=hash_func(key,size);
    return hash_entry[hash_value].head;
}
//it returns the number of elements per head
size_t get_no_of_element_per_head(const T& key){
    int hash_value=hash_func(key,size);
   Hash_node<Pair<T,M>>*iter=hash_entry[hash_value].head;
   size_t sz=get_no_of_element(iter);
   return sz;
}
//it returns the nth node for a particular head chosen 
 Hash_node<Pair<T,M>>*get_nth_node_for_head(const T& key, const size_t& sz){
      int hash_value=hash_func(key,size);
      Hash_node<Pair<T,M>>*iter=get_nth_node(hash_entry[hash_value].head,sz);
      return iter;
  }
  
  void print_synonyms(const T& val){
      int hash_value=hash_func(val,size);
      Hash_node<Pair<T,M>>*iter=hash_entry[hash_value].head;
      while(iter!=null){
          cout<<iter->value.second<<endl;
          iter=iter->next;
      }
  }
};
template<class T,class M>
void print_synonym(const String_map<T,M>& smap,const T& value){
    int hash_value=Hash_string(value,smap.size);
   Hash_node<Pair<T,M>>*iter=smap.hash_entry[hash_value].head;
    while(iter!=null){
        cout<<iter->value.second<<endl;
        iter=iter->next;
    }
}