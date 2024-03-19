#include<iostream>
#include<string>
#include<initializer_list>
using namespace std;
template<class T>
class Vector{
  private:
  T* str;
  size_t size;
  public:
  typedef T* iterator;
     typedef const T* const_iterator;
     typedef unsigned int size_c;
     typedef T& reference;
     typedef const T& const_reference;
  size_t get_length(){
      return (*this).size;
  }
  size_t get_length() const{
      return size;
  }
  static int get_length_from_pos(iterator iter1,iterator iter2) {
        int y=0;
        while(iter1!=iter2){
            ++iter1;
            ++y;
        }
        return y;
    }
    
  Vector(initializer_list<T> val){
      size=val.size();
      str=new T[size];
      auto iter1=val.begin();
       for(int i=0;i<size;i++){
           str[i]=iter1[i];
       }
  }
     Vector():str{nullptr},size{0}{}
    Vector(const Vector& ref){
        size_t m=ref.get_length();
        str=new T[m];
        for(int i=0;i<m;i++){
            str[i]=ref.str[i];
        }
        size=m;
    }
    Vector(size_t sz,const T& val){
          size_t m=sz;
        str=new T[m];
        for(int i=0;i<m;i++){
            str[i]=val;
        }
        size=m;
    }
    //assignment 
    Vector& operator=(const Vector& vec){
        size=vec.get_length();
        str=new T[size];
        for(int i=0;i<size;i++){
            str[i]=vec.str[i];
    }
    return *this;
    }
    void assign(size_t n,const T& elem){
        str=new T[n];
        size=n;
        for(int i=0;i<n;i++){
            str[i]=n;
        }
    }
    void assign( const initializer_list<T>& val){
        int y=val.size();
        auto key=val.begin();
        str=new T[y];
        for(int i=0;i<y;i++){
            str[i]=*(key+i);
        }
        size=y;
    }
    void assign(iterator begin,iterator end){
        int y=Vector<T>::get_length_from_pos(begin,end);
        str=new T[y];
        size=y;
        for(int i=0;i<size;i++){
            str[i]=*(begin+i);
        }
    }
    void swap(const Vector<T>& vec){
        Vector<T> help=vec;
        Vector<T> help2=*this;
        *this=help;
        vec=help2;
    }
    //done with assignment
    //we enter element access
    reference operator[ ](const size_t& idx){
        if(idx<(*this).get_length() and idx>=0){
            return str[idx];
        }
    }
    reference operator[ ](const size_t& idx) const{
        if(idx<(*this).get_length() and idx>=0){
            return str[idx];
        }
    }
    reference front(){
        return str[0];
    }
    reference back(){
        return str[size-1];
    }
    //we move to iterator(a type used to access a position of an element within a container)
    iterator begin(){
        return &str[0];
    }
    iterator begin() const{
        return &str[0];
    }
    iterator end(){
        return &str[size];
    }
        iterator end() const{
            return &str[size];
    }
    const_iterator cbegin(){
        return &str[0];
    }
    const_iterator cend(){
        return &str[size];
    }
    //we move to inserting elements 
    void push_back(const T& elem){
        Vector<T> vec=*this;
        ++size;
        str=new T[size];
        for(int i=0;i<size;i++){
            str[i]=vec.str[i];
        }
        str[size-1]=elem;
    }
    void pop_back(){
        Vector<T> vec=*this;
        --size;
        str=new T[size];
        for(int i=0;i<size;i++){
            str[i]=vec.str[i];
        }
    }
   iterator insert(iterator pos,const T& elem){
       Vector<T> vec=*this;
       iterator pos1=(*this).begin();
       int y=Vector<T>::get_length_from_pos(pos1,pos);
       ++size;
       str=new T[size];
       for(int i=0;i<y;i++){
           str[i]=vec.str[i];
       }
       str[y]=elem;
       for(int i=y;i<(*this).get_length();i++){
           str[y+1]=vec.str[y];
       }
       iterator iter1=(*this).begin()+y;
       return iter1;
   }
   iterator insert(iterator pos,size_t n,const T& elem){
        Vector<T> vec=*this;
         int len1=this->size+n;
         int y=Vector<T>::get_length_from_pos((*this).begin(),pos);
         size=len1;
         str=new T[size];
         for(int i=0;i<y;i++){
             str[i]=vec.str[i];
         }
         for(int i=y;i<(y+n);i++){
             str[i]=elem;
         }
         int len2=(y+n);
         int len3=size-len2;
         for(int i=0;i<len3;i++){
             str[len2+i]=vec.str[y+i];
         }
         iterator iter1=(*this).begin()+y;
         return iter1;
   }
  iterator insert(iterator pos, iterator begin, iterator end){
      Vector<T> vec=*this;
      int y=Vector::get_length_from_pos(begin,end);
      int f=Vector::get_length_from_pos((*this).begin(),pos);
      int len1=size+y;
      size=len1;
      str=new T[size];
      for(int i=0;i<f;i++){
          str[i]=vec.str[i];
      }
      for(int i=0;i<y;i++){
          str[f+i]=*(begin+i);
      }
      int len2=f+y;
      int len3=size-len2;
      for(int i=0;i<len3;i++){
          str[len2+i]=vec.str[f+i];
      }
      iterator iter1=(*this).begin()+f;
      return iter1;
  }
    
};