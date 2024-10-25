#include<iostream>
#define COLLECTION_H
//This class is  defined to encapsulate two pointers that hold pointer to the elements of a collection....
bool Does_Index_Exist(const size_t& index,const size_t& size){
    if(index<size){
        return true;
    }
}

template<class T> 
class Element{
    public:
    T value;
    public:
    Element(){
        value=T{};
    }
    Element(const Element& element){
        value=element.value;
    }
    bool is_Empty(){
        if(value==T{}){
            return true;
        }
    }
    Element(const T& value1){
        value=value1;
    }
    void Set_Value(const T& value1){
        value=value1;
        return;
    }
    T Get_Value() const {
        return value;
    }
    Element& operator=(const Element& element){
        *this={element};
        return *this;
    }
};

template<class T>
class Range{
    private:
    T* first_ptr;
    T* second_ptr;
    public:
    Range()=default;
    Range(const T* ptr1,const T* ptr2){
        if(ptr1!=NULL && (ptr2!=NULL)){
        first_ptr=ptr1;
        second_ptr=ptr2;
        }
    }
    Range(T* ptr1,T* ptr2){
         if(ptr1!=NULL && (ptr2!=NULL)){
        first_ptr=ptr1;
        second_ptr=ptr2;
        }
    }
    T* Get_First_Ptr(){
        if(first_ptr!=NULL){
            return first_ptr;
        }
        return NULL;
    }
    T* Get_Second_Ptr(){
         if(second_ptr!=NULL){
            return first_ptr;
        }
        return NULL;
     }
    Range(const Range& range){
       first_ptr=range.Get_First_Ptr();
       second_ptr=range.Get_Second_Ptr(); 
    }
    void Destroy(){
        if(first_ptr!=NULL  && (second_ptr!=NULL)){
            first_ptr=NULL;
            second_ptr=NULL;
            return;
        }
        return;
    }
    bool Is_Empty() const {
        if(first_ptr==NULL && (second_ptr==NULL) ){
            return true;
        }
    }
    size_t GetSize() const {
        T* ptr=first_ptr;
        if(!Is_Empty()){
            size_t size=0;
            while(ptr!=second_ptr){
                ++size;
                ++ptr;
            }
            if(size!=0){
                return size;
            }
        }
    }
 };
 
 
 template<class T>
 class Collection{
     private:
     Element<T>* pointer;
     size_t sz;
     typedef  Range<Element<T>> Iterator_Range;
     
     public:
     Collection()=default;
     Collection(const Range<Element<T>>& range){
         sz=range.Get_Size();
         Element<T>* first_pointer= range.Get_First_Ptr();
         pointer=new Element<T>[sz];
         if(sz!=0 && (sz!= sizeof(size_t)) && (pointer!=NULL) &&(first_pointer!=NULL)){
             int i=0;
             while(i<sz &&(first_pointer!=range.Get_Second_Ptr())){
                 pointer[i]=*first_pointer;
                 ++i;
                 ++first_pointer;
             }
         }
     }
   Element<T>& Access_An_Element(const size_t& index){
       if(Does_Index_Exist(index,Get_Size())){
           if(pointer!=NULL){
               return pointer[index];
           }
       }
   }
  size_t Get_Size() const{
      return sz;
  }
  void Allocate_Size(const size_t& size){
      if(size==0){
          return;
      }
      sz=size;
      pointer=new Element<T>[sz];
      return;
  }
    void Initialize_An_Element(const size_t& index,const T& value){
        if(Get_Size()==0){
            return;
        }
        if(Does_Index_Exist(index,Get_Size())){
            if(pointer!=NULL){
                pointer[index].value=value;
                return;
            }
        }
        return;
    }
    void Initialize_An_Element(const size_t& index,const Element<T>& element ){
        if(Get_Size()==0){
            return;
        }
        if(Does_Index_Exist(index,Get_Size())){
            if(pointer!=NULL){
                pointer[index].Set_Value(element.Get_Value());
                return;
            }
        }
        return;
    }
 
 void Initialize_All_Element(const Collection& collection){
     if(pointer==NULL){
         return;
     }
     if(Get_Size()<collection.Get_Size()){
         return;
     }
     for(int i=0;i<collection.Get_Size();i++){
         pointer[i].Set_Value(collection.Access_An_Element(i).Get_Value());
        }
        return;
 }
 void Initialize_All_Element(const Element<T>& element){
     if(pointer==NULL){
         return;
     }
     if(element.IsEmpty()){
         return;
     }
     for(int i=0;i<Get_Size();i++){
         pointer[i].Set_Value(element.Get_Value());
     }
 }
 void Initialize_Range_of_Element(const size_t& start_index,const Range<Element<T>>& range){
     if(range.Is_Empty()){
         return;
     }
     size_t length1=start_index+range.Get_Size();
     
     if(!Does_index_Exist(length1,Get_Size())){
         return;
     }
     for(int i=0;i<range.Get_Size();i++){
         pointer[i+start_index].Set_Value(range.Get_First_Ptr()->Get_Value());
         ++range.Get_First_Ptr();
     }
     return;
 }
 };