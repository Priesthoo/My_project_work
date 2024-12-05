#include<iterator>
#include<iostream>
#include<vector>
#include<memory>
using namespace std;
//Binary search tree is a type of search tree that contains no more than two nodes and  it facilotates searching.
//it provides three types of Tree Transversal.
//inorder Tranversal
// Post order Tranversal
// pre order Transversal.
enum Tree_Tranversa{
    INORDER_TRANVERSAL,
    POST_ORDER_TRANVERSAL,
    PRE_ORDER_TRANVERSAL
};
template<class T>
class  Binary_Node{
    private:
    T element;
    shared_ptr<Binary_Node<T>> right;
    shared_ptr<Binary_Node<T>> left;
    public:
    Binary_Node(){
        element=T{};
        right.reset();
        left.reset();
    }
    Binary_Node(const Binary_Node<T>& other_object){
        element=other_object.Element();
        right=other_object.Right_Node();
        left=other_object.Left_Node();
    }
    Binary_Node(const T& Element, T* Left_1,T* Right_1 ){
        element=Element;
        left.reset();
        right.reset();
        
    }
    Binary_Node<T>*  Right() { // If Right is equal to NULL, it should return NULL,else it should return the stored pointer's object.'
        if(right.get()==NULL){
            return NULL;
        }
       return right.get();
    }
    Binary_Node<T>* Left() {
        if(left.get()==NULL){ // if get() of left is equal to NULL,it should return NULL
        return NULL;
}
      return left.get();
}
      T Element() const {
          return element;
      }
      T& Element() {
          return element;
      }
   shared_ptr<Binary_Node<T>>&  Right_Node() {
       return right;
    }
    shared_ptr<Binary_Node<T>>&  Left_Node(){
        return left;
    }
   void Set_Right(const T& value){
       if(Right()!=NULL){
           right.reset(); // Reset right, right will then point to NULL;
           right.reset(new Binary_Node<T>(value,NULL,NULL));
           return;
       }
       right.reset(new Binary_Node<T>(value,NULL,NULL));
       return;
      }
   void Set_Left(const T& value){
       if(Left()!=NULL){
           left.reset();
           left.reset(new Binary_Node<T>(value,NULL,NULL));
           return;
           }
           left.reset(new Binary_Node<T>(value,NULL,NULL));
           return;
   }
};
template<class T>
 void Insert(const T& ele,shared_ptr<Binary_Node<T>>&  root){
      if(root.get()==NULL){
          root.reset(new Binary_Node<T>(ele,NULL,NULL));
      }
      else if(ele<root.get()->Element()){
          Insert(ele, root.get()->Left_Node());
      }
      else if(ele>root.get()->Element()){
          Insert(ele,root.get()->Right_Node());
      }
      else{
          return;
    }
 }
 template<class T>
 void Inorder_Transversal(shared_ptr<Binary_Node<T>>& root){
     if(root.get()==NULL){
         return;
     }
     Inorder_Transversal(root.get()->Left_Node());
     std::cout<<root.get()->Element()<<"->";
     Inorder_Transversal(root.get()->Right_Node());
     
 }

template<class T>
class Binary_Search_Tree{
    private:
    shared_ptr<Binary_Node<T>> Root;
    public:
    void Insert_Element(const T& Element){
        if(Root.get()==NULL){
           Root.reset(new Binary_Node<T>(Element,NULL,NULL));
        }
        else if(Element<Root.get()->Element()){
            Insert(Element,Root.get()->Left_Node());
        }
        else if(Element>Root.get()->Element()){
            Insert(Element,Root.get()->Right_Node());
        }
        else {
            return;
        }
   }
   
   
};


int main(int argc, char *argv[])
{
	shared_ptr<Binary_Node<int>> root;
	Insert(12,root);
	Insert(13,root);
	Insert(7,root);
	Insert(4,root);
	Inorder_Transversal(root);
	
}