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
enum HASH{
    INT_MOD,
    STRING_MOD
};
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
int Hash_function(const string key,int Entry_size){
    int Hash_value=0;
    for(auto ch:key){
        Hash_value+=(int)ch;
}
int result=Hash_value MOD Entry_size;
return result;
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
 //return set of indices that were used.
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
template<class T>
void sort_node(Hash_node<T>*node){
    Hash_node<T>*iter=node;
    bool is_sorted=false;
    while(is_sorted!=true){
        less_than(iter);
        is_sorted=is_less_than(iter);
    }
    
}
 
typedef int(*hash_function)(int,int);


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
    private:
    Hash_entry<Pair<T,M>> *hash_entry;
    size_t size;
    
    public:
    Hash_table():hash_entry{null},size{}{}
    Hash_table(Hash_entry<Pair<T,M>>*hash_en,const size_t& sz){
        hash_entry=hash_en;
        size=sz;
    }
    explicit Hash_table(const size_t& sz){
        size=sz;
    }
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
  Hash_table(const Hash_table& htable){
      size=htable.size;
      hash_entry=new Hash_entry<Pair<T,M>>[size];
      for(int i=0;i<size;i++){
          hash_entry[i].head=htable.hash_entry[i].head;
      }
  }
  Hash_table& operator=(const initializer_list<Pair<T,M>>& list){
      *this={list};
      return *this;
  }
  Hash_table& operator=(const Hash_table& htable){
      *this={htable};
      return *this;
  }
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
  }
void Resize(const size_t& sz){
    Rehash(sz);
}
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
 }
};
