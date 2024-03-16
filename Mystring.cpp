#include<iostream>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<vector>
//only implement random access  iterator
using namespace std;

class Mystring{
    private:
    char*str;
     public:
     typedef char* iterator;
     typedef const char* const_iterator;
     typedef unsigned int size_c;
     static  const unsigned int no_pos=4294967295;
     Mystring get_string(){
         return str;
     }
     ~Mystring(){
         if(str!=nullptr){
             delete [ ] str;
         }
     }
    Mystring():str{nullptr}{
        str=new char[1];
        str[0]='\0';
        }
    Mystring(char*val){
        if(val==NULL){
            str=new char[1];
            str[0]='\0';
        }
        else{
        int v=strlen(val);
        str=new char[v+1];
        strcpy(str,val);
        str[v]='\0';
    }
    }
    
    void print_out(){
        cout<<str<<endl;
    }
    void set_size(int size){
        str=new char[size+1];
        str[size]='\0';
       }
    Mystring(const char*m){
        if(m==nullptr){
            str=new char[1];
            str[0]='\0';
       }
       else{
           int h=strlen(m);
           str=new char[h+1];
           strcpy(str,m);
           str[h]='\0';
           
       }
    }
    int get_length() const{
        int y=strlen(str);
        return y;
    }
    int get_length(){
        int y=strlen(str);
        return y;
    }
    Mystring(Mystring& ref){
        int b=ref.get_length();
        str=new char[b+1];
        strcpy(str,ref.str);
        str[b]='\0';
    }
    
    Mystring(const Mystring& ref){
        int b=ref.get_length();
        str=new char[b+1];
        strcpy(str,ref.str);
        str[b]='\0';
    }
    Mystring(const Mystring& ref,int idx){
        int h=ref.get_length()+1;
        int y=h-idx;
        str=new char[y+1];
        for(int i=0;i<y;i++){
            str[i]=ref.str[i+idx];
        }
        str[y]='\0';
     }
     Mystring(const char* ref,int idx){
        int h=strlen(ref)+1;
        int y=h-idx;
        str=new char[y+1];
        for(int i=0;i<y;i++){
            str[i]=ref[i+idx];
        }
        str[y]='\0';
     }
    Mystring(const Mystring& ref,int idx,int len){
       
        if((idx+len)<ref.get_length()){
            str=new char[len+1];
            for(int i=0;i<len;i++){
                str[i]=ref.str[i+idx];
            }
            str[len]='\0';
        }
        else{
            int h=ref.get_length()+1;
        int y=h-idx;
        str=new char[y+1]; //different types of constructors
        for(int i=0;i<y;i++){
            str[i]=ref.str[i+idx];
        }
        str[y]='\0';
        }
    }
    Mystring(const char*ref,int idx,int len){
       
        if((idx+len)<strlen(ref)){
            str=new char[len+1];
            for(int i=0;i<len;i++){
                str[i]=ref[i+idx];
            }
            str[len]='\0';
        }
        else{
            int h=strlen(ref)+1;
        int y=h-idx;
        str=new char[y+1]; //different types of constructors
        for(int i=0;i<y;i++){
            str[i]=ref[i+idx];
        }
        str[y]='\0';
        }
    }
    Mystring(iterator iter1,iterator iter2){
        int y=Mystring::get_length_from_pos(iter1,iter2);
        str=new char[y+1];
        for(int i=0;i<y;i++){
            str[i]=iter1[i];
        }
        str[y]='\0';
        
    }
    char* begin(){
        return &str[0];
    }
    char* begin() const {
        return &str[0];
    }
    
    char*end(){
        return &str[strlen(str)];
    }
     char*end() const {
        return &str[strlen(str)];
    }
    const char* cbegin() const {
        return &str[0];
    }
    const char* cend() const {
        return &str[strlen(str)];
    }
    char& front(){
        return str[0];
    }
    char& back(){
        return str[strlen(str)-1];
    }
    char& front() const {
        return str[0];
    }
    char& back() const {
        return str[strlen(str)-1];
    }
    bool empty_str(){
        if(strlen(str)==0){
            return true;
        }
        else{
            return false;
        }
    }
static void advance_by_1(iterator iter){
   ++iter;
   }
   static iterator advance_by_n(iterator iter1,int n){
       iterator iter2=iter1+n;
       return iter2;
       } 
   Mystring substring(const int& idx){//substring
        Mystring str1={*this,idx};
        return str1;
    }
    
    Mystring substring(const int& idx) const {
        Mystring str1={*this,idx};
        return str1;
    }
    Mystring substring(int idx,int len){
        Mystring str1={*this,idx,len};
        return str1;
    }
    Mystring substring(int idx,int len) const {
        Mystring str1={*this,idx,len};
        return str1;
    }
    //bool operator
    bool operator==(const Mystring& ref){
        bool is_value=true;
        if(strlen(str)==strlen(ref.str)){
            for(int i=0;i<strlen(str);i++){
                if(str[i]!=ref.str[i]){
                   is_value=false;
                   break;
                    }
        }
        if(is_value==false){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
    }
    bool operator==(const char* ref){
        bool is_value=true;
        if(strlen(str)==strlen(ref)){
            for(int i=0;i<strlen(str);i++){
                if(str[i]!=ref[i]){
                   is_value=false;
                   break;
                    }
        }
        if(is_value==false){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
    }
   
    //indexing
    char& operator[ ](const int idx){
        if(idx<strlen(str)){
            return str[idx];
        }
        else if(idx==strlen(str)){
            return str[idx];
        }
    }
   Mystring operator+(const Mystring& ref){
    int len=strlen(this->str)+strlen(ref.str);
    char* buffer=new char[len];
    strcpy(buffer,this->str);
    strcat(buffer,ref.str);
    Mystring mystr;
    mystr.str=new char[len+1];
    strcpy(mystr.str,buffer);
    mystr.str[len]='\0';
    delete [ ] buffer;
    return mystr;
 }
    char& at(const int& idx){
        if(idx<strlen(str)){
            return str[idx];
        }
    }
    //assignment operation, it is still equivalent to =;
    Mystring& operator=(const Mystring& ref){
        int len=strlen(ref.str);
        str=new char[len+1];
        strcpy(str,ref.str);
        str[len]='\0';
        return *this;
    }
       Mystring& assign(const Mystring& ref){
        if(str[0]=='\0'){
            int y=ref.get_length();
            str=new char[y+1];
            strcpy(str,ref.str);
            str[y]='\0';
            return *this;
     }
     else{
         return *this;
     }
       }
     Mystring& n_assign(const Mystring& ref){
            int y=ref.get_length();
            str=new char[y+1];
            strcpy(str,ref.str);
            str[y]='\0';
            return *this;
    }
    Mystring& assign(const Mystring& ref,int idx,int len ){
        if(str[0]=='\0'){
            int j=len-idx;//ifi idx >len, program will misbehave
            str=new char[j+1];
            for(int i=0;i<j;i++){
                str[i]=ref.str[i+idx];
            }
            str[j]='\0';
            return *this;
            
        }
        else{
            return *this;
        }
    }
    Mystring& n_assign(const Mystring& ref,int idx,int len ){
            int j=len-idx;//ifi idx >len, program will misbehave
            str=new char[j+1];
            for(int i=0;i<j;i++){
                str[i]=ref.str[i+idx];
            }
            str[j]='\0';
            return *this;
    }
    Mystring& assign(const char*ref){
        if(str[0]=='\0'){
            int len=strlen(ref);
            str=new char[len+1];
            strcpy(str,ref);
            str[len]='\0';
            return *this;
        }
        else{
            return *this;
        }
    }
    Mystring& n_assign(const char*ref){
           int len=strlen(ref);
            str=new char[len+1];
            strcpy(str,ref);
            str[len]='\0';
            return *this;
             }
    
    static int get_length_from_pos(iterator iter1,iterator iter2) {
        int y=0;
        while(iter1!=iter2){
            ++iter1;
            ++y;
        }
        return y;
    }
    
   
   Mystring& assign(iterator iter1,iterator iter2){
       int m=Mystring::get_length_from_pos(iter1,iter2);
       if(str[0]=='\0'){
           str=new char[m+1];
           for(int i=0;i<m;i++){
               str[i]=iter1[i];
           }
           str[m]='\0';
           return *this;
       }
       else{
           return *this;
       }
   }
   Mystring& n_assign(iterator iter1,iterator iter2){
       int m=Mystring::get_length_from_pos(iter1,iter2);
           str=new char[m+1];
           for(int i=0;i<m;i++){
               str[i]=iter1[i];
           }
           str[m]='\0';
           return *this;
   }
   Mystring& operator=(const char*ref){
       int len=strlen(ref);
       str=new char[len+1];
       strcpy(str,ref);
       str[len]='\0';
       return *this;
   }
   //appending operation... +=
   Mystring& operator+=(const Mystring& ref){
       *this=*this+ref;
       return *this;
   }
   Mystring& append(const Mystring& ref){
       *this+=ref;
       return *this;
   }
   Mystring& append(const Mystring& ref,int idx,int len){
       Mystring m={ref,idx,len};
       *this+=m;
       return *this;
   }
   Mystring& operator+=(const char* ref){
       int len=(*this).get_length()+strlen(ref);
       Mystring cpy=*this;
       delete [ ] str;
       str=new char[len+1];
       strcpy(str,cpy.str);
       strcat(str,ref);
       str[len]='\0';
       return *this;
   }
   Mystring& append(const char* ref){
       *this+=ref;
       return *this;
   }
   Mystring& append(iterator iter1,iterator iter2){
       Mystring f={iter1,iter2};
       *this+=f;
       return *this;
   }
Mystring& push_back(const char& c){
   int len=(*this).get_length();
   Mystring mystr=*this;
   str=new char[len+2];
   *this=mystr;
   str[len]=c;
   str[len+1]='\0';
   return *this;
   }
   void push_back_once(const char& c){
   int len=(*this).get_length();
   Mystring mystr=*this;
   str=new char[len+2];
   *this=mystr;
   str[len]=c;
   str[len+1]='\0';
}
 //insert method():To insert elements at a specific location idx...
 Mystring& insert(int idx,const Mystring& ref){
     Mystring mystr=*this;
     int tlen=(*this).get_length()+strlen(ref.str);
     str=new char[tlen];
     int len=strlen(ref.str);
     for(int i=0;i<idx;i++){
        str[i]=mystr.str[i];
     }
     for(int i=0;i<len;i++){
         str[i+idx]=ref.str[i];
     }
   
   int len1=idx+len;
   int len2=tlen-len1;
   for(int i=1;i<len2;i++){
       str[i+len1-1]=mystr.str[idx+i];
   }
   str[tlen]='\0';
     return *this;
}
Mystring& insert(int idx1,const Mystring& ref,int idx,int len1){
    Mystring mystr=*this;
    int len=strlen(str)+len1;
    str=new char[len];
    for(int i=0;i<idx1;i++){
        str[i]=mystr.str[i];
    }
    for(int i=0;i<len1;i++){
        str[i+idx1]=ref.str[i+idx];
    }
    int y=idx1+len1;
    int len2=len-y;
    for(int i=1;i<len2;i++){
        str[y+i-1]=mystr.str[idx1+i];
    }
    str[len]='\0';
    return *this;
}
Mystring& insert(int idx,const char* ref){
     Mystring mystr=*this;
     int tlen=(*this).get_length()+strlen(ref);
     str=new char[tlen];
     int len=strlen(ref);
     for(int i=0;i<idx;i++){
        str[i]=mystr.str[i];
     }
     for(int i=0;i<len;i++){
         str[i+idx]=ref[i];
     }
   
   int len1=idx+len;
   int len2=tlen-len1;
   for(int i=1;i<len2;i++){
       str[i+len1-1]=mystr.str[idx+i];
   }
   str[tlen]='\0';
     return *this;
}
Mystring& insert(int idx1,const char*ref,int idx,int len1){
    Mystring mystr=*this;
    int len=strlen(str)+len1;
    str=new char[len];
    for(int i=0;i<idx1;i++){
        str[i]=mystr.str[i];
    }
    for(int i=0;i<len1;i++){
        str[i+idx1]=ref[i+idx];
    }
    int y=idx1+len1;
    int len2=len-y;
    for(int i=1;i<len2;i++){
        str[y+i-1]=mystr.str[idx1+i];
    }
    str[len]='\0';
    return *this;
}
   Mystring& insert(int idx,const char* ref,int len){
       Mystring mystr=*this;
       int len1=strlen(str)+len;
       str=new char[len1];
       for(int i=0;i<idx;i++){
           str[i]=mystr.str[i];
       }
       for(int i=0;i<len;i++){
           str[i+idx]=ref[i];
       }
       int len2=idx+len;
       int len3=len1-len2;
       for(int i=0;i<len3;i++){
           str[len2+i-1]=mystr.str[i+idx];
       }
       str[len1]='\0';
       return *this;
   }
   iterator insert(iterator pos,iterator begin,iterator end){
       iterator iter=(*this).begin();
       int glen=Mystring::get_length_from_pos(iter,pos);
       int len2=Mystring::get_length_from_pos(begin,end);
       int len=(*this).get_length()+len2;
       Mystring mystr=*this;
       str=new char[len];
       
       iter=(*this).begin();
       for(int i=0;i<glen;i++){
           iter[i]=mystr.str[i];
       }
       for(int i=0;i<len2;i++){
           iter[i+glen]=*(begin+i);
       }
       int len3=glen+len2;
       int len4=len-len3;
       for(int i=0;i<len4;i++){
           iter[len3+i-1]=mystr.str[glen+i];
        }
        str[len]='\0';
        iterator iter1=(*this).begin()+glen;
        return iter1;
   }
   //we are through with insertion
   //we move to erasing elements
   void clear(){
       delete [ ] str;
       str=new char[1];
       str[0]='\0';
  }
  Mystring& erase(){
      str=new char[1];
      str[0]='\0';
      return *this;
  }
 Mystring& erase(int idx){
     Mystring mystr=*this;
     delete [ ] str;
     str=new char[idx+1];
     for(int i=0;i<idx;i++){
         str[i]=mystr.str[i];
     }
     str[idx]='\0';
     return *this;
 }
iterator erase(iterator pos){
    iterator pos1=(*this).begin();
    int len1=(*this).get_length();
    Mystring ref=*this;
    Mystring::iterator iter6=this->begin();
    int len=Mystring::get_length_from_pos(pos1,pos);
    for(int i=0;i<len1;i++){
        if((iter6+i)==pos){
            str[i]=0;
            break;
        }
    }
  for(int i=len;i<len1-1;i++){
        str[i]=ref.str[i+1];
    }
    Mystring mystr=*this;
  int f=len1-1;
  str=new char[f];
  for(int i=0;i<f;i++){
      str[i]=mystr.str[i];
      } 
      str[f]='\0'; 
      iterator iter1=(*this).begin()+len;
      return iter1;
}
iterator erase(iterator begin,iterator end){
    Mystring mystr=*this;
    iterator iter1=(*this).begin();
     int len1=Mystring::get_length_from_pos(iter1,begin);
     int len2=Mystring::get_length_from_pos(iter1,end);
     int len3=(*this).get_length();
     int len4=len3-len2;
     for(int i=0;i<len4;i++){
         str[i+len1]=mystr.str[i+len2];
     }
     Mystring ref=*this;
     int len5=len1+len4;
     str=new char[len5];
     for(int i=0;i<len5;i++){
         str[i]=ref.str[i];
     }
     iterator iter2=(*this).begin()+len1;
     return iter2;
}
Mystring& pop_back(){
    int len=(*this).get_length();
    --len;
    Mystring mystr=*this;
    str=new char[len+1];
    strcpy(str,mystr.str);
    str[len]='\0';
    return *this;
}
//we are done with variants of erase..
//we move to replacing set of characters with another set of characters
Mystring& replace(int idx,int len,const Mystring& ref){
    for(int i=0;i<len;i++){
        str[idx+i]=ref.str[i];
    }
    return *this;
}
Mystring& replace(int idx,int len,const Mystring& ref,int idx1,int len1){
    if(len1<=len){
        for(int i=0;i<len1;i++){
            str[i+idx]=ref.str[i+idx1];
        }
    }
    else{
        for(int i=0;i<len;i++){
            str[i+idx]=ref.str[i+idx1];
        }
    }
    return *this;
}
Mystring& replace(int idx,int len,const char* ref){
    for(int i=0;i<len;i++){
        str[idx+i]=ref[i];
    }
    return *this;
}
Mystring& replace(int idx,int len,const char* ref,int idx1,int len1){
    if(len1<=len){
        for(int i=0;i<len1;i++){
            str[i+idx]=ref[i+idx1];
        }
    }
    else{
        for(int i=0;i<len;i++){
            str[i+idx]=ref[i+idx1];
        }
    }
    return *this;
}
Mystring& replace( iterator iter1,iterator  iter2,const char* ref){
    int len1=Mystring::get_length_from_pos(iter1,iter2);
    for(int i=0;i<len1;i++){
        *(iter1+i)=ref[i];
    }
    return *this;
}
Mystring& replace(iterator iter1,iterator iter2,const Mystring& ref){
    int len1=Mystring::get_length_from_pos(iter1,iter2);
    for(int i=0;i<len1;i++){
        *(iter1+i)=ref.str[i];
    }
    return *this;
}
Mystring& replace(iterator iter1,iterator iter2,const char* ref,int len1){
    int len=Mystring::get_length_from_pos(iter1,iter2);
    if(len1<=len){
        for(int i=0;i<len1;i++){
            *(iter1+i)=ref[i];
        }
    }
    else{
        for(int i=0;i<len;i++){
        *(iter1+i)=ref[i];
    }
    }
    return *this;
}
Mystring& replace(iterator iter1,iterator iter2,const Mystring& ref,int len1){
    int len=Mystring::get_length_from_pos(iter1,iter2);
    if(len1<=len){
        for(int i=0;i<len1;i++){
            *(iter1+i)=ref.str[i];
        }
    }
    else{
        for(int i=0;i<len;i++){
        *(iter1+i)=ref.str[i];
    }
    }
    return *this;
}
Mystring& replace(int idx,int len,int num,char c){
    if(num<=len){
        for(int i=0;i<num;i++){
            str[i+idx]=c;
        }
    }
    else{
        for(int i=0;i<len;i++){
            str[i+idx]=c;
        }
    }
    return *this;
}
Mystring& replace(iterator iter1,iterator iter2,char c){
    int len=Mystring::get_length_from_pos(iter1,iter2);
    for(int i=0;i<len;i++){
        *(iter1+i)=c;
    }
    return *this;
}
Mystring& replace(iterator iter1,iterator iter2,iterator iter3,iterator iter4){
   int len1=Mystring::get_length_from_pos(iter1,iter2);
   int len2=Mystring::get_length_from_pos(iter3,iter4);
   if(len2<=len1){
       for(int i=0;i<len2;i++){
           *(iter1+i)=*(iter3+i);
       }
   }
   else{
       for(int i=0;i<len1;i++){
           *(iter1+i)=*(iter3+i);
       }
   }
   return *this;
}
//find functions..
size_t find(const char c) const {
    int j=-1;
    for(int i=0;i<(*this).get_length();i++){
        if(str[i]==c){
            j=i;
            break;
        }
    }
    if(j<=(*this).get_length() and j>=0){
        return j;
    }
    else if(j==-1){
        return Mystring::no_pos;
    }
}
size_t find(const char c,int idx) const {
    int j=-1;
    for(int i=idx;i<(*this).get_length();i++){
        if(str[i]==c){
            j=i;
            break;
        }
     }
     if(j<=(*this).get_length()and j>=0){
         return j;
     }
     else if(j==-1){
         return Mystring::no_pos;
     }
}
size_t find(const Mystring& mystr) const {
    int p=-1;
    int g=mystr.get_length();
    int j=(*this).get_length();
    int k=j-g;
    ++k;
    for(int i=0;i<k;i++){
        if((*this).substring(i,g)==mystr){
            p=i;
            break;
     }
    }
    if(p<=(*this).get_length() and p>=0){
        return p;
    }
    else if(p==-1){
        return Mystring::no_pos;
    }
}
// update find(const Mystring& mystr) const with break;
size_t find(const Mystring& mystr,int idx) const {
 Mystring mine=mystr.substring(idx);
  int p=-1;
  int len1=mine.get_length();
  int j=(*this).get_length();
  int k=j-len1;
  ++k;
  for(int i=0;i<k;i++){
       if((*this).substring(i,len1)==mine){
           p=i;
           break;
       }
  }
  if(p<=(*this).get_length() and p>=0){
       return p;
       } 
    else if(p==-1){
       return Mystring::no_pos;
       } 
}
size_t find(const Mystring& ref,int idx,int len) const {
    Mystring my=ref.substring(idx,len);
    int p=-1;
    int y=(*this).get_length();
    int k=y-len;
    ++k;
    for(int i=0;i<k;i++){
        if((*this).substring(i,len)==my){
            p=i;
            break;
        }
    }
    if(p<=(*this).get_length() and p>=0){
        return p;
    }
    else if(p==-1){
        return Mystring::no_pos;
    }
    
}
size_t find(const char*ref) const {
    Mystring mystr={ref};
    int p=-1;
    int y=(*this).get_length();
    int len1=mystr.get_length();
    int k=y-len1;
    ++k;
    for(int i=0;i<k;i++){
        if((*this).substring(i,len1)==mystr){
            p=i;
            break;
        }
    }
    if(p<=(*this).get_length() and p>=0){
        return p;
    }
    else{
        return Mystring::no_pos;
    }
    }
  size_t find(const char*ref,int idx) const{
      Mystring mystr={ref,idx};
      int p=-1;
    int y=(*this).get_length();
    int len1=mystr.get_length();
    int k=y-len1;
    ++k;
    for(int i=0;i<k;i++){
        if((*this).substring(i,len1)==mystr){
            p=i;
            break;
        }
    }
    if(p<=(*this).get_length() and p>=0){
        return p;
    }
    else{
        return Mystring::no_pos;
    }
  }
 size_t find(const char*ref,int idx,int len) const {
     Mystring mystr={ref,idx,len};
      int p=-1;
    int y=(*this).get_length();
    int k=y-len;
    ++k;
    for(int i=0;i<k;i++){
        if((*this).substring(i,len)==mystr){
            p=i;
            break;
        }
    }
    if(p<=(*this).get_length() and p>=0){
        return p;
    }
    else if(p==-1){
        return Mystring::no_pos;
    }
 }
 vector<size_t> g_find(const char c) const{
     vector<size_t> g;
     for(int i=0;i<(*this).get_length();i++){
         if(str[i]==c){
             g.push_back(i);
         }
     }
     if(!g.empty()){
         return g;
     }
     else{
         int y=Mystring::no_pos;
         g.push_back(y);
         return g;
     }
 }
 vector<size_t> g_find(const char c,int idx) const {
    vector<size_t>g;
    for(int i=idx;i<(*this).get_length();i++){
        if(str[i]==c){
            g.push_back(i);
          }
     }
     if(!g.empty()){
         return g;
     }
     else {
        int y=Mystring::no_pos;
        g.push_back(y);
        return g;
     }
}
vector<size_t>g_find(const Mystring& mystr) const {
    vector<size_t> h;
    int g=mystr.get_length();
    int j=(*this).get_length();
    int k=j-g;
    ++k;
    for(int i=0;i<k;i++){
        if((*this).substring(i,g)==mystr){
            h.push_back(i);
     }
    }
    if(!h.empty()){
        return h;
    }
    else{
        int y= Mystring::no_pos;
        h.push_back(y);
        return h;
    }
}
vector<size_t>g_find(const Mystring& mystr,int idx) const {
 Mystring mine=mystr.substring(idx);
  vector<size_t> h;
  int len1=mine.get_length();
  int j=(*this).get_length();
  int k=j-len1;
  ++k;
  for(int i=0;i<k;i++){
       if((*this).substring(i,len1)==mine){
           h.push_back(i);
       }
  }
  if(!h.empty()){
       return h;
       } 
    else{
       int y=Mystring::no_pos;
       h.push_back(y);
       return h;
    }
}
vector<size_t> g_find(const Mystring& ref,int idx,int len) const {
    Mystring my=ref.substring(idx,len);
    vector<size_t> h;
    int y=(*this).get_length();
    int k=y-len;
    ++k;
    for(int i=0;i<k;i++){
        if((*this).substring(i,len)==my){
            h.push_back(i);
        }
    }
    if(!h.empty()){
        return h;
    }
    else{
        int y=Mystring::no_pos;
        h.push_back(y);
        return h;
    }
}
vector<size_t> g_find(const char*ref) const {
    Mystring mystr={ref};
    vector<size_t> h;
    int y=(*this).get_length();
    int len1=mystr.get_length();
    int k=y-len1;
    ++k;
    for(int i=0;i<k;i++){
        if((*this).substring(i,len1)==mystr){
            h.push_back(i);
        }
    }
    if(!h.empty()){
        return h;
    }
    else{
        int y= Mystring::no_pos;
        h.push_back(y);
        return h;
    }
    }
  vector<size_t> g_find(const char*ref,int idx) const{
    Mystring mystr={ref,idx};
    vector<size_t> h;
    int y=(*this).get_length();
    int len1=mystr.get_length();
    int k=y-len1;
    ++k;
    for(int i=0;i<k;i++){
        if((*this).substring(i,len1)==mystr){
            h.push_back(i);
        }
    }
    if(!h.empty()){
        return h;
    }
    else{
        int y=Mystring::no_pos;
        h.push_back(y);
        return h;
    }
  }
  vector<size_t>g_find(const char*ref,int idx,int len) const {
     Mystring mystr={ref,idx,len};
      vector<size_t> h;
    int y=(*this).get_length();
    int k=y-len;
    ++k;
    for(int i=0;i<k;i++){
        if((*this).substring(i,len)==mystr){
            h.push_back(i);
        }
    }
    if(!h.empty()){
        return h;
    }
    else{
        int y=Mystring::no_pos;
        h.push_back(y);
        return h;
    }
 }
 };
