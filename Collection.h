#include<iostream>
#define COLLECTION_H
using namespace std;
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
    typedef T Value_Type;
    public:
    Element(){
        value=T{};
    }
    Element(const Element& element){
        value=element.value;
    }
    bool is_Empty() const{
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
    T* Get_First_Ptr() const{
        if(first_ptr!=NULL){
            return first_ptr;
        }
        return NULL;
    }
    T* Get_Second_Ptr() const {
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
    
     public:
      typedef  Range<Element<T>> Iterator_Range;
     
     Collection()=default;
     Collection(const Range<Element<T>>& range){
         sz=range.GetSize();
         Element<T>* first_pointer= range.Get_First_Ptr();
         pointer=new Element<T>[sz];
         if(sz!=0 && (sz!= sizeof(size_t)) && (pointer!=NULL) &&(first_pointer!=NULL)){
             for(int i=0;i<sz;i++){
                 pointer[i].Set_Value(first_pointer[i].Get_Value());
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
 bool Is_Empty() const {
     if(Get_Size()==0){
         return true;
     }
 }
 bool Is_NULL() const {
     if(pointer==NULL){
         return true;
     }
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
     if(element.is_Empty()){
         return;
     }
     for(int i=0;i<Get_Size();i++){
         pointer[i].Set_Value(element.Get_Value());
     }
     return;
 }
 void Initialize_Range_of_Element(const size_t& start_index,const Range<Element<T>>& range){
     if(range.is_Empty()){
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
 Element<T>& Get_First_Element(){
     if(pointer!=NULL){
         return pointer[0];
     }
     }
     Element<T>& Get_Last_Element(){
         if(pointer!=NULL){
             return pointer[Get_Size()-1];
         }
     }
     Element<T>* Get_Ptr_To_First_Element(){
         if(pointer!=NULL){
             return pointer;
         }
     }
     Element<T>* Get_Ptr_To_Last_Element(){
         return NULL;
     }
  Iterator_Range Get_Range_Of_Element(const size_t& first_index,const size_t& second_index) const {
        if(Does_Index_Exist(first_index,Get_Size()) &&(Does_Index_Exist(second_index,Get_Size()))){
            Iterator_Range range(&pointer[first_index],&pointer[second_index]);
            return range;
        }
     }
 Iterator_Range Define_Range() const {
       Iterator_Range Range(&pointer[0],&pointer[Get_Size()]);
       if(!Range.Is_Empty()){
           return Range;
       }
    }
    
 void Insert_An_Element_before_Index(const size_t& idx,const Element<T>& element){
     if(pointer==NULL){
         return;
     }
     if(Get_Size()==0){
         return;
     }
     Collection collection(Define_Range());
     if(!collection.Is_Ok()){
         return;
     }
     
     if(!Is_NULL()){
         delete [ ] pointer;
         pointer=NULL;
     }
     
     pointer=new Element<T>[Get_Size()+1];
     sz=Get_Size()+1;
     if(!Does_Index_Exist(idx,sz)){
         return;
     }
     for(int i=0;i<idx;i++){
         pointer[i].Set_Value(collection.Access_An_Element(i).Get_Value());
     }
     pointer[idx].Set_Value(element.Get_Value());
     size_t size=Get_Size()-idx;
     for(int i=0;i<size;i++){
         if(!collection.Access_An_Element(i).is_Empty()){
         pointer[idx+1+i].Set_Value(collection.Access_An_Element(idx+i).Get_Value());
         }
     }
     if(pointer==NULL){
         return;
     }
     if(!collection.Is_NULL()){ //if collection is  not null
         collection.Destroy(); // destroy collection.
     }
     return;
 }
 
 void Destroy(){
     if(!Is_NULL()){
         delete [ ] pointer;
         pointer=NULL;
         sz=0;
         return;
     }
     return;
 }
 
 void Assign_Value_At_Index(const size_t& idx,const Element<T>& element){
     if(Is_NULL()){
         return;
     }
     if(Is_Empty()){
         return;
     }
     if(Does_Index_Exist(idx,Get_Size())){
         pointer[idx].Set_Value(element.Get_Value());
     }
     return;
 }
 bool Is_Ok() const {
     if(!Is_NULL() &&(!Is_Empty())){
         return true;
     }
 }
 void Delete_An_Element(const size_t& idx){
     if(!Is_Ok()){// this checks for the size and the pointer to an allocated memory ..
         return;
     }
     if(!Does_Index_Exist(idx,Get_Size())){
         return;
     }
     Collection collection(Define_Range());
     Destroy(); // This destroys the collection object...
     if(!Is_Ok()){
         Allocate_Size(collection.Get_Size()-1);
     }
     if(!Is_Ok()){
         return;
     }
     for(int i=0;i<idx;i++){
         Access_An_Element(i).Set_Value(collection.Access_An_Element(i).Get_Value());
     }
     int size=Get_Size()-idx;
     for(int i=0;i<size;i++){
         Access_An_Element(i+idx).Set_Value(collection.Access_An_Element(i+idx+1).Get_Value());
     }
     if(collection.Is_Ok()){
         collection.Destroy();
     }
     return;
 }
 
 };
 