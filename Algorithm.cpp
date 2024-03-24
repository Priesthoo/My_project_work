#include<iostream>
#include"Vector.h"
//my target is a vector class..
using namespace std;
template<class T>
class Algorithm{
    public:
    static size_t count_n(T* begin,T *end){
        size_t  y=0;
        while(begin!=end){
            ++begin;
            ++y;
        }
        return y;
    }
    static T* min_elem(T* begin,T*end){
        T*  beg=begin;   
        size_t num=Algorithm<T>::count_n(begin,end);
        for(int i=1;i<num;i++){
            if(*(begin+i)<*beg){
                beg=begin+i;
            }
        }
        return beg;
 }
 static T* max_elem(T*begin,T*end){
     T* beg=begin;   
        size_t num=Algorithm<T>::count_n(begin,end);
        for(int i=1;i<num;i++){
            if(*(begin+i)>*beg){
                beg=begin+i;
            }
        }
        return beg;
}
static T* find(T* begin,T* end,const T& value){
    T* beg=NULL;
    size_t num=Algorithm<T>::count_n(begin,end);
    for(int i=0;i<num;i++){
        if(*(begin+i)==value){
            beg=begin+i;
            break;
        }
    }
    return beg;
}
static T*search_n(T*begin,T*end,T*s_begin,T*s_end){
    T*beg=nullptr;
    bool is_value=true;
    size_t num=Algorithm<T>::count_n(begin,end);
    size_t num1=Algorithm<T>::count_n(s_begin,s_end);
     size_t num2=num1-num+1;
     for(int i=0;i<num2;i++){
         if(is_value==true){
             for(int j=0;j<num;j++){
                 if(*(begin+j)!=*(s_begin+i+j)){
                      break;
                 }
                 if(*(begin+j)==*(s_begin+i+j) and j==num-1){
                     is_value=false;
                     beg=begin;
                     break;
                 }
             }
         }
         else{
             break;
         }
     }
   return beg;
}

};
template<class T,class pred>
class Algorithm_if{
    public:
    static  size_t  count_if(T* begin,T* end,pred op){
      size_t j=Algorithm<T>::count_n(begin,end);
      size_t y=0;
      for(int i=0;i<j;i++){
          if(op(*(begin+i))==true){
              ++y;
          }
      }
      return y;
    }
    static T*find_if(T*begin,T*end,pred op){
        T*beg=nullptr;
        size_t j=Algorithm<T>::count_n(begin,end);
        for(int i=0;i<j;i++){
            if(op(*(begin+i))==true){
                beg=(begin+i);
                break;
         }
        }
        return beg;
    }
  static T* find_if_not(T*begin,T*end,pred op){
        T*beg=nullptr;
        size_t h=Algorithm<T>::count_n(begin,end);
        for(int i=0;i<h;i++){
            if(op(*(begin+i))==false){
                beg=(begin+i);
                break;
            }
        }
        return beg;
    }
   
};
bool greater_than_13(const int& ref){
    if(ref>13){
        return true;
    }
    else{
        return false;
    }
}
bool less_than_12(const int& ref){
    if(ref<12){
        return true;
    }
    else{
        return false;
    }
}
