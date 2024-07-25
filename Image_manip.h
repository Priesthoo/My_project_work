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
#include<utility>
#define BIG_NUM 8880000000
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


#define BIT_32 INTENSITY_LEVEL::BIT_32
enum SPATIAL_OPERATIONS{
    SINGLE_OPS,
    NEIGHBOUR_OPS
};

#ifndef CLAMP
#define CLAMP
float clamp_value(const float min,const float v,const float max){
    if(v<min){
        return min;
    }
    else if(v>max){
        return max;
    }
    return v;
}
#endif //for clamp

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
 bool operator<(const Sample& samp) const {
     if((this->x< samp.x) and(this->y>samp.y)){
         return false;
     }
     else if((this->x>samp.x) and (this->y<samp.y)){
         return false;
     }
     return true;
 }
 bool operator==(const Sample& samp) const{
     if((this->x==samp.x) and (this->y==samp.y)){
         return true;
     }
     return false;
 }
};

std::ostream& operator<<(std::ostream& str,const Sample& samp){
    str<<"["<<samp.x<<","<<samp.y<<"]"<<std::endl;
    return str;
}
#endif
enum PIXEL_COLOR_FORMAT{
    RGBA_8_8_8_8
};


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
float agba=clamp_value(0.0f,true_color.a,1.0f);
true_color.a=agba;
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
if(this->a==0.0f and tcolor.a==1.0f){
true_color.a=0.0f;
return true_color;
}
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
true_color.a=this->a;
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
true_color.a=this->a;
return true_color;
#endif
}
};
std::ostream& operator<<(ostream& str,const True_color& tcolor2){
    str<<"red:"<<tcolor2.r<<" green:"<<tcolor2.g<<" blue:"<<tcolor2.b<<" alpha:"<<tcolor2.a<<endl;
    return str;
}
#endif

//set colors
True_color set_color(const float& red,const float& green,const float& blue,const float& alpha ){
   True_color tcolor;
   tcolor.r=red;
   tcolor.g=green;
   tcolor.b=blue;
   tcolor.a=alpha;
   return tcolor;
}
True_color set_color(const float& red,const float& green,const float& blue){
   True_color tcolor;
   tcolor.r=red;
   tcolor.g=green;
   tcolor.b=blue;
   return tcolor;
}
bool is_sorted(const std::vector<Sample>& samp){
    for(int i=1;i<samp.size();i++){
      if(samp[i]<samp[i-1]){
          return false;
      }
   }
   return true;
}
bool is_found(const std::vector<Sample> samp,const Sample samp1){
    for(int i=0;i<samp.size();i++){
        if(samp[i]==samp1){
            return true;
        }
    }
    return false;
}
#ifndef MATH_OPERATION
#define MATH_OPERATION
#endif
#ifndef MY_ARRAY_FOR_IMAGE
#define MY_ARRAY_FOR_IMAGE
#endif

#ifndef SWAP_VALUES
#define SWAP_VALUES
template<class T>
void swap_values(T& first, T& second){
    T swap=first;
    first=second;
    second =swap;
}
#endif

typedef pair<Sample,True_color> Pixel;



#ifndef IMAGE_TYPE
#define IMAGE_TYPE
class Image_type{
    public:
    int width;
    int height;
    std::vector<Sample> samples;
    std::vector<True_color>colors;
    typedef std::vector<Sample>::iterator Pixel_point;
    typedef std::vector<True_color>::iterator Pixel_color;
  Image_type():samples{},colors{}{}
  void push_back(const Sample& samp, const True_color& tcolor){
      if(!samples.empty()){
          if(is_found(samples,samp)){
              return;
          }
      }
      samples.push_back(samp);
      colors.push_back(tcolor);
      
  }
 size_t size() const {
     if(samples.size()==colors.size()){
         return samples.size();
     }
 }
 /*
        image coordinate system
   (0,0) ------------------------------------------------>y-axis(width).
           |
           |   (x0,y0)(a sample).
           |
           |
           |
           |
           |
           |
           |
           |
           x-axis(height)...
 */
 Pixel_point get_sample_begin(){
     return samples.begin();
 }
 Pixel_color get_color_begin(){
     return colors.begin();
 }

 Pixel_point get_sample_end(){
  return samples.end();
  }
  Pixel_color get_color_end(){
      return colors.end();
  }
  void construct_samples(const int& width,const int& height) {
   Sample sample7;
   int i=0;
   this->width=width;
   this->height=height;
  while(i<height){
      sample7.x=i;
      int j=0;
      while(j<width){
          sample7.y=j;
         this->samples.push_back(sample7);
          ++j;
      }
      ++i;
 }  
 }
 void insert_colors(std::vector<True_color>tcolor) {
     if(this->samples.size()==0){
         return;
     }
     if(this->samples.size()!=tcolor.size()){
         return;
      }
     for(int i=0;i<this->samples.size();i++){
         this->colors.push_back(tcolor[i]);
     }
     return;
 }
};
#endif

#define EXTRACT_PIXEL_COLOR
#ifdef EXTRACT_PIXEL_COLOR
Pixel convert_image_type_to_pixel(const Image_type& image,const int& idx){
    Pixel pixel;
    int k=0;
    if(idx>=0 and idx<image.size()){
    for(size_t i=0;i<image.size();i++){
        k=(image.samples[i].x+1)*(image.samples[i].y+1);
        if(k==(idx+1)){
            pixel.first=image.samples[i];
            pixel.second=image.colors[i];
        }
        return pixel;
     }
    }
}
#endif //Extract_pixel_color...