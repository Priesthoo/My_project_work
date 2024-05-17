#include<iostream>
using namespace std;
#include<string>
#include<vector>
#ifndef CHAR_CONVERT
#define CHAR_CONVERT  32
#endif
#ifndef null 
#define null nullptr
#endif
//the distance between the upper case letter and the lower case letter in the ascii table is 32...
//we are here to implement our 4 basic function.
//A,E,I,O,U..
//a,e,i,o,u..
char to_upper_case(const char val){
    char c;
    if(val>='a' and val<='z'){
        int v=(int)val-CHAR_CONVERT;
        c=(char)v;
        return c;
    }
    c=val;
    return c;
 }
char to_lower_case(const char val){
    char c;
    if(val>='A' and val<='Z'){
        int v=(int)val+CHAR_CONVERT;
        c=(char)v;
        return c;
    }
    c=val;
    return c;
}
bool is_lower_case(const char c){
    if(c>='a' and c<='z'){
        return true;
    }
    return false;
}
bool is_upper_case(const char c){
    if(c>='A' and c<='Z'){
        return true;
    }
    return false;
}
size_t vowel_cnt(const char c){
    const char*v={"aeiou"};
    const char*v2={"AEIOU"};
    size_t sz=1;
   for(int i=0;i<5;++i){
       if(c==v[i]){
           return sz;
       }
       else if(c==v2[i]){
           return sz;
       }
   }
   return (size_t)0;
}
int consonant_cnt(const char c){
  const char*alphabet={"BCDFGHJKLMNPQRSTVWXYZ"};
  char* small=new char[21];
  for(int i=0;i<21;i++){
      small[i]=(char)(CHAR_CONVERT +(int)alphabet[i]);
  }
      int  sz=1;
    if((int)c>=0 and (int)c<=64){
           return 0;
       }
     else if( (int)c>=91 and (int)c<=96 ){
         return 0;
     }
     else if((int)c>=123){
         return 0;
     }
   for(int i=0;i<21;++i){
         if(c==small[i]){
           return sz;
         }
         else if(c==alphabet[i]){
             return sz;
         }
   }
   return 0;
}
int get_consonant_cnt(const char* c){
    int  sz=0;
    for(int i=0;i<strlen(c);++i){
        sz+=consonant_cnt(c[i]);
    }
    return sz;
}
int get_vowel_cnt(const char* c){
    int sz=0;
    for(int i=0;i<strlen(c);++i){
        sz+=vowel_cnt(c[i]);
    }
    return sz;
}
const char* few_consonant(const vector<const char*> few){
    const char* few_con;
    for(int i=1;i<few.size();i++){
        if(get_consonant_cnt(few[i-1])<get_consonant_cnt(few[i])){
            few_con=few[i-1];
        }
    }
    if(get_consonant_cnt(few[few.size()-1])<get_consonant_cnt(few_con)){
        few_con=few[few.size()-1];
    }
    return few_con;
 }
const char* few_vowel(const vector<const char*>few){
    const char* few_con;
    for(int i=1;i<few.size();i++){
        if(get_vowel_cnt(few[i-1])<get_vowel_cnt(few[i])){
            few_con=few[i-1];
        }
    }
    if(get_vowel_cnt(few[few.size()-1])<get_vowel_cnt(few_con)){
        few_con=few[few.size()-1];
    }
    return few_con;
    
}