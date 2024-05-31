#include<iostream>
#include<string>
#include<sstream>
#include<cmath> //for pow(n,t);
#define number 0x7FFF
using namespace std;
enum BASE{
    BASE_TWO=1<<1,
    BASE_EIGHT=1<<3,
    BASE_SIXTEEN=1<<4
};

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
long long convert_to_binary(const long long& value,const int& divide){
    if(value==0){
        return 0;
    }
    string str={};
    long long v=value;
    stringstream str1;
    int c=0;
    while(v>=divide){
        c=v%divide;
        long long  f=v/divide;
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
int convert_bin(const char c){
    if(c=='1'){
        return 1;
    }
    else if(c=='0'){
        return 0;
    }
}
long long convert_to_decimal(const long long& binary,BASE base=BASE_TWO){
    stringstream str3;
    str3<<binary;
    string str1=str3.str();
    long long  v=0;
    long long  j=0;
    string str2=Reverse_string(str1);
    for(int i=str1.size()-1;i>=0;--i){
        v=convert_bin(str2[i]);
        v*=pow(2,i);
        j+=v;
    }
    return j;
}
long long convert_hex_to_binary(long long hex){
    long long  v=convert_to_binary(hex,2);
    return v;
}
void print(const long long& value,const string& v){
    cout<<value<<"     |    "<<v<<endl;
}
char convert_to_hex(const int& hex){
    int arr[]={48,49,50,51,52,53,54,55,56,57}; 
     int sz=sizeof(arr)/sizeof(arr[0]); 
     if(hex>=0 and hex<=9){
    for(int i=0;i<sz;++i){
        if(hex==(arr[i]-arr[0])){
            return (char)arr[i];
            }
        }
     }
  else if(hex>=10 and hex<=15){
      char c[]={"ABCDEF"};
      int f[]={10,11,12,13,14,15};
      for(int i=0;i<6;i++){
          if(hex==f[i]){
              return c[i];
          }
      }
  }
}
string  convert_decimal_to_hex(const long long& decimal,const int& divide,BASE base=BASE_SIXTEEN){
    long long value=decimal;
    string str={};
    if(value<divide){
        char v=convert_to_hex(value);
        str.push_back(v);
        return str;
    }
    while(value<=decimal and value>=divide){
        long long v=value/divide;
        int v1=value%divide;
        char c=convert_to_hex(v1);
        str.push_back(c);
        value=v;
    }
    char g=convert_to_hex(value);
    str.push_back(g);
    string str1=Reverse_string(str);
    return str;
 }
 
 string binary_to_hex(const long long& bin){
    long long value=convert_to_decimal(bin);
    string str=convert_decimal_to_hex(value,16);
    return str;
}

void print_for_fun(){
    cout<<"decimal"<<" |   "<<"Base 16"<<endl;
}