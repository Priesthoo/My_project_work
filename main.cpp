#include<iostream>
using namespace std;
#include<string>
#include<vector>
#define power pow
#ifndef CHAR_CONVERT
#define CHAR_CONVERT  32
#endif
#ifndef null 
#define null nullptr
#endif
#define SSTREAM
#ifdef SSTREAM
#include<sstream>
#endif
#define STRING
#ifdef STRING
#include<string>
#endif
#define MATH_INCLUDE
#ifdef MATH_INCUDE
#include<cmath>
#endif
#ifndef INT_MAX 
#define INT_MAX 2147483648
#endif
#ifndef INT_MIN 
#define INT_MIN -2147483647
#endif
#ifndef S_SHORT_MAX
#define S_SHORT_MAX 32767
#endif
#ifndef S_SHORT_MIN
#define S_SHORT MIN -32768
#endif
#ifndef SHORT_MAX 
#define SHORT_MAX 65535
#endif
#ifndef SHORT_MIN 
#define SHORT_MIN 0
#endif
#ifndef U_INT_MAX
#define U_INT_MAX 4294967295
#endif
#ifndef U_INT_MIN
#define U_INT_MIN 0
#endif
#ifndef LONG_INT_MAX 
#define LONG_INT_MAX  power(2,63)-1
#endif
#ifndef LONG_INT_MIN
#define LONG_INT_MIN  -power(2,63)
#endif
#ifndef U_LONG_LONG_INT_MAX
#define U_LONG_LONG_INT_MAX 18446744073709551
#endif 
#ifndef U_LONG_LONG_INT_MIN 
#define U_LONG_LONG_INT_MIN 0
#endif
#ifndef S_CHAR_MAX
#define S_CHAR_MAX 127
#endif
#ifndef S_CHAR_MIN
#define S_CHAR_MIN -128
#endif
#ifndef U_CHAR_MAX 
#define U_CHAR_MAX 255
#endif
#ifndef U_CHAR_MIN
#define U_CHAR_MIN 0
#endif
#ifndef FLOAT_MAX 
#define FLOAT_MAX 3.4*power(10,38)
#endif
#ifndef FLOAT_MIN
#define FLOAT_MIN -3.4*power(10,38)
#endif
#ifndef DOUBLE_MAX
#define DOUBLE_MAX 1.7*power(10,308)
#endif
#ifndef DOUBLE_MIN
#define DOUBLE_MIN -1.7*power(10,308)
#endif
#ifndef LONG_DOUBLE_MAX 
#define LONG_DOUBLE_MAX 1.1*power(10,4932)
#endif
#ifndef LONG_DOUBLE_MIN 
#define LONG_DOUBLE_MIN -1.1*power(10,4932)
#endif

//the distance between the upper case letter and the lower case letter in the ascii table is 32...
//we are here to implement our 4 basic function.
//A,E,I,O,U..
//a,e,i,o,u..
/*
max value of short int 32,767
min value of short int -32,768
max value of short 65,535
min value of short 0
max value of unsigned  int 4,294,967,295
min value of unsigned int 0
max value of int 2,147,483,647
min value of int 2,147,483,648
max value of long int( same as int)
long long max and min :-2^63 to 2^63-1
unsigned long long max:18,446,744,073,709,551
min of long long:0
max of signed char:127
min of   signed char:-128
max of unsigned char:255
min of unsigned char:0
max and min of float: -3.4*10^38 to 3.4*10^38
max and min of double:-1.7*10^308 to  1.7*10^308
max and min of  long double:-1.1*10^4932  to  1.1*10^4932

*/
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
const char* More_consonant(const vector<const char*> more){
    const char* few_con;
    for(int i=1;i<more.size();i++){
        if(get_consonant_cnt(more[i-1])>get_consonant_cnt(more[i])){
            few_con=more[i-1];
        }
    }
    if(get_consonant_cnt(more[more.size()-1])>get_consonant_cnt(few_con)){
        few_con=more[more.size()-1];
    }
    return few_con;
}
const char* More_vowel(const vector<const char*>more){
    const char* few_con;
    for(int i=1;i<more.size();i++){
        if(get_vowel_cnt(more[i-1])>get_vowel_cnt(more[i])){
            few_con=more[i-1];
        }
    }
    if(get_vowel_cnt(more[more.size()-1])>get_vowel_cnt(few_con)){
        few_con=more[more.size()-1];
    }
    return few_con;
    
}
bool is_consonant(const char&  c){
    int sz=0;
    sz=consonant_cnt(c);
    if(sz==1){
        return true;
    }
    else if(sz==0){
        return false;
    }
}
bool is_vowel(const char& c){
    int sz=0;
    sz=vowel_cnt(c);
    if(sz==1){
        return true;
    }
    else if(sz==0){
        return false;
    }
}
bool is_alphanumeric(const char& c){
    if((int)c>=65 and (int)c<=90){
        return true;
    }
    else if((int)c>=97 and (int)c<=122){
        return true;
    }
    else if((int)c>=48 and (int)c<=57){
        return true;
    }
    return false;
}
bool is_space(const char& c){
    if((int)c==32){
         return true;
    }
    return false;
}
bool is_digit(const char& c){
    if((int)c>=48 and (int)c<=57){
        return true;
    }
    return false;
}
bool is_ctrl(const char& c){
    if((int)c>=0 and(int)c<=31){
        return true;
    }
    return false;
}
unsigned int string_to_unsigned_int(const string& str){
    stringstream ss;
    unsigned int num;
    ss<<str;
    ss>>num;
    return num;
}
int string_to_int(const string& str){
    stringstream ss;
    int num;
    ss<<str;
    ss>>num;
    return num;
}
long long string_to_long_long(const string& str){
    stringstream ss;
    long long num;
    ss<<str;
    ss>>num;
    return num;
}
unsigned long long string_to_unsigned_long_long(const string& str){
    stringstream ss;
    unsigned long long num;
    ss<<str;
    ss>>num;
    return num;
}
short string_to_short(const string& str){
    stringstream ss;
    short num;
    ss<<str;
    ss>>num;
    return num;
}
float string_to_float(const string& str){
    stringstream ss;
    float num;
    ss<<str;
    ss>>num;
    return num;
}
double string_to_double(const string& str){
    stringstream ss;
    double num;
    ss<<str;
    ss>>num;
    return num;
}
template<class T>
string value_to_string(const T& value){
    stringstream os;
    os<<value;
    string num=os.str();
    return num;
}
bool string_to_bool(const string& str){
    if(str=="true" or str=="TRUE" or str=="True"){
        return true;
    }
    else if(str=="false" or str=="FALSE" or str=="False"){
        return false;
    }
}
string Reverse_string(const string& str){
    string rstr={" ",str.size()};
    int i=0;
    int z=str.size()-1;
    while(i<str.size() and z>=0){
        rstr[i]=str[z];
        ++i;
        --z;
    }
    return rstr;
