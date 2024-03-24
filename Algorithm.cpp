#include<iostream>
#include"Vector.h"
//my target is a vector class...
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
};
bool greater_than_13(const int& ref){
    if(ref>13){
        return true;
    }
    else{
        return false;
    }
}