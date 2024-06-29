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
}
#endif //for Simple stack;

