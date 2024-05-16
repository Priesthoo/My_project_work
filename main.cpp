#include<iostream>
using namespace std;
#ifndef CHAR_CONVERT
#define CHAR_CONVERT  32
#endif
//the distance between the upper case letter and the lower case letter in the ascii table is 32...
//we are here to implement our 4 basic function.
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
