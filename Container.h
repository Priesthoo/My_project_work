 #ifndef ALL_CONTAINER_H
#define ALL_CONTAINER_H

#ifndef VECTOR_H
#define VECTOR_H
#include<vector>
#endif //for vector 

#ifndef TYPE_CASTING
#define TYPE_CASTING
#define Type_cast_(T,v) ((T)v)
#endif // type casting 

#ifndef POINTER_CAST
#define POINTER_CAST
#define Pointer_cast_(T,v) ((T*)v)
#endif //for pointer cast

#ifndef DEQUE_H
#define DEQUE_H
#include<deque>
#endif 

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
#include<forward_list>
#endif //for linked list

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include<list>
#endif // double linked list 

#ifndef SET_H
#define SET_H
#include<set>
#endif //Set

#ifndef MAP_H
#define MAP_H
#include<map>
#endif  //map

#ifndef UNORDERED_CONTAINER
#define UNORDERED_CONTAINER
#ifndef UNORDERED_SET_H
#define UNORDERED_SET_H
#include<unordered_set>
#endif  // unordered set
#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H
#include<unordered_map>
#endif  //unordered map
#endif  //unordered container

#ifndef UNALLLOCATED_CHAR_MEMORY
#define UNALLOCATED_CHAR_MEMORY
#include<string_view>
#endif //for string view....

#ifndef ALLOCATED_CHAR_MEMORY
#define ALLOCATED_CHAR_MEMORY
#include<string>
#endif //for string....

#ifndef ALL_ITERATOR_IN_CPP
#define ALL_ITERATOR_IN_CPP
#include<iterator>
#endif // for all iterators

enum class COLLECTION:int {
    DATA_STREAMS=0x07,
    FORWARD_LIST=0x08,
    LIST=0x0A,
    MAP,
    MULTI_MAP,
    MULTI_SET,
    UNORDERED_MAP,
    UNORDERED_SET,
    DEQUE,
    VECTOR,
    ARRAY
};


template<class T,class U>
constexpr T Type_cast(const U other_type){
      T data=Type_cast_(T,other_type);
      return data;
}

template<class T,class U=void>
constexpr T* Pointer_cast(const U* other_type){
    T* data=Pointer_cast_(T,other_type);
    return data;
}

#ifndef CHAR
#define CHAR
#include"char_collection.h"
#endif //char collection..








enum class ITERATOR:int{
    INPUT_ITERATOR=(int)COLLECTION::DATA_STREAMS,
    OUTPUT_ITERATOR=Type_cast<int>(COLLECTION::DATA_STREAMS),
    FORWARD_ITERATOR,
    BIDIRECTIONAL_ITERATOR,
    RANDOM_ACCESS_ITERATOR
};

#endif //all containers




