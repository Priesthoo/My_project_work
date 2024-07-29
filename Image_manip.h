#include<iostream>
using namespace std;
#include<memory>
#include<string>
#define MULTI_COLOR
#define ALPHA
#ifndef SHARED_PTR
#define SHARED_PTR
#endif
#include<utility>
#define BIG_NUM 8880000000
#include"Image_color.h"

const char* my_assert(bool statement,const char* error){
    if(!statement){
        return error;
    }
 }
 #define IM_ASSERT(T,V) my_assert(T,V);
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
    NEIGHBOUR_OPS,
    SPATIAL_TRANSFORM,
    INTENSITY_ASSIGNMENT,
    PROBABILITY
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
 #ifndef SHARED_PTR
  Sample& operator=(const Sample& samp){
      this->x=samp.x;
      this->y=samp.y;
      return *this;
  }
 #endif
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
    RGBA_8_8_8_8,
    GRAY_SCALE_8,
    B_8_BIT,
    R_8_BIT,
    G_8_BIT
};



//set colors

bool is_sorted(const Table<Sample>& samp){
    for(int i=1;i<samp.get_size();i++){
      if(samp[i]<samp[i-1]){
          return false;
      }
   }
   return true;
}
bool is_found(const Table<Sample>& samp,const Sample& samp1){
    for(int i=0;i<samp.get_size();i++){
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


#ifndef IMAGE_TYPE
#define IMAGE_TYPE
class Image_type{
    public:
    int width;
    int height;
 Table<Sample>samples;
 Table<Color> True_colors;
  Image_type():samples{},True_colors{},width{},height{}{}
  Image_type(const Image_type& im_type){
      this->width=im_type.width;
      this->height=im_type.height;
      this->samples=im_type.samples;
   }
  
Image_type& operator=(const Image_type& im_type){
    *this={im_type};
    return *this;
}
  
   Image_type(const int& _x,const int& _y){
       this->construct_samples(_x,_y);
       this->init_all_samples();
       True_colors.set_size(this->size());
   }
 size_t size() const {
    return samples.get_size();
  }
 void init_all_samples(){
     if(this->size()==0){
         return;
     }
     Sample samp={};
     int i=0;
     while(i<this->size()){
         for(int j=0;j<this->height;j++){
             samp.x=j;
             for(int k=0;k<this->width;k++){
                 samp.y=k;
                 this->samples[i]=samp;
                 ++i;
             }
         }
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

  
  void construct_samples(const int& width,const int& height) {
   this->width=width;
   this->height=height;
   int result=width*height;
  this->samples.set_size(result);
 }

 ~Image_type(){
     samples.~Table();
     width=0;
     height=0;
     } 
 Color& operator[ ](const Sample& samp){
     if((samp.x<this->height) and (samp.y<this->width) and this->size()!=0){
         for(int i=0;i<this->size();i++){
            if(samples[i]==samp){
                return True_colors[i];
            }
         }
     }
 }
  Color operator[ ](const Sample& samp) const {
     if((samp.x<this->height) and (samp.y<this->width) and this->size()!=0){
         for(int i=0;i<this->size();i++){
            if(samples[i]==samp){
                return True_colors[i];
            }
         }
     }
 }
};
#endif

/*
This type is for Spatial transformation, After performing spatial transformation,
convert it back to 2D

*/
#define SAMPLE_3D
#ifdef SAMPLE_3D
struct Sample_3d{
    int x;
    int y;
    int z;
    Sample_3d():x{},y{},z{}{}
    Sample_3d(const int& _x,const int& _y,const int& _z=1){
        x=_x;
        y=_y;
        z=1;
    }
    Sample_3d (const Sample_3d& samp3d){
        *this={samp3d.x,samp3d.y,samp3d.z};
    }
 Sample_3d& operator=(const Sample_3d& samp3d){
     *this={samp3d};
     return *this;
 }
 };
#endif  //for Samp3d
enum class  INTERPOLATION{
    NEAREST_NEIGHBOUR,
    BILINEAR_INTERPOLATION,
    BICUBIC_INTERPOLATION,
    SPLINE_INTERPOLATION,
    LINEAR_INTERPOLATION,
    CUBIC_CONVOLUTION_INTERPOLATION
};
#ifndef TRANSFORM_2D
#define TRANSFORM_2D
enum class TRANSFORM {
    ROTATION,
    TRANSLATION,
    SHEAR_VERTICAL,
    SHEAR_HORIZONTAL,
    SCALING
};
#endif //transform 

enum READ_IMAGE{
    HORIZONTAL_SCAN
};
typedef Table<Sample> Samples;
typedef Table<float> Values;
class Transform{
    private:
    Samples loc;
    Values value;
    public:
    Transform(){
        this->init_all_location();
        value.set_size(loc.get_size());
    }
    
 void init_all_location(){
     Sample samp;
     for(int i=0;i<3;i++){
         samp.x=i;
         for(int j=0;j<3;j++){
             samp.y;
             loc.push(samp);
         }
     }
     return;
 }
 size_t size_of_matrix() const{
     return loc.get_size();
 }
 float& operator[ ](const Sample& sz){
     if((loc.get_size()!=0) and (value.get_size()!=0)){
         for(int i=0;i<9;i++){
             if(loc[i]==sz){
                 return value[i];
             }
         }
    }
 }
 float operator[ ](const Sample& sz) const{
     if((loc.get_size()!=0) and (value.get_size()!=0)){
         for(int i=0;i<9;i++){
             if(loc[i]==sz){
                 return value[i];
             }
         }
    }
 }
 
 
    
};