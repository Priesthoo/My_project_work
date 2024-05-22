#include<iostream>
using namespace std;
#define TABLE_SIZE 567
#ifndef null
#define null nullptr
#endif
#ifndef MOD
#define MOD %
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
class Hash_entry{
    int key;
    Hash_node<T>* head;
    public:
    Hash_entry():key{0},head{null}{}
};
template<class T>
class Hash_map{
    Hash_entry<T>*hash_entry;
    size_t size;
    public:
    Hash_map():hash_entry{null},size{0}{}
};
