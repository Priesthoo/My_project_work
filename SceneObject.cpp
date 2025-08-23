#include<algorithm>
#include<iostream>
#include<vector>
//August 2025
using namespace std;
class SceneObject{
	private:
	SceneObject* root=nullptr;
	int id=0;
	std::vector<SceneObject*>sceneobjects;
	SceneObject* parent=nullptr;
	
	public:
	SceneObject(){
		
	}
	//The parameter (parent_1) is used to initialize the root 
	SceneObject(SceneObject* parent_1,const int& id_1){
		if(parent_1!=nullptr){
		parent_1->sceneobjects.push_back(this);
		root=parent_1;
			id=id_1;
			return;
		}
		
		id=id_1;
		return;
	}
	//Tranverse method
	//This tranverse the root node and it's parent,and also tranverse the root children and it's parent
	//if root==nullptr, check it's parent,if it nullptr, check children, if the children is empty, Transverse it's parent, '
void TranverseByRoot(){
	if(root==nullptr){// if root is equal to nullptr
		std::cout<<id<<std::endl;
		if(parent!=nullptr){ //check it's parent'
			TranverseParent();  //Tranverse it's parent of parent '
		    	return;
		}
else {
			if(!sceneobjects.empty()){ //check it's scene object '
		for(auto elem:sceneobjects){  
			if(elem!=nullptr){
				std::cout<<elem->id<<std::endl;
			}
		}	
}

		if(!sceneobjects.empty()){
			for(auto elem: sceneobjects){
				std::cout<<elem->id<<std::endl;
				elem->TranverseParent();
			}
		}
return;
	}
	}
//print the root children, parent children and it's children..'
	else if(root!=nullptr){
		if(!root->sceneobjects.empty()){
			std::cout<<root->id<<endl;
		for(auto elem:root->sceneobjects){
			if(elem!=nullptr){
				std::cout<<elem->id<<std::endl;
				elem->TranverseParent();
			}
		}
	
		}
		root->TranverseParent();
		if(!sceneobjects.empty()){
			for(auto elem: sceneobjects){
				std::cout<<elem->id<<std::endl;
				elem->TranverseParent();
			}
		}
		return;
	}
	
	std::cout<<"There is no scene objects in this root and it's parent "<<std::endl;
	if(!sceneobjects.empty()){
			for(auto elem: sceneobjects){
				std::cout<<elem->id<<std::endl;
			}
		}
	
	return;
}
void TranverseParent(){
		if(parent!=nullptr){
			std::cout<<parent->id<<std::endl;
			if(!parent->sceneobjects.empty()){
			for(auto elem: parent->sceneobjects){
				std::cout<<elem->id<<std::endl;
			}
		}
		if(parent->parent!=nullptr){
			parent->TranverseParent();
		}
		std::cout<<"Parents are tranversed"<<std::endl;
		return;
		
		}
		
		return;
		
	}

~SceneObject(){
	if(root!=nullptr){
		delete root;
		root=nullptr;
	}
	if(parent!=nullptr){
		delete parent;
		parent=nullptr;
	}
	
}
//This one reparents the parent, check if the it's parent is equa to the parent_object parameter, '
void SetParent(SceneObject* parent_object){
	  if(root==parent_object){
	  	std::cout<<"The root cannot be equal to the parent object, it will affect out tranversal algorithm"<<std::endl;
	  	return;
	  }
	  if(parent_object==nullptr){
	  	return;
	  }
	  if(parent==parent_object){
	  	return;
	  }
	  if(parent==nullptr){
	  	if(parent_object->root==root){
	  		auto iter= std::find_if(root->sceneobjects.begin(),root->sceneobjects.end(),[&,parent_object](SceneObject* object){
	  		if(object==parent_object){
	  			return true;
	  		}
	  		return false;
	  		}
	  		);
	  		//still equivalent to end(root->sceneobjects);
	  		if(iter!=root->sceneobjects.end()){
	  			parent_object->root=nullptr;
	  			root->sceneobjects.erase(iter);
	  			std::cout<<"Done"<<std::endl;
	  		}
	  	}
	  parent=parent_object;
	  std::cout<<"Parent had been set already "<<std::endl;
	  return;
	  }
	  else{
	  	if(parent->root==root){
	  		std::cout<<"Apply ReRoot method to avoid issue with tranversing, we might encounter copy(s) of element while tranversing"<<std::endl;
	  		return;
	  	}
	  	auto iter=std::find_if(parent->sceneobjects.begin(),parent->sceneobjects.end(),[&,this](SceneObject* object_1){
		if(object_1==this){
			return true;
		}
		return false;
	});
	if(iter!=parent->sceneobjects.end()){
		//erase iter from sceneobjects of root 
	parent->sceneobjects.erase(iter);
	std::cout<<"Object has been successfully removed from the  Parent "<<std::endl;
	parent_object->sceneobjects.push_back(this);
	  parent=parent_object;
	}
	else{
		std::cout<<"It cannot find object in parent "<<std::endl;
		parent_object->sceneobjects.push_back(this);
	  parent=parent_object;
	}
	  
	  }
	  return;
	}
	void NullifyRoot(){
		root=nullptr;
		std::cout<<"Root is nullified"<<std::endl;
		return;
	}
void RemoveChildFromRoot(SceneObject* object){
	//we have to check if the root is nullptr, it must return at this point, because we are trying to remove element from the root 
	if(root==nullptr){
		std::cout<<"We cannot remove any element because root is empty"<<std::endl;
		return;
	}
	
	auto iter=std::find_if(root->sceneobjects.begin(),root->sceneobjects.end(),[&,object](SceneObject* object_1){
		if(object_1==object){
			return true;
		}
		return false;
	});
	if(iter!=root->sceneobjects.end()){
		//erase iter from sceneobjects of root 
	  
	root->sceneobjects.erase(iter);
	std::cout<<"Object has been successfully removed from the root"<<std::endl;
	}
	else{
		std::cout<<"It cannot find object in Root"<<std::endl;
	}
	return;
}
//This enable us to reroot our scene object. or root it,
//if this object is not found in root, add this to new root and change this root to newroot;
void ReRoot(SceneObject* newroot){
	if(newroot==nullptr){
		
		return;
	}
	if(root==nullptr){
		auto iter= std::find(newroot->sceneobjects.begin(),newroot->sceneobjects.end(),this);
		if(iter==newroot->sceneobjects.end()){
		newroot->sceneobjects.push_back(this);
		root=newroot;
		return;
		}
	}
	auto iter=std::find_if(root->sceneobjects.begin(),root->sceneobjects.end(),[&,this](SceneObject* object){
		if(object==this){
			return true;
		}
		else{
			return false;
		}
	});
	if(iter!=root->sceneobjects.end()){
	root->sceneobjects.erase(iter);
	newroot->sceneobjects.push_back(this);
	root=newroot;
	return;
	}
	else{ // if it cannot find any element,
	auto iter= std::find(newroot->sceneobjects.begin(),newroot->sceneobjects.end(),this);
		if(iter==newroot->sceneobjects.end()){
		newroot->sceneobjects.push_back(this);
		root=newroot;
		return;
		}
	  
	}
}
void RemoveChildFromParent(SceneObject* object){
	return;
}
};

int main(){
 
 SceneObject* object=new SceneObject(nullptr,15);
 SceneObject* object_1=new SceneObject(object,12);
  SceneObject* parent_object=new SceneObject(object,150);
 SceneObject* object_2=new SceneObject(object,112);
 object_2->TranverseByRoot();
  object_2->SetParent(parent_object);
 object_2->RemoveChildFromRoot(object_1);
  object_1->TranverseByRoot();

  
 
  
   
   
 
}