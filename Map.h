#include<iostream>
#include<string>


using namespace std;
template<class T, class M>
struct  Pair{
    T first;
    M second;
    Pair()=default;
    Pair(T f, M sec){
        first=f;
        second=sec;
    }
M& operator[ ](const T key) const{
    if(key==first){
        return second;
    }
 }
 M& operator[ ](const T key){
     if(key==first){
         return second;
     }
 }
 
    
};
template<class T,class M>
struct Node{
    Pair<T,M> value;
    Node<T,M> *next;
    Node():value{},next{nullptr}{}
};

template<class T,class M>
class Map{
};