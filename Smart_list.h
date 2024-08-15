#include<memory>
#include<iostream>
using namespace std;
#ifndef INIT_LIST
#define INIT_LIST 10
#include<initializer_list>
#endif
#ifndef MATH_H
#define MATH_H
#include<cmath>
#define NOT_FOUND pow(2,32)
#endif

#ifndef CCTYPE_H
#define CCTYPE_H
#include<cctype>
#endif
//deleter for char
template<class T>
class Deleter_for_string{
    public:
    void operator()(T* ptr){
        if(ptr!=nullptr){
            delete [ ] ptr;
        }
    }
};





#ifndef SMART_NODE
#define SMART_NODE 12
template<class T>
struct Node{
    T value;
    shared_ptr<Node<T>> next; // each next is a shared pointer...
 };
 template<class T>
void add_element(shared_ptr<Node<T>>&ptr,const T& value1){
    if(ptr.get()==nullptr){
        ptr.reset(new Node<T>);
        ptr.get()->value=value1;
        return;
    }
    add_element(ptr.get()->next,value1);
    }
    
template<class T>
void print_out_node(const shared_ptr<Node<T>>& ptr){
    shared_ptr<Node<T>> ptr1={ptr};
    while(ptr1.get()!=nullptr){
        if(ptr1.get()->next.get()!=nullptr){
                cout<<ptr1.get()->value<<",";
        }
        else{
            cout<<ptr1.get()->value<<endl;
        }
        ptr1=ptr1.get()->next;
    }
}

#endif
#ifndef SMART_LIST
#define SMART_LIST
template<class T>
class Smart_list{//size of smart list is still the same as the size of the shared_ptr type..
    private:
    shared_ptr<Node<T>> ptr;
    public:
    Smart_list():ptr{}{}
    void Insert(const T& value1){
        add_element(ptr,value1);
    }
  Smart_list(const initializer_list<T>& list){
      auto key=list.begin();
      for(int i=0;i<list.size();i++){
          this->Insert(key[i]);
      }
  }
  shared_ptr<Node<T>> get_head() const{
      return this->ptr;
  }
  void clear(){
     ptr.reset();
  }
  const char* check_null(){
      if(ptr.get()==nullptr){
          const char*g={"it is null"};
          return g;
      }
      const char*h={"it is not null"};
      return h;
  }
  shared_ptr<Node<T>> get_begin(){
      return this->ptr;
  }
  shared_ptr<Node<T>> get_end(){
      shared_ptr<Node<T>> ptr1;
      if(ptr1.get()==nullptr){
          return ptr1;
      }
  }
};
#endif
template<class T>
ostream& operator<<(ostream& os,const Smart_list<T>& ptr){
    shared_ptr<Node<T>> ptr1={ptr.get_head()};
    while(ptr1.get()!=nullptr){
        if(ptr1.get()->next.get()!=nullptr){
                os<<ptr1.get()->value<<",";
        }
        else{
            os<<ptr1.get()->value<<endl;
        }
        ptr1=ptr1.get()->next;
    }
    return os;
}
#ifndef SMART_ITERATOR
#define SMART_ITERATOR
template<class T>
class Smart_iterator{
    public:
    shared_ptr<Node<T>>iter;
    public:
    Smart_iterator():iter{}{}
    Smart_iterator(const shared_ptr<Node<T>>& sptr){
        iter=sptr;
    }
    Smart_iterator& operator=(const shared_ptr<Node<T>>& sptr){
        *this={sptr};
        return *this;
    }
 Smart_iterator& operator++(){
     iter=iter.get()->next;
     return *this;
 }
 const Smart_iterator operator++(int){
     shared_ptr<Node<T>> ptr={iter};
     iter=iter.get()->next;
     return ptr;
 }
        
};
#endif
template<class T>
ostream& operator<<(ostream& os,const Smart_iterator<T>& iter1){
    os<<iter1.iter.get()->value<<endl;
    return os;
}

#ifndef SMART_BUFFER_STRING
#define SMART_BUFFER_STRING 1000000
class Smart_string{
    private:
    shared_ptr<char>ptr;
    size_t ssize;
    public:
    Smart_string():ptr{}{}
    Smart_string(const size_t& sz,const char& c){
        ptr.reset(new char[sz],Deleter_for_string<char>());
       for(int i=0;i<sz;i++){
           ptr.get()[i]=c;
       }
       ssize=sz;
    }
    //sets the size, allocate memory according to size,and initializes the allocated variables with ' '
    void set_size(const size_t& sz){
        if(ptr.get()!=nullptr){
            ptr.reset();
        }
        ptr.reset(new char[sz],Deleter_for_string<char>());
        for(int i=0;i<sz;i++){
            ptr.get()[i]=' ';
        }
        ssize=sz;
    }

   Smart_string(const size_t& sz){
       *this={sz,' '};
  }
  Smart_string(const char* ch){
      size_t sz=strlen(ch);
      ptr.reset(new char[sz],Deleter_for_string<char>());
      for(int i=0;i<sz;i++){
          ptr.get()[i]=ch[i];
      }
      ssize=sz;
  }
  //returns ptr;
  shared_ptr<char> get_first_head() const{
      return ptr;
  }
  
  char& operator [ ](const size_t& idx){
      return ptr.get()[idx];
  }
   char operator [ ](const size_t& idx) const{
      return ptr.get()[idx];
  }
  //for size.........
size_t get_smart_size() const {
    return ssize;
}
Smart_string(const Smart_string& str){
    ptr=str.ptr;
    ssize=str.ssize;
}
void push_char(const char& ch){
    if(ptr.get()==nullptr){
        ptr.reset(new char[1],Deleter_for_string<char>());
        ssize=1;
        ptr.get()[0]=ch;
        return;
    }
   Smart_string str1={*this};
   this->ptr.reset();
   ptr.reset(new char[str1.ssize+1],Deleter_for_string<char>());
   this->ssize=str1.ssize+1;
   for(int i=0;i<str1.get_smart_size();i++){
       ptr.get()[i]=str1[i];
   }
   ptr.get()[str1.ssize]=ch;
   str1.get_first_head().reset();
   str1.ssize=0;
   return;
   
}
Smart_string substring(const size_t& idx) const {
    size_t sz=this->ssize- idx;
    Smart_string str;
    str.set_size(sz);
    for(int i=0;i<sz;i++){
        str[i]=this->ptr.get()[i+idx];
    }
  return str;
}
//it creates a substring starting at idx with len..
Smart_string substring(const size_t& idx,const size_t len) const {
    Smart_string str;
    for(int i=idx;i<len;i++){
        str.push_char(this->get_first_head().get()[i]);
    }
    return str;
}
//overloading the (==) equality operator...
bool operator==(const Smart_string& str) const {
    if(this->get_smart_size()==str.get_smart_size()){
        for(int i=0;i<this->get_smart_size();i++){
            if(this->get_first_head().get()[i]!=str[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

//returns the starting index of a substring within a string..
//The length of the substring must be less than the smart string object.
size_t find_idx(const char*c)  const{
    Smart_string str={c};
    size_t sz=str.get_smart_size(); // returns the length of string of characters.
    size_t sz1=this->get_smart_size()-sz;
    ++sz1;
    for(int i=0;i<sz1;i++){
        if(this->substring(i,sz)==str){
            return i;
        }
    }
    return NOT_FOUND;
}
Smart_string operator+(const Smart_string& str){
    size_t sz=this->get_smart_size()+str.get_smart_size();
    Smart_string str1={sz};
    for(int i=0;i<this->get_smart_size();i++){
        str1[i]=this->ptr.get()[i];
    }
    for(int i=0;i<str.get_smart_size();i++){
        str1[this->get_smart_size()+i]=str[i];
    }
    return str1;
 }
};
//overloading the output operator 
ostream& operator<<(ostream& os,const Smart_string& str){
    for(size_t sz=0;sz<str.get_smart_size();sz++){
        os<<str[sz];
    }
    os<<endl;
    os<<"string size: "<<str.get_smart_size()<<endl;
    return os;
}
 
#endif // smart_string