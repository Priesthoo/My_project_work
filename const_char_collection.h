#include<iostream>
#ifndef CHAR_COLLECTION
#define CHAR_COLLECTION 0
#endif
#define CCTYPE
#ifdef CCTYPE 
#include<cctype>// for strcpy(),strlen()...
#endif
#define null ((void*)0)
#define _PROTOTYPE(name,params) name##params
#define CSTRING
#ifdef CSTRING
#include<cstring>
#endif
#define MAX 4294967295

/*
    Writing for both pointer to const char type , pointer to a char type. 
 This is a container class for C c style character array.
 for memory allocation,I will have to use new keyword for allocation,delete keyword for deallocation

*/
using namespace std;
namespace C{
const char* get_memory(){
  const char*c={"Glory to the most high"};
    return c;
    }
const char* init(const char*c){
    const char*f=c;
    return f;
}
//for initializing a variable of const char* with a variable of char*
const char*init(char*c){
    return c;
}
//for initializing a variable of const char*
const char*init(const char* ch,int idx){
    int len=strlen(ch)-idx;
    char*c=new char[len];
    for(int i=0;i<len;i++){
        c[i]=ch[idx+i];
    }
    return c;
}
//initialize a variable of const char* with another  variable of const char starting with index idx with length len.
const char* init(const char*c,int idx,int len){
    if(len>strlen(c)){
        return nullptr;
    }
    char*ch=new char[len];
    for(int i=0;i<len;i++){
        ch[i]=c[idx+i];
    }
    return ch;
}
//it returns a pointer to the first element of the C style array 
const char*begin(const char*c){
    return &c[0];
}//it returns a pointer to the one past last element of the C style aaray.
const char*end(const char*c){
    const int len=strlen(c);
    return &c[len];
}
//it returns a reference to the first element 
const char& front(const char*c){
    return c[0];
}
//it returns a reference to the last element
const char& back(const char*c){
    const int len=strlen(c);
    return c[len-1];
}
//it returns an object that is initialized with variable of const char* starting with index idx
const char* substring(const char* ch,int idx){
    const char* ch1=init(ch,idx);
    return ch1;
}
//it returns an object that is initialized with a variable of const char* starting with index idx to length len
const char*substring(const char*ch,int idx,int len){
    const char*ch1=init(ch,idx,len);
    return ch1;
}
//it returns a modified variable of const char*(it adds the value of variable c to the end of ch of const char* type)
const char* push_back(const char* ch,const char c){
    int len=strlen(ch);
    char*ch1=new char[len+1];
    for(int i=0;i<len+1;++i){
        ch1[i]=ch[i];
    }
    ch1[len]=c;
   return ch1;
}
const char* append(const char* ch,const char c){
    const char* ch1=push_back(ch,c);
    return ch1;
}
const char* insert_before(const char*c,int idx,const char j){
    char *ch=new char[strlen(c)+1];
    for(int i=0;i<idx;i++){
        ch[i]=c[i];
    }
    ch[idx]=j;
    int len=strlen(c)+1;
    int len1=len-idx;
    for(int i=0;i<len1;++i){
        ch[idx+i+1]=c[idx+i];
    }
    return ch;
}

const char*insert(const char*c,int idx,const char k){
    char*ch=new char[strlen(c)+1];
    int n=strlen(c)+1;
    int i=0;
    int j=0;
    while(i<strlen(c) and j<n){
        if(j==idx+1){
            ch[j]=k;
            j+=1;
            continue;
        }
        ch[j]=c[i];
        ++j;
        ++i;
    }
    return ch;
}
const char*insert_at_idx(const char*c,int idx,const char ch1){
    char*ch=new char[strlen(c)];
    int len=strlen(c);
    for(int i=0;i<len;++i){
        if(i==idx){
            ch[i]=ch1;
            continue;
        }
        ch[i]=c[i];
    }
    return ch;
}
const char*insert_after(const char*c,int idx,const char*ch1){
    char*ch=new char[strlen(c)+strlen(ch1)];
    int len=strlen(c);
    int len1=strlen(c)+strlen(ch1);
    int i=0;
    int j=0;
    while(i<len and j<len1){
        if(j==idx+1){
            j=idx+1+strlen(ch1);
            for(int k=0;k<strlen(ch1);k++){
                ch[idx+1+k]=ch1[k];
            }
        }
        ch[j]=c[i];
        ++i;
        ++j;
    }
    return ch;
}
const char*insert_at_idx(const char*c,int idx,const char*ch1){
    char*ch=new char[strlen(c)+strlen(ch1)-1];
    int len=strlen(c);
    int len1=strlen(c)+strlen(ch1)-1;
    int i=0;
    int j=0;
    while(i<len and j<len1){
        if(j==idx){
            j=idx+strlen(ch1);
            i+=1;
            for(int k=0;k<strlen(ch1);k++){
                ch[idx+k]=ch1[k];
            }
        }
        ch[j]=c[i];
        ++i;
        ++j;
    }
    return ch;
}
const char*insert_before_idx(const char*c,int idx,const char*ch1){
    char*ch=new char[strlen(c)+strlen(ch1)];
    int len=strlen(c);
    int len1=strlen(c)+strlen(ch1);
    int i=0;
    int j=0;
    while(i<len and j<len1){
        if(j==idx){
            j=idx+strlen(ch1);
            for(int k=0;k<strlen(ch1);k++){
                ch[k+idx]=ch1[k];
            }
        }
        ch[j]=c[i];
        ++i;
        ++j;
    }
    return ch;
}
const char*insert_after(const char*c,int idx,int len,const char*ch1,int idx1){
    char*ch=new char[strlen(c)+len];
    int len1=strlen(c);
    int len2=strlen(c)+len;
    int i=0;
    int j=0;
    while(i<len1 and j<len2){
        if(j==idx+1){
            j=idx+1+len;
            for(int k=0;k<len;k++){
                ch[idx+1+k]=ch1[idx1+k];
            }
        }
        ch[j]=c[i];
        ++i;
        ++j;
    }
    return ch;
}
const char*pop_back(const char*c){
    char*ch=new char[strlen(c)-1];
    int i=0;
    while(i<(strlen(c)-1)){
        ch[i]=c[i];
        ++i;
    }
    return ch;
}
const char*insert_at_idx(const char*c,int len,int idx,const char*ch1,int idx2){
    char*ch=new char[strlen(c)+len-1];
    int len1=strlen(c);
    int len2=strlen(c)+strlen(ch1)-1;
    int i=0;
    int j=0;
    while(i<len1 and j<len2){
        if(j==idx){
            j=idx+len;
            i+=1;
            for(int k=0;k<len;k++){
                ch[idx+k]=ch1[k+idx2];
            }
        }
        ch[j]=c[i];
        ++i;
        ++j;
    }
    return ch;
 }
 const char* insert_before(const char*c,int idx,int len, const char*ch1,int idx2){
     char*ch=new char[strlen(c)+len];
    int len1=strlen(c);
    int len2=strlen(c)+len;
    int i=0;
    int j=0;
    while(i<len1 and j<len2){
        if(j==idx){
            j=idx+len;
            for(int k=0;k<strlen(ch1);k++){
                ch[k+idx]=ch1[k+idx2];
            }
        }
        ch[j]=c[i];
        ++i;
        ++j;
    }
    return ch;
     
 }
 bool is_equal(const char*c,const char*ch1){
     if(strcmp(c,ch1)==0){
         return true;
     }
     return false;
 }
 const char*replace(const char*c,int idx,const char c1){
     char*ch=new char[strlen(c)];
     int len=strlen(c);
     unsigned int i=0;
     while(i<len){
         if(i==idx){
             ch[i]=c1;
             i++;
             continue;
         }
         ch[i]=c[i];
         i++;
     }
     return ch;
 }
 const char*replace(const char*c,int idx,int len,const char*c1){
     char*ch=new char[strlen(c)];
     int len1=strlen(c);
     unsigned int i=0;
     while(i<len1){
         if(i==idx){
             i=idx+len;
             for(int j=0;j<len;j++){
                 ch[idx+j]=c1[j];
             }
         }
         ch[i]=c[i];
         i++;
     }
     return ch;
 }
 const char*replace(const char*c,int idx,int len,const char*c1,int idx2){
     char*ch=new char[strlen(c)];
     int len1=strlen(c);
     unsigned int i=0;
     while(i<len1){
         if(i==idx){
             i=idx+len;
             for(int k=0;k<len;k++){
                 ch[idx+k]=c1[idx2+k];
             }
         }
         ch[i]=c[i];
         ++i;
     }
     return ch;
 }
unsigned int find_char(const char*c,const char c1){
    for(int i=0;i<strlen(c);i++){
        if(c[i]==c1){
            return i;
        }
    }
    return MAX;
}
unsigned int find_char(const char*c,int idx,const char c1){
    for(int i=idx;i<strlen(c);i++){
        if(c[i]==c1){
            return i;
        }
    }
    return MAX;
}
unsigned int find_substring(const char*c,const char*c1){
    int len=strlen(c);
    int len1=strlen(c1);
    int len2=len-len1;
    ++len2;
    for(unsigned int i=0;i<len2;++i){
      const char*ch=init(c,i,len);
      if(C::is_equal(ch,c1)){
          return i;
      }
    }
    return MAX;
}
}
