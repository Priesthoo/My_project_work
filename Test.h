#include<iostream>
using namespace std;
#ifndef BIN_TREE 
#define BIN_TREE 9070
#endif
#ifndef null
#define null nullptr
#endif
template<class T>
struct Bnode{
    T value;
    Bnode* right;
    Bnode* left;
};
/*
we assume  that bnode is pointing an allocated memory..
*/

template<class T>
void create_node(Bnode<T>* bnode,const T& val){
    if(val<bnode->value){
        if(bnode->left==null){
            bnode->left=new Bnode<T>;
            bnode->value=val;
            bnode->left->right=null;
            bnode->left->left=null;
        }
        else{
            create_node(bnode->left,val);
        }    
    }
    else if(val>bnode->value){
        if(bnode->right==null){
            bnode->right=new Bnode<T>;
            bnode->right->value=val;
            bnode->right->right=null;
            bnode->right->left=null;
        }
        else{
            create_node(bnode->right,val);
        }
    }
 }
