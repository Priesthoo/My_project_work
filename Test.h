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
    Bnode()=default;
    Bnode(const T& val,Bnode*r,Bnode*l){
        value=val;
        right=r;
        left=l;
    }
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
template<class T>
void insert_new_node(Bnode<T>*bnode,const T& value){
    if(bnode!=null){
        if(value<bnode->value){
            if(bnode->left==null){
                bnode->left=new Bnode<T>;
                bnode->left->value=value;
                bnode->left->right=null;
                bnode->left->left=null;
                }
                else{
                    insert_new_node(bnode->left,value);
                }
        }
        else if(value>bnode->value){
            if(bnode->right==null){
                bnode->right=new Bnode<T>;
                bnode->right->value=value;
                bnode->right->right=null;
                bnode->right->left=null;
            }
            else{
                insert_new_node(bnode->right,value);
            }
        }
    }
    else{
        bnode=new Bnode<T>;
        bnode->value=value;
        bnode->right=null;
        bnode->left=null;
    }
}
