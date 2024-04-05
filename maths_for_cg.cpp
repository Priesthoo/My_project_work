#include<iostream>
using namespace std;
class Vector3d{
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
    
};
