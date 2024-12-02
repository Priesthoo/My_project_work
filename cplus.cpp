#include<iostream>
#include<memory>
#include<chrono>
#include<initializer_list>
#include<vector>
#include<list>
using namespace std;
//using linked_list, shared_ptr and  vector to implement std::stack;
//Deletion and insertion are performed at the top.it implements  the LIFO(last in first out)
//Composition vs Aggregation.
template<class T>
class Array_Stack{
    private:
    std::vector<T>stack;
    int top;
    public:
    Array_Stack(){
        top=0;
    }
    //This class holds push_element() which pushes element to the top of the stack and increments
    void push_element(const T& value){
        stack.push_back(value); // stack calls push_back function to push back value;
        ++top;
    }
    void pop_element(){
        if(top>0){  
        --top;
        return;
        }
        top=0;
        return;
   }
   //I actually love naming my getter's function as the name of the member variables.'
  std::vector<T> Stack() const {
      return stack; //  This returns the stack associated with the object of this class 
  }
  int Top_value() const{
    return top;
    } 
  
};
//This uses linked_list to implement stack
template<class T>
class List_Stack{
    
};

int main(){
    Array_Stack<int> array_stack;
    array_stack.push_element(5);
    if(!array_stack.Stack().empty()){
        cout<<"array stack is not empty"<<endl;
    }
   for(int i=1;i<34;i++){
       array_stack.push_element(i+1);
   }
   cout<<array_stack.Top_value()<<endl;
   array_stack.pop_element();
   cout<<array_stack.Top_value()<<endl;
}
