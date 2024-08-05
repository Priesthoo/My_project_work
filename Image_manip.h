#include<iostream>
using namespace std;
#include<memory>
#include<string>
#define MULTI_COLOR
#define ALPHA
#ifndef SHARED_PTR
#define SHARED_PTR
#endif

#ifndef MATH_H
#define MATH_H
#include<cmath>
#endif



#include<utility>
#define BIG_NUM 8880000000
#include"Image_color.h"
typedef float gray_scale_f; //float version of grayscale
typedef size_t grayscale_ui; //unsigned int version of grayscale;

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

#ifndef COLOR_CLAMP
#define COLOR_CLAMP
void clamp_values(const float min,float& v,const float max){
    if(v>max){
        v=max;
 }
 else if(v<min){
     v=min;
 }
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
      this->True_colors=im_type.True_colors;
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
 Color& operator[ ](const size_t& sz){
     if(sz<this->size()){
         return True_colors[sz];
     }
 }
 Color operator[ ](const size_t& sz) const {
     if(sz<this->size()){
         return True_colors[sz];
     }
 }
 size_t convert_samples_to_index(const Sample& samp){
     if(this->size()!=0){
     for(int i=0;i<this->size();i++){
         if(samples[i]==samp){
             return i;
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
 Sample_3d convert_to_samp_3d(const Sample samp){
     this->x=samp.x;
     this->y=samp.y;
     this->z=1;
 }
 };
 ostream& operator<<(ostream& os,const Sample_3d& samp){
     os<<"["<<samp.x<<","<<samp.y<<","<<samp.z<<"]"<<endl;
     return os;
 }
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
    public:
    Samples loc;
    Values value;
    public:
    Transform(){
        this->init_all_location();
        value.set_size(loc.get_size());
        identity(*this);
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
 float& operator[ ](const size_t& sz){
     if((loc.get_size()!=0) and sz<9){
         return this->value[sz];
   }
 }
  float operator[ ](const size_t& sz) const{
     if((loc.get_size()!=0) and sz<9){
         return this->value[sz];
   }
  }
void construct_translation(const float& x,const float& y){
     this->value[6]=x;
     this->value[7]=y;
}
Transform(const Transform& transform){
    loc=transform.loc;
    value=transform.value;
    }
Transform& operator=(const Transform& trans){
    *this={trans};
    return *this;
}
size_t return_by_sample(const Sample& samp){
    size_t sz1=0;
    if(this->size_of_matrix()!=0){
       for(int i=0;i<9;i++){
        if(loc[i]==samp){
            sz1=i;
            return sz1;
        }
    }
   }
}
void construct_vertical_shear(const float& sh);
void construct_horizontal_shear(const float& sh);
/*
Note: theta must be in radians,constructing a rotational matrix on the called object
*/
 void construct_rotation(const float& theta){
this->value[0]=cos(theta);
 this->value[1]=sin(theta);
 this->value[3]=-sin(theta);
 this->value[4]=cos(theta);
}
 void identity(Transform& trans){
     trans[0]=1.0f;
     trans[1]=0.0f;
     trans[2]=0.0f;
     trans[3]=0.0f;
     trans[4]=1.0f;
     trans[5]=0.0f;
     trans[6]=0.0f;
     trans[7]=0.0f;
     trans[8]=1.0f;
 }
 void construct_scale(const float&  uniform_scale){
 for(int i=0;i<9;i++){
       if((i==4) or (i==0)){ //uniform scaling
           this->value[i]=uniform_scale;
       }
 }
 }
 Transform operator*(const Transform& trans){
     Transform trans1;
     trans1[0]=(this->value[0]*trans[0])+(this->value[1]*trans[3])+(this->value[2]*trans[6]);
     trans1[1]=(this->value[0]*trans[1])+(this->value[1]*trans[4])+(this->value[2]*trans[7]);
     trans1[2]=(this->value[0]*trans[2])+(this->value[1]*trans[5])+(this->value[2]*trans[8]);
     trans1[3]=(this->value[3]*trans[0])+(this->value[4]*trans[3])+(this->value[5]*trans[6]);
     trans1[4]=(this->value[3]*trans[1])+(this->value[4]*trans[4])+(this->value[5]*trans[7]);
     trans1[5]=(this->value[3]*trans[2])+(this->value[4]*trans[5])+(this->value[5]*trans[8]);
     trans1[6]=(this->value[6]*trans[0])+(this->value[7]*trans[3])+(this->value[8]*trans[6]);
     trans1[7]=(this->value[6]*trans[1])+(this->value[7]*trans[4])+(this->value[8]*trans[7]);
     trans1[8]=(this->value[6]*trans[2])+(this->value[7]*trans[5])+(this->value[8]*trans[8]);
     return trans1;
     }
 void convert_to_matrix(const Sample_3d& samp){
    this->value[0]=(float)samp.x;
     this->value[3]=(float)samp.y;
     this->value[6]=(float)samp.z;
     
 }

 };
 enum SPATIAL_FILTER{
     MASK,
     KERNEL
 };
 enum SAMPLER_ORDER{
     ROW_ORDER,
     COLUMN_ORDER
};
 enum File_encoder{
 };
 enum File_decoder{
 };
 
 ostream& operator<<(ostream& os,const Transform& trans){
     os<<"[";
     for(int i=0;i<9;i++){
       os<<trans.value[i]<<",";
          if(i==8){
             os<<"]"<<endl;
         }
         else if((i==2) or(i==5)){
             os<<endl;
         }
     }
     
     return os;
 }
 void  get_sample_3d_from_transform(const Transform& trans,Sample_3d& samp){
     samp.x=trans[0];
     samp.y=trans[3];
     samp.z=trans[6];
     return;
 }
bool is_found_in_image(const Color& color,const Image_type& image){
    for(int i=0;i<image.size();i++){
        if(color==image.True_colors[i]){
            return true;
        }
    }
    return false;
}

class Spatial_Filter{
    private:
    Table<float>mask;
    public:
    Spatial_Filter():mask{}{}
    Spatial_Filter(const size_t& sz){
        this->mask.set_size(sz);
    }
    void push_filter_value(const float& fs){
        this->mask.push(fs);
    }
 float operator[ ](const size_t& idx){
     return mask[idx];
 }
 size_t size_of_filter() const{
     return mask.get_size();
 }
 
    
};