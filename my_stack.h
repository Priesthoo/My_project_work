#include<iostream>
using namespace std;
#define ONE 1
#ifndef SIMPLE_STACK
#define SIMPLE_STACK
namespace My_Stack{
#define UINT
#ifdef UINT
#define null_ptr nullptr
 namespace TYPE{
 typedef unsigned int uint_type;
 }
#endif //for UINT
#ifndef INITIALIZER_LIST
#define INITIALIZER_LIST
#endif 

#ifdef INITIALIZER_LIST
#include<initializer_list>
#endif //endif for initializer list
template<class G>
class Simple_stack{
    public:
    G*arr;
    TYPE::uint_type stack_size;
    Simple_stack():arr{null_ptr},stack_size{0}{}
    
    
    void push(const G& value){//Allocation of memory in the heap
     if(this->arr==null_ptr){
         this->arr=new G[ONE];
         this->arr[0]=value;
         this->stack_size=ONE;
          return;
     }
   Simple_stack<G>nstack={};
   nstack.arr=new G[this->stack_size];
   for(int i=0;i<this->stack_size;i++){
     nstack.arr[i]=this->arr[i];
      }
     delete [ ] this->arr;
     this->stack_size+=1;
     this->arr=new G[this->stack_size];
     for(int i=0;i<this->stack_size;i++){
        if(i==this->stack_size-1){
            this->arr[i]=value;
             break;
         }
       this->arr[i]=nstack.arr[i];
   }
   delete [ ] nstack.arr;
   return;
 }
  Simple_stack(const initializer_list<G>& list){
   auto key=list.begin();
   this->stack_size=list.size();
   this->arr=new G[list.size()];
   for(int i=0;i<list.size();i++){
       this->arr[i]=key[i];
   }
   
  }
 
 void pop(void){
     Simple_stack<G> nstack={};
     --this->stack_size;
     nstack.arr=new G[this->stack_size];
     for(int i=0;i<this->stack_size;++i){
         nstack.arr[i]=this->arr[i];
     }
     delete [ ] this->arr;
     this->arr=new G[this->stack_size];
    for(int i=0;i<this->stack_size;i++){
        this->arr[i]=nstack.arr[i];
    }
    delete [ ] nstack.arr;
     return;
 }
 
 G operator[ ](const TYPE::uint_type& idx) const {
     return arr[idx];
 }
 
G& operator[ ](const TYPE::uint_type& idx){
    return arr[idx];
}
   
void clear(void){
    delete [ ] this->arr;
    this->arr=null_ptr;
    this->stack_size=0;
  }
static TYPE::uint_type get_size(Simple_stack<G>stack){
    return stack.stack_size;
}
static bool is_empty(Simple_stack<G>stack){
    if((stack.stack_size==0) or(stack.arr==null_ptr)){
        return true;
    }
    return false;
}
 
};


#endif //for Simple stack;

#ifndef STACK_LIST_NODE
#define STACK_LIST_NODE
#endif
#ifdef STACK_LIST_NODE
template<class T>
 typedef struct Stack_node{
     T value;
     Stack_node*next;
 };
#endif//for stack_node

#ifndef GET_LAST_NODE
#define GET_LAST_NODE
template<class T>
 Stack_node<T>* get_last_node(Stack_node<T>*stacknode){
     Stack_node<T>*stnode=stacknode;
     while(stnode!=null_ptr){
         if(stnode->next==null_ptr){
             return stnode;
         }
         stnode=stnode->next;
     }
     return null_ptr;  //This will never be executed....
 }
#endif   //for get_last_node

#ifndef STACK_LIST
#define STACK_LIST
template<class T>
class Stack_list{
    public:
    Stack_node<T>*head_node;
    Stack_list():head_node{null_ptr}{}
    
 void push(const T& val){
     if(head_node==null_ptr){
         head_node=new Stack_node<T>;
         head_node->value=val;
         head_node->next=null_ptr;
         return;
         }
      Stack_node<T>*last_node=get_last_node(this->head_node);
      last_node->next=new Stack_node<T>;
      last_node->next->value=val;
      last_node->next->next=null_ptr;
      return;
 }
Stack_list(const initializer_list<T>& list){
    auto key=list.begin();
    Stack_node<T>* iter=null_ptr;
    TYPE::uint_type sz=list.size();
    head_node=new Stack_node<T>;
    head_node->value=key[0];
    TYPE::uint_type sz1=1;
    iter=get_last_node(this->head_node);
    while(sz1<sz){
        if(iter->next==null_ptr){
            iter->next=new Stack_node<T>;
            iter->next->value=key[sz1];
            iter->next->next=null_ptr;
           }
           iter=iter->next;
           ++sz1;
    }
}
  void pop(void){
      Stack_node<T>*stnode=get_last_node(this->head_node);
      stnode=stnode->next;
      return;
      
}
TYPE::uint_type get_size() const{
    TYPE::uint_type sz=0;
     Stack_node<T>*stnode=head_node;
     while(stnode!=null_ptr){
         ++sz;
         stnode=stnode->next;
     }
     return sz;
}
static bool is_empty(Stack_list<T>stack){
    if(stack.head_node==null_ptr){
        return true;
    }
    return false;
}
static Stack_node<T>* get_Nth_node(Stack_list<T>stack,TYPE::uint_type sz){
    if(sz>stack.get_size()){
        return null_ptr;
    }
    TYPE::uint_type sz1=1;
    Stack_node<T>*stnode=stack.stack_node;
    while(stnode!=null_ptr){
        if(sz==sz1){
            return stnode;
        }
        ++sz1;
        stnode=stnode->next;
    }
    return null_ptr;
}

};
#endif//For stack_list...
}
template<class T>
void clear_nodes(My_Stack::Stack_list<T>*stack){
    stack->head_node=null_ptr;
    return;
}
template<class T>
void print(My_Stack::Stack_list<T> stack){
    My_Stack::Stack_node<T>*stnode=stack.head_node;
    while(stnode!=null_ptr){
        if(stnode->next==null_ptr){
            cout<<stnode->value<<endl;
            return;
        }
        cout<<stnode->value<<"->";
        stnode=stnode->next;
    }
    return;
  }
template<class T>
void clear_allocated_array(My_Stack::Simple_stack<T>*mystack){
    mystack->arr=null_ptr;
    mystack->stack_size=0;
    return;
}