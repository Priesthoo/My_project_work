 #include<iostream>
#include<memory>
#include<string>
#include<vector>
using namespace std;

#ifndef SHARED_PTR
#define SHARED_PTR
#endif 

#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#endif

/*
implement ur own default deleter for shared_ptr when it uses array type as a template argumentl
*/
template<class T>
class Deleter_for_array{
    public:
    void operator()(T* ptr){
        if(ptr!=nullptr){
            delete [ ] ptr;
        }
    }
};
template<class T>
class Deleter_for_value{
    public:
    void operator()(T*ptr){
        if(ptr!=nullptr){
            delete ptr;
        }
    }
};
template<class T>
class Table{
    public:
    shared_ptr<T>data;
      size_t sz;
      
   Table():data{nullptr},sz{}{}
   
     void set_size(const size_t sz1){
        if(data.get()==nullptr){
        sz=sz1;
        data.reset(new T [sz],Deleter_for_array<T>());
       const T d={};
    for(int i=0;i<sz;i++){
          data.get()[i]=d;
    }
    }
}
Table(const size_t& sz1){
    this->set_size(sz1);
 }
 Table(const Table& table){
     this->data=table.data;     //sharing ownership...
     this->sz=table.sz;
 }
    
   void push(const T& value){
    if(data.get()==nullptr){
        data.reset(new T[1],Deleter_for_array<T>());
        sz=1;
        data.get()[0]=value;
        return;
    }
   Table table=*this;
   this->sz=table.sz+1;
   this->data.reset(new T[sz],Deleter_for_array<T>());
   for(int i=0;i<table.sz;i++){
       (*this)[i]=table[i];
  }
   (*this)[this->sz-1]=value;
   table.~Table();
   return;
   }
   
T& operator[ ](const size_t& idx){
    if(idx<sz){
        return data.get()[idx];
    }
}
T operator[ ](const size_t& idx) const{
    if(idx<sz){
        return data.get()[idx];
    }
}
Table& operator=(const Table& table){
    *this={table};
    return *this;
}

~Table(){
    data.reset();
    sz=0;
}
size_t get_size() const {
    return sz;
}
};
class Color {
    public:
    float color[3];
  Color()=default;
  Color(const float& r,const float& g,const float& b){
      color[0]=r;
      color[1]=g;
      color[2]=b;
  }
  Color(const Color& color1){
      color[0]=color1.color[0];
      color[1]=color1.color[1];
      color[2]=color1.color[2];
  }
#ifndef SHARED_PTR 
Color& operator=(const Color& clor1){
    *this={color1};
    return *this;
}
#endif
  Color operator+(const Color& color1){
   Color color0;
   color0 .color[0]=color[0]+color1.color[0];
   color0.color[1]=color[1]+color1.color[1];
   color0.color[2]=color[2]+color1.color[2];
   return color0;
 }
   Color operator-(const Color& color1){
   Color color0;
   color0 .color[0]=color[0]-color1.color[0];
   color0.color[1]=color[1]-color1.color[1];
   color0.color[2]=color[2]-color1.color[2];
   return color0;
 }
 
   Color operator/(const Color& color1){
   Color color0;
   color0 .color[0]=color[0]/color1.color[0];
   color0.color[1]=color[1]/color1.color[1];
   color0.color[2]=color[2]/color1.color[2];
   return color0;
 }
   Color operator*(const Color& color1){
   Color color0;
   color0 .color[0]=color[0]*color1.color[0];
   color0.color[1]=color[1]*color1.color[1];
   color0.color[2]=color[2]*color1.color[2];
   return color0;
 }
    Color operator*(const float& color1){
   Color color0;
   color0 .color[0]=color[0]*color1;
   color0.color[1]=color[1]*color1;
   color0.color[2]=color[2]*color1;
   return color0;
 }
    Color operator*(const size_t& color1){
   Color color0;
   color0 .color[0]=color[0]*color1;
   color0.color[1]=color[1]*color1;
   color0.color[2]=color[2]*color1;
   return color0;
 }
 
  //don't overload (=) operator;'
};

ostream& operator<<(ostream& str,const Color& color){
    str<<" red: "<<color.color[0]<<"  green: "<<color.color[1]<<"  blue: "<<color.color[2]<<endl;
    return str;
}