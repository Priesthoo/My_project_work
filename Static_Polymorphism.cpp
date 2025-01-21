#include<iostream>
#include<memory>
using namespace std;
// This class will  serve as a base class for all derived classes that will be defined here,It will also implement the function that will be shared across derived class
template<class T>
class Strategy{
    public:
    void execute_all_strategy(){
        //execute() is the function that will be shared across the derived class
        static_cast<T*>(this)->execute();
    }
   ~Strategy(){
       
   }
};
//An inheritor
class Defensive_Strategy:public Strategy<Defensive_Strategy>{
   public:
   void execute(){
       std::cout<<"Using Defensive Strategy"<<std::endl;
   }
~Defensive_Strategy(){
    
}
};
//An inheritor
class Offensive_Strategy:public Strategy<Offensive_Strategy>{
    public:
    void execute(){
        std::cout<<"Using Offensive Strategy"<<std::endl;
    }
    ~Offensive_Strategy(){
        
    }
};

class Player{
    public:
template<class T>
    void change_strategy(){
        T strategy;
        strategy.execute_all_strategy();
       return;
    }
    
    ~Player(){
        
    }
};
struct Binary_Node{
    int value;
    Binary_Node* right;
    Binary_Node*left;
};
Binary_Node* Create_Root(const int& value1){
    Binary_Node*root_node=new Binary_Node;
    //check if memory is allocated.
    if(root_node==NULL){
        return NULL;
    }
    
    root_node->value=value1;
    root_node->right=NULL;
    root_node->left=NULL;
    return root_node;
}

int main(int argc, char *argv[])
{
	std::cout<<Create_Root(5)->value<<std::endl;
}