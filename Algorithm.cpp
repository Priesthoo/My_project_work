#include<iostream>
#include"Vector.h"
#include<utility>
//my target is a vector class..
using namespace std;
template<class T>
class Negate{
    public:
    T operator()(const T& ref){
        T result=-ref;
        return result;
    }
};
template<class T>
class Plus{
    public:
    T operator()(const T& ref1,const T&  ref2){
        T result=ref1+ref2;
        return result;
    }
};
template<class T>
class Minus{
    public:
    T operator()(const T& ref,const T& ref2){
        T result=ref-ref2;
        return result;
    }
};
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
static T*search(T*begin,T*end,T*s_begin,T*s_end){
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
static T*find_first_of(T*begin,T*end,T*s_begin,T*s_end){
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
                     beg=(s_begin+i);
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
static T*adjacency_find(T*beg,T*end){
    T*b=nullptr;
    size_t num=Algorithm<T>::count_n(beg,end);
    size_t num1=num-2;
    for(int i=0;i<num1+1;i++){
        if(*(beg+i)==*(beg+i+1)){
            b=beg+i;
            break;
        }
    }
    return b;
}
static bool is_equal(T*begin,T*end,T*cmp){
    size_t num=Algorithm<T>::count_n(begin,end);
    bool is_value=false;
    for(int i=0;i<num;i++){
        if(*(begin+i)==*(cmp+i) and i==num-1){
            is_value=true;
        }
        else{
            is_value=false;
            break;
        }
    }
    return is_value;
}
static bool is_sorted(T*begin,T*end){
    size_t sz=Algorithm<T>::count_n(begin,end);
    bool is_true=false;
    for(int i=1;i<sz;i++){
        if(*(begin+i-1)<*(begin+i) and i==sz-1){
            is_true=true;
        }
        else if(*(begin+i-1)>*(begin+i)){
            is_true=false;
            break;
        }
   }
    return is_true;
}
static pair<T*,T*> mismatch(T*begin,T*end,T*cmp){
    size_t sz=Algorithm<T>::count_n(begin,end);
    pair<T*,T*> m;
    for(int i=0;i<sz;i++){
        if(*(begin+i)!=*(cmp+i)){
            m.first=begin+i;
            m.second=cmp+i;
            break;
        }
    }
    return m;
}
static T*copy(T*begin,T*end,T*dest){
    size_t sz=Algorithm<T>::count_n(begin,end);
    for(int i=0;i<sz;i++){
        *(dest+i)=*(begin+i);
    }
    auto iter=dest+sz;
    return iter;
}
static void swap_elements(T*begin,T*end){
    size_t sz=Algorithm<T>::count_n(begin,end);
    for(int i=1;i<sz;i++){
        T result=*(begin+i-1);
        *(begin+i-1)=*(begin+i);
        *(begin+i)=result;
    }
}
static T* swap_range(T*begin,T*end,T*beg){
    size_t sz=Algorithm<T>::count_n(begin,end);
    for(int i=0;i<sz;i++){
        T result=*(begin+i);
        *(begin+i)=*(beg+i);
        *(beg+i)=result;
    }
    auto iter=beg+(sz-1);
    return iter;
}
static void fill(T*begin,T*end,const T& val){// To fill the range [beg,end) with val.
    size_t sz=Algorithm<T>::count_n(begin,end);
    for(int i=0;i<sz;i++){
        *(begin+i)=val;
    }
}
static void sort_range(T*begin,T*end){//sort the range[beg,end)
    size_t sz=Algorithm<T>::count_n(begin,end);
    bool is_true=false;
    while(is_true!=true){
        for(int i=1;i<sz;i++){
            if(*(begin+i)<*(begin+i-1)){
                T result=*(begin+i-1);
                *(begin+i-1)=*(begin+i);
                *(begin+i)=result;
            }
        }
        is_true=Algorithm<T>::is_sorted(begin,end);
      }
  }
}; //End of algorithm<T>
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
    static T*search(T*begin,T*end,T*s_begin,T*s_end,pred op){
    T*beg=nullptr;
    bool is_value=true;
    size_t num=Algorithm<T>::count_n(begin,end);
    size_t num1=Algorithm<T>::count_n(s_begin,s_end);
     size_t num2=num1-num+1;
     for(int i=0;i<num2;i++){
         if(is_value==true){
             for(int j=0;j<num;j++){
                 if(op((*(begin+j),*(s_begin+i+j)))!=false){
                      break;
                 }
                 if(op(*(begin+j),*(s_begin+i+j))==true and j==num-1){
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
 static T*find_first_of(T*begin,T*end,T*s_begin,T*s_end,pred op){
    T*beg=nullptr;
    bool is_value=true;
    size_t num=Algorithm<T>::count_n(begin,end);
    size_t num1=Algorithm<T>::count_n(s_begin,s_end);
     size_t num2=num1-num+1;
     for(int i=0;i<num2;i++){
         if(is_value==true){
             for(int j=0;j<num;j++){
                 if(op((*(begin+j),*(s_begin+i+j)))!=false){
                      break;
                 }
                 if(op(*(begin+j),*(s_begin+i+j))==true and j==num-1){
                     is_value=false;
                     beg=s_begin+i;
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
static T*adjacency_find_if(T*beg,T*end,pred op){
    T*b=nullptr;
    size_t num=Algorithm<T>::count_n(beg,end);
    size_t num1=num-2;
    for(int i=0;i<num1+1;i++){
        if(op(*(beg+i),*(beg+i+1))==true){
            b=beg+i;
            break;
        }
    }
    return b;
}
static bool is_equal_if(T*begin,T*end,T*cmp,pred op){
    size_t num=Algorithm<T>::count_n(begin,end);
    bool is_value=false;
    for(int i=0;i<num;i++){
        if(op(*(begin+i),*(cmp+i))==true and i==num-1){
            is_value=true;
        }
        else{
            is_value=false;
            break;
        }
    }
    return is_value;
}
static bool is_sorted_if(T*begin,T*end,pred op){
    size_t sz=Algorithm<T>::count_n(begin,end);
    bool is_true;
    for(int i=1;i<sz;i++){
        if(op(*(begin+i-1),*(begin+i))==true and i==sz-1){
            is_true=true;
        }
        else if(op(*(begin+i-1),*(begin+i))==false){
            is_true=false;
            break;
        }
    }
    return is_true;
}
static pair<T*,T*> mismatch_if(T*begin,T*end,T*cmp,pred op){
    size_t sz=Algorithm<T>::count_n(begin,end);
    pair<T*,T*> m;
    for(int i=0;i<sz;i++){
        if(op(*(begin+i),*(cmp+i))==false){
            m.first=begin+i;
            m.second=cmp+i;
            break;
        }
    }
    return m;
}
static bool all_of(T*begin,T*end,pred op){
    size_t sz=Algorithm<T>::count_n(begin,end);
    bool is_true;
    for(int i=0;i<sz;i++){
        if(op(*(begin+i))==true and i==sz-1){
            is_true=true;
        }
        else{
            is_true=false;
            break;
        }
     }
     return is_true;
}
static bool any_of(T*begin,T*end,pred op){
    size_t sz=Algorithm<T>::count_n(begin,end);
    bool is_true=false;
    for(int i=0;i<sz;i++){
        if(op(*(begin+i))==true){
            is_true=true;
        }
  }
  return is_true;
}
bool none_of(T*begin,T*end,pred op){
    size_t sz=Algorithm<T>::count_n(begin,end);
    bool is_true=false;
    for(int i=0;i<sz;i++){
        if(op(*(begin+i))==false and i==sz-1){
            is_true=true;
        }
        else{
            is_true=false;
            break;
        }
    }
    return is_true;
}
static T* copy_if(T*begin,T*end,T*dest,pred op){
    size_t sz=Algorithm<T>::count_n(begin,end);
    size_t y;
    for(int i=0;i<sz;i++){
        if(op(*(begin+i))==true){
            *(dest+i)=*(begin+i);
            ++y;
        }
    }
    auto iter=dest+y;
    return iter;
}
static T* Transform_range1(T*begin,T*end,T*dest,pred op){
    size_t sz=Algorithm<T>::count_n(begin,end);
    T result;
    for(int i=0;i<sz;i++){
        result=op(*begin+i);
        *(dest+i)=result;
    }
    auto iter=dest+sz;
    return iter;
}
static T* Transform_range2(T*begin,T*end,T*begin1,T*dest,pred op){
    size_t sz=Algorithm<T>::count_n(begin,end);
    for(int i=0;i<sz;i++){
        T result=op(*(begin+i),*(begin1+i));
        *(dest+i)=result;
    }
    auto iter=dest+sz;
    return iter;
}
static void sort_range_if(T*begin,T*end,pred op){
    size_t sz=Algorithm<T>::count_n(begin,end);
    bool is_true=false;
    while(is_true!=true){
        for(int i=1;i<sz;i++){
            if(op(*(begin+i-1,*(begin+i)))==false){
                   T result=*(begin+i-1);
                *(begin+i-1)=*(begin+i);
                *(begin+i)=result;
            }
        }
        is_true=Algorithm_if<T,pred>::is_sorted_if(begin,end,op);
    }
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
int main(int argc, char *argv[])
{
   using Comp=bool(*)(const int& ref);
	Comp func=greater_than_13;
	Vector<int>vec={1,2,1,3,5,4,7,6};
	Vector<int>vec1;
	vec1.set_size(vec.get_length());
     Algorithm_if<int,Negate<int>>::Transform_range1(vec.begin(),vec.end(),vec1.begin(),Negate<int>());
     vec1.print_out();
}