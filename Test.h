#include<iostream>
using namespace std;
#ifndef BIN_TREE 
#define BIN_TREE 9070
#endif
#ifndef null
#define null nullptr
#endif
enum ORDER{
    IN_ORDER=10,
    POST_ORDER=12,
    PRE_ORDER=14,
    ALL_ORDER=16
};
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
template<class T>
Bnode<T>* Find_max_value(Bnode<T>* bnode){
    Bnode<T>*iter;
    iter=bnode;
    while(iter!=null){
        if(iter->right==null){
            return iter;
        }
        iter=iter->right;
    }
    return iter;
 }
 template<class T>
 Bnode<T>*Find_min_value(Bnode<T>*bnode){
     Bnode<T>*iter;
     iter=bnode;
     while(iter!=null){
         if(iter->left==null){
             return iter;
         }
         iter=iter->left;
     }
     return iter;
 }
 /*
    The tranversal operation searches until.it encounters a leaf node
 */
template<class T>
void print_in_order(Bnode<T>* node)
{
    if (node == null){
    return;
}
 print_in_order(node->left);
cout << node->value << " ";
 print_in_order(node->right);
}

template<class T>
void print_pre_order(Bnode<T>*bnode){
    if(bnode==null){
        return ;
    }
    cout<<bnode->value<<" ";
    print_pre_order(bnode->left);
    print_pre_order(bnode->right);
}
template<class T>
void print_post_order(Bnode<T>*bnode){
    if(bnode==null){
        return ;
    }
    print_post_order(bnode->left);
    print_post_order(bnode->right);
    cout<<bnode->value<<" ";
}
template<class T>
void print_tree(Bnode<T>*bnode,ORDER state){
    if(bnode!=null){
    if(state==IN_ORDER){
        cout<<"IN_ORDER:"<<"[";
        print_in_order(bnode);
        cout<<"]"<<endl;
        
    }
    else if(state==POST_ORDER){
        cout<<"POST_ORDER:"<<"[";
        print_post_order(bnode);
        cout<<"]"<<endl;
      }
     else if(state==PRE_ORDER){
        cout<<"PRE_ORDER:"<<"[";
        print_pre_order(bnode);
        cout<<"]"<<endl;
      }  
       else if(state==ALL_ORDER){
        cout<<"IN_ORDER:"<<"[";
        print_in_order(bnode);
        cout<<"]"<<"  ";
        cout<<"POST_ORDER:"<<"[";
        print_post_order(bnode);
        cout<<"]"<<"   ";
        cout<<"PRE_ORDER:"<<"[";
        print_pre_order(bnode);
        cout<<"]"<<endl;
       }
 }
}
