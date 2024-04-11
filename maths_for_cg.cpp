#include<iostream>
#include<cmath>
#include<string>
#include"Vector.h"
typedef Vector<float> Mat_elem;
using namespace std;
class Render{
};// this update the frame_buffer
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
    Vector3d operator+(const Vector3d& vec1)const{
        Vector3d vec;
        vec.x=(this->x+vec1.x);
        vec.y=(this->y+vec1.y); //adding two vectors together
        vec.z=(this->z+vec1.z);
        return vec;
    }
    Vector3d operator-(const Vector3d& vec1)const {
        Vector3d vec;
         vec.x=(this->x-vec1.x);
        vec.y=(this->y-vec1.y); //subtracting a vector from the other
        vec.z=(this->z-vec1.z);
        return vec;
    }
    Vector3d operator*(const float& s) const {
        Vector3d vec;
        vec.x=this->x*s;  //multiplying a vector by a scalar
        vec.y=this->y*s;
        vec.z=this->z*s;
        return vec;
    }
    Vector3d operator*(const Vector3d& f2) const {
        Vector3d vec;
        vec.x=(this->y*f2.z)-(this->z*f2.y);
        vec.y=(this->x*f2.z)-(this->z*f2.x);  //cross product.
        vec.z=(this->x*f2.y)-(this->y*f2.x);
        return vec;
    }
    Vector3d operator/(const float& s)const {
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
    Vector3d& operator=(const Vector3d& vec){
        x=vec[1];
        y=vec[2];
        z=vec[3];
        return *this;
    }
    Vector3d negate() const{
        Vector3d vec1;
        vec1.x=-this->x;
        vec1.y=-this->y;
        vec1.z=-this->z;
        return vec1;
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
     size_t get_mat_length() const {
        return  mat.get_length();
     }
     Mat3x3& operator=(const Mat3x3& mat1){
         for(int i=0;i<mat.get_length();i++){
             mat[i]=mat1.mat[i];
         }
         return *this;
     }
                    
};
class Mat4x4{ // for both position and orientation,....
    private:
    Mat_elem V;
    public:
    Mat4x4(){
        if(V.check_if_NULL()==true){
            V.set_size(16);
        }
    }
    float& operator[ ](const int& idx){
        return V[idx];
    }
  const  float& operator[ ](const int& idx) const {
        return V[idx];
    }
    Mat4x4(const Mat3x3& mat,const Vector3d& trans){
        if(V.check_if_NULL()==true){
            V.set_size(16);
        }
        V[0]=mat[0];
        V[1]=mat[1];
        V[2]=mat[2];
        V[3]=trans[0];
        V[4]=mat[3];
        V[5]=mat[4];
         V[6]=mat[5];
         V[7]=trans[1];
         V[8]=mat[6];
         V[9]=mat[7];
         V[10]=mat[8];
         V[11]=trans[2];
         V[12]=0;
         V[13]=0;
         V[14]=0;
         V[15]=1;
    }
    Mat4x4(const float&a,const float&b,const float& c,const float& d,const float& e,const float& f,const float& g,const float& h,const float& i,const float& j,const float& k,const float& l,const float& m,const float& n,const float& o,const float&p){
        if(V.check_if_NULL()==true){
            V.set_size(16);
        }
        V[0]=a;
        V[1]=b;
        V[2]=c;
        V[3]=d;
        V[4]=e;
        V[5]=f;
         V[6]=g;
         V[7]=h;
         V[8]=i;
         V[9]=j;
         V[10]=k;
         V[11]=l;
         V[12]=m;
         V[13]=n;
         V[14]=o;
         V[15]=p;
     }
    void set_translation(const Vector3d& trans){
        V[3]=trans[0];
        V[7]=trans[1];
        V[11]=trans[2];
    }
    void set_matrix(const Mat3x3&  mat,const Vector3d& trans){
          if(V.check_if_NULL()==true){
            V.set_size(16);
        }
        V[0]=mat[0];
        V[1]=mat[1];
        V[2]=mat[2];
        V[3]=trans[0];
        V[4]=mat[3];
        V[5]=mat[4];
         V[6]=mat[5];
         V[7]=trans[1];
         V[8]=mat[6];
         V[9]=mat[7];
         V[10]=mat[8];
         V[11]=trans[2];
         V[12]=0;
         V[13]=0;
         V[14]=0;
         V[15]=1;
    }
    static void print_out_mat(const Mat4x4&  mat){
        cout<<"{"<<mat[0]<<","<<mat[1]<<","<<mat[2]<<","<<mat[3]<<endl;
     cout<<","<<mat[4]<<","<<mat[5]<<","<<mat[6]<<","<<mat[7]<<endl;
     cout<<","<<mat[8]<<","<<mat[9]<<","<<mat[10]<<","<<mat[11]<<endl;
      cout<<","<<mat[12]<<","<<mat[13]<<","<<mat[14]<<","<<mat[15]<<"}"<<endl;
    }
    Mat3x3 get_Mat3x3_comp() const {
        Mat3x3 mat;
        mat[0]=V[0];
        mat[1]=V[1];
        mat[2]=V[2];
        mat[3]=V[4];
        mat[4]=V[5];
        mat[5]=V[6];
        mat[6]=V[8];
        mat[7]=V[9];
        mat[8]=V[10];
        return mat;
     }
     Vector3d get_translation() const{
         Vector3d vec;
         vec[0]=V[3];
         vec[1]=V[7];
         vec[2]=V[11];     
         return vec;
         }
   Mat4x4 operator*(const Mat4x4& mat){
       Mat4x4 op;
       op[0]=V[0]*mat[0]+V[1]*mat[4]+V[2]*mat[8]+V[3]*mat[12];
       op[1]=V[0]*mat[1]+V[1]*mat[5]+V[2]*mat[9]+V[3]*mat[13];
       op[2]=V[0]*mat[2]+V[1]*mat[6]+V[2]*mat[10]+V[3]*mat[14];
      op[3]=V[0]*mat[3]+V[1]*mat[7]+V[2]*mat[11]+V[3]*mat[15];
      op[4]=V[4]*mat[0]+V[5]*mat[4]+V[6]*mat[8]+V[7]*mat[12];
      op[5]=V[4]*mat[1]+V[5]*mat[5]+V[6]*mat[9]+V[7]*mat[13];
      op[6]=V[4]*mat[2]+V[5]*mat[6]+V[6]*mat[10]+V[7]*mat[14];
      op[7]=V[4]*mat[3]+V[5]*mat[7]+V[6]*mat[11]+V[7]*mat[15];
     op[8]=V[8]*mat[0]+V[9]*mat[4]+V[10]*mat[8]+V[11]*mat[12];
     op[9]=V[8]*mat[1]+V[9]*mat[5]+V[10]*mat[9]+V[11]*mat[13];
     op[10]=V[8]*mat[2]+V[9]*mat[6]+V[10]*mat[10]+V[11]*mat[14];
     op[11]=V[8]*mat[3]+V[9]*mat[7]+V[10]*mat[11]+V[11]*mat[15];
     op[12]=V[12]*mat[0]+V[13]*mat[4]+V[14]*mat[8]+V[15]*mat[12];
     op[13]=V[12]*mat[1]+V[13]*mat[5]+V[14]*mat[9]+V[15]*mat[13];
     op[14]=V[12]*mat[2]+V[13]*mat[6]+V[14]*mat[10]+V[15]*mat[14];
      op[15]=V[12]*mat[3]+V[13]*mat[7]+V[14]*mat[11]+V[15]*mat[15];
     return op;
   }
 
};

enum ROTATE{
    ROTATE_X,
    ROTATE_Y,
    ROTATE_Z
  };
  class Transform{
      public:
      static Mat3x3 construct_rotation(float theta,ROTATE rot){
          Mat3x3 mat;
          float c=cos(theta);
          float s=sin(theta);
          if(rot==ROTATE_X){
              mat={1 ,0 ,0
                         ,0,c,-s
                         ,0,s,c};
          }
          else if(rot==ROTATE_Y){
              mat={c,0,s
                        ,0,1,0
                        ,-s,0,c};
          }
          else if(rot==ROTATE_Z){
              mat={c,-s,0
                       ,s,c,0
                       ,0,0,1};
              }
         return mat;
      }
   static Mat3x3 construct_scale(float s){
       Mat3x3 mat;
       mat={s,0,0
                 ,0,s,0
                 ,0,0,s};
       return mat;
     }
     static Mat4x4 construct_trans(const Vector3d& trans){
         Mat4x4 mat={1 ,0,0, trans[0]
                                  ,0,1,0,trans[1]
                                  ,0,0,1,trans[2]
                                  ,0,0,0,1};
          return mat;
        }
     static Mat4x4 construct_trans(const Mat3x3& mat1,const Vector3d& trans){
         Mat4x4 mat={mat1,trans};
         return mat;
     }
  };
  class Quat{
      private:
      Vector3d vec;
      float w;
     public:
      Quat()=default;
      Quat(const Vector3d& vec1,const float& w1){
          vec=vec1;
          w=w1;   
      }
    
      //operations performed on quaternions
      Quat operator+(const Quat& q) const {
         Quat q1;
         q1.vec=this->vec+q.vec;
         q1.w=this->w+q.w;
         return q1;
      }
      Quat operator*(const Quat& q) const {
          Vector3d v1=(this->vec*q.vec)+(q.vec*this->w)+(this->vec*q.w);
          float w1=Vector3d::dot_product(this->vec,q.vec);
          float w2=(this->w*q.w);
          float w3=w2-w1;
          Quat q1={v1,w3};
    return q1;      
      }
  
  Quat compute_conjugate() const {
      Vector3d vec1=this->vec.negate();
      Quat q1={vec1,this->w};
      return q1;
   }
    Quat operator*(const float& s) const{
        Vector3d vec1=this->vec* s;
        float v=this->w*s;
        Quat q={vec1,v};
        return q;
    }
    float q_norm() const {
        float q1=this->vec[0]*this->vec[0];
        float q2=this->vec[1]*this->vec[1];
        float q3=this->vec[2]*this->vec[2];
        float q4=this->w*this->w;
        float q5=sqrt(q1+q2+q3+q4);
        return q5;
    }
   Quat compute_inverse()const {
       Quat q=this->compute_conjugate();
       float t=this->q_norm();
       Vector3d vec1=q.vec/t;
       float g=q.w/t;
       Quat q1={vec1,g};
       return q1;
   }
 };
 enum VIEW{
     ORTHO,
     PERSP
 };
 class Cam_view{
     
 };
  
class Camera{
    
};