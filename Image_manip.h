 #include<iostream>
using namespace std;
#include"container.h"
#include<memory>
#include<string>
#define MULTI_COLOR
#define ALPHA
#ifndef SHARED_PTR
#define SHARED_PTR
#endif
template<class T>
 void print(const char*c,const T& value){
     cout<<c<<value<<endl;
 }
void print_header(const char*c){
    cout<<c<<endl;
}
void new_line(){
    cout<<endl;
}
/*
Most images ,when decoded contain RGB or RGBA data by default, we can either convert it to other color space(sRGB,CYMK and others).
*/
#define N_L  new_line()
#define MEMORY_MODEL_H 0x67<<6
enum class  INTENSITY_LEVEL{
    BIT_8=0x08,
    BIT_24=0x18,
    BIT_32=0x20
};

#define BIT_8 INTENSITY_LEVEL::BIT_8
#define BIT_24 INTENSITY_LEVEL::BIT_24
#define BIT_32 INTENSITY_LEVEL::BIT_32

#ifndef VALUE_TYPE
#define VALUE_TYPE
template<class T>
struct Value_type{
    T value;
    Value_type():value{}{}
    Value_type(const Value_type& valtype){
        this->value=valtype.value;
    }
  Value_type(const T& value1){
      this->value=value1;
  }
  Value_type& operator=(const Value_type& value){
      *this={value};
      return *this;
  }
 
};
#endif
/*



*/
#ifndef SAMPLE
#define SAMPLE
struct Sample{
    int x;
    int y;
    Sample():x{},y{}{}
    Sample(int _x,int _y):x{_x},y{_y}{}
  Sample& operator=(const Sample& samp){
      this->x=samp.x;
      this->y=samp.y;
      return *this;
  }
 bool operator<(const Sample& samp){
     if((this->x< samp.x) and(this->y>samp.y)){
         return false;
     }
     else if((this->x>samp.x) and (this->y<samp.y)){
         return false;
     }
     return true;
 }
};
#endif


#ifndef INTENSITY_TRUE_COLOR
#define INTENSITY_TRUE_COLOR
struct True_color{
#ifdef GRAY_SCALE && #ifndef MULTI_COLOR && #ifdef BIT_8
 float gcolor;
#endif
#ifdef MULTI_COLOR && #ifndef GRAY_SCALE && ifdef BIT_24
    float r;
    float g;
    float b;
#endif

 #ifdef ALPHA && #ifdef MULTI_COLOR && #ifdef BIT_32 && #ifndef GRAY_SCALE
    float a;
#endif

True_color(){
 #ifdef GRAY_SCALE && #ifndef MULTI_COLOR && #ifdef BIT_8
 gcolor={};
 #endif
#ifdef MULTI_COLOR && #ifndef GRAY_SCALE && ifdef BIT_24
r={};
g={};
b={};
#endif
#ifdef ALPHA && #ifdef MULTI_COLOR && #ifdef BIT_32 && #ifndef GRAY_SCALE
 a={};
#endif 
}

True_color(const True_color& tcolor){
 #ifdef GRAY_SCALE && #ifndef MULTI_COLOR && #ifdef BIT_8
 this->gcolor=tcolor.gcolor;
 #endif
 #ifdef MULTI_COLOR && #ifndef GRAY_SCALE && ifdef BIT_24
this->r=tcolor.r;
this->g=tcolor.g;
this->b=tcolor.b;
#endif 
#ifdef ALPHA && #ifdef MULTI_COLOR && #ifdef BIT_32 && #ifndef GRAY_SCALE
this->r=tcolor.r;
this->g=tcolor.g;
this->b=tcolor.b;
this->a=tcolor.a;
#endif
}

True_color& operator=(const True_color& tcolor){
#ifdef GRAY_SCALE && #ifndef MULTI_COLOR && #ifdef BIT_8
*this={tcolor};
return *this;
#endif
#ifdef MULTI_COLOR && #ifndef GRAY_SCALE && ifdef BIT_24
*this={tcolor};
return *this;
#endif
#ifdef ALPHA && #ifdef MULTI_COLOR && #ifdef BIT_32 && #ifndef GRAY_SCALE
*this={tcolor};
return *this;
#endif
}

True_color operator+(const True_color& tcolor){
 True_color true_color;
 #ifdef GRAY_SCALE && #ifndef MULTI_COLOR && #ifdef BIT_8
true_color.gcolor=this->gcolor+tcolor.gcolor;
 return true_color;
#endif
#ifdef MULTI_COLOR && #ifndef GRAY_SCALE && ifdef BIT_24
true_color.r=this->r+tcolor.r;
true_color.g=this->g+tcolor.g;
true_color.b=this->b+tcolor.b;
return true_color;
#endif
#ifdef ALPHA && #ifdef MULTI_COLOR && #ifdef BIT_32 && #ifndef GRAY_SCALE
true_color.r=this->r+tcolor.r;
true_color.g=this->g+tcolor.g;
true_color.b=this->b+tcolor.b;
true_color.a=this->a+tcolor.a;
return true_color;
#endif
 }
 
True_color operator-(const True_color& tcolor){
True_color true_color;
#ifdef GRAY_SCALE && #ifndef MULTI_COLOR && #ifdef BIT_8
true_color.gcolor=this->gcolor-tcolor.gcolor;
 return true_color;
#endif
#ifdef MULTI_COLOR && #ifndef GRAY_SCALE && ifdef BIT_24
true_color.r=this->r-tcolor.r;
true_color.g=this->g-tcolor.g;
true_color.b=this->b-tcolor.b;
return true_color;
#endif
#ifdef ALPHA && #ifdef MULTI_COLOR && #ifdef BIT_32 && #ifndef GRAY_SCALE
true_color.r=this->r-tcolor.r;
true_color.g=this->g-tcolor.g;
true_color.b=this->b-tcolor.b;
true_color.a=this->a-tcolor.a;
return true_color;
#endif
}

True_color operator*(const True_color& tcolor){
 True_color true_color;
 #ifdef GRAY_SCALE && #ifndef MULTI_COLOR && #ifdef BIT_8
true_color.gcolor=this->gcolor*tcolor.gcolor;
 return true_color;
#endif
#ifdef MULTI_COLOR && #ifndef GRAY_SCALE && ifdef BIT_24
true_color.r=this->r*tcolor.r;
true_color.g=this->g*tcolor.g;
true_color.b=this->b*tcolor.b;
return true_color;
#endif
#ifdef ALPHA && #ifdef MULTI_COLOR && #ifdef BIT_32 && #ifndef GRAY_SCALE
true_color.r=this->r*tcolor.r;
true_color.g=this->g*tcolor.g;
true_color.b=this->b*tcolor.b;
true_color.a=this->a*tcolor.a;
return true_color;
#endif
}

True_color operator/(const True_color& tcolor){
 True_color true_color;
 #ifdef GRAY_SCALE && #ifndef MULTI_COLOR && #ifdef BIT_8
true_color.gcolor=this->gcolor/tcolor.gcolor;
 return true_color;
#endif
#ifdef MULTI_COLOR && #ifndef GRAY_SCALE && ifdef BIT_24
true_color.r=this->r/tcolor.r;
true_color.g=this->g/tcolor.g;
true_color.b=this->b/tcolor.b;
return true_color;
#endif
#ifdef ALPHA && #ifdef MULTI_COLOR && #ifdef BIT_32 && #ifndef GRAY_SCALE
true_color.r=this->r/tcolor.r;
true_color.g=this->g/tcolor.g;
true_color.b=this->b/tcolor.b;
true_color.a=this->a/tcolor.a;
return true_color;
#endif
}

True_color operator*(const float& tcolor){
 True_color true_color;
 #ifdef GRAY_SCALE && #ifndef MULTI_COLOR && #ifdef BIT_8
true_color.gcolor=this->gcolor*tcolor;
 return true_color;
#endif
#ifdef MULTI_COLOR && #ifndef GRAY_SCALE && ifdef BIT_24
true_color.r=this->r*tcolor;
true_color.g=this->g*tcolor;
true_color.b=this->b*tcolor;
return true_color;
#endif
#ifdef ALPHA && #ifdef MULTI_COLOR && #ifdef BIT_32 && #ifndef GRAY_SCALE
true_color.r=this->r*tcolor;
true_color.g=this->g*tcolor;
true_color.b=this->b*tcolor;
true_color.a=this->a*tcolor;
return true_color;
#endif
}
True_color operator/(const float& tcolor){
 True_color true_color;
 #ifdef GRAY_SCALE && #ifndef MULTI_COLOR && #ifdef BIT_8
true_color.gcolor=this->gcolor/tcolor;
 return true_color;
#endif
#ifdef MULTI_COLOR && #ifndef GRAY_SCALE && ifdef BIT_24
true_color.r=this->r/tcolor;
true_color.g=this->g/tcolor;
true_color.b=this->b/tcolor;
return true_color;
#endif
#ifdef ALPHA && #ifdef MULTI_COLOR && #ifdef BIT_32 && #ifndef GRAY_SCALE
true_color.r=this->r/tcolor;
true_color.g=this->g/tcolor;
true_color.b=this->b/tcolor;
true_color.a=this->a/tcolor;
return true_color;
#endif
}

};
#endif

#ifndef PIXEL_DATA
#define PIXEL_DATA
struct Pixel{
 #ifdef VALUE_TYPE
 Value_type<Sample> Samples;
 #endif
 True_color color;
Pixel():Samples{},color{}{}
Pixel(const Value_type<Sample>&  samp,const True_color& true_color){
    Samples=samp;
    color=true_color;
} 
};
#endif

#ifndef MATH_OPERATION
#define MATH_OPERATION
#endif
#ifndef MY_ARRAY_FOR_IMAGE
#define MY_ARRAY_FOR_IMAGE
#endif
