#include<iostream>
#include<cmath>
#include<string>
#include"Vector.h"
typedef Vector<float> Mat_elem;
using namespace std;
class Vector3d{
   protected:
   float x,y,z;
   public:
    Vector3d()=default;
    Vector3d(const float& r,const float& p,const float& q){
        x=r;
        y=p;
        z=q;
    }
    Vector3d(float& r,float& p,float& q){
        x=r;
        y=p;
        z=q;
    }
    //operations performed on vector3d type:
    Vector3d operator+(const Vector3d& vec1){
        Vector3d vec;
        vec.x=(this->x+vec1.x);
        vec.y=(this->y+vec1.y); //adding two vectors together
        vec.z=(this->z+vec1.z);
        return vec;
    }
    Vector3d operator-(const Vector3d& vec1){
        Vector3d vec;
         vec.x=(this->x-vec1.x);
        vec.y=(this->y-vec1.y); //subtracting a vector from the other
        vec.z=(this->z-vec1.z);
        return vec;
    }
    Vector3d operator*(const float& s){
        Vector3d vec;
        vec.x=this->x*s;  //multiplying a vector by a scalar
        vec.y=this->y*s;
        vec.z=this->z*s;
        return vec;
    }
    Vector3d operator*(const Vector3d& f2){
        Vector3d vec;
        vec.x=(this->y*f2.z)-(this->z*f2.y);
        vec.y=(this->x*f2.z)-(this->z*f2.x);  //cross product.
        vec.z=(this->x*f2.y)-(this->y*f2.x);
        return vec;
    }
    Vector3d operator/(const float& s){
        Vector3d vec;
        vec.x=this->x/s;  // dividing a vector by a scalar
        vec.y=this->y/s;
        vec.z=this->z/s;
        return vec;
    }
 static  float dot_product(const Vector3d& vec1,const Vector3d& vec2){
       float dot=(vec1.x*vec2.x)+(vec1.y*vec2.y)+(vec1.z*vec2.z);
       return dot; //for performing dot product on the vector for the purpose of finding the angle between the vectors.,if dot_product(v1,v2) <0,theta is less than 90°,else if dot_product(v1,v2)==0, theta is 90°,else if dot_product(v1,v2)>0,theta is greater than 90°....
   }
 static  float mag(const Vector3d& vec){
     float mag=sqrt(vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
     return mag;
 } //finding the magnitude of the vector....
    void print_vector(){
        cout<<"Vector3d("<<x<<","<<y<<","<<z<<")"<<endl;
    }
    float get_comp(const string& enter) const {
        if(enter=="X"){
            return x;
        }
        else if(enter=="Y"){
            return y;
         }
         else if(enter=="Z"){
             return z;
         }
    }
    float&  get_comp(const string& enter)  {
        if(enter=="X"){
            return x;
        }
        else if(enter=="Y"){
            return y;
         }
         else if(enter=="Z"){
             return z;
         }
    }
    float& operator[ ](const int idx){
        if(idx==0){
            return x;
        }
        else if(idx==1){
            return y;
        }
        else if(idx==2){
            return z;
        }
    }
  const  float& operator[ ](const int idx) const {
        if(idx==0){
            return x;
        }
        else if(idx==1){
            return y;
        }
        else if(idx==2){
            return z;
        }
    }
};
class Point4D:public Vector3d{ //single inheritance
    float w;
    public:
    Point4D()=default;
    Point4D(const float& r,const float& p,const float& q,const float& s){
        x=r;
        y=p;
        z=q;
        w=s;
    }
     Point4D( float& r, float& p, float& q, float& s){
        x=r;
        y=p; //a point that lies on a vector(direction);3
        z=q;
        w=s;
    }
    Point4D(const Vector3d& vec,const float&  j){
        x=vec.get_comp("X");
        y=vec.get_comp("Y");
        z=vec.get_comp("Z");
        w=j;
    }
    Point4D operator/(const float& s){
        Vector3d vec1={this->get_comp("X"),this->get_comp("Y"),this->get_comp("Z")};
        float j=this->w/s;
        vec1=vec1/s;
        Point4D focus={vec1,j};
        return focus;
        }
  };
class Mat3x3{//construct the coordinate system
    Mat_elem mat;
    public:
    Mat3x3(){
        mat.set_size(9);
        (*this).set_identity();
    }
    Mat3x3(const Vector<float>& vec){
        if(mat.check_if_NULL()==true){
            mat.set_size(9);
        }
        for(int i=0;i<mat.get_length();i++){
            mat[i]=vec[i];
        }
    }
    Mat3x3(const float& a0,const float& a1,const float& a2,const float& a3,const float& a4,const float& a5,const float& a6,const float& a7,const float& a8){
        if(mat.check_if_NULL()==true){
            mat.set_size(9);
        }
        mat[0]=a0;    // | mat[0]   mat[1]   mat[2] |
         mat[1]=a1;   // | mat[3]   mat[4]   mat[5] |
        mat[2]=a2;   //  |  mat[6]   mat[7]   mat[8]|  
        mat[3]=a3;
        mat[4]=a4;
        mat[5]=a5;
        mat[6]=a6;
        mat[7]=a7;
        mat[8]=a8;
     }
    void set_mat3x3(const Mat3x3& M){
        if(mat.check_if_NULL()==true){
            mat.set_size(9);
        }
        for(int i=0;i<mat.get_length();i++){
            mat[i]=M.mat[i];
        }
    }
    float& operator[ ](const int idx){
        return mat[idx];    
        }
        float& operator[ ](const int idx) const{
            return mat[idx];
        }
        Mat3x3 operator*(const Mat3x3& v1){ 
            Mat3x3 result;
            Mat3x3 v=*this;
            result[0]=v[0]*v1[0]+v[1]*v1[3]+v[2]*v1[6];
            result[1]=v[0]*v1[1]+v[1]*v1[4]+v[2]*v1[7];
            result[2]=v[0]*v1[2]+v[1]*v1[5]+v[2]*v1[8];    
             result[3]=v[3]*v1[0]+v[4]*v1[3]+v[5]*v1[6];
            result[4]=v[3]*v1[1]+v[4]*v1[4]+v[5]*v1[7];
            result[5]=v[3]*v1[2]+v[4]*v1[5]+v[5]*v1[8];   
             result[6]=v[6]*v1[0]+v[7]*v1[3]+v[8]*v1[6];
            result[7]=v[6]*v1[1]+v[7]*v1[4]+v[8]*v1[7];
            result[8]=v[6]*v1[2]+v[7]*v1[5]+v[8]*v1[8];    
            return result;
}
Vector3d operator*(const Vector3d& vec){// transforming the vector coordinate system or changing the coordinate system
    Vector3d vec1;
    Mat3x3 vec2=*this;
    vec1[0]=vec[0]*vec2[0]+vec[1]*vec2[3]+vec[2]*vec2[6];
    vec1[1]=vec[0]*vec2[1]+vec[1]*vec2[4]+vec[2]*vec2[7];
    vec1[2]=vec[0]*vec2[2]+vec[1]*vec2[5]+vec[2]*vec2[8];
    return vec1;
 }
 void print_out_matrix(){
     cout<<"{"<<mat[0]<<","<<mat[1]<<","<<mat[2]<<endl;
     cout<<","<<mat[3]<<","<<mat[4]<<","<<mat[5]<<endl;
     cout<<","<<mat[6]<<","<<mat[7]<<","<<mat[8]<<"}"<<endl;
     }  
 void set_identity(){
     mat[0]=1;
     mat[1]=0;
     mat[2]=0;
     mat[3]=0;
     mat[4]=1;
     mat[5]=0;
     mat[6]=0;
     mat[7]=0;
     mat[8]=1;
     }               
};
