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
//hash function,I use modulo operator 
/*
Firstly work with hash function that converts int key to int hash_value.
why do i need the hash node,Incase I encountered the same key 
load factor=number of filled slots/total number of slots..
i have to handle collision by seperate chaining.
*/

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
        cout<<iter->value<<"->";
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