#include<iostream>
#include<string>
#include<sstream>
#include<cmath> //for pow(n,t);
#define number 0x7FFF
#define SSTREAM
#ifdef DEBUG
#include<assert.h>
#endif
#define ASSERT(exp,value,str){ \
if (exp!=true){ \
   str val={value};  \
     return val;  \
     } \
     }
using namespace std;
template<class T>
string assertion(T condition,string str){
    if(condition!=true){
        return str;
    }
}
enum BASE{
    BASE_TWO=1<<1,
    BASE_EIGHT=1<<3,
    BASE_SIXTEEN=1<<4
};

string Reverse_string(const string& str){
    string rstr;
    for(int i=0;i<str.size();i++){
        rstr.push_back(' ');
    }
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
long long string_to_decimal(const string& str){
    string str1=Reverse_string(str);
    long long v=0;
    long long j=0;
    for(int i=str1.size()-1;i>=0;--i){
        v=convert_bin(str1[i]);
        v*=pow(2,i);
        j+=v;
    }
    return j;
  }
  string decimal_to_string_binary(long long& value){
      string str;
      long long v=value;
      int divide=2;
      int c=0;
      while(v>=divide){
        c=v%divide;
        long long  f=v/divide;
        char c1=convert(c);
        str.push_back(c1);
        v=f;
    }
    str.push_back('1');
    str=Reverse_string(str);
    return str;
  }
long long convert_hex_to_binary(long long hex){
    long long  v=convert_to_binary(hex,2);
    return v;
}
void print(const long long& value,const long long& v1,const string& v){
    cout<<value<<"        |    "<<v1<< "    |  "<<v<<endl;
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
    return str1;
 }
 
 string binary_to_hex(const long long& bin){
    long long value=convert_to_decimal(bin);
    string str=convert_decimal_to_hex(value,16);
    return str;
}

void print_for_fun(){
    cout<<"decimal"<<"  |   "<<"Base 2"<<"|  "<<"Base 16"<<endl;
}
int convert_to_number(const char c){
    int v[ ]={48,49,50,51,52,53,54,55,56,57};
    if(c>=(char)v[0] and c<=(char)v[9]){
        for(int i=0;i<10;++i){
            if(c==(char)v[i]){
                return i;
            }
        }
    }
  int f[ ]={10,11,12,13,14,15};
  char j[ ]={"ABCDEF"};
  for(int i=0;i<6;++i){
      if(c==j[i]){
          return f[i];
      }
  }
}
long long convert_hex_to_decimal(const string& str){
    long long add=0;
    string str1=Reverse_string(str);
     string str2={str1,0,str1.size()-2};
     for(int i=0;i<str2.size();i++){
         int v=convert_to_number(str2[i]);
         v*=pow(16,i);
         add+=v;
         }
     return add;
}
string invert_all_bits(long long value){
    stringstream ssobj;
    ssobj<<value;
    string str=ssobj.str();
    for(int i=0;i<str.size();++i){
        if(str[i]=='0'){
            str[i]='1';
        }
        else if(str[i]=='1'){
            str[i]='0';
        }
    }
  return str;
 }
 string invert_bits(const string& str){
     string str2=str;
     for(int i=0;i<str.size();++i){
         if(str[i]=='0'){
             str2[i]='1';
         }
         else if(str[i]=='1'){
             str2[i]='0';
         }
     }
     return str2;
 }
bool is_binary(const string& str){
    bool is_bin=true;
    for(int i=0;i<str.size();i++){
        if(str[i]>=(char)50){
            return false;
        }
    }
    return is_bin;
}
size_t get_no_of_bits(long long value){
    size_t sz=0;
    long long val=value;
    while(val>0){
        ++sz;
        val/=2;
    }
    return sz;
}
template<size_t N>
string Bits_anded(const string& str,const string& str2){
    string str4(N,'0');
    string str3(N,'0');
    string str1(N,'0');
    int j=N-1;
    int k=N-1;
    for(int i=str.size()-1;i>=0;i--){
        str1[j]=str[i];
        --j;
    }
    for(int i=str2.size()-1;i>=0;i--){
        str3[k]=str2[i];
        k--;
    }
    for(int i=str1.size()-1;i>=0;i--){
        if(str1[i]=='1' and str3[i]=='0'){
            str4[i]='0';
        }
        else if(str1[i]=='1' and str3[i]=='1'){
            str4[i]='1';
        }
        else if(str1[i]=='0' and str3[i]=='1' ){
            str4[i]='0';
        }
        else if(str1[i]=='0' and str3[i]=='0'){
            str4[i]='0';
        }
    }
    return str4;
}
template<size_t N>
string Bits_ored(const string& str,const string& str2){
    string str4(N,'0');
    string str3(N,'0');
    string str1(N,'0');
    int j=N-1;
    int k=N-1;
    for(int i=str.size()-1;i>=0;i--){
        str1[j]=str[i];
        --j;
    }
    for(int i=str2.size()-1;i>=0;i--){
        str3[k]=str2[i];
        k--;
    }
    for(int i=str1.size()-1;i>=0;i--){
        if(str1[i]=='1' and str3[i]=='0'){
            str4[i]='1';
        }
        else if(str1[i]=='1' and str3[i]=='1'){
            str4[i]='1';
        }
        else if(str1[i]=='0' and str3[i]=='1' ){
            str4[i]='1';
        }
        else if(str1[i]=='0' and str3[i]=='0'){
            str4[i]='0';
        }
    }
    return str4;
}
template<size_t N>
string Bits_xored(const string& str,const string& str2){
    string str4(N,'0');
    string str3(N,'0');
    string str1(N,'0');
    int j=N-1;
    int k=N-1;
    for(int i=str.size()-1;i>=0;i--){
        str1[j]=str[i];
        --j;
    }
    for(int i=str2.size()-1;i>=0;i--){
        str3[k]=str2[i];
        k--;
    }
    for(int i=str1.size()-1;i>=0;i--){
        if(str1[i]=='1' and str3[i]=='0'){
            str4[i]='1';
        }
        else if(str1[i]=='1' and str3[i]=='1'){
            str4[i]='0';
        }
        else if(str1[i]=='0' and str3[i]=='1' ){
            str4[i]='1';
        }
        else if(str1[i]=='0' and str3[i]=='0'){
            str4[i]='0';
        }
    }
    return str4;
}
 template<size_t N>
 class Bit {
     private:
     string str;
      public:
Bit(){
         string str;
         for(int i=0;i<N;i++){
             str.push_back('0');
         }
    }
Bit(string str1){
        str=str1;
    }
Bit(long long value){
      if(N!=0){
          for(int i=0;i<N;i++){
             str.push_back('0');
         }
      }
      int j=str.size()-1;
#ifdef SSTREAM
    stringstream ssobj;
#endif
    ssobj<<value;
    string str1=ssobj.str();
    if(is_binary(str1)==true){
    for(int i=str1.size()-1;i>=0;i--){
        str[j]=str1[i];
        --j;
 }
    }//if is_binary is false, convert value to binary
    else{
        long long value1=convert_to_binary(value,2);
        stringstream str2;
        str2<<value1;
        string str3=str2.str();
        for(int i=str3.size()-1;i>=0;i--){
        str[j]=str3[i];
        --j;
    }
   }
}
string get_head() const {
    return str;
}
string& get_head(){
    return str;
}
template<size_t  B>
static void print_bit_pattern(const Bit<B>& bit){
    cout<<bit.get_head()<<endl;
}
static bool check_binary(const Bit<N>& bit){
    bool is_bin=is_binary(bit.get_head());
    return is_bin;
}
template<size_t G>
static Bit cast_to_N_bit(const Bit<G>& bit){
    string strz;
    for(int i=0;i<N;i++){
        strz.push_back('0');
    }
    int j=strz.size()-1;
  for(int i=bit.get_head().size();i>=0;i--){
      strz[j]=bit.get_head()[i];
      --j;
  }
  Bit<N>bit1=strz;
  return bit1;
}
Bit& operator=(const Bit<N>& bits){
    str=bits.str;
    return *this;
}
Bit& operator=(const string& str1){
    *this={str1};
    return *this;
}
template<size_t K>
Bit operator &(const Bit<K>&bits){
    if(this->get_head().size()!=bits.get_head().size()){
        Bit<N> bit1=assertion<const size_t>(this->get_head().size()==bits.get_head().size(),"Cast to same size, sizes are not equal");
        return bit1;
    }
    Bit<N> bit=Bits_anded<N>(this->get_head(),bits.get_head());
    return bit;
}
template<size_t K>
Bit& operator&=(const Bit<K>& bit){
    *this=*this & bit;
    return *this;
}
template<size_t K>
Bit operator |(const Bit<K>&bits){
    if(this->get_head().size()!=bits.get_head().size()){
        Bit<N> bit1=assertion<const size_t>(this->get_head().size()==bits.get_head().size(),"Cast to same size, sizes are not equal");
        return bit1;
    }
    Bit<N> bit=Bits_ored<N>(this->get_head(),bits.get_head());
    return bit;
}
template<size_t K>
Bit& operator|=(const Bit<K>& bit){
    *this=*this |  bit;
    return *this;
}
template<size_t K>
Bit operator ^(const Bit<K>&bits){
    if(this->get_head().size()!=bits.get_head().size()){
        Bit<N> bit1=assertion<const size_t>(this->get_head().size()==bits.get_head().size(),"Cast to same size, sizes are not equal");
        return bit1;
    }
    Bit<N> bit=Bits_xored<N>(this->get_head(),bits.get_head());
    return bit;
}
template<size_t K>
Bit& operator^=(const Bit<K>& bit){
    *this=*this^bit;
    return *this;
}
Bit operator~(void ){
    string str1=invert_bits(this->get_head());
    Bit<N> bit1={str1};
    return bit1;
 }
 Bit operator<<(int value){
     long long h=pow(2,value);
     long long value1=string_to_decimal(this->get_head());
     long long value2=value1*h;
     Bit<N> bit={value2};
     return bit; 
 }
 Bit& operator<<=(int value){
     *this=*this<<value;
     return *this;
 }

 Bit operator>>(int value){
     long long h=pow(2,value);
     long long value1=string_to_decimal(this->get_head());
     long long value2=value1/h;
     Bit<N>bit={value2};
     return bit;
 }
 Bit& operator >>=(int value){
     *this=*this>>value;
     return *this;
 }

template<size_t H>
Bit operator+(const Bit<H>&bit){
    long long val=string_to_decimal(this->get_head());
    long long val2=string_to_decimal(bit.get_head());
    long long value1=val+val2;
    Bit<N> bit1={value1};
    return bit1;
}
Bit operator+(const long long& value){
    long long val=string_to_decimal(this->get_head());
    long long val2=val+value;
    Bit<N> bit={val2};
    return bit;
}
Bit& operator+=(const Bit<N>& bit){
    *this=*this+bit;
    return *this;
}
Bit& operator+=(const long long& value){
    *this=*this+value;
    return *this;
}
static long long convert_bit_to_value(const Bit<N>& bit){
    long long val=string_to_decimal(bit.get_head());
    return val;
}
template<size_t G>
Bit operator-(const Bit<G>& bit){
    if(Bit<N>::convert_bit_to_value(*this)>Bit<G>::convert_bit_to_value(bit)){
    long long val=string_to_decimal(this->get_head());
    long long val2=string_to_decimal(bit.get_head());
    long long val3=val-val2;
    Bit<N> bit={val3};
    }
    return bit;
}

static Bit number_rep(const long long& value){
    stringstream str2;
    str2<<value;
    string str1=str2.str();
    if(str1[0]=='-'){
        long long value2=0;
        str1=str1.substr(1,str1.size());
        stringstream str5;
        str5<<str1;
        str5>>value2;
        Bit<N> bit={value2};
        Bit<N> bit_comp=~bit;
        Bit<N> bit6={1};
        Bit<N> bit3=bit_comp+bit6;
        return bit3;
    }
    else {
        Bit<N>bit={value};
        return bit;
    }
}

};
