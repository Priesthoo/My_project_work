#include<iostream>
#include<cmath>
#include<string>
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
    } //getting the component of a vector3d
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
        z=vec[3];    //To assign a vector value to another vector
        return *this;
    }
    Vector3d negate() const{
        Vector3d vec1;
        vec1.x=-this->x;
        vec1.y=-this->y;
        vec1.z=-this->z;     //applying a minus sign to all component 
        return vec1;
    }
    bool operator==(const Vector3d& vec){
        if(this->x==vec.x and this->y==vec.y and this->z==vec.z){
            return true;
        }
        return false;
    }
    bool operator!=(const Vector3d& vec){
        if(this->x!=vec.x and this->y!=vec.y and this->z!= vec.z){
            return true;
        }
        return false;
    }
    bool operator<(const Vector3d& vec){
        if(this->x<vec.x and this->y < vec.y and this->z< vec.z){
            return true;
        }
        return false;
    }
    bool operator>(const Vector3d& vec){
        if(this->x>vec.x and this->y> vec.y and this->z> vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(const Vector3d& vec){
        if(this->x<=vec.x and this->y <= vec.y and this->z <=vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(const Vector3d& vec){
        if(this->x>=vec.x and this->y >=vec.y and this->z >= vec.z){
            return true;
        }
        return false;
    }
   Vector3d normalize(){
       float mag1=Vector3d::mag(*this);
       Vector3d vec1=*this;
       if(mag1>0){
       Vector3d vec2=vec1/mag1;
       return vec2;
   }
   }
};

enum COORDINATE_SYSTEM{
    LEFT_HANDEDNESS,
    RIGHT_HANDEDNESS
};