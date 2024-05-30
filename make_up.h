#include<iostream>
#include<string>
#include<sstream>
using namespace std;

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
}
char convert(const int& c){
    if(c==1){
        return '1';
    }
    else if(c==0){
        return '0';
    }
}
int convert_to_binary(const int& value,const int& divide){
    string str={};
    int v=value;
    stringstream str1;
    int c=0;
    while(v>=divide){
        c=v%divide;
        int f=v/divide;
        char c1=convert(c);
        str.push_back(c1);
        v=f;
    }
    str.push_back('1');
    string str2=Reverse_string(str);
    str1<<str2;
    str1>>v;
    return v;
}
i