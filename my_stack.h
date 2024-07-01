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
#endif
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
    this->stack_size=0;
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


};
#endif
}
