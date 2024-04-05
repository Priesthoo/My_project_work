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
        y=p;
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

