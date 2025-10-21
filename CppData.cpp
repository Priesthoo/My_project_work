#include<iostream>
using namespace std;
//this is the root of node....
template<class T>
struct Node{
	T data;
	Node<T>* next;
};

template<class T>
Node<T>* createNewNode(const T& val){
	Node<T>* newnode=new Node<T>;
	newnode->data=val;
	newnode->next=nullptr;
	if(newnode){
		return newnode;
	}
	return nullptr;
}
//Let's try using while loop to initialize a node
//Criteria:  rootNode must not be equal to nullptr.
template<class T>
void insertUsingWhileLoop(Node<T>* rootNode, const T& value){
	if(rootNode){
		Node<T>* iter=rootNode;
		while(iter){
			if(iter->next==nullptr){
				iter->next=createNewNode(value);
				return;
			}
			iter=iter->next;
		}
	}
	return;
}

template<class T>
void InsertValue(Node<T>* rootNode,const T& value ){
	if(!rootNode->next){
		rootNode->next=createNewNode(value);
		 return;
	}
	else{
	  InsertValue(rootNode->next,value);	
	}
	return;
}
//At this point, we assume that rootNode is not a nullptr.... 
template<class T>
void InsertNextValue(Node<T>* rootNode,const T& val){
	if(!rootNode){
		std::cout<<"The First parameter of InsertNextValue() is pointing to nullptr, Allocate a memory for it"<<std::endl;
		return;
	}
	if(!rootNode->next){
		rootNode->next=createNewNode(val);
		return;
	}
	else{
		InsertValue(rootNode->next,val);
		
	}
	return;
}
template<class T>
void DestroyNode(Node<T>*rootNode){
	if(rootNode){
		delete rootNode;
		rootNode=nullptr;
		return;
	}
	return;
	
}
template<class T>
void PrintNode(Node<T>* rootNode){
	   Node<T>*iter=rootNode;
	   while(iter){
	   	cout<<iter->data<<std::endl;
	   	iter=iter->next;
	   }
	   return;
}

//it returns the node that has the value....
//root_node must not point to nullptr...
template<class T>
Node<T>* FindValue(Node<T>*root_node,const T& val){
	Node<T>*iter=root_node;
	while(iter){
		if(iter->data==val){
			return iter;
		}
		iter=iter->next;
	}
	return nullptr;
}
//NB: root must not a nullptr, unless you want an unexpected result,
//childnode can either be a subset of rootNode or not
template<class T>
bool hasNode(Node<T>* root,Node<T>* childnode){
	Node<T>* iter=root;
	while(iter){
		if(iter==childnode){
			return true;
		}
		iter=iter->next;
		}
	return false;
}
//Requirement for T:
//T must be assignable, must be have assignment operator overloaded...
template<class T>
class SinglyLinkedList{
	private:
	Node<T>* root=nullptr;
	public:
	SinglyLinkedList(){}
// methods: to insert values...
	void insertValue(const T& val){
		if(!root){
			 root=new Node<T>;
			root->data=val;
			return;
		}
		InsertNextValue(root,val);
	    return;
	}
//Reference
Node<T>* GetRoot() const{
		return root;
	}

void ClearAllNode(){
		this->~SinglyLinkedList();
	
	return;
}
  ~SinglyLinkedList(){
  	if(root){
  		delete root;
  		root=nullptr;
  		if(!root){
  			std::cout<<"Successfully Destroyed"<<std::endl;
  			return;
  		}
  	}
  	else{
  		std::cout<<"An Object of SinglyLinkedList is pointing to an unexisting memory,i.e No memory is assigned to it"<<std::endl;
  		return;
  	}
 }
};




int main(int argc, char *argv[])
{
  SinglyLinkedList<int> rlist;
  rlist.insertValue(12); //12 is added...
  InsertNextValue(rlist.GetRoot(),14);      //14 is added 
  insertUsingWhileLoop(rlist.GetRoot(),15); // 15 is added 
  PrintNode(rlist.GetRoot()); //12,14,15
  cout<<endl; //indirectly new line....
 
  
}