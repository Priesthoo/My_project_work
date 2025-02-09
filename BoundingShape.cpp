 #include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
using namespace std;
enum BOUNDINGSHAPE{
    BOUNDINGBOX,
    BoundingSphere,
    BoundingCapsule
};

//Let's construct a point3d interface 

class Point3d{
    private:
    float x;
    float y;
    float z;
    public:
    Point3d()=default;
    Point3d(const float& X,const float& Y,const float& Z){
        x=X;
        y=Y;
        z=Z;
    }
    Point3d(const Point3d& point){
        x=point.X();
        y=point.Y();
        z=point.Z();
    }
    float X() const{
        return x;
    }
    float Y() const{
        return y;
    }
    float Z() const{
        return z;
    }
    float& X() {
        return x;
    }
    float& Y(){
        return y;
    }
    float& Z(){
        return z;
    }
    float& operator[ ](const unsigned int& index){
        if(index==0){
            return X();
        }
        if(index==1){
            return Y();
        }
        if(index==2){
            return Z();
        }
    }
     float operator[ ](const unsigned int& index) const{
        if(index==0){
            return X();
        }
        if(index==1){
            return Y();
        }
        if(index==2){
            return Z();
        }
    }
    bool operator>(const Point3d& point) const{
        if(this->X()>point.X() &&(this->Y() >point.Y()) && (this->Z()>point.Z())){
        return true;
        }
        else{
            return false;
        }
    }
  bool operator<(const Point3d& point) const{
        if(this->X()<point.X() &&(this->Y() <point.Y()) && (this->Z()<point.Z())){
        return true;
        }
        else{
            return false;
        }
    }
    bool operator>=(const Point3d& point) const{
        if(this->X()>=point.X() &&(this->Y() >=point.Y()) && (this->Z()>=point.Z())){
        return true;
        }
        else{
            return false;
        }
    }
   bool operator<=(const Point3d& point) const{
        if(this->X()<=point.X() &&(this->Y() <=point.Y()) && (this->Z()<=point.Z())){
        return true;
        }
        else{
            return false;
        }
    } 
  Point3d& operator=(const Point3d& point){
      this->X()=point.X();
      this->Y()=point.Y();
      this->Z()=point.Z();
      return *this;
  }
  Point3d operator-(const Point3d& point){
      return Point3d(this->X()-point.X(),this->Y()-point.Y(),this->Z()-point.Z());
  }
  friend Point3d operator*(const float& value, const Point3d& point){
      return Point3d(value*point.X(),value*point.Y(),value*point.Z());
 }
  Point3d operator+(const Point3d& point){
      return Point3d(this->X()+point.X(),this->Y()+point.Y(),this->Z()+point.Z());
  }
 };
 typedef Point3d Vertex;
 
class BoundingBox{
    private:
    Vertex max_point;
    Vertex min_point;
    public:
    BoundingBox(){
        max_point.X()=1e-30f;
        max_point.Y()=1e-30f;
        max_point.Z()=1e-30f;
        min_point.X()=1e30f;
        min_point.Y()=1e30f;
        min_point.Z()=1e30f;
    }
BoundingBox(const float& min_x,const float& min_y,const float& min_z,const float& max_x,const float& max_y,const float& max_z){
min_point.X()=min_x;
min_point.Y()=min_y;
min_point.Z()=min_z;
max_point.X()=max_x;
max_point.Y()=max_y;
max_point.Z()=max_z;
}
BoundingBox(const Vertex& vertex1,const Vertex& vertex2){
    max_point=vertex1;
    min_point=vertex2;
 }
 //Use to construct an object of a bounding Box
 BoundingBox(const BoundingBox& box){
     this->max_point.X()=box.max_point.X();
     this->max_point.Y()=box.max_point.Y();
     this->max_point.Z()=box.max_point.Z();
     this->min_point.X()= box.min_point.X();
     this->min_point.Y()=box.min_point.Y();
     this->min_point.Z()=box.min_point.Z();
 }
 //Function to calculate Centroid
 Vertex Centroid(){
     return Vertex(0.5f*max_point+0.5f*min_point);
 }
 //Union of two Bounding Box
void  Union(const BoundingBox& Box2){
 this->max_point=std::max(this->max_point,Box2.max_point);
 this->min_point=std::min(this->min_point,Box2.min_point);
 return;
}
Vertex Max_Point() const{
    return max_point;
}
Vertex Min_Point() const{
    return min_point;
}
//This returns the  vector length between the maximum point and the minimum point
Vertex Diagonal() {
    Vertex Diagonal_Vector=Max_Point()-Min_Point();
    return Diagonal_Vector;
 }
 //This Function returns the maximum magnitude of the component along one of the axis
 int MaximumExtent(){
     Vertex Diagonal_Vector=Diagonal();
     if(Diagonal_Vector.X()>Diagonal_Vector.Y() && Diagonal_Vector.X()>Diagonal_Vector.Z()){
        return 0;
     }
     else if(Diagonal_Vector.Y()<Diagonal_Vector.Z()){
         return 1;
     }
     else{
         return 2;
     }
 }
 

};
typedef BoundingBox Bound;
class GeometryObject{
    private:
    std::vector<Vertex>&Vertices;
    size_t numVertices; //This is initialized when Vertices is filled, It is still the same as Vertices.size()
    Bound GBound; //Thid represents the Geometry Bounding Box
};

int main(int argc, char *argv[])
{
	BoundingBox box(Point3d(0.3f,0.8f,-10.0f),Point3d(9.0f,5.0f,6.0f));
	BoundingBox box1(Point3d(12.0f,5.0f,3.0f),Point3d(-1.0f,2.0f,5.0f));
    box.Union(box1);
    std::cout<<"Set of Maximum point are:"<<std::endl;
    for(int i=0;i<3;i++){
        std::cout<<box.Max_Point()[i]<<std::endl;
    }
   std::cout<<"Components of Minimum point:"<<std::endl;
   for(int i=0;i<3;i++){
       std::cout<<box.Min_Point()[i]<<std::endl;
   }
   Point3d Centre=box.Centroid();
   std::cout<<"Components of Centre point:"<<std::endl;
   for(int i=0;i<3;i++){
       std::cout<<Centre[i]<<std::endl;
   }
   Vertex diagonal=box.Diagonal();
   std::cout<<"Components of Diagonal vector:"<<std::endl;
   for(int i=0;i<3;i++){
       std::cout<<diagonal[i]<<std::endl;
   }
   std::cout<<"Maximum Extent of the Box:"<<box.MaximumExtent()<<std::endl;
} 